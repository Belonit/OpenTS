/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "always.h"

#include "movies.h"
#include "dbgprint.h"
#include "vector.h"

DynamicVectorClass<char const *> Movies;

// Returning no movie lets menu animations use their existing PCX fallback.
VQHandle * Movie_Create(char const * name, Surface *, Rect, Rect, int, bool)
{
	DebugString("[MoviePlaybackStub] Skipping movie animation: %s\n", name != nullptr ? name : "<none>");
	return(nullptr);
}


void Movie_Destroy(VQHandle *)
{
}


bool Movie_Advance_Frame(VQHandle *, bool & finished)
{
	finished = true;
	return(false);
}


bool Movie_Is_Playing(void)
{
	return(false);
}


void Movie_Update_Visible_Surface(void)
{
}
