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

#pragma once

#include "theme.hh"
#include "movie_type.hh"

template<class T> class DynamicVectorClass;

extern DynamicVectorClass<char const *> Movies;

bool Movie_Is_Available(char const *name);
void Play_Movie(char const * name, ThemeType theme=THEME_NONE, bool clrscrn_after=true, bool stretch=true, bool clrscrn_before=true);
void Play_Movie(MovieType movie, ThemeType theme=THEME_NONE, bool clrscrn=true, bool stretch=true);
void Play_InGame_Movie(MovieType movie);
void Pause_InGame_Movie(bool pause);
void Stop_InGame_Movie(void);
