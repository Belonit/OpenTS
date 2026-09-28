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

/* $Header: /CounterStrike/THEME.CPP 3     3/11/97 4:03p Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : THEME.CPP                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : August 14, 1994                                              *
 *                                                                                             *
 *                  Last Update : August 12, 1996 [JLB]                                        *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   ThemeClass::AI -- Process the theme engine and restart songs.                             *
 *   ThemeClass::Base_Name -- Fetches the base filename for the theme specified.               *
 *   ThemeClass::From_Name -- Determines theme number from specified name.                     *
 *   ThemeClass::Full_Name -- Retrieves the full score name.                                   *
 *   ThemeClass::Is_Allowed -- Checks to see if the specified theme is legal.                  *
 *   ThemeClass::Next_Song -- Calculates the next song number to play.                         *
 *   ThemeClass::Play_Song -- Starts the specified song play NOW.                              *
 *   ThemeClass::Queue_Song -- Queues the song to the play queue.                              *
 *   ThemeClass::Scan -- Scans all scores for availability.                                    *
 *   ThemeClass::Set_Theme_Data -- Set the theme data for scenario and owner.                  *
 *   ThemeClass::Still_Playing -- Determines if music is still playing.                        *
 *   ThemeClass::Stop -- Stops the current theme from playing.                                 *
 *   ThemeClass::ThemeClass -- Default constructor for the theme manager class.                *
 *   ThemeClass::Theme_File_Name -- Constructs a filename for the specified theme.             *
 *   ThemeClass::Track_Length -- Calculates the length of the song (in seconds).               *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "theme.h"

#include "addon.h"
#include "ccini.h"
#include "ccrand.h"
#include "audio/audioengine.h"
#include "dbgprint.h"
#include "globals.h"
#include "houstype.h"
#include "incdec.h"
#include "session.h"
#include "vector.h"

#include <algorithm>


/// <summary>
/// Builds the theme list from the INI database.
/// This routine is used when the rules are read. A theme that is already known is
/// updated rather than duplicated, so a later rules file may amend the scores that an
/// earlier one declared as well as add scores of its own.
/// </summary>
/// <param name="ini">The INI database to fetch the theme list from.</param>
void ThemeClass::Init_Themes(CCINIClass const & ini)
{
	Read_General(ini);

	ThemeControl *ctrl;
	int count = ini.Entry_Count("Themes");
	for (int i = 0; i < count; i++) {
		char name[32];
		if (ini.Get_String("Themes", ini.Get_Entry("Themes", i), "", name, sizeof(name))) {

			ThemeType theme = From_Name(name);
			if (theme == THEME_NONE) {
				ctrl = new ThemeControl;
				strcpy(ctrl->Name, name);
				Themes.Add(ctrl);
			} else {
				ctrl = Themes[theme];
			}

			ctrl->Fill_In(ini);
		}
	}
}


/// <summary>
/// Frees the list of theme controls.
/// This routine is used before the rules are read afresh, and on the way out of the
/// game, so that the controls created by Init_Themes do not accumulate.
/// </summary>
void ThemeClass::Free_Themes(void)
{
	while (Themes.Count() > 0) {
		delete Themes[0];
		Themes.Delete_Index(0);
	}
}


/***********************************************************************************************
 * ThemeClass::Scan -- Scans all scores for availability.                                      *
 *                                                                                             *
 *    This routine should be called whenever a score mixfile is registered. It will scan       *
 *    to see if any score is unavailable. If this is the case, then the score will be so       *
 *    flagged in order not to appear on the play list. This condition is likely to occur       *
 *    when expansion mission disks contain a different score mix than the release version.     *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   01/04/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void ThemeClass::Scan(void)
{
	if (ScoresPresent && AudioEngine.Is_Available() && !Debug_Quiet) {
		for (ThemeType theme = THEME_FIRST; theme < Themes.Count(); theme++) {
			ThemeControl & control = *Themes[theme];
			char const * base = (control.Sound[0] != '\0') ? control.Sound : control.Name;
			control.StartFailed = false;
			control.Available = AudioEngineClass::Find_Named_File(base, control.File, sizeof(control.File));
		}
	}
}


/***********************************************************************************************
 * ThemeClass::Base_Name -- Fetches the base filename for the theme specified.                 *
 *                                                                                             *
 *    This routine is used to retrieve a pointer to the base filename for the theme            *
 *    specified.                                                                               *
 *                                                                                             *
 * INPUT:   theme -- The theme number to convert into a base filename.                         *
 *                                                                                             *
 * OUTPUT:  Returns with a pointer to the base filename for the theme specified. If the        *
 *          theme number is invalid, then a pointer to "No Theme" is returned instead.         *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/29/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
char const * ThemeClass::Base_Name(ThemeType theme) const
{
	if ((unsigned)theme < (unsigned)Themes.Count()) {
		return(Themes[theme]->Name);
	}
	return("No theme");
}


/***********************************************************************************************
 * ThemeClass::ThemeClass -- Default constructor for the theme manager class.                  *
 *                                                                                             *
 *    This is the default constructor for the theme class object.                              *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   01/16/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
ThemeClass::ThemeClass(void) :
	Current(),
	Fading(),
	Score(THEME_NONE),
	Pending(THEME_NONE),
	Volume(255),
	IsRepeat(false),
	IsShuffle(false),
	LastEnded(THEME_NONE),
	RetryAt(0),
	NoneAllowedLogged(false),
	FadeInNext(false),
	FadeOutMs(DEFAULT_FADE_OUT_MS),
	CrossFadeMs(0),
	IonStormLevel(DEFAULT_ION_STORM_LEVEL),
	StormLevel(1.0f),
	IsPaused(false)
{
}


/***********************************************************************************************
 * ThemeClass::Full_Name -- Retrieves the full score name.                                     *
 *                                                                                             *
 *    This routine will fetch and return with a pointer to the full name of the theme          *
 *    specified.                                                                               *
 *                                                                                             *
 * INPUT:   theme -- The theme to fetch the full name for.                                     *
 *                                                                                             *
 * OUTPUT:  Returns with a pointer to the full name for this score. This pointer may point to  *
 *          EMS memory.                                                                        *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   01/16/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
char const * ThemeClass::Full_Name(ThemeType theme) const
{
	if ((unsigned)theme < (unsigned)Themes.Count()) {
		return(Themes[theme]->Fullname);
	}
	return(NULL);
}


/// <summary>
/// Starts the next score once nothing is playing. Call it often.
/// </summary>
/// <remarks>A crossfaded score starts during the previous one's fade; any other waits for
/// the fade to end.</remarks>
void ThemeClass::AI(void)
{
	if (AudioEngine.Is_Available() && !Debug_Quiet) {
		if (!Fading.Is_Null() && Fading.Is_Finished()) {
			Fading.Clear();
		}

		// A repeating song ends only when repeat came on too late to loop its stream, and plays
		// again. After a song that nothing follows, the next pick continues from it.
		if (!Current.Is_Null() && Current.Is_Finished()) {
			Current.Clear();
			if (Loops(Score) && (Pending == THEME_NONE || Pending == THEME_PICK_ANOTHER)) {
				Pending = Score;
			} else if (Pending == THEME_NONE) {
				LastEnded = Score;
				Score = THEME_NONE;
			}
		}

		if (ScoresPresent && Volume > 0 && Current.Is_Finished() && (FadeInNext || Fading.Is_Finished()) && !IsPaused && (int)(AudioEngine.Now_Ms() - RetryAt) >= 0) {
			if (Pending != THEME_NONE && Pending != THEME_QUIET && !ScenarioInit) {
				/*
				**	If the pending song needs to be picked, then pick it now.
				*/
				if (Pending == THEME_PICK_ANOTHER) {
					Pending = Next_Song(Score != THEME_NONE ? Score : LastEnded);
					if (Pending == THEME_NONE) {
						Pending = THEME_PICK_ANOTHER;
						if (!NoneAllowedLogged) {
							DebugString("Theme::AI(No song is allowed)\n");
							NoneAllowedLogged = true;
						}
						RetryAt = AudioEngine.Now_Ms() + RETRY_MS;
						return;
					}
					NoneAllowedLogged = false;
					DebugString("Theme::AI(Next song = %d)\n", Pending);
				}

				/*
				**	Start the song playing and then flag it so that a new song will
				**	be picked when this one ends.
				*/
				Current.Clear();
				Start(Pending, FadeInNext);
				Pending = THEME_PICK_ANOTHER;
			}
		}
	}
}


