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

#include "ccini.h"


/// <summary>
/// Constructs a nameless and unavailable theme control.
/// The control is a blank slate until Fill_In supplies the real settings from the rules
/// database, so it belongs to no side and will not be considered for play.
/// </summary>
ThemeControl::ThemeControl(void) :
	Scenario(0),
	Duration(0),
	Normal(true),
	Repeat(false),
	Available(false),
	Owner(-1)
{
	Name[0] = '\0';
	Fullname[0] = '\0';

}


/// <summary>
/// Fetches this score's settings from the INI database.
/// This routine is used by Init_Themes to flesh out a theme control from the section
/// that bears its name. Any setting the section leaves out keeps the value it had.
/// </summary>
/// <param name="ini">The INI database to fetch the settings from.</param>
/// <returns>bool; Was a section for this score found?</returns>
bool ThemeControl::Fill_In(CCINIClass const & ini)
{
	if (ini.Is_Present(Name)) {
		ini.Get_String(Name, "Name", Fullname, Fullname, sizeof(Fullname));
		Scenario = ini.Get_Int(Name, "Scenario", Scenario);
		Duration = ini.Get_Float(Name, "Length", Duration);
		Normal = ini.Get_Bool(Name, "Normal", Normal);
		Repeat = ini.Get_Bool(Name, "Repeat", Repeat);
		Owner = ini.Get_Side(Name, "Side", (SideType)Owner);
		return(true);
	}
	return(false);
}
