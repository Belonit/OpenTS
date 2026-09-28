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

#include "always.h"

#include "_keyboar.h"
#include "addon.h"
#include "ccfile.h"
#include "ccini.h"
#include "dbgprint.h"
#include "globals.h"
#include "keyboard.h"
#include "movie.h"
#include "restate.h"
#include "scenario.h"
#include "theme.h"
#include "ui/screens/restate/uirestate.h"

#include <cstdio>
#include <cstring>


// The scenario's briefing, or its entry in the mission INI when it has none.
static void Briefing_Text(ScenarioClass * scen, char * text, int size)
{
	text[0] = '\0';

	if (strlen(scen->BriefingText)) {
		DebugString("Restate: Fetching breifing text from %s\n", scen->ScenarioName);
		strncpy(text, scen->BriefingText, size - 1);
		text[size - 1] = '\0';
		return;
	}

	char buffer[32];
	CCFileClass file;
	if (scen->RequiredAddOn > ADDON_BASE_GAME) {
		sprintf(buffer, "MISSION%1d.INI", scen->RequiredAddOn);
		file.Set_Name(buffer);
	} else {
		file.Set_Name("MISSION.INI");
	}

	if (file.Is_Available() == true) {
		CCINIClass ini;
		ini.Load(file, false);
		DebugString("Restate: Fetching breifing text from Mission.ini\n");

		if (ini.Is_Present(scen->ScenarioName, "Briefing")) {
			ini.Get_String(scen->ScenarioName, "Briefing", "", buffer, sizeof(buffer));
			if (strlen(buffer)) {
				ini.Get_TextBlock(buffer, text, size);
			}
		}
	}
}


/***********************************************************************************************
 * Restate_Mission -- Handles restating the mission objective.                                 *
 *                                                                                             *
 *    This routine will display the mission objective (as text). It will also give the         *
 *    option to redisplay the mission briefing video.                                          *
 *                                                                                             *
 * INPUT:   name  -- The scenario name. This is the unique identifier for the scenario         *
 *                   briefing text as it appears in the "MISSION.INI" file.                    *
 *                                                                                             *
 * OUTPUT:  Returns the response from the dialog. This will either be 1 if the video was       *
 *          requested, or 0 if the return to game options button was selected.                 *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   06/23/1995 JLB : Created.                                                                 *
 *   08/06/1995 JLB : Uses preloaded briefing text.                                            *
 *=============================================================================================*/
void Restate_Mission(ScenarioClass * scen)
{
	if (scen == NULL) {
		return;
	}

	char text[sizeof(scen->BriefingText)];
	Briefing_Text(scen, text, sizeof(text));

	bool save_started = ScenarioActive;
	ScenarioActive = false;
	if (UI_Restate_Mission(text, scen->BriefMovie != VQ_NONE)) {
		Theme.Pause();
		Play_Movie(scen->BriefMovie, THEME_NONE, 1, 1);
		Theme.Resume();
	}
	ScenarioActive = save_started;
	Keyboard->Clear();
}
