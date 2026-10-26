/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Pins the virtual-key code each SDL key becomes, since saved hotkeys store those codes, and
// the names the keyboard screen shows for them.

#include "sdl/sdlkeys.h"

#include "win.h"

#include "doctest/doctest.h"

#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_scancode.h>

namespace {

int Key(SDL_Scancode scancode, SDL_Keycode keycode, SDL_Keymod modifiers = SDL_KMOD_NONE)
{
	return(Virtual_Key_From_SDL(scancode, keycode, modifiers));
}


// A key whose layout gives it no character, as SDL reports for keys like the arrows.
int Unprinted(SDL_Scancode scancode, SDL_Keymod modifiers = SDL_KMOD_NONE)
{
	return(Key(scancode, SDLK_UNKNOWN, modifiers));
}


int Scanned(SDL_Scancode scancode, Uint16 raw, HKL layout, SDL_Keymod modifiers = SDL_KMOD_NONE)
{
	return(Virtual_Key_From_SDL(scancode, SDLK_UNKNOWN, modifiers, raw, layout));
}


// A keyboard layout, which the checks load only when the session lacks it and unload after.
struct TestLayout
{
	HKL Layout = NULL;
	bool Loaded = false;

	TestLayout(WORD language, wchar_t const * name)
	{
		HKL layouts[64];
		int const count = GetKeyboardLayoutList(64, layouts);
		for (int index = 0; index < count; index++) {
			if (LOWORD((UINT_PTR)layouts[index]) == language) {
				Layout = layouts[index];
				return;
			}
		}
		Layout = LoadKeyboardLayoutW(name, KLF_NOTELLSHELL);
		Loaded = (Layout != NULL);
	}

	~TestLayout(void)
	{
		if (Loaded) {
			UnloadKeyboardLayout(Layout);
		}
	}
};

}


TEST_CASE("a letter key is its letter wherever the layout puts it")
{
	CHECK_MESSAGE(Key(SDL_SCANCODE_A, SDLK_A) == 'A', "a letter key is its capital letter");
	CHECK_MESSAGE(Key(SDL_SCANCODE_Q, SDLK_A) == 'A', "the key an AZERTY layout prints A on is A");
	CHECK_MESSAGE(Key(SDL_SCANCODE_Y, SDLK_Z) == 'Z', "the key a QWERTZ layout prints Z on is Z");
	CHECK_MESSAGE(Key(SDL_SCANCODE_SEMICOLON, SDLK_M) == 'M', "a letter off the US letter keys is still that letter");
}


TEST_CASE("a digit key is its digit, even when it prints a symbol")
{
	CHECK(Key(SDL_SCANCODE_1, SDLK_1) == '1');
	CHECK(Key(SDL_SCANCODE_0, SDLK_0) == '0');
	CHECK(Key(SDL_SCANCODE_1, SDLK_AMPERSAND) == '1');
}


TEST_CASE("the comma and plus keys follow what the layout prints on them")
{
	CHECK(Key(SDL_SCANCODE_M, SDLK_COMMA) == VK_OEM_COMMA);
	CHECK(Key(SDL_SCANCODE_RIGHTBRACKET, SDLK_PLUS) == VK_OEM_PLUS);
	CHECK_MESSAGE(Key(SDL_SCANCODE_EQUALS, SDLK_EQUALS) == VK_OEM_PLUS, "the US equals key is the plus key");
}


TEST_CASE("without a scan code, the other punctuation keys keep their US positions")
{
	CHECK_MESSAGE(Key(SDL_SCANCODE_MINUS, (SDL_Keycode)0xDF) == VK_OEM_MINUS, "a key printing a letter with no code");
	CHECK(Key(SDL_SCANCODE_GRAVE, SDLK_GRAVE) == VK_OEM_3);
	CHECK(Key(SDL_SCANCODE_SLASH, SDLK_SLASH) == VK_OEM_2);
}


TEST_CASE("the extra key beside left Shift is its own key")
{
	CHECK(Key(SDL_SCANCODE_NONUSBACKSLASH, SDLK_LESS) == VK_OEM_102);
}


TEST_CASE("a keypad digit follows Num Lock, and Shift makes it a navigation key")
{
	CHECK_MESSAGE(Unprinted(SDL_SCANCODE_KP_7, SDL_KMOD_NUM) == VK_NUMPAD7, "Num Lock on");
	CHECK_MESSAGE(Unprinted(SDL_SCANCODE_KP_7) == VK_HOME, "Num Lock off");
	CHECK_MESSAGE(Unprinted(SDL_SCANCODE_KP_7, (SDL_Keymod)(SDL_KMOD_NUM | SDL_KMOD_LSHIFT)) == VK_HOME, "Num Lock on with Shift held");
}


TEST_CASE("the keypad centre and zero are Clear and Insert without Num Lock")
{
	CHECK(Unprinted(SDL_SCANCODE_KP_5) == VK_CLEAR);
	CHECK(Unprinted(SDL_SCANCODE_KP_0) == VK_INSERT);
}


