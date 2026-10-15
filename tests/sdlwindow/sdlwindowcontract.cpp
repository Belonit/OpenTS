/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Pins what the game receives from the SDL layer's pump: each event once and in order, with
// the keys reported held as of that event, however many events one pump delivers.

#include "gamewindow.h"
#include "sdl/sdlwindow.h"
#include "windowevent.hh"

#include "win.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_video.h>

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cwchar>
#include <functional>
#include <limits>
#include <thread>
#include <vector>

namespace {

int Failures = 0;


void Check(bool condition, char const * what)
{
	std::printf("%-76s %s\n", what, condition ? "ok" : "FAILED");

	if (!condition) {
		Failures++;
	}
}


struct IconImage
{
	int Width = 0;
	int Height = 0;
	std::vector<unsigned char> Pixels;

	bool operator==(IconImage const &) const = default;
};


IconImage Window_Icon(WPARAM size)
{
	HWND const window = (HWND)Main_Window_Native().Handle;
	HICON const icon = (HICON)SendMessageW(window, WM_GETICON, size, 0);
	IconImage image;
	if (icon == NULL) {
		return(image);
	}

	ICONINFO info = {};
	bool const gotinfo = GetIconInfo(icon, &info) != FALSE;
	Check(gotinfo, "the window icon's bitmaps can be read");
	if (!gotinfo) {
		return(image);
	}

	BITMAP bitmap = {};
	bool const gotbitmap = info.hbmColor != NULL && GetObjectW(info.hbmColor, sizeof(bitmap), &bitmap) != 0;
	Check(gotbitmap, "the window icon has a color bitmap");
	if (gotbitmap) {
		image.Width = bitmap.bmWidth;
		image.Height = bitmap.bmHeight;
		image.Pixels.resize((size_t)image.Width * image.Height * 4);
		BITMAPINFO format = {};
		format.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		format.bmiHeader.biWidth = image.Width;
		format.bmiHeader.biHeight = -image.Height;
		format.bmiHeader.biPlanes = 1;
		format.bmiHeader.biBitCount = 32;
		format.bmiHeader.biCompression = BI_RGB;
		HDC const dc = GetDC(NULL);
		Check(GetDIBits(dc, info.hbmColor, 0, image.Height, image.Pixels.data(), &format, DIB_RGB_COLORS) == image.Height,
			"the window icon's BGRA pixels can be read");
		ReleaseDC(NULL, dc);
	}
	if (info.hbmColor != NULL) {
		DeleteObject(info.hbmColor);
	}
	if (info.hbmMask != NULL) {
		DeleteObject(info.hbmMask);
	}
	return(image);
}


std::vector<WindowEvent> Received;

// Whether the SDL layer reported Ctrl held while each received event was handled.
std::vector<bool> CtrlHeld;


void Push_Key(bool down, SDL_Scancode scancode, SDL_Keycode keycode, SDL_Keymod modifiers = SDL_KMOD_NONE)
{
	SDL_Event event = {};
	event.type = down ? SDL_EVENT_KEY_DOWN : SDL_EVENT_KEY_UP;
	event.key.scancode = scancode;
	event.key.key = keycode;
	event.key.mod = modifiers;
	event.key.down = down;
	SDL_PushEvent(&event);
}


void Push_Window(SDL_EventType type)
{
	SDL_Event event = {};
	event.type = type;
	SDL_PushEvent(&event);
}


void Push_Click(void)
{
	SDL_Event event = {};
	event.type = SDL_EVENT_MOUSE_BUTTON_DOWN;
	event.button.button = SDL_BUTTON_LEFT;
	event.button.down = true;
	event.button.clicks = 1;
	SDL_PushEvent(&event);
}


// An event the last pump delivered, and whether Ctrl was reported held while it was handled.
struct Delivered
{
	WindowEvent Event;
	bool Ctrl;
};


// The events of one type the last pump delivered.
std::vector<Delivered> Pumped(WindowEventType type)
{
	Received.clear();
	CtrlHeld.clear();
	Main_Window_Pump_Events();

	std::vector<Delivered> result;
	for (size_t index = 0; index < Received.size(); index++) {
		if (Received[index].Type == type) {
			result.push_back({ Received[index], CtrlHeld[index] });
		}
	}
	return(result);
}


// SDL takes the capture only for the window it last saw the pointer over, and a released
// capture can clear that until the pointer moves or a button is pressed.
bool Point_At(SDL_Window * window)
{
	int width = 0;
	int height = 0;
	SDL_GetWindowSize(window, &width, &height);
	SDL_WarpMouseInWindow(window, width / 2.0f, height / 2.0f);
	Pumped(WINDOW_EVENT_NONE);
	return(SDL_GetMouseFocus() == window);
}


// The sizes SDL lists: the current mode and every mode of more than 256 colors.
std::vector<std::pair<int, int>> Windows_Sizes(void)
{
	std::vector<std::pair<int, int>> sizes;
	DEVMODEW mode = {};
	mode.dmSize = sizeof(mode);
	if (EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, &mode)) {
		sizes.emplace_back((int)mode.dmPelsWidth, (int)mode.dmPelsHeight);
	}

