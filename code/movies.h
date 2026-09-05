/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

#include "rect.h"

class Surface;

// Only placement fields remain for the existing menu animation callers.
struct MoviePlayback
{
	Rect InitialRect;
	Rect StretchRect;
};

MoviePlayback * Movie_Create(char const * name, Surface * surface, Rect rect1, Rect rect2, int volume, bool fullscreen);
void Movie_Destroy(MoviePlayback * playback);
bool Movie_Advance_Frame(MoviePlayback * playback, bool & finished);
bool Movie_Is_Playing(void);
void Movie_Update_Visible_Surface(void);