/// <summary>
/// Chooses the song to play after the specified one.
/// </summary>
/// <param name="theme">The song that played last, or THEME_NONE to start from the top of
/// the list.</param>
/// <returns>Returns with the same song when it repeats and its last start worked. Otherwise
/// returns with an allowed song, at random with shuffle on but not the last one while
/// another is allowed, or else the next allowed one in list order; THEME_NONE if none is
/// allowed.</returns>
ThemeType ThemeClass::Next_Song(ThemeType theme) const
{
	if ((unsigned)theme < (unsigned)Themes.Count() && Themes[theme]->Available && !Themes[theme]->StartFailed && Loops(theme)) {
		return(theme);
	}

	if (IsShuffle) {

		/*
		**	Shuffle the theme, but never pick the same theme that was just
		**	playing unless no other is allowed.
		*/
		std::vector<ThemeType> choices;
		for (ThemeType candidate = THEME_FIRST; candidate < Themes.Count(); candidate = ThemeType(candidate + 1)) {
			if (candidate != theme && Is_Allowed(candidate)) {
				choices.push_back(candidate);
			}
		}
		if (choices.empty()) {
			return(((unsigned)theme < (unsigned)Themes.Count() && Is_Allowed(theme)) ? theme : THEME_NONE);
		}
		return(choices[NonCriticalRandomNumber(0, (int)choices.size() - 1)]);
	}

	/*
	**	Sequential score playing.
	*/
	int count = Themes.Count();
	int start = ((unsigned)theme < (unsigned)count) ? theme + 1 : THEME_FIRST;
	for (int step = 0; step < count; step++) {
		ThemeType candidate = ThemeType((start + step) % count);
		if (Is_Allowed(candidate)) {
			return(candidate);
		}
	}
	return(THEME_NONE);
}