TEST_CASE("the keypad point is the decimal key or Delete")
{
	CHECK(Unprinted(SDL_SCANCODE_KP_PERIOD, SDL_KMOD_NUM) == VK_DECIMAL);
	CHECK(Unprinted(SDL_SCANCODE_KP_PERIOD) == VK_DELETE);
}


TEST_CASE("the keypad Enter is Enter")
{
	CHECK(Unprinted(SDL_SCANCODE_KP_ENTER) == VK_RETURN);
}


TEST_CASE("the keypad operators are the keypad's own keys whether or not Num Lock is on")
{
	CHECK(Unprinted(SDL_SCANCODE_KP_PLUS) == VK_ADD);
	CHECK(Unprinted(SDL_SCANCODE_KP_MINUS) == VK_SUBTRACT);
	CHECK(Unprinted(SDL_SCANCODE_KP_MULTIPLY) == VK_MULTIPLY);
	CHECK(Unprinted(SDL_SCANCODE_KP_DIVIDE) == VK_DIVIDE);
}


TEST_CASE("either side of Shift, Ctrl and Alt is the modifier, and the Windows keys keep their sides")
{
	CHECK(Unprinted(SDL_SCANCODE_LSHIFT) == VK_SHIFT);
	CHECK(Unprinted(SDL_SCANCODE_RSHIFT) == VK_SHIFT);
	CHECK(Unprinted(SDL_SCANCODE_LCTRL) == VK_CONTROL);
	CHECK(Unprinted(SDL_SCANCODE_RCTRL) == VK_CONTROL);
	CHECK(Unprinted(SDL_SCANCODE_LALT) == VK_MENU);
	CHECK(Unprinted(SDL_SCANCODE_RALT) == VK_MENU);
	CHECK(Unprinted(SDL_SCANCODE_LGUI) == VK_LWIN);
	CHECK(Unprinted(SDL_SCANCODE_RGUI) == VK_RWIN);
}


TEST_CASE("the function keys run from F1 to F24")
{
	CHECK(Unprinted(SDL_SCANCODE_F1) == VK_F1);
	CHECK(Unprinted(SDL_SCANCODE_F12) == VK_F12);
	CHECK(Unprinted(SDL_SCANCODE_F13) == VK_F13);
	CHECK(Unprinted(SDL_SCANCODE_F24) == VK_F24);
}


TEST_CASE("the navigation and editing keys are their Windows keys")
{
	CHECK_MESSAGE(Unprinted(SDL_SCANCODE_PAGEUP) == VK_PRIOR, "Page Up is Prior");
	CHECK_MESSAGE(Unprinted(SDL_SCANCODE_PAGEDOWN) == VK_NEXT, "Page Down is Next");
	CHECK(Unprinted(SDL_SCANCODE_LEFT) == VK_LEFT);
	CHECK(Unprinted(SDL_SCANCODE_DOWN) == VK_DOWN);
	CHECK(Unprinted(SDL_SCANCODE_ESCAPE) == VK_ESCAPE);
	CHECK_MESSAGE(Unprinted(SDL_SCANCODE_BACKSPACE) == VK_BACK, "Backspace is Back");
	CHECK(Key(SDL_SCANCODE_RETURN, SDLK_RETURN) == VK_RETURN);
	CHECK(Key(SDL_SCANCODE_SPACE, SDLK_SPACE) == VK_SPACE);
}


TEST_CASE("the lock, Pause and Print Screen keys are their own keys")
{
	CHECK(Unprinted(SDL_SCANCODE_SCROLLLOCK) == VK_SCROLL);
	CHECK(Unprinted(SDL_SCANCODE_PAUSE) == VK_PAUSE);
	CHECK_MESSAGE(Unprinted(SDL_SCANCODE_PRINTSCREEN) == VK_SNAPSHOT, "Print Screen is the snapshot key");
	CHECK(Unprinted(SDL_SCANCODE_CAPSLOCK) == VK_CAPITAL);
	CHECK(Unprinted(SDL_SCANCODE_NUMLOCKCLEAR) == VK_NUMLOCK);
}


TEST_CASE("a key Windows has no code for is dropped")
{
	CHECK(Unprinted(SDL_SCANCODE_LANG1) == 0);
}


TEST_CASE("every letter key named by SDL is its letter when its layout prints none")
{
	for (int letter = 0; letter < 26; letter++) {
		char name[2] = { (char)('A' + letter), '\0' };
		INFO("letter ", name);
		SDL_Scancode scancode = SDL_GetScancodeFromName(name);
		CHECK(Unprinted(scancode) == 'A' + letter);
	}
}


