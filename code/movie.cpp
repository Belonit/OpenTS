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

#include "_keyboar.h"
#include "_map.h"
#include "_rect.h"
#include "_surface.h"
#include "dbgprint.h"
#include "dsurface.h"
#include "globals.h"
#include "goptions.h"
#include "gscreen.h"
#include "movie_player.h"
#include "session.h"
#include "vector.h"
#include "movie_type.hh"

#include <memory>
#include <utility>


DynamicVectorClass<char const *> Movies;

void Play_Movie(char const * name, ThemeType theme, bool clrscrn_after, bool stretch, bool clrscrn_before)
{
	// Don't play movies in multiplayer mode
	if (Session.Type != GAME_NORMAL) {
		return;
	}

	Keyboard->Clear();

	std::unique_ptr<MoviePlayback> movie = Movie_Create_Fullscreen(name, HiddenSurface, Rect(0,0,0,0), int(Options.SoundVolume * 255.0f));

	if (movie != NULL) {

		if (movie->Get_Width() < 320 && movie->Get_Height() < 200) {
			return;
		}

		bool oversized = movie->Frame_Rect().Width > VisibleRect.Width
			|| movie->Frame_Rect().Height > VisibleRect.Height;
		bool dostretch = oversized || (stretch == true && Options.StretchMovies == true);

		if (DSurface::AllowStretchBlits == true && dostretch == true && movie->Frame_Rect().Is_Valid()) {
			double scalex = (double)VisibleRect.Width / (double)movie->Frame_Rect().Width;
			double scaley = (double)VisibleRect.Height / (double)movie->Frame_Rect().Height;
			double scale = (scalex < scaley) ? scalex : scaley;

			Rect displayrect = movie->Display_Rect();
			displayrect.Width = (int)(movie->Frame_Rect().Width * scale);
			displayrect.Height = (int)(movie->Frame_Rect().Height * scale);
			displayrect.X = (VisibleRect.Width - displayrect.Width) / 2;
			displayrect.Y = (VisibleRect.Height - displayrect.Height) / 2;
			movie->Set_Rects(movie->Frame_Rect(), displayrect);
			DebugString("Stretching movie %dx%d -> %dx%d\n", movie->Frame_Rect().Width,
				movie->Frame_Rect().Height, movie->Display_Rect().Width, movie->Display_Rect().Height);
		}

		/*
		** Prepare to play a movie. First hide the mouse and stop any score that is playing.
		** While the score (if any) is fading to silence, fade the palette to black as well.
		** When the palette has finished fading, wait until the score has finished fading
		** before launching the movie.
		*/
		// The screen around a movie that does not cover the display has to be cleared too.
		if (clrscrn_before || movie->Display_Rect() != VisibleRect) {
			HiddenSurface->Fill(0);
			Update_Visible_Surface(HiddenSurface);
		}

		Movie_Play(*movie, theme);

		/*
		** Presume that the screen is left in a garbage state as well as the palette
		** being in an unknown condition. Recover from this by clearing the screen and
		** forcing the palette to black.
		*/
		if (clrscrn_after == true) {
			HiddenSurface->Fill(0);
			Update_Visible_Surface(HiddenSurface);
		}

		Map.Flag_To_Redraw(GS_REDRAW_ALL);
		Keyboard->Clear();
	}
}


/// <summary>
/// Plays a movie.
/// This routine is the convenient form that takes a movie identifier rather than a filename.
/// A movie identifier of MOVIE_NONE is quietly ignored.
/// </summary>
void Play_Movie(MovieType movie, ThemeType theme, bool clrscrn, bool stretch)
{
	if (movie != MOVIE_NONE) {
		Play_Movie(Movies[movie], theme, clrscrn, stretch, true);
	}
}


/// <summary>
/// Plays a movie on the sidebar.
/// This routine queues the movie up to play within the sidebar surface while the game
/// carries on around it. A missing movie, or a multiplayer game, is quietly ignored.
/// </summary>
/// <param name="name">The movie name, with or without an extension.</param>
void Play_InGame_Movie(const char * name)
{
	if (Session.Type == GAME_NORMAL) {
		std::unique_ptr<MoviePlayback> movie =
			Movie_Create_On_Surface(name, SidebarSurface, Rect(0,0,0,0), int(Options.SoundVolume * 255.0f));
		if (movie != nullptr) {
			Rect rect = movie->Frame_Rect();
			rect.X = Map.RadX + Map.RadOffX;
			rect.Y = Map.RadY + Map.RadOffY;
			movie->Set_Rects(rect, rect);
			Movie_Queue_InGame(std::move(movie));
		}
	}
}

/// <summary>
/// Plays a movie on the sidebar.
/// This routine is the convenient form that takes a movie identifier rather than a filename.
/// A movie identifier of MOVIE_NONE is quietly ignored.
/// </summary>
void Play_InGame_Movie(MovieType movie)
{
	if (movie != MOVIE_NONE) {
		Play_InGame_Movie(Movies[movie]);
	}
}


/// <summary>
/// Shuts down any in game movies that are playing.
/// This routine tears down every queued sidebar movie and releases it. Call it whenever the
/// sidebar is going away or the scenario is ending.
/// </summary>
void Stop_InGame_Movie(void)
{
	Map.Cancel_Movie_Playback();
	Movie_Clear_InGame();
}


/// <summary>
/// Suspends or resumes the in game movie.
/// Use this routine when the game itself is being suspended, so that the sidebar movie does
/// not run on while everything else is stopped.
/// </summary>
/// <param name="pause">Should the movie be suspended rather than resumed?</param>
void Pause_InGame_Movie(bool pause)
{
	MoviePlayback * movie = Movie_Get_InGame();
	if (movie != nullptr) {
		if (pause == true) {
			movie->Pause();
			DebugString("In-game movie paused\n");
		} else {
			movie->Resume();
			DebugString("In-game movie resumed\n");
		}
	}
}