/// <summary>
/// Queues the song to play once the current one has faded out. This is the normal and
/// friendly method of changing the current song.
/// </summary>
/// <param name="theme">The song to play next. THEME_NONE or THEME_QUIET only fades the
/// current song out.</param>
/// <remarks>Ignored while another song waits, unless it is THEME_NONE or THEME_QUIET. With
/// a crossfade the next song starts at once and fades in as the current one fades out.</remarks>
void ThemeClass::Queue_Song(ThemeType theme)
{
	/*
	**	If there is no score file present, then abort.
	*/
	if (!ScoresPresent) return;

	/*
	**	If there is no sound driver or sounds have been specifically
	**	turned off, then abort.
	*/
	if (!AudioEngine.Is_Available() || Debug_Quiet) return;

	/*
	**	If the current score volumne is set to silent, then there is no need to play the
	**	specified theme.
	*/
	if (Volume == 0) return;

	/*
	**	If the pending theme is available to be set and the specified theme is valid, then
	**	set the queued theme accordingly.
	*/
	if (Pending == THEME_NONE || Pending == THEME_PICK_ANOTHER || theme == THEME_NONE || theme == THEME_QUIET) {
		if (Pending != theme) {
			DebugString("Theme::QueueSong(%d)\n", theme);
		}
		Pending = theme;

		// Picking another song for a repeating one picks the same song, so it plays on.
		if (theme == THEME_PICK_ANOTHER && !Current.Is_Finished() && Loops(Score)) {
			return;
		}

		Interrupt.Intact = false;
		if (theme == THEME_QUIET) {
			Discard_Interruption();
		}

		if (!Current.Is_Finished()) {
			bool crossfade = CrossFadeMs > 0 && theme != THEME_NONE && theme != THEME_QUIET;
			Retire(crossfade ? CrossFadeMs : FadeOutMs);
			FadeInNext = crossfade;
		}
	}
}


