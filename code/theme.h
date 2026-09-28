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

/* $Header: /CounterStrike/THEME.H 1     3/03/97 10:26a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : THEME.H                                                      *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : August 14, 1994                                              *
 *                                                                                             *
 *                  Last Update : August 14, 1994   [JLB]                                      *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#pragma once

#include "audio/audiohandle.h"
#include "stimer.h"
#include "vector.h"

#include "side.hh"
#include "theme.hh"

#include <stdlib.h>
#include <vector>

class CCINIClass;
class INIClass;

struct ThemeControl {
	ThemeControl(void);
	bool Fill_In(INIClass const & ini);
	bool Allows_Side(SideType side) const;

	char Name[256];			// Section name; also the file's base name unless Sound is set.
	char Fullname[64];		// Title shown in the sound options.
	char Sound[256];		// File base name; empty to use Name.
	char File[_MAX_FNAME+_MAX_EXT];	// The file Scan found, extension included.
	int Scenario;			// Scenario when it first becomes available.
	float Duration;			// Length= in minutes.
	float Volume;			// Share of the music volume.
	int RequiredAddon;		// Expansion that must be running; 0 for none.
	bool Normal;			// Allowed in normal game play?
	bool Repeat;			// Always repeat this score?
	bool StartFailed = false;	// The last attempt to open the file failed.
	bool Available;			// Is the score available?
	float Measured;			// Seconds the file states; 0 if none, -1 until measured.
	std::vector<SideType> Owners;	// Sides that may hear this score; empty for all.

	private:
		void Read_Sides(char const * text);
};

class ThemeClass
{
	private:
		char const * Theme_File_Name(ThemeType theme);
		bool Start(ThemeType theme, bool fadein);
		bool Loops(ThemeType theme) const;
		float Level(ThemeType theme) const;
		void Discard_Interruption(void);
		void Retire(int ms);

		AudioHandle Current;		// The current score, never one fading out.
		AudioHandle Fading;			// The score fading out, if any.
		ThemeType Score;			// Score number currently being played.
		ThemeType Pending;			// Score to play next.

		/*
		 * This is the volume the music is played at (0 - 255). At zero the theme handler
		 * does not bother starting a score at all.
		 */
		int Volume;

		/*
		 * If every score is to be played over again rather than moving on to the next one,
		 * then this flag will be true. A score can also ask to repeat on its own account
		 * through its Repeat setting.
		 */
		bool IsRepeat;

		/*
		 * If the next score is to be picked at random rather than in order, then this flag
		 * will be true. The score just played is only picked again when no other is allowed.
		 */
		bool IsShuffle;

		/*
		 * These are the scores the theme handler knows about, in the order they were read
		 * from the rules. A ThemeType is an index into this list.
		 */
		DynamicVectorClass<ThemeControl *> Themes;

		// The score that last ended with nothing after it; the next pick continues from it.
		ThemeType LastEnded;

		// After a failed start, no score starts before this time.
		unsigned RetryAt;

		// Having no allowed score is already logged.
		bool NoneAllowedLogged;

		// The next score rises from silence, after a crossfading change.
		bool FadeInNext;

		// THEME.INI [General] FadeOut= and CrossFade=, in milliseconds.
		int FadeOutMs;
		int CrossFadeMs;

		// THEME.INI [General] IonStormVolume=, and the scale on every score's volume: that
		// value while a storm plays its storm sound, else 1.
		float IonStormLevel;
		float StormLevel;

		// The current score is paused until Resume.
		bool IsPaused;

		// The score Begin_Interruption paused and the state to restore; not intact once
		// another request changes the music.
		struct InterruptionClass {
			bool Active = false;
			bool Intact = false;
			ThemeType Theme = THEME_NONE;
			AudioHandle Handle;
			ThemeType Score = THEME_NONE;
			ThemeType Pending = THEME_NONE;
			ThemeType LastEnded = THEME_NONE;
			bool FadeInNext = false;
		} Interrupt;

		static constexpr float DEFAULT_ION_STORM_LEVEL = 0.33f;

		enum {
			DEFAULT_FADE_OUT_MS = 1500,	// The 60 maintenance ticks the old driver took to fade.
			FADE_CUT_MS = 100,			// How quickly a newer fade cuts an older one short.
			RETRY_MS = 1000,
			PAUSE_FADE_MS = 250			// Pauses and resumes without a crossfade take this long.
		};

	public:
		ThemeClass(void);

		ThemeType From_Name(char const * name) const;
		ThemeType Next_Song(ThemeType index) const;
		ThemeType What_Is_Playing(void) const {return(Score);}
		bool Is_Allowed(ThemeType index) const;
		bool Is_Regular(ThemeType theme) const {return(theme != THEME_NONE && Themes[theme]->Normal);}
		char const * Base_Name(ThemeType index) const;
		char const * Full_Name(ThemeType index) const;
		int Max_Themes(void) const {return(Themes.Count());}
		AudioHandle Play_Song(ThemeType index);
		bool Still_Playing(void) const;
		int Track_Length(ThemeType index) const;
		void Scan(void);
		void AI(void);
		void Fade_Out(void) {Queue_Song(THEME_QUIET);}
		void Queue_Song(ThemeType index);
		void Stop(bool fade = false);
		void Pause(void);
		void Resume(void);
		void Begin_Interruption(ThemeType theme);
		void End_Interruption(void);
		void Set_Storm_Level(bool storm, bool instant);
		void Set_Shuffle(bool on) {IsShuffle = on;}
		void Set_Repeat(bool on);
		bool Is_Shuffle(void) const {return(IsShuffle);}

		void Set_Volume(int volume);

		void Init_Themes(CCINIClass const & ini);
		void Read_General(INIClass const & ini);
		void Free_Themes(void);
};

extern ThemeClass Theme;