	for (DWORD index = 0; ; index++) {
		mode = {};
		mode.dmSize = sizeof(mode);
		if (!EnumDisplaySettingsW(NULL, index, &mode)) {
			break;
		}
		if (mode.dmBitsPerPel == 15 || mode.dmBitsPerPel == 16 || mode.dmBitsPerPel == 24 || mode.dmBitsPerPel == 32) {
			sizes.emplace_back((int)mode.dmPelsWidth, (int)mode.dmPelsHeight);
		}
	}

	std::sort(sizes.begin(), sizes.end());
	sizes.erase(std::unique(sizes.begin(), sizes.end()), sizes.end());
	return(sizes);
}


wchar_t const BoxTitle[] = L"sdlwindow question";


struct BoxAnswer
{
	enum { YES, NO, ESCAPE } Press;
	bool YesFirst = false;
	bool YesDefault = false;
};


struct BoxButtons
{
	HWND Yes = NULL;
	HWND No = NULL;
};


BOOL CALLBACK Find_Box_Button(HWND child, LPARAM lparam)
{
	BoxButtons & buttons = *(BoxButtons *)lparam;
	wchar_t text[8] = {};
	GetWindowTextW(child, text, 8);
	if (std::wcscmp(text, L"Yes") == 0) {
		buttons.Yes = child;
	} else if (std::wcscmp(text, L"No") == 0) {
		buttons.No = child;
	}
	return(TRUE);
}


// A box that never appears ends the test, since the main thread waits on it.
void Answer_Box(BoxAnswer & answer)
{
	HWND box = NULL;
	BoxButtons buttons;
	for (int tries = 0; tries < 500 && (buttons.Yes == NULL || buttons.No == NULL); tries++) {
		Sleep(20);
		box = FindWindowW(L"#32770", BoxTitle);
		if (box != NULL && IsWindowVisible(box)) {
			EnumChildWindows(box, Find_Box_Button, (LPARAM)&buttons);
		}
	}
	if (box == NULL) {
		std::printf("the confirm box never appeared\n\nFAILED\n");
		std::fflush(stdout);
		std::_Exit(1);
	}

	if (buttons.Yes == NULL || buttons.No == NULL || answer.Press == BoxAnswer::ESCAPE) {
		PostMessageW(box, WM_COMMAND, IDCANCEL, 0);
		return;
	}
	HWND const pressed = (answer.Press == BoxAnswer::YES) ? buttons.Yes : buttons.No;

	RECT yes = {};
	RECT no = {};
	GetWindowRect(buttons.Yes, &yes);
	GetWindowRect(buttons.No, &no);
	answer.YesFirst = yes.left < no.left;
	answer.YesDefault = (GetWindowLongW(buttons.Yes, GWL_STYLE) & BS_TYPEMASK) == BS_DEFPUSHBUTTON;
	PostMessageW(box, WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(pressed), BN_CLICKED), (LPARAM)pressed);
}