/// <summary>
/// Starts the specified song playing now, cutting off any song already playing.
/// </summary>
/// <param name="theme">The song to play. THEME_PICK_ANOTHER, or any song while the music
/// volume is zero, waits for the next pick instead.</param>
/// <returns>Returns with the handle of the song started, or a null handle.</returns>
AudioHandle ThemeClass::Play_Song(ThemeType theme)
{
	if (ScoresPresent && AudioEngine.Is_Available() && !Debug_Quiet) {
		Stop(false);
		if (theme != THEME_NONE && theme != THEME_QUIET) {
			if (theme > THEME_NONE && Volume > 0) {
				Start(theme, false);
			} else {
				Pending = theme;
			}
		}
	}
	return(Current);
}


/// <summary>
/// Opens the stream for a song and makes it the current one.
/// </summary>
/// <param name="theme">The song to start.</param>
/// <param name="fadein">Should the song rise from silence over the crossfade time?</param>
/// <returns>bool; Did the song start?</returns>
bool ThemeClass::Start(ThemeType theme, bool fadein)
{
	FadeInNext = false;
	if ((unsigned)theme >= (unsigned)Themes.Count()) {
		return(false);
	}

	ThemeControl & control = *Themes[theme];
	float level = Level(theme);
	Current = AudioEngine.Open_Stream(Theme_File_Name(theme), AUDIO_GROUP_MUSIC, fadein ? 0.0f : level, Loops(theme));

	/*
	 * Stopping a score that never started does nothing, so recording one that
	 * failed to start as the current score would silence the game for good.
	 */
	if (Current.Is_Null()) {
		if (!control.StartFailed) {
			DebugString("Theme::PlaySong(%d) - Unavailable\n", theme);
			control.StartFailed = true;
		}
		Score = THEME_NONE;
		Pending = THEME_NONE;
		LastEnded = theme;
		RetryAt = AudioEngine.Now_Ms() + RETRY_MS;
		return(false);
	}
	if (fadein) {
		Current.Set_Volume(level, CrossFadeMs);
	}

	control.StartFailed = false;
	Score = theme;
	DebugString("Theme::PlaySong(%d) - %s\n", Score, Loops(theme) ? "Repeating" : "Playing");
	return(true);
}


/// <summary>
/// Does the song start over at its end, by its own Repeat= or the repeat option?
/// </summary>
bool ThemeClass::Loops(ThemeType theme) const
{
	if ((unsigned)theme >= (unsigned)Themes.Count()) return(false);
	return(IsRepeat || Themes[theme]->Repeat || (Interrupt.Active && theme == Interrupt.Theme));
}


/// <summary>
/// Turns the repeat option on or off. The song playing now follows the new setting.
/// </summary>
/// <remarks>In about the last five seconds of a song, turning repeat on lets it restart after
/// a short gap, and turning it off lets it play once more.</remarks>
void ThemeClass::Set_Repeat(bool on)
{
	IsRepeat = on;
	if (!Current.Is_Finished()) {
		AudioEngine.Set_Stream_Loop(Current, Loops(Score));
	}
	if (Interrupt.Active && !Interrupt.Handle.Is_Finished()) {
		AudioEngine.Set_Stream_Loop(Interrupt.Handle, Loops(Interrupt.Score));
	}
}


/// <summary>
/// Fades the current song out over the time given, cutting short any older fade.
/// </summary>
void ThemeClass::Retire(int ms)
{
	if (!Fading.Is_Finished()) {
		Fading.Cut(FADE_CUT_MS);
	}
	Fading = Current;
	Current.Fade(ms);
	Current.Clear();
}


/// <summary>
/// Fetches the file Scan found for the specified theme, extension included.
/// </summary>
/// <returns>Returns with the file name, or an empty string for an invalid theme or one
/// whose file was not found.</returns>
char const * ThemeClass::Theme_File_Name(ThemeType theme)
{
	if ((unsigned)theme < (unsigned)Themes.Count()) {
		return(Themes[theme]->File);
	}

	return("");
}


