/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 *
 * Contains material derived from Electronic Arts source code.
 * Modified by OpenTS contributors, 2026.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 ******************************************************************************/

// Reads THEME.INI into the theme player's track list.

#include "always.h"

#include "theme.h"

#include "dbgprint.h"
#include "ini.h"
#include "side.h"
#include "voc.h"

#include <cstring>
#include <string>


/// <summary>
/// Constructs a nameless and unavailable theme control.
/// The control is a blank slate until Fill_In supplies the real settings from the rules
/// database, so it belongs to every side and will not be considered for play.
/// </summary>
ThemeControl::ThemeControl(void) :
	Scenario(0),
	Duration(0),
	Volume(1.0f),
	RequiredAddon(0),
	Normal(true),
	Repeat(false),
	Available(false)
{
	Name[0] = '\0';
	Fullname[0] = '\0';
	Sound[0] = '\0';
	File[0] = '\0';
}


/// <summary>
/// Fetches this score's settings from the INI database.
/// This routine is used by Init_Themes to flesh out a theme control from the section
/// that bears its name. Any setting the section leaves out keeps the value it had.
/// </summary>
/// <param name="ini">The INI database to fetch the settings from.</param>
/// <returns>bool; Was a section for this score found?</returns>
bool ThemeControl::Fill_In(INIClass const & ini)
{
	if (ini.Is_Present(Name)) {
		ini.Get_String(Name, "Name", Fullname, Fullname, sizeof(Fullname));
		ini.Get_String(Name, "Sound", Sound, Sound, sizeof(Sound));
		Scenario = ini.Get_Int(Name, "Scenario", Scenario);
		Duration = ini.Get_Float(Name, "Length", Duration);
		std::string volume = ini.Get_String(Name, "Volume", "");
		if (!volume.empty()) {
			Volume = Sound_Parse_Volume(volume.c_str(), Volume);
		}
		RequiredAddon = ini.Get_Int(Name, "RequiredAddon", RequiredAddon);
		Normal = ini.Get_Bool(Name, "Normal", Normal);
		Repeat = ini.Get_Bool(Name, "Repeat", Repeat);
		std::string side = ini.Get_String(Name, "Side", "");
		if (!side.empty()) {
			Read_Sides(side.c_str());
		}
		return(true);
	}
	return(false);
}


/// <summary>
/// Sets the sides allowed to hear this score from a list of side names.
/// </summary>
/// <param name="text">Side names separated by commas. "&lt;none&gt;" allows every side.</param>
/// <remarks>An undeclared name is logged and skipped; if none is declared, the previous
/// sides stay.</remarks>
void ThemeControl::Read_Sides(char const * text)
{
	std::vector<SideType> sides;
	std::string list(text);
	size_t start = 0;
	while (start <= list.size()) {
		size_t end = list.find(',', start);
		if (end == std::string::npos) {
			end = list.size();
		}
		std::string name = list.substr(start, end - start);
		size_t first = name.find_first_not_of(" \t");
		size_t last = name.find_last_not_of(" \t");
		name = (first == std::string::npos) ? std::string() : name.substr(first, last - first + 1);

		if (!name.empty()) {
			if (stricmp(name.c_str(), "<none>") == 0) {
				Owners.clear();
				return;
			}
			SideType side = SideClass::From_Name(name.c_str());
			if (side == SIDE_NONE) {
				DebugString("[%s] Side=%s names no side declared in [Sides]; ignored.\n", Name, name.c_str());
			} else {
				sides.push_back(side);
			}
		}
		start = end + 1;
	}

	if (!sides.empty()) {
		Owners = sides;
	}
}


/// <summary>
/// Is this score allowed for a player of the specified side?
/// </summary>
bool ThemeControl::Allows_Side(SideType side) const
{
	if (Owners.empty()) {
		return(true);
	}
	for (SideType owner : Owners) {
		if (owner == side) {
			return(true);
		}
	}
	return(false);
}
