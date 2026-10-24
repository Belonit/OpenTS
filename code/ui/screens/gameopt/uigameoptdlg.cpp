/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "always.h"

#include "_ui.h"
#include "data.h"
#include "event.h"
#include "gamedlg.h"
#include "globals.h"
#include "house.h"
#include "loaddlg.h"
#include "queue.h"
#include "savemgr.h"
#include "scenario.h"
#include "session.h"
#include "ui/screens/gameopt/uigameopt.h"
#include "ui/uienginehost.h"
#include "ui/uishell.h"
#include "ui/uiview.h"

#include <cstring>


namespace
{

class UIGameOptionsEngineServiceClass : public UIGameOptionsServiceClass
{
	public:
		virtual void Read(UIGameOptionsState & state) override
		{
			UI_Game_Options_State(state);
		}

		virtual void Save(void) override
		{
			char description[512];
			std::strncpy(description, Scen->Description, sizeof(description) - 1);
			description[sizeof(description) - 1] = '\0';
			LoadOptionsClass().Save(description, sizeof(description));
		}

		virtual void Delete(void) override
		{
			LoadOptionsClass().Delete();
		}

		virtual bool Load(void) override
		{
			return(LoadOptionsClass().Load());
		}
};

}


void UI_Game_Options_State(UIGameOptionsState & state)
{
	state = UIGameOptionsState();
	state.Solo = (Session.Type == GAME_NORMAL || Session.Type == GAME_SKIRMISH);

	if (state.Solo) {
		bool const present = LoadOptionsClass().Files_Present();
		state.LoadEnabled = present;
		state.DeleteEnabled = present;
		state.BriefingEnabled = (Session.Type != GAME_SKIRMISH);
	} else {
		state.SaveEnabled = SaveManager.Is_Multiplayer_Saving_Allowed();
		state.LoadEnabled = SaveManager.Multiplayer_Load_Is_Allowed()
			&& MultiplayerLoadOptionsClass().Files_Present();
	}
}


UIGameOptionsChoice UI_Game_Options_Dialog(void)
{
	UIGameOptionsState state;
	UI_Game_Options_State(state);

	UIGameOptionsEngineServiceClass service;
	UIGameOptionsPresenterClass presenter(service, state);
	std::unique_ptr<UIViewClass> view = UI_Game_Options_View(presenter);

	if (UI_Run_Modal(*view) == UI_RESULT_FAILED_TO_OPEN) {
		return(UI_GAME_OPTIONS_RESUME);
	}

	UIGameOptionsChoice const choice = presenter.Choice;

	if (!state.Solo && choice == UI_GAME_OPTIONS_SAVE) {
		OutList.push_back(EventClass(PlayerPtr->HeapID, EventClass::SAVEGAME));
	}
	if (!state.Solo && choice == UI_GAME_OPTIONS_LOAD) {
		SpecialDialog = SDLG_LOAD;
	}

	return(choice);
}