/***********************************************************************************************
 * ThemeClass::Track_Length -- Calculates the length of the song (in seconds).                 *
 *                                                                                             *
 *    Use this routine to calculate the length of the song. The length is determined by        *
 *    reading the header of the song and dividing the sample rate into the sample length.      *
 *                                                                                             *
 * INPUT:   theme -- The song number to examine to find its length.                            *
 *                                                                                             *
 * OUTPUT:  Returns with the length of the specified theme. This length is in the form of      *
 *          seconds.                                                                           *
 *                                                                                             *
 * WARNINGS:   This routine goes to disk to fetch this information. Don't call frivolously.    *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   01/16/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
int ThemeClass::Track_Length(ThemeType theme) const
{
	if ((unsigned)theme < (unsigned)Themes.Count()) {
		return(Themes[theme]->Duration * 60);
	}
	return(0);
}


/// <summary>
/// Stops the current song. No more music plays until a song is started or queued.
/// </summary>
/// <param name="fade">Should the song fade out over the fade out time rather than stop at
/// once? A song already fading out finishes either way.</param>
/// <remarks>Also drops a song Begin_Interruption set aside.</remarks>
void ThemeClass::Stop(bool fade)
{
	if (ScoresPresent && AudioEngine.Is_Available() && !Debug_Quiet) {
		Discard_Interruption();
		IsPaused = false;
		if (!Current.Is_Finished()) {
			if (fade) {
				DebugString("Theme::Stop(%d) - Fading\n", Score);
				Retire(FadeOutMs);
			} else {
				DebugString("Theme::Stop(%d)\n", Score);
				Current.Stop();
			}
		}
		Current.Clear();
		Score = THEME_NONE;
		Pending = THEME_NONE;
		LastEnded = THEME_NONE;
		RetryAt = AudioEngine.Now_Ms();
		FadeInNext = false;
	}
}


/// <summary>
/// Pauses the current song in place, as for a movie played over it.
/// </summary>
/// <remarks>Cuts short a song still fading out. No song starts until Resume or Stop.</remarks>
void ThemeClass::Pause(void)
{
	if (!Fading.Is_Finished()) {
		Fading.Cut(FADE_CUT_MS);
	}
	if (!IsPaused && !Current.Is_Finished()) {
		DebugString("Theme::Pause(%d)\n", Score);
		Current.Pause(PAUSE_FADE_MS);
		IsPaused = true;
	}
}


/// <summary>
/// Resumes a song paused by Pause from the point it reached.
/// </summary>
void ThemeClass::Resume(void)
{
	if (IsPaused) {
		IsPaused = false;
		if (!Current.Is_Finished()) {
			DebugString("Theme::Resume(%d)\n", Score);
			Current.Resume(PAUSE_FADE_MS);
		}
	}
}


/// <summary>
/// Pauses the current song and plays the specified one looping in its place, as an ion
/// storm does.
/// </summary>
/// <param name="theme">The song to play for the interruption.</param>
/// <remarks>Does nothing while the music is off or silent, or when the song is not
/// available.</remarks>
void ThemeClass::Begin_Interruption(ThemeType theme)
{
	if (!ScoresPresent || !AudioEngine.Is_Available() || Debug_Quiet || Volume <= 0) return;
	if ((unsigned)theme >= (unsigned)Themes.Count() || !Themes[theme]->Available) return;

	// An earlier interruption ends first, so its paused song is the one set aside.
	End_Interruption();
	Resume();

	int ms = CrossFadeMs > 0 ? CrossFadeMs : PAUSE_FADE_MS;
	Interrupt.Handle = Current.Is_Finished() ? AudioHandle() : Current;
	Interrupt.Score = Score;
	Interrupt.Pending = Pending;
	Interrupt.LastEnded = LastEnded;
	Interrupt.FadeInNext = FadeInNext;
	if (!Interrupt.Handle.Is_Null()) {
		Interrupt.Handle.Pause(ms);
	}
	DebugString("Theme::BeginInterruption(%d) - Setting %d aside\n", theme, Score);

	Current.Clear();
	Score = THEME_NONE;
	Pending = THEME_NONE;
	Interrupt.Theme = theme;
	Interrupt.Active = true;
	Interrupt.Intact = true;
	if (!Start(theme, CrossFadeMs > 0)) {
		End_Interruption();
	}
}


/// <summary>
/// Ends an interruption: the song set aside resumes where it paused. If the music was
/// changed meanwhile, the song playing now continues and the set aside one is dropped.
/// </summary>
void ThemeClass::End_Interruption(void)
{
	if (!Interrupt.Active) return;
	Interrupt.Active = false;

	if (!Interrupt.Intact) {
		DebugString("Theme::EndInterruption - Keeping %d\n", Score);
		if (!Interrupt.Handle.Is_Finished()) {
			Interrupt.Handle.Stop();
		}
		Interrupt.Handle.Clear();
		return;
	}

	int ms = CrossFadeMs > 0 ? CrossFadeMs : PAUSE_FADE_MS;
	if (!Current.Is_Finished()) {
		Retire(ms);
	}
	Current.Clear();
	Score = Interrupt.Score;
	Pending = Interrupt.Pending;
	LastEnded = Interrupt.LastEnded;
	FadeInNext = Interrupt.FadeInNext;
	DebugString("Theme::EndInterruption - Resuming %d\n", Score);

	if (!Interrupt.Handle.Is_Finished()) {
		Current = Interrupt.Handle;
		if ((unsigned)Score < (unsigned)Themes.Count()) {
			Current.Set_Volume(Level(Score), 0);
			AudioEngine.Set_Stream_Loop(Current, Loops(Score));
		}
		Current.Resume(ms);
	} else if (Score != THEME_NONE && Pending == THEME_NONE) {
		// A set aside song that is gone counts as one that played to its end.
		LastEnded = Score;
		Score = THEME_NONE;
	}
	Interrupt.Handle.Clear();
}


/// <summary>
/// Drops the song set aside by an interruption, if any, without playing it again.
/// </summary>
void ThemeClass::Discard_Interruption(void)
{
	if (Interrupt.Active) {
		if (!Interrupt.Handle.Is_Finished()) {
			Interrupt.Handle.Stop();
		}
		Interrupt.Handle.Clear();
		Interrupt.Active = false;
	}
}


/// <summary>
/// Scales every song's volume by IonStormVolume= while a storm plays its storm sound, or by 1.
/// </summary>
/// <param name="storm">Is the storm sound playing?</param>
/// <param name="instant">Should the song playing now change at once rather than over the
/// fade out time?</param>
void ThemeClass::Set_Storm_Level(bool storm, bool instant)
{
	StormLevel = storm ? IonStormLevel : 1.0f;
	if (!Current.Is_Finished() && (unsigned)Score < (unsigned)Themes.Count()) {
		Current.Set_Volume(Level(Score), instant ? 0 : FadeOutMs);
	}
}


/// <summary>
/// The volume the specified song plays at: its own Volume= under any ion storm lowering.
/// </summary>
float ThemeClass::Level(ThemeType theme) const
{
	return(Themes[theme]->Volume * StormLevel);
}


/// <summary>
/// Is music still audible? A song fading out counts until it is silent.
/// </summary>
bool ThemeClass::Still_Playing(void) const
{
	if (ScoresPresent && AudioEngine.Is_Available() && Volume > 0 && !Debug_Quiet) {
		return(!Current.Is_Finished() || !Fading.Is_Finished());
	}
	return(false);
}


/***********************************************************************************************
 * ThemeClass::Is_Allowed -- Checks to see if the specified theme is legal.                    *
 *                                                                                             *
 *    Use this routine to determine if a theme is allowed to be played. A theme is not allowed *
 *    if the scenario is too early for that score, or the score only is allowed in special     *
 *    cases.                                                                                   *
 *                                                                                             *
 * INPUT:   index -- The score the check to see if it is allowed to play.                      *
 *                                                                                             *
 * OUTPUT:  Is the specified score allowed to play in the normal score playlist?               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/09/1995 JLB : Created.                                                                 *
 *   07/04/1996 JLB : Handles alternate playlist checking.                                     *
 *=============================================================================================*/
