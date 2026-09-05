/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

#include "movie_audio.h"
#include "movie_decoder.h"
#include "rect.h"

#include "theme.hh"

#include <chrono>
#include <memory>
#include <optional>


class Surface;


enum class MovieAdvance
{
	Waiting,
	FrameReady,
	Finished,
	Failed,
};


class MoviePlayback
{
	public:
		MoviePlayback(std::unique_ptr<MovieDecoder> decoder, Surface *surface, Rect framerect, Rect displayrect, int volume, bool fullscreen);
		~MoviePlayback(void);

		MoviePlayback(MoviePlayback const &) = delete;
		MoviePlayback & operator=(MoviePlayback const &) = delete;

		MovieAdvance Advance(void);
		bool Redraw(void);
		void Pause(void);
		void Resume(void);
		void Set_Focused(bool focused);
		bool Is_Paused(void) const { return(UserPaused || FocusPaused); }

		int Get_Width(void) const;
		int Get_Height(void) const;
		Rect const & Frame_Rect(void) const { return(FrameRect); }
		Rect const & Display_Rect(void) const { return(DisplayRect); }
		void Set_Rects(Rect const &framerect, Rect const &displayrect)
		{
			FrameRect = framerect;
			DisplayRect = displayrect;
		}

	private:
		void Update_Pause_State(bool waspaused);
		bool Pump_Decoder(void);
		double Playback_Position(std::chrono::steady_clock::time_point now);
		bool Present_Frame(MovieFrame const &frame);

		std::unique_ptr<MovieDecoder> Decoder;
		MovieAudioPlayback AudioPlayback;
		Surface *DrawSurface;
		Rect FrameRect;
		Rect DisplayRect;
		bool Fullscreen;
		bool UserPaused = false;
		bool FocusPaused = false;
		bool AudioStarted = false;
		bool ClockStarted = false;
		double WallClockOffset = 0.0;
		double LastPresentedFrameEnd = 0.0;
		std::optional<MovieFrame> LastPresentedFrame;
		std::chrono::steady_clock::time_point WallClockStart;
};


std::unique_ptr<MoviePlayback> Movie_Create_Fullscreen(char const *name, Surface *surface, Rect displayrect, int volume);
std::unique_ptr<MoviePlayback> Movie_Create_On_Surface(char const *name, Surface *surface, Rect framerect, int volume);
void Movie_Play(MoviePlayback &movie, ThemeType theme);
void Movie_Queue_InGame(std::unique_ptr<MoviePlayback> movie);
MoviePlayback * Movie_Get_InGame(void);
void Movie_Remove_InGame(void);
void Movie_Clear_InGame(void);