bool Ask(BoxAnswer & answer)
{
	std::thread driver(Answer_Box, std::ref(answer));
	bool const result = Main_Window_Confirm_Box("sdlwindow question", "Go on?", "Yes", "No");
	driver.join();
	return(result);
}

}


// Stands in for the game's window handler and records what the SDL layer hands it.
void Game_Window_Handle_Event(WindowEvent const & event)
{
	Received.push_back(event);
	CtrlHeld.push_back(Main_Window_Key_Down(VK_CONTROL));
}


int main(void)
{
	// Windows keeps a program from taking the foreground from another, so the window may get
	// no keyboard focus otherwise.
	SDL_SetHint(SDL_HINT_FORCE_RAISEWINDOW, "1");
	if (!Main_Window_Create(true, 64, 48)) {
		std::printf("the main window could not be created\n\nFAILED\n");
		return(1);
	}
	Main_Window_Pump_Events();
	IconImage const defaultsmall = Window_Icon(ICON_SMALL);
	IconImage const defaultbig = Window_Icon(ICON_BIG);

	Main_Window_Request_Repaint();
	Main_Window_Request_Repaint();
	Check(Pumped(WINDOW_EVENT_EXPOSED).size() == 1, "repaints requested before a pump reach the game as one exposure");

	std::vector<std::pair<int, int>> const sizes = Main_Window_Fullscreen_Sizes();
	DEVMODEW desktop = {};
	desktop.dmSize = sizeof(desktop);
	EnumDisplaySettingsW(NULL, ENUM_CURRENT_SETTINGS, &desktop);
	Check(!sizes.empty() && std::adjacent_find(sizes.begin(), sizes.end(), std::greater_equal<>()) == sizes.end(), "the fullscreen sizes are listed once each, smallest first");
	Check(std::find(sizes.begin(), sizes.end(), std::make_pair((int)desktop.dmPelsWidth, (int)desktop.dmPelsHeight)) != sizes.end(), "and include the desktop's size");
	Check(sizes == Windows_Sizes(), "and are Windows' sizes for the display of more than 256 colors");

	SDL_Cursor * const system = Main_Window_System_Cursor(UI_CURSOR_ARROW);
	Check(system != nullptr, "the window has the system's arrow before one is set");
	Main_Window_Set_Cursor(system);
	unsigned int const pixels[4] = { 0xFF00FF00, 0xFF00FF00, 0xFF00FF00, 0x00000000 };
	SDL_Cursor * const custom = Main_Window_Create_Cursor(pixels, 2, 2, 0, 0);
	Main_Window_Set_Arrow(custom);
	Check(custom != nullptr && Main_Window_System_Cursor(UI_CURSOR_ARROW) == custom, "a set arrow is the window's arrow");
	Check(SDL_GetCursor() == custom, "and replaces the system's arrow on screen");
	Main_Window_Set_Arrow(nullptr);
	SDL_Cursor * const restored = Main_Window_System_Cursor(UI_CURSOR_ARROW);
	Check(restored != nullptr && restored != custom && SDL_GetCursor() == restored, "clearing it puts the system's arrow back on screen");

	SDL_Cursor * const pointer = Main_Window_Create_Cursor(pixels, 2, 2, 0, 0);
	SDL_Cursor * const arrow = Main_Window_Create_Cursor(pixels, 2, 2, 1, 1);
	Main_Window_Set_Arrow(arrow);
	Main_Window_Set_Cursor(pointer);
	Main_Window_Destroy_Cursor(pointer);
	Check(pointer != nullptr && SDL_GetCursor() == arrow, "destroying the cursor on screen puts the window's arrow up");
	Main_Window_Set_Arrow(nullptr);

	Push_Key(true, SDL_SCANCODE_A, SDLK_A);
	Push_Key(true, SDL_SCANCODE_B, SDLK_B);
	std::vector<Delivered> keys = Pumped(WINDOW_EVENT_KEY_DOWN);
	Check(keys.size() == 2 && keys[0].Event.VirtualKey == 'A' && keys[1].Event.VirtualKey == 'B', "each queued key reaches the game once, in order");

	Push_Key(false, SDL_SCANCODE_A, SDLK_A);
	Push_Key(false, SDL_SCANCODE_B, SDLK_B);
	Pumped(WINDOW_EVENT_KEY_UP);

	Check(!Main_Window_Key_Down(VK_CONTROL), "no key is held before one is pressed");
	Push_Key(true, SDL_SCANCODE_LCTRL, SDLK_LCTRL, SDL_KMOD_LCTRL);
	Push_Key(true, SDL_SCANCODE_A, SDLK_A, SDL_KMOD_LCTRL);
	keys = Pumped(WINDOW_EVENT_KEY_DOWN);
	Check(keys.size() == 2 && keys[1].Ctrl && (keys[1].Event.Modifiers & WINDOW_MOD_CTRL) != 0, "a key pressed after Ctrl in the same pump sees Ctrl held");
	Check(Main_Window_Key_Down(VK_LCONTROL) && !Main_Window_Key_Down(VK_RCONTROL), "and the side it was pressed on");

	Push_Click();
	std::vector<Delivered> clicks = Pumped(WINDOW_EVENT_MOUSE_DOWN);
	Check(clicks.size() == 1 && (clicks[0].Event.Modifiers & WINDOW_MOD_CTRL) != 0, "a click while Ctrl is held carries Ctrl");

	Push_Key(false, SDL_SCANCODE_A, SDLK_A, SDL_KMOD_LCTRL);
	Push_Key(false, SDL_SCANCODE_LCTRL, SDLK_LCTRL);
	Push_Key(true, SDL_SCANCODE_B, SDLK_B);
	Push_Click();
	Received.clear();
	CtrlHeld.clear();
	Main_Window_Pump_Events();
	bool released = false;
	bool clicked = false;
	for (size_t index = 0; index < Received.size(); index++) {
		if (Received[index].Type == WINDOW_EVENT_KEY_DOWN && Received[index].VirtualKey == 'B') {
			released = !CtrlHeld[index] && (Received[index].Modifiers & WINDOW_MOD_CTRL) == 0;
		}
		if (Received[index].Type == WINDOW_EVENT_MOUSE_DOWN) {
			clicked = true;
			released = released && (Received[index].Modifiers & WINDOW_MOD_CTRL) == 0;
		}
	}
	Check(released && clicked, "a key or click after Ctrl's release in the same pump sees it released");

	Push_Key(false, SDL_SCANCODE_B, SDLK_B);
	Pumped(WINDOW_EVENT_KEY_UP);

	// Windows reports the Left Ctrl it presses for AltGr only while the Right Alt press is queued.
	BYTE state[256] = {};
	state[VK_CONTROL] = 0x80;
	state[VK_LCONTROL] = 0x80;
	SetKeyboardState(state);
	Push_Key(true, SDL_SCANCODE_RALT, SDLK_RALT, SDL_KMOD_RALT);
	std::memset(state, 0, sizeof(state));
	SetKeyboardState(state);
	Push_Key(true, SDL_SCANCODE_Q, SDLK_Q, SDL_KMOD_RALT);
	Push_Key(false, SDL_SCANCODE_Q, SDLK_Q, SDL_KMOD_RALT);
	Push_Key(false, SDL_SCANCODE_RALT, SDLK_RALT);
	keys = Pumped(WINDOW_EVENT_KEY_DOWN);
	Check(keys.size() == 2 && keys[1].Ctrl && keys[1].Event.Modifiers == (WINDOW_MOD_CTRL | WINDOW_MOD_ALT) && !keys[1].Event.System, "a key typed with AltGr in one pump carries AltGr's Ctrl");
	Check(!Main_Window_Key_Down(VK_CONTROL), "and Ctrl is released with AltGr");

	Push_Key(true, SDL_SCANCODE_LALT, SDLK_LALT, SDL_KMOD_LALT);
	Push_Key(false, SDL_SCANCODE_LALT, SDLK_LALT);
	keys = Pumped(WINDOW_EVENT_KEY_UP);
	Check(keys.size() == 1 && keys[0].Event.VirtualKey == VK_MENU && keys[0].Event.System, "Alt's own release is a system key, as Windows reports it");

	HWND const window = (HWND)Main_Window_Native().Handle;

	// SDL reports no key still held after it resets the keyboard, and drops such a key's release.
	std::memset(state, 0, sizeof(state));
	state[VK_SHIFT] = 0x80;
	state[VK_LSHIFT] = 0x80;
	SetKeyboardState(state);
	Push_Window(SDL_EVENT_WINDOW_FOCUS_GAINED);
	Pumped(WINDOW_EVENT_FOCUS_GAINED);
	Check(Main_Window_Key_Down(VK_SHIFT) && Main_Window_Key_Down(VK_LSHIFT) && !Main_Window_Key_Down(VK_RSHIFT), "a Shift held as the window gains the focus is held");
	Push_Click();
	clicks = Pumped(WINDOW_EVENT_MOUSE_DOWN);
	Push_Key(true, SDL_SCANCODE_A, SDLK_A);
	keys = Pumped(WINDOW_EVENT_KEY_DOWN);
	Check(clicks.size() == 1 && (clicks[0].Event.Modifiers & WINDOW_MOD_SHIFT) != 0 && keys.size() == 1 && (keys[0].Event.Modifiers & WINDOW_MOD_SHIFT) != 0, "and a click or a key after it carries Shift");
	Push_Key(false, SDL_SCANCODE_A, SDLK_A);
	Pumped(WINDOW_EVENT_KEY_UP);

	std::memset(state, 0, sizeof(state));
	SetKeyboardState(state);
	Push_Click();
	clicks = Pumped(WINDOW_EVENT_MOUSE_DOWN);
	Check(clicks.size() == 1 && (clicks[0].Event.Modifiers & WINDOW_MOD_SHIFT) == 0 && !Main_Window_Key_Down(VK_SHIFT), "it is released when Windows releases it, though SDL reports no release");

	// SDL's first press of a key held as the window gains the focus is one Windows reports as a
	// repeat.
	state['A'] = 0x80;
	SetKeyboardState(state);
	Push_Window(SDL_EVENT_WINDOW_FOCUS_GAINED);
	Pumped(WINDOW_EVENT_FOCUS_GAINED);
	Push_Key(true, SDL_SCANCODE_A, SDLK_A);
	keys = Pumped(WINDOW_EVENT_KEY_DOWN);
	Check(keys.size() == 1 && keys[0].Event.Repeat && Main_Window_Key_Down('A'), "a key held as the window gains the focus reaches the game as a repeat");
	std::memset(state, 0, sizeof(state));
	SetKeyboardState(state);
	Push_Key(false, SDL_SCANCODE_A, SDLK_A);
	keys = Pumped(WINDOW_EVENT_KEY_UP);
	Check(keys.size() == 1 && !Main_Window_Key_Down('A'), "and its release reaches the game");

	// The drag loop and the mouse capture need the keyboard focus.
	if (SDL_GetKeyboardFocus() == nullptr) {
		std::printf("%-76s %s\n", "the checks that need the keyboard focus", "not run");
	} else {
		SendMessageW(window, WM_ENTERSIZEMOVE, 0, 0);
		state[VK_SHIFT] = 0x80;
		state[VK_LSHIFT] = 0x80;
		SetKeyboardState(state);
		SendMessageW(window, WM_EXITSIZEMOVE, 0, 0);
		Pumped(WINDOW_EVENT_NONE);
		Check(Main_Window_Key_Down(VK_SHIFT), "a Shift held through a drag of the window is held after it");
		std::memset(state, 0, sizeof(state));
		SetKeyboardState(state);
		Pumped(WINDOW_EVENT_NONE);

		HWND focused = CreateWindowExW(0, L"STATIC", L"", WS_POPUP | WS_VISIBLE, 0, 0, 8, 8, NULL, NULL, GetModuleHandleW(NULL), NULL);
		SetFocus(focused);
		Pumped(WINDOW_EVENT_FOCUS_LOST);
		Main_Window_Take_Focus();
		Check(GetFocus() == window, "the window takes back the keyboard focus from another window");
		Check(Pumped(WINDOW_EVENT_FOCUS_GAINED).size() == 1, "and the game hears it gained the focus");
		DestroyWindow(focused);
		Pumped(WINDOW_EVENT_NONE);

		SDL_Window * const sdlwindow = SDL_GetKeyboardFocus();
		POINT pointer = {};
		GetCursorPos(&pointer);
		if (!Point_At(sdlwindow)) {
			std::printf("%-76s %s\n", "the checks that need the pointer over the window", "not run");
		} else {
			Main_Window_Capture_Mouse(true);
			bool const captured = Main_Window_Mouse_Captured() && GetCapture() == window;
			Check(captured, "the window can take the mouse capture");
			if (captured) {
				SendMessageW(window, WM_CANCELMODE, 0, 0);
				Check(!Main_Window_Mouse_Captured(), "a capture Windows cancels is reported gone at once");
				Check(Pumped(WINDOW_EVENT_CAPTURE_LOST).size() == 1, "and reaches the game as one lost capture");

				Main_Window_Capture_Mouse(true);
				Check(Main_Window_Mouse_Captured() && GetCapture() == window, "the capture can be taken again after it was cancelled");

				Main_Window_Capture_Mouse(false);
				Check(!Main_Window_Mouse_Captured() && Pumped(WINDOW_EVENT_CAPTURE_LOST).empty(), "releasing it is no lost capture");

				HWND other = CreateWindowExW(0, L"STATIC", L"", WS_POPUP, 0, 0, 8, 8, NULL, NULL, GetModuleHandleW(NULL), NULL);
				Point_At(sdlwindow);
				Main_Window_Capture_Mouse(true);
				Check(Main_Window_Mouse_Captured() && GetCapture() == window, "the capture can be taken again after it was released");
				SetCapture(other);
				Check(!Main_Window_Mouse_Captured(), "another window taking the capture is reported at once");
				Check(Pumped(WINDOW_EVENT_CAPTURE_LOST).size() == 1, "and reaches the game as one lost capture");
				ReleaseCapture();
				DestroyWindow(other);
				Main_Window_Capture_Mouse(false);
				Pumped(WINDOW_EVENT_CAPTURE_LOST);
			}
		}
		SetCursorPos(pointer.x, pointer.y);
	}

	BoxAnswer yes = { BoxAnswer::YES };
	Check(Ask(yes), "the confirm box's yes button answers yes");
	Check(yes.YesFirst && yes.YesDefault, "and it is the default, left of no");
	BoxAnswer no = { BoxAnswer::NO };
	Check(!Ask(no), "the no button answers no");
	BoxAnswer escape = { BoxAnswer::ESCAPE };
	Check(!Ask(escape), "Escape answers no");
	Pumped(WINDOW_EVENT_NONE);

	Main_Window_Destroy();

	int const iconwidth = GetSystemMetrics(SM_CXICON);
	int const iconheight = GetSystemMetrics(SM_CYICON);
	std::vector<unsigned char> iconpixels((size_t)iconwidth * iconheight * 4);
	for (size_t pixel = 0; pixel < iconpixels.size(); pixel += 4) {
		bool const top = pixel < iconpixels.size() / 2;
		iconpixels[pixel] = top ? 0xE1 : 0xB0;
		iconpixels[pixel + 1] = top ? 0x52 : 0x60;
		iconpixels[pixel + 2] = top ? 0x29 : 0x20;
		iconpixels[pixel + 3] = top ? 0xFF : 0x80;
	}
	MainWindowIcon const icon = { iconpixels, iconwidth, iconheight };
	bool const created = Main_Window_Create(true, 64, 48, &icon);
	Check(created, "the main window accepts a custom RGBA icon");
	if (created) {
		// GetDIBits returns BGRA, while the supplied pixels are RGBA.
		std::vector<unsigned char> expected = iconpixels;
		for (size_t pixel = 0; pixel < expected.size(); pixel += 4) {
			std::swap(expected[pixel], expected[pixel + 2]);
		}
		std::fill(iconpixels.begin(), iconpixels.end(), 0);
		IconImage const small = Window_Icon(ICON_SMALL);
		IconImage const big = Window_Icon(ICON_BIG);
		Check(small.Width == iconwidth && small.Height == iconheight && small.Pixels == expected,
			"the small icon preserves RGBA channels, row order, and straight alpha");
		Check(big.Width == iconwidth && big.Height == iconheight && big.Pixels == expected,
			"the large icon retains its pixels after the caller changes the buffer");
		for (IconImage const * image : { &small, &big }) {
			if (image->Width != iconwidth || image->Height != iconheight || image->Pixels != expected) {
				std::printf("%s icon: %dx%d; system icon: %dx%d\n", image == &small ? "small" : "large",
					image->Width, image->Height, GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON));
				if (image->Width > 0 && image->Height > 0 && image->Pixels.size() >= (size_t)image->Width * image->Height * 4) {
					unsigned char const * top = image->Pixels.data();
					unsigned char const * bottom = top + (size_t)(image->Height - 1) * image->Width * 4;
					std::printf("  BGRA top: %02X %02X %02X %02X; bottom: %02X %02X %02X %02X\n",
						top[0], top[1], top[2], top[3], bottom[0], bottom[1], bottom[2], bottom[3]);
				}
			}
		}
	}
	Main_Window_Destroy();

	Check(Main_Window_Create(true, 64, 48), "the main window can be recreated without a custom icon");
	Check(Window_Icon(ICON_SMALL) == defaultsmall && Window_Icon(ICON_BIG) == defaultbig,
		"destroying and recreating the window restores both default icons");
	Main_Window_Destroy();

	int const max = std::numeric_limits<int>::max();
	struct InvalidIcon
	{
		MainWindowIcon Icon;
		char const * Name;
	};
	InvalidIcon const invalid[] = {
		{ { {}, 32, 32 }, "an empty pixel buffer keeps both default icons" },
		{ { std::span<unsigned char const>(iconpixels).first(iconpixels.size() - 1), iconwidth, iconheight }, "a buffer one byte short keeps both default icons" },
		{ { iconpixels, 0, 32 }, "a zero icon width keeps both default icons" },
		{ { iconpixels, 32, 0 }, "a zero icon height keeps both default icons" },
		{ { iconpixels, -1, 32 }, "a negative icon width keeps both default icons" },
		{ { iconpixels, 32, -1 }, "a negative icon height keeps both default icons" },
		{ { iconpixels, max / 4 + 1, 1 }, "an overflowing icon pitch keeps both default icons" },
		{ { iconpixels, max, max }, "maximum icon dimensions keep both default icons" },
		{ { iconpixels, max / 4, max }, "an excessive icon byte count keeps both default icons" },
		{ { iconpixels, 1, max }, "an excessive icon height keeps both default icons" },
	};
	for (InvalidIcon const & entry : invalid) {
		bool const validwindow = Main_Window_Create(true, 64, 48, &entry.Icon);
		Check(validwindow, "an invalid icon does not prevent window creation");
		Check(validwindow && Window_Icon(ICON_SMALL) == defaultsmall && Window_Icon(ICON_BIG) == defaultbig, entry.Name);
		Main_Window_Destroy();
	}

	Check(Main_Window_Create(true, 64, 48, nullptr), "an explicit null icon allows window creation");
	Check(Window_Icon(ICON_SMALL) == defaultsmall && Window_Icon(ICON_BIG) == defaultbig,
		"an explicit null icon keeps both default icons");
	Main_Window_Destroy();

	std::printf("\n%s\n", Failures == 0 ? "PASSED" : "FAILED");
	return(Failures == 0 ? 0 : 1);
}
