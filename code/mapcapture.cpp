/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/


#include "always.h"

#include "mapcapture.h"

#include "_map.h"
#include "_rect.h"
#include "_surface.h"
#include "_tactica.h"
#include "addon.h"
#include "ccfile.h"
#include "ccini.h"
#include "dbgprint.h"
#include "dsurface.h"
#include "globals.h"
#include "headless.h"
#include "house.h"
#include "init.h"
#include "mplayer.h"
#include "png.h"
#include "rawfile.h"
#include "scenario.h"
#include "session.h"
#include "sidebar.h"
#include "tactical.h"

#include <cstdio>
#include <string>


namespace MapCapture
{
	namespace {

		// Random animation delays come from the seed, so a fixed one draws the same frame every run.
		constexpr int CAPTURE_SEED = 1;

		std::string MapName;
		std::string OutputPath;


		/// <summary>
		/// Does the map play as a campaign mission? A multiplayer map may name a player house
		/// too, so only a house the map itself lists, other than Neutral or Special, counts.
		/// </summary>
		bool Is_Campaign_Map(CCINIClass & ini)
		{
			if (ini.Get_Bool("Basic", "MultiplayerOnly", false)) {
				return(false);
			}

			char player[64];
			ini.Get_String("Basic", "Player", "", player, sizeof(player));
			if (player[0] == '\0' || stricmp(player, "Neutral") == 0 || stricmp(player, "Special") == 0) {
				return(false);
			}

			int const count = ini.Entry_Count("Houses");
			for (int index = 0; index < count; index++) {
				char house[64];
				ini.Get_String("Houses", ini.Get_Entry("Houses", index), "", house, sizeof(house));
				if (stricmp(house, player) == 0) {
					return(true);
				}
			}

			return(false);
		}


		void Seat_Observer(void)
		{
			Session.Type = GAME_SKIRMISH;

			Clear_Vector(&Session.Players);
			Clear_Vector(&Session.Computers);

			Session.Options.Bases = false;
			Session.Options.Goodies = false;
			Session.Options.UnitCount = 0;
			Session.Options.AIPlayers = 0;
			Session.Options.FogOfWar = false;

			std::snprintf(Session.Handle, sizeof(Session.Handle), "%s", "Observer");
			Session.House = HOUSE_FIRST;
			Session.ColorIdx = 0;
			Session.PrefColor = 0;

			NodeNameType * node = new NodeNameType;
			std::snprintf(node->Name, sizeof(node->Name), "%s", Session.Handle);
			node->Player.House = Session.House;
			node->Player.Color = Session.ColorIdx;
			node->Player.ProcessTime = -1;
			node->Player.IsObserver = true;
			Session.Players.Add(node);

			Session.NumPlayers = 1;
			Session.PlayerHouse = (HousesType)Session.House;
		}


		void Seat_Campaign(void)
		{
			Session.Type = GAME_NORMAL;
			Session.CampaignDifficulty = DIFF_NORMAL;
			Session.CampaignCDifficulty = DIFF_NORMAL;
			Scen->Campaign = CAMPAIGN_NONE;
		}


		bool Render_And_Write(void)
		{
			Rect const & local = Map.LocalRect;

			// The scroll limits of a view exactly this size leave it a single position, which
			// frames the whole LocalSize area.
			Rect const view(0, 0, ISO_TILE_PIXEL_W * local.Width, ISO_TILE_PIXEL_H * (2 * local.Height + 9) / 2);
			if (!view.Is_Valid()) {
				Headless::Fail("The map's LocalSize %d,%d,%d,%d leaves nothing to draw.", local.X, local.Y, local.Width, local.Height);
				return(false);
			}

			Rect const sidebar(0, 0, SidebarClass::SIDE_WIDTH, VisibleRect.Height);
			if (!Allocate_Surfaces(VisibleRect, view, view, sidebar)
					|| CompositeSurface == NULL || TileSurface == NULL
					|| ((DSurface *)CompositeSurface)->Get_Buffer() == NULL
					|| ((DSurface *)TileSurface)->Get_Buffer() == NULL) {
				Headless::Fail("No %dx%d drawing surface could be allocated.", view.Width, view.Height);
				return(false);
			}

			Map.Set_View_Dimensions(view);

			LogicalSurface = CompositeSurface;
			TacticalMap->Render(*CompositeSurface, true, DRAW_PASS_FULL);

			DSurface const * surface = (DSurface const *)CompositeSurface;
			unsigned short const * pixels = (unsigned short const *)surface->Get_Buffer();

			RawFileClass file(OutputPath.c_str());
			if (!Write_PNG_File(file, view.Width, view.Height, surface->Stride(), pixels)) {
				file.Delete();
				Headless::Fail("%s could not be written.", OutputPath.c_str());
				return(false);
			}

			DebugString("MapCapture: wrote %s, %dx%d, from LocalSize %d,%d,%d,%d.\n", OutputPath.c_str(),
				view.Width, view.Height, local.X, local.Y, local.Width, local.Height);
			return(true);
		}


		bool Check(void)
		{
			if (MapName.empty() || OutputPath.empty()) {
				Headless::Fail("A map capture needs both -CAPTUREMAP=<map> and -CAPTUREOUT=<png>.");
				return(false);
			}
			return(true);
		}


		/// <summary>
		/// Loads the requested map, draws its LocalSize area with no shroud and no interface,
		/// and writes the PNG. A multiplayer map is loaded with one observer, so only Neutral
		/// and Special objects remain; a campaign mission keeps every house it lists. No game
		/// logic runs, so the frame is the scenario exactly as it starts.
		/// </summary>
		/// <returns>bool; Was the PNG written?</returns>
		bool Run(void)
		{
			CCFileClass file(MapName.c_str());
			if (!file.Is_Available()) {
				Headless::Fail("The map %s was not found.", MapName.c_str());
				return(false);
			}

			CCINIClass ini;
			ini.Load(file, false);
			bool const campaign = Is_Campaign_Map(ini);

			// Firestorm adds to the base game's art and rules, so with it every map draws.
			Disable_Addon(ADDON_ANY);
			if (Addon_Installed(ADDON_FIRESTORM)) {
				Enable_Addon(ADDON_FIRESTORM);
				Set_Required_Addon(ADDON_FIRESTORM);
			}

			if (campaign) {
				Seat_Campaign();
			} else {
				Seat_Observer();
			}

			CustomSeed = CAPTURE_SEED;
			Init_Random();

			std::snprintf(Scen->ScenarioName, sizeof(Scen->ScenarioName), "%s", MapName.c_str());
			DebugString("MapCapture: loading %s as a %s map.\n", Scen->ScenarioName, campaign ? "campaign" : "multiplayer");

			if (!Read_Scenario(Scen->ScenarioName)) {
				Headless::Fail("The map %s could not be loaded.", MapName.c_str());
				return(false);
			}

			if (campaign) {
				Map.Reveal_The_Map(PlayerPtr, true);
				Session.ObiWan = 1;
			}

			return(Render_And_Write());
		}


		Headless::Task const Task = { "MapCapture", Check, Run };
	}


	/// <summary>
	/// Names the map a capture run draws, which makes the run headless.
	/// </summary>
	void Request_Map(char const * name)
	{
		MapName = name;
		Headless::Request(Task);
	}


	/// <summary>
	/// Names the PNG a capture run writes, replacing any file already there, which makes the
	/// run headless. A relative path is taken from the game's folder.
	/// </summary>
	void Request_Output(char const * path)
	{
		OutputPath = path;
		Headless::Request(Task);
	}
}