TEST_CASE("a scan code leaves the function, arrow, modifier and Pause keys their fixed codes")
{
	HKL const current = GetKeyboardLayout(0);
	CHECK(Scanned(SDL_SCANCODE_F1, 0x3B, current) == VK_F1);
	CHECK(Scanned(SDL_SCANCODE_UP, 0xE048, current) == VK_UP);
	CHECK(Scanned(SDL_SCANCODE_RSHIFT, 0x36, current) == VK_SHIFT);
	CHECK(Scanned(SDL_SCANCODE_RCTRL, 0xE01D, current) == VK_CONTROL);
	CHECK(Scanned(SDL_SCANCODE_PAUSE, 0xE046, current) == VK_PAUSE);
}


TEST_CASE("with a scan code, the keypad still follows Num Lock")
{
	HKL const current = GetKeyboardLayout(0);
	CHECK(Scanned(SDL_SCANCODE_KP_8, 0x48, current, SDL_KMOD_NUM) == VK_NUMPAD8);
	CHECK(Scanned(SDL_SCANCODE_KP_8, 0x48, current) == VK_UP);
}


TEST_CASE("a character key takes the code the active layout gives its scan code")
{
	HKL const current = GetKeyboardLayout(0);
	for (unsigned int raw = 0x02; raw <= 0x35; raw++) {
		UINT const expected = MapVirtualKeyExW(raw, MAPVK_VSC_TO_VK_EX, current);
		if (expected >= 'A' && expected <= 'Z') {
			INFO("scan code ", raw);
			CHECK(Scanned(SDL_SCANCODE_A, raw, current) == (int)expected);
		}
	}
}


TEST_CASE("on a German layout, the keys keep the German codes and names")
{
	TestLayout german(0x0407, L"00000407");
	if (german.Layout == NULL || MapVirtualKeyExW(0x0C, MAPVK_VSC_TO_VK_EX, german.Layout) != 0xDB) {
		MESSAGE("skipped: the system has no German layout");
		return;
	}

	CHECK_MESSAGE(Scanned(SDL_SCANCODE_MINUS, 0x0C, german.Layout) == 0xDB, "the sharp s key keeps its own code");
	CHECK_MESSAGE(Scanned(SDL_SCANCODE_SLASH, 0x35, german.Layout) == VK_OEM_MINUS, "the minus key keeps the minus code");
	CHECK_MESSAGE(Scanned(SDL_SCANCODE_SEMICOLON, 0x27, german.Layout) == 0xC0, "the umlaut keys keep theirs");
	CHECK_MESSAGE(Scanned(SDL_SCANCODE_LEFTBRACKET, 0x1A, german.Layout) == 0xBA, "the umlaut keys keep theirs");
	CHECK_MESSAGE(Scanned(SDL_SCANCODE_Y, 0x15, german.Layout) == 'Z', "the Z and Y keys swap");
	CHECK_MESSAGE(Scanned(SDL_SCANCODE_Z, 0x2C, german.Layout) == 'Y', "the Z and Y keys swap");
	CHECK_MESSAGE(Virtual_Key_Name(0xDB, german.Layout) == "\xC3\x9F", "the keys are named by what German prints on them");
	CHECK_MESSAGE(Virtual_Key_Name(0xC0, german.Layout) == "\xC3\x96", "the keys are named by what German prints on them");
}


TEST_CASE("on a US layout, a key is named by what it prints")
{
	TestLayout us(0x0409, L"00000409");
	if (us.Layout == NULL) {
		MESSAGE("skipped: the system has no US layout");
		return;
	}

	CHECK(Virtual_Key_Name('A', us.Layout) == "A");
	CHECK(Virtual_Key_Name('7', us.Layout) == "7");
	CHECK(Virtual_Key_Name(VK_OEM_COMMA, us.Layout) == ",");
}


// A key the layout prints nothing on takes the English name SDL gives its position.
TEST_CASE("a key that prints nothing takes SDL's name for its position")
{
	CHECK_MESSAGE(Virtual_Key_Name(VK_NUMPAD7) == "Keypad 7", "a keypad digit is named as the keypad's");
	CHECK_MESSAGE(Virtual_Key_Name(VK_HOME) == "Home", "a navigation key is named after the main block's key");
	CHECK(Virtual_Key_Name(VK_INSERT) == "Insert");
	CHECK(Virtual_Key_Name(VK_F1) == "F1");
	CHECK(Virtual_Key_Name(VK_F12) == "F12");
	CHECK(Virtual_Key_Name(VK_RETURN) == "Return");
	CHECK(Virtual_Key_Name(VK_SPACE) == "Space");
	CHECK_MESSAGE(Virtual_Key_Name(VK_SHIFT) == "Shift", "the modifiers are named without a side");
	CHECK(Virtual_Key_Name(VK_CONTROL) == "Ctrl");
	CHECK(Virtual_Key_Name(VK_MENU) == "Alt");
}


TEST_CASE("a code no key produces has no name")
{
	CHECK(Virtual_Key_Name(0).empty());
	CHECK(Virtual_Key_Name(0xFF).empty());
}
