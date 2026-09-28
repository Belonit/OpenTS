/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

#include "coord.h"

#include "audio/audiohandle.h"


class SaveStreamClass;
#include "win.h"

class ShapeSet;

class IonStormClass
{
	public:
		static void Init(void);
		static bool Save(SaveStreamClass & stream);
		static bool Load(SaveStreamClass & stream);

		static void Serialize(SaveStreamClass & stream);

		static void Do_Screen_Static(int shapenum);
		static void Lightning_Bolt(Cell cell);
		static void Set_Ion_Storm_Active(bool active);
		static bool Is_Ion_Storm_Active(void);
		static void Ion_Storm_Begin(int duration, int warning=0);
		static void Ion_Storm_End(void);
		static void AI(void);
		static void Apply_Secondary_Effect(bool do_static);

		// Ends the storm sound and restores the music's level at once, for a mission
		// ending mid-storm. Leaves a storm track and the storm running.
		static void Stop_Audio(void);

		// Starts the audio of a storm in progress again, for music stopped after a load.
		static void Restart_Audio(void);

	private:
		static void Start_Audio(bool instant);
		static void End_Audio(void);

		/*
		 * If an ion storm is raging over the battlefield, then this flag will be true.
		 * While it is set, ion sensitive locomotors have no power and the world wears
		 * the ion tint.
		 */
		static bool IsActive;

		/*
		 * This is the game frame that the current storm broke on. Together with the
		 * duration it decides when the storm has blown itself out.
		 */
		static int StartFrame;

		/*
		 * This is how long the storm is to last, expressed in game frames. A storm that
		 * is still waiting to break carries its duration here as well, so that the
		 * deferment can hand it over when the wait is up. If -1, the storm never expires.
		 */
		static int Duration;

		/*
		 * This is the number of game frames still to wait before a scheduled storm
		 * breaks, counted down once per frame. The player is warned every fifteen seconds
		 * as it runs out. Zero means that no storm is pending.
		 */
		static int Deferment;

		/*
		 * This points to the screen static shapes that are tiled over the tactical view
		 * while the palettes are being tinted. They are fetched the first time they are
		 * needed and kept for the rest of the session.
		 */
		static ShapeSet const * StaticShape;

		/*
		 * This is the storm sound playing in place of the storm's music track, when
		 * SOUND.INI lists an IONSTORM sound. It is not saved; a loaded game starts it again.
		 */
		static AudioHandle StormSound;
		static bool UsesStormSound;
};
