/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Pins the keys the SDL layer reports held, by the Windows codes the game reads, as SDL's key
// events and Windows' own key state change.

#include "sdl/sdlinput.h"

#include "win.h"
#include "windowevent.hh"

#include "doctest/doctest.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>

#include <initializer_list>

namespace {

Uint64 Clock = 0;


SDL_KeyboardEvent Key(bool down, SDL_Scancode scancode, SDL_Keycode keycode, SDL_Keymod modifiers = SDL_KMOD_NONE)
{
	SDL_KeyboardEvent key = {};
	key.type = down ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
	key.timestamp = ++Clock;
	key.scancode = scancode;
	key.key = keycode;
	key.mod = modifiers;
	key.down = down;
	return(key);
}


// Queues and then handles a key, as the SDL layer does.
void Press(SDLInputStateClass & input, SDL_KeyboardEvent const & key)
{
	input.Note_Queued_Key(key);
	input.Track_Key(key);
}


void Windows_Holds(std::initializer_list<int> keys)
{
	BYTE state[256] = {};
	for (int key : keys) {
		state[key] = 0x80;
	}
	SetKeyboardState(state);
}


// Windows' key state and SDL's lock state belong to the process, so each case starts with
// nothing held and no lock on.
struct Fixture
{
	SDLInputStateClass input;

	Fixture(void)
	{
		Windows_Holds({});
		SDL_SetModState(SDL_KMOD_NONE);
	}
};

}


TEST_CASE_FIXTURE(Fixture, "a Shift press holds Shift and the side it was pressed on, and its release lets both go")
{
	Press(input, Key(true, SDL_SCANCODE_LSHIFT, SDLK_LSHIFT, SDL_KMOD_LSHIFT));
	CHECK(input.Key_Down(VK_SHIFT));
	CHECK(input.Key_Down(VK_LSHIFT));
	CHECK_FALSE(input.Key_Down(VK_RSHIFT));
	CHECK(input.Modifiers() == WINDOW_MOD_SHIFT);

	Press(input, Key(false, SDL_SCANCODE_LSHIFT, SDLK_LSHIFT));
	CHECK_FALSE(input.Key_Down(VK_SHIFT));
	CHECK_FALSE(input.Key_Down(VK_LSHIFT));
	CHECK(input.Modifiers() == 0);
}


// Windows shows the Left Ctrl it presses for AltGr only while the Right Alt press is queued.
TEST_CASE_FIXTURE(Fixture, "a Right Alt queued while Windows shows Left Ctrl is AltGr, and Ctrl is released with it")
{
	SDL_KeyboardEvent altgr = Key(true, SDL_SCANCODE_RALT, SDLK_RALT, SDL_KMOD_RALT);
	Windows_Holds({ VK_CONTROL, VK_LCONTROL });
	input.Note_Queued_Key(altgr);
	Windows_Holds({});
	input.Track_Key(altgr);
	CHECK(input.Key_Down(VK_CONTROL));
	CHECK(input.Key_Down(VK_LCONTROL));
	CHECK(input.Modifiers() == (WINDOW_MOD_CTRL | WINDOW_MOD_ALT));

	Press(input, Key(false, SDL_SCANCODE_RALT, SDLK_RALT));
	CHECK_FALSE(input.Key_Down(VK_CONTROL));
	CHECK(input.Modifiers() == 0);
}


TEST_CASE_FIXTURE(Fixture, "a Right Alt queued without Windows showing Left Ctrl is Alt alone")
{
	Press(input, Key(true, SDL_SCANCODE_RALT, SDLK_RALT, SDL_KMOD_RALT));
	CHECK_FALSE(input.Key_Down(VK_CONTROL));
	CHECK(input.Key_Down(VK_RMENU));
	CHECK(input.Modifiers() == WINDOW_MOD_ALT);
}


TEST_CASE_FIXTURE(Fixture, "the lock keys are read again whenever the window regains the focus")
{
	SDL_SetModState(SDL_KMOD_CAPS);
	input.Focus_Gained();
	CHECK(input.Key_Toggled(VK_CAPITAL));
	CHECK((input.Modifiers() & WINDOW_MOD_CAPS) != 0);

	SDL_SetModState(SDL_KMOD_NONE);
	input.Focus_Gained();
	CHECK_MESSAGE(!input.Key_Toggled(VK_CAPITAL), "a lock that went off is read off");
}


