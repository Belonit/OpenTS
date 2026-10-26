/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Pins how SDL events become the window events the game reads.

#include "sdl/sdlevents.h"

#include "win.h"

#include "doctest/doctest.h"

#include <SDL3/SDL_events.h>

#include <cstring>
#include <vector>

namespace {

SDL_Event Event_Of(Uint32 type)
{
	SDL_Event event;
	std::memset(&event, 0, sizeof(event));
	event.type = type;
	return(event);
}


std::vector<WindowEvent> Translate(SDL_Event const & event, float pixeldensity = 1.0f, int modifiers = 0)
{
	std::vector<WindowEvent> events;
	Window_Events_From_SDL(event, pixeldensity, modifiers, events);
	return(events);
}


// Translates an event that must produce exactly one window event of the given type.
WindowEvent Translate_One(SDL_Event const & event, WindowEventType type, float pixeldensity = 1.0f, int modifiers = 0)
{
	std::vector<WindowEvent> events = Translate(event, pixeldensity, modifiers);
	REQUIRE(events.size() == 1);
	REQUIRE(events[0].Type == type);
	return(events[0]);
}


SDL_Event Motion(float x, float y)
{
	SDL_Event event = Event_Of(SDL_EVENT_MOUSE_MOTION);
	event.motion.x = x;
	event.motion.y = y;
	return(event);
}


SDL_Event Button(bool down, Uint8 button, Uint8 clicks, float x, float y)
{
	SDL_Event event = Event_Of(down ? SDL_EVENT_MOUSE_BUTTON_DOWN : SDL_EVENT_MOUSE_BUTTON_UP);
	event.button.down = down;
	event.button.button = button;
	event.button.clicks = clicks;
	event.button.x = x;
	event.button.y = y;
	return(event);
}


SDL_Event Wheel(float x, float y, SDL_MouseWheelDirection direction = SDL_MOUSEWHEEL_NORMAL)
{
	SDL_Event event = Event_Of(SDL_EVENT_MOUSE_WHEEL);
	event.wheel.x = x;
	event.wheel.y = y;
	event.wheel.direction = direction;
	event.wheel.mouse_x = 30.0f;
	event.wheel.mouse_y = 40.0f;
	return(event);
}


SDL_Event Key(bool down, SDL_Scancode scancode, SDL_Keycode keycode, SDL_Keymod modifiers, bool repeat = false)
{
	SDL_Event event = Event_Of(down ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP);
	event.key.down = down;
	event.key.scancode = scancode;
	event.key.key = keycode;
	event.key.mod = modifiers;
	event.key.repeat = repeat;
	return(event);
}


SDL_Event Resize(int width, int height)
{
	SDL_Event event = Event_Of(SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED);
	event.window.data1 = width;
	event.window.data2 = height;
	return(event);
}

}


TEST_CASE("a mouse move lands on the pixel it is over")
{
	WindowEvent move = Translate_One(Motion(12.75f, 34.0f), WINDOW_EVENT_MOUSE_MOVE);
	CHECK(move.X == 12);
	CHECK(move.Y == 34);
}


TEST_CASE("a window with a pixel density of two doubles the position")
{
	WindowEvent move = Translate_One(Motion(12.75f, 34.0f), WINDOW_EVENT_MOUSE_MOVE, 2.0f);
	CHECK(move.X == 25);
	CHECK(move.Y == 68);
}


TEST_CASE("a position left of the client area stays outside it")
{
	CHECK(Translate_One(Motion(-0.5f, 34.0f), WINDOW_EVENT_MOUSE_MOVE).X == -1);
}


TEST_CASE("a left press is a single click where it happened")
{
	WindowEvent press = Translate_One(Button(true, SDL_BUTTON_LEFT, 1, 5.0f, 6.0f), WINDOW_EVENT_MOUSE_DOWN);
	CHECK(press.Button == WINDOW_BUTTON_LEFT);
	CHECK(press.Clicks == 1);
	CHECK(press.X == 5);
	CHECK(press.Y == 6);
}


TEST_CASE("a press carries the modifiers held")
{
	WindowEvent press = Translate_One(Button(true, SDL_BUTTON_LEFT, 1, 5.0f, 6.0f), WINDOW_EVENT_MOUSE_DOWN, 1.0f, WINDOW_MOD_SHIFT);
	CHECK(press.Modifiers == WINDOW_MOD_SHIFT);
}