bool ThemeClass::Is_Allowed(ThemeType index) const
{
	if (index == THEME_QUIET || index == THEME_PICK_ANOTHER) return(true);

	if ((unsigned)index >= (unsigned)Themes.Count()) return(false);

	/*
	**	If the theme is not present, then it certainly isn't allowed.
	*/
	if (!Themes[index]->Available) return(false);

	/*
	**	Only normal themes (playable during battle) are considered allowed.
	*/
	if (!Themes[index]->Normal) return(false);

	/*
	**	If the theme is not allowed to be played by the player's house, then don't allow
	**	it. If the player's house hasn't yet been determined, then presume this test
	**	passes.
	*/
	if (PlayerPtr != NULL && !Themes[index]->Allows_Side(PlayerPtr->Class->Side)) return(false);

	// An expansion requirement holds only while that expansion runs; one naming none never does.
	int addon = Themes[index]->RequiredAddon;
	if (addon != ADDON_BASE_GAME && (addon < ADDON_ANY || addon >= ADDON_COUNT || !Addon_Enabled((AddonType)addon))) return(false);

	/*
	**	If the scenario doesn't allow this theme yet, then return the failure flag. The
	**	scenario check only makes sense for solo play.
	*/
	if (Session.Type == GAME_NORMAL && Scen->Scenario < Themes[index]->Scenario) return(false);

	/*
	**	Since all tests passed, return with the "is allowed" flag.
	*/
	return(true);
}


