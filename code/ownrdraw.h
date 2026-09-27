/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

#include "keyboard.h"
#include "surface.h"
#include "win.h"

#include <string>


namespace OwnerDraw {

	void Prepare_Resources(void);

	int Capture_Mouse(void);
	int Release_Mouse(void);
};


#define OD_TEXT_ALIGN_MIN 1
#define OD_TEXT_ALIGN_CENTER 2
#define OD_TEXT_ALIGN_MAX 3

int OD_Draw_Text(COLORREF color, HFONT font, Rect const & rect, const char * text, int len, int x_alignment, int y_alignment, Surface * surface);
HFONT WS_Get_Font(HDC hdc, const char * face_name, int decipt_width, int decipt_height, int attributes);

std::string Build_Hotkey_String(KeyNumType key);

extern unsigned short ODRComponentMask;
extern unsigned short ODGComponentMask;
extern unsigned short ODBComponentMask;


inline unsigned short OD_Blend_Color(unsigned short pixel, unsigned short color, unsigned char alpha)
{
	static unsigned blend_color_alpha;
	static unsigned blend_pixel_alpha;

	blend_color_alpha = alpha;
	blend_pixel_alpha = 255 - alpha;

	unsigned short r = ((((pixel & ODRComponentMask) * blend_pixel_alpha) + ((color & ODRComponentMask) * blend_color_alpha)) >> 8) & ODRComponentMask;
	unsigned short g = ((((pixel & ODGComponentMask) * blend_pixel_alpha) + ((color & ODGComponentMask) * blend_color_alpha)) >> 8) & ODGComponentMask;
	unsigned short b = (((pixel & ODBComponentMask) * blend_pixel_alpha) + ((color & ODBComponentMask) * blend_color_alpha)) >> 8;
	return((unsigned short)(r | g | b));
}