TEST_CASE("a run of clicks alternates single and double clicks, as Windows counts them")
{
	WindowEvent second = Translate_One(Button(true, SDL_BUTTON_RIGHT, 2, 0.0f, 0.0f), WINDOW_EVENT_MOUSE_DOWN);
	CHECK(second.Button == WINDOW_BUTTON_RIGHT);
	CHECK_MESSAGE(second.Clicks == 2, "the second press is a double click");

	WindowEvent third = Translate_One(Button(true, SDL_BUTTON_MIDDLE, 3, 0.0f, 0.0f), WINDOW_EVENT_MOUSE_DOWN);
	CHECK_MESSAGE(third.Clicks == 1, "the third press starts over");

	WindowEvent fourth = Translate_One(Button(true, SDL_BUTTON_X2, 4, 0.0f, 0.0f), WINDOW_EVENT_MOUSE_DOWN);
	CHECK_MESSAGE(fourth.Button == WINDOW_BUTTON_X2, "the second extra button counts the same way");
	CHECK_MESSAGE(fourth.Clicks == 2, "the fourth press is double again");
}


TEST_CASE("a release is never a double click")
{
	CHECK(Translate_One(Button(false, SDL_BUTTON_LEFT, 2, 0.0f, 0.0f), WINDOW_EVENT_MOUSE_UP).Clicks == 1);
}


TEST_CASE("a button beyond the fifth is dropped")
{
	CHECK(Translate(Button(true, 9, 1, 0.0f, 0.0f)).empty());
}


TEST_CASE("two notches toward the player are -2 on the vertical wheel, where the mouse is")
{
	WindowEvent turn = Translate_One(Wheel(0.0f, -2.0f), WINDOW_EVENT_MOUSE_WHEEL);
	CHECK(turn.Wheel == -2.0f);
	CHECK_FALSE(turn.Horizontal);
	CHECK(turn.X == 30);
	CHECK(turn.Y == 40);
}


TEST_CASE("a flipped wheel is turned back the way the hand moved")
{
	CHECK(Translate_One(Wheel(0.0f, -2.0f, SDL_MOUSEWHEEL_FLIPPED), WINDOW_EVENT_MOUSE_WHEEL).Wheel == 2.0f);
}


TEST_CASE("a diagonal turn is a vertical turn and then a horizontal one")
{
	std::vector<WindowEvent> events = Translate(Wheel(1.0f, 0.5f));
	REQUIRE(events.size() == 2);
	CHECK_FALSE(events[0].Horizontal);
	CHECK(events[0].Wheel == 0.5f);
	CHECK(events[1].Horizontal);
	CHECK(events[1].Wheel == 1.0f);
}


TEST_CASE("a key press carries its virtual key and the modifiers held, and is neither a repeat nor a system key")
{
	WindowEvent press = Translate_One(Key(true, SDL_SCANCODE_A, SDLK_A, (SDL_Keymod)(SDL_KMOD_LSHIFT | SDL_KMOD_RCTRL)), WINDOW_EVENT_KEY_DOWN, 1.0f, WINDOW_MOD_SHIFT | WINDOW_MOD_CTRL);
	CHECK(press.VirtualKey == 'A');
	CHECK(press.Modifiers == (WINDOW_MOD_SHIFT | WINDOW_MOD_CTRL));
	CHECK_FALSE(press.Repeat);
	CHECK_FALSE(press.System);
}


TEST_CASE("a held key's repeat is marked as one")
{
	CHECK(Translate_One(Key(true, SDL_SCANCODE_A, SDLK_A, SDL_KMOD_NONE, true), WINDOW_EVENT_KEY_DOWN).Repeat);
}


TEST_CASE("a release is never a repeat")
{
	CHECK_FALSE(Translate_One(Key(false, SDL_SCANCODE_A, SDLK_A, SDL_KMOD_NONE, true), WINDOW_EVENT_KEY_UP).Repeat);
}


TEST_CASE("a key pressed with Alt held is a system key")
{
	WindowEvent press = Translate_One(Key(true, SDL_SCANCODE_F4, SDLK_F4, SDL_KMOD_LALT), WINDOW_EVENT_KEY_DOWN, 1.0f, WINDOW_MOD_ALT);
	CHECK(press.System);
	CHECK(press.Modifiers == WINDOW_MOD_ALT);
}


