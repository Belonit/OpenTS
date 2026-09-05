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

#include "movie.h"
#include "dbgprint.h"


// Playback requests complete immediately while the replacement player is absent.
void Play_Movie(char const * name, ThemeType, bool, bool, bool)
{
	DebugString("[MoviePlaybackStub] Skipping fullscreen movie: %s\n", name != nullptr ? name : "<none>");
}


void Play_Movie(VQType vq, ThemeType, bool, bool)
{
	if (vq != VQ_NONE) {
		DebugString("[MoviePlaybackStub] Skipping fullscreen movie ID: %d\n", static_cast<int>(vq));
	}
}


void Play_Ingame_Movie(VQType vq)
{
	if (vq != VQ_NONE) {
		DebugString("[MoviePlaybackStub] Skipping radar movie ID: %d\n", static_cast<int>(vq));
	}
}


void Stop_Ingame_Movie(void)
{
}


void Pause_Ingame_Movie(bool)
{
}


bool Has_Ingame_Movies(void)
{
	return(false);
}