// SDL reports no key still held after it resets the keyboard, and drops such a key's release.
TEST_CASE_FIXTURE(Fixture, "a Shift Windows holds as the window gains the focus is held until Windows releases it")
{
	Windows_Holds({ VK_SHIFT, VK_LSHIFT });
	input.Focus_Gained();
	CHECK(input.Key_Down(VK_SHIFT));
	CHECK(input.Key_Down(VK_LSHIFT));
	CHECK_FALSE(input.Key_Down(VK_RSHIFT));
	CHECK(input.Modifiers() == WINDOW_MOD_SHIFT);

	Windows_Holds({});
	input.Drop_Released_Keys();
	CHECK_MESSAGE(input.Modifiers() == 0, "it is released for the next event once Windows releases it");

	Windows_Holds({ VK_SHIFT, VK_LSHIFT });
	input.Focus_Gained();
	Windows_Holds({});
	CHECK_MESSAGE(!input.Key_Down(VK_SHIFT), "it is read released at once, with no event");
}


TEST_CASE_FIXTURE(Fixture, "losing the focus releases a key held into the window")
{
	Windows_Holds({ VK_SHIFT, VK_LSHIFT });
	input.Focus_Gained();
	input.Focus_Lost();
	CHECK_FALSE(input.Key_Down(VK_SHIFT));
}


TEST_CASE_FIXTURE(Fixture, "once SDL reports a key held into the window, only SDL's release lets it go")
{
	Windows_Holds({ VK_SHIFT, VK_LSHIFT });
	input.Focus_Gained();
	Press(input, Key(true, SDL_SCANCODE_LSHIFT, SDLK_LSHIFT, SDL_KMOD_LSHIFT));
	Windows_Holds({});
	CHECK_MESSAGE(input.Key_Down(VK_SHIFT), "Windows no longer releases it");

	Press(input, Key(false, SDL_SCANCODE_LSHIFT, SDLK_LSHIFT));
	CHECK_MESSAGE(!input.Key_Down(VK_SHIFT), "SDL's release does");
}


TEST_CASE_FIXTURE(Fixture, "a modifier Windows holds after a window drag is held")
{
	Windows_Holds({ VK_MENU, VK_RMENU });
	input.Hold_Windows_Keys();
	CHECK(input.Key_Down(VK_MENU));
	CHECK(input.Key_Down(VK_RMENU));
	CHECK_FALSE(input.Key_Down(VK_LMENU));
}


TEST_CASE_FIXTURE(Fixture, "a Right Alt pressed with a Left Ctrl held into the window is not AltGr")
{
	Windows_Holds({ VK_CONTROL, VK_LCONTROL });
	input.Focus_Gained();
	SDL_KeyboardEvent ralt = Key(true, SDL_SCANCODE_RALT, SDLK_RALT, SDL_KMOD_RALT);
	input.Note_Queued_Key(ralt);
	Windows_Holds({});
	input.Drop_Released_Keys();
	input.Track_Key(ralt);
	CHECK_FALSE(input.Key_Down(VK_CONTROL));
	CHECK(input.Modifiers() == WINDOW_MOD_ALT);
}


TEST_CASE_FIXTURE(Fixture, "any key Windows holds as the window gains the focus is held, and SDL takes it over")
{
	Windows_Holds({ 'A' });
	input.Focus_Gained();
	CHECK(input.Key_Down('A'));
	CHECK(input.Modifiers() == 0);
	Windows_Holds({});
	CHECK_MESSAGE(!input.Key_Down('A'), "it is released when Windows releases it");

	Windows_Holds({ 'A' });
	input.Focus_Gained();
	SDL_KeyboardEvent a = Key(true, SDL_SCANCODE_A, SDLK_A);
	input.Note_Queued_Key(a);
	CHECK_MESSAGE(input.Track_Key(a), "its first press from SDL continues the key held into the window");
	Windows_Holds({});
	CHECK_MESSAGE(input.Key_Down('A'), "from then on SDL reports it");
	a = Key(false, SDL_SCANCODE_A, SDLK_A);
	Press(input, a);
	CHECK_MESSAGE(!input.Key_Down('A'), "including its release");

	SDL_KeyboardEvent b = Key(true, SDL_SCANCODE_B, SDLK_B);
	input.Note_Queued_Key(b);
	CHECK_MESSAGE(!input.Track_Key(b), "a key pressed after the window gains the focus is a new press");
}


TEST_CASE_FIXTURE(Fixture, "releasing one Shift held into the window leaves the other held")
{
	Windows_Holds({ VK_SHIFT, VK_LSHIFT, VK_RSHIFT });
	input.Focus_Gained();
	Press(input, Key(true, SDL_SCANCODE_LSHIFT, SDLK_LSHIFT, SDL_KMOD_LSHIFT));
	Press(input, Key(false, SDL_SCANCODE_LSHIFT, SDLK_LSHIFT));
	CHECK(input.Key_Down(VK_SHIFT));
	CHECK(input.Key_Down(VK_RSHIFT));
	CHECK_FALSE(input.Key_Down(VK_LSHIFT));
}