TEST_CASE("F10 is a system key on its own")
{
	CHECK(Translate_One(Key(true, SDL_SCANCODE_F10, SDLK_F10, SDL_KMOD_NONE), WINDOW_EVENT_KEY_DOWN).System);
}


TEST_CASE("a key pressed with Ctrl and Alt held is not a system key")
{
	CHECK_FALSE(Translate_One(Key(true, SDL_SCANCODE_Q, SDLK_Q, (SDL_Keymod)(SDL_KMOD_LALT | SDL_KMOD_LCTRL)), WINDOW_EVENT_KEY_DOWN, 1.0f, WINDOW_MOD_CTRL | WINDOW_MOD_ALT).System);
}


TEST_CASE("a key Windows has no code for is dropped")
{
	CHECK(Translate(Key(true, SDL_SCANCODE_LANG1, SDLK_UNKNOWN, SDL_KMOD_NONE)).empty());
}


TEST_CASE("typed text arrives one character at a time")
{
	SDL_Event text = Event_Of(SDL_EVENT_TEXT_INPUT);
	text.text.text = "a\xD0\x9F\xF0\x9F\x98\x80";
	std::vector<WindowEvent> events = Translate(text);
	REQUIRE(events.size() == 3);
	CHECK(events[0].Type == WINDOW_EVENT_TEXT);
	CHECK(events[0].Text == 'a');
	CHECK(events[1].Text == 0x041F);
	CHECK(events[2].Text == 0x1F600);
}


TEST_CASE("empty text is no character")
{
	SDL_Event text = Event_Of(SDL_EVENT_TEXT_INPUT);
	text.text.text = "";
	CHECK(Translate(text).empty());
}


TEST_CASE("losing the focus loses the capture first")
{
	std::vector<WindowEvent> events = Translate(Event_Of(SDL_EVENT_WINDOW_FOCUS_LOST));
	REQUIRE(events.size() == 2);
	CHECK(events[0].Type == WINDOW_EVENT_CAPTURE_LOST);
	CHECK(events[1].Type == WINDOW_EVENT_FOCUS_LOST);
}


TEST_CASE("gaining the focus is a gain of focus")
{
	Translate_One(Event_Of(SDL_EVENT_WINDOW_FOCUS_GAINED), WINDOW_EVENT_FOCUS_GAINED);
}


TEST_CASE("a new pixel size is a resize to that size")
{
	WindowEvent resize = Translate_One(Resize(800, 600), WINDOW_EVENT_RESIZED);
	CHECK(resize.Width == 800);
	CHECK(resize.Height == 600);
}


TEST_CASE("a size with no area is not a resize")
{
	CHECK(Translate(Resize(800, 0)).empty());
}


TEST_CASE("a size in window coordinates is left to the pixel size")
{
	CHECK(Translate(Event_Of(SDL_EVENT_WINDOW_RESIZED)).empty());
}


TEST_CASE("window and display changes become their window events")
{
	SUBCASE("an exposed window is exposed")
	{
		Translate_One(Event_Of(SDL_EVENT_WINDOW_EXPOSED), WINDOW_EVENT_EXPOSED);
	}
	SUBCASE("a window moving to another display changes the display")
	{
		Translate_One(Event_Of(SDL_EVENT_WINDOW_DISPLAY_CHANGED), WINDOW_EVENT_DISPLAY_CHANGED);
	}
	SUBCASE("a display changing mode changes the display")
	{
		Translate_One(Event_Of(SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED), WINDOW_EVENT_DISPLAY_CHANGED);
	}
	SUBCASE("the close button asks to close")
	{
		Translate_One(Event_Of(SDL_EVENT_WINDOW_CLOSE_REQUESTED), WINDOW_EVENT_CLOSE_REQUESTED);
	}
	SUBCASE("a request to quit asks to close")
	{
		Translate_One(Event_Of(SDL_EVENT_QUIT), WINDOW_EVENT_CLOSE_REQUESTED);
	}
}


TEST_CASE("an event the game does not use produces nothing")
{
	CHECK(Translate(Event_Of(SDL_EVENT_WINDOW_MOUSE_ENTER)).empty());
}