/***********************************************************************************************
 * ThemeClass::From_Name -- Determines theme number from specified name.                       *
 *                                                                                             *
 *    Use this routine to convert a name (either the base filename of the theme, or a partial  *
 *    substring of the full name) into the matching ThemeType value. Typical use of this is    *
 *    when parsing the INI file for theme control values.                                      *
 *                                                                                             *
 * INPUT:   name  -- Pointer to base filename of theme or a partial substring of the full      *
 *                   theme name.                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the matching theme number. If no match could be found, then           *
 *          THEME_NONE is returned.                                                            *
 *                                                                                             *
 * WARNINGS:   If a filename is specified the comparison is case insensitive. When scanning    *
 *             the full theme name, the comparison is case sensitive.                          *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   05/29/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
ThemeType ThemeClass::From_Name(char const * name) const
{
	if (name && strlen(name) > 0) {
		/*
		**	First search for an exact name match with the filename
		**	of the theme. This is guaranteed to be unique.
		*/
		ThemeType theme;
		for (theme = THEME_FIRST; theme < Themes.Count(); theme = ThemeType(theme + 1)) {
			if (stricmp(Themes[theme]->Name, name) == 0) {
				return(theme);
			}
		}

		/*
		**	If the filename scan failed to find a match, then scan for
		**	a substring within the full name of the score. This might
		**	yield a match, but is not guaranteed to be unique.
		*/
		for (theme = THEME_FIRST; theme < Themes.Count(); theme = ThemeType(theme + 1)) {
			if (strstr(Themes[theme]->Fullname, name) != NULL) {
				return(theme);
			}
		}
	}

	return(THEME_NONE);
}


/// <summary>
/// Sets the volume that the music is played at.
/// This routine is used by the options screen. Any score that happens to be playing has
/// its volume adjusted right away rather than waiting for the next track to start.
/// </summary>
/// <param name="volume">The volume to play the music at. Anything louder than maximum
/// volume is quietly clipped.</param>
void ThemeClass::Set_Volume(int volume)
{
	Volume = std::min(volume, 255);

	AudioEngine.Set_Group_Gain(AUDIO_GROUP_MUSIC, (float)std::max(Volume, 0) / 255.0f);
}
