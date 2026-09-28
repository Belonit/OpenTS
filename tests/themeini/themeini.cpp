/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Reads music track sections shaped like the shipped THEME.INI and with the
// keys OpenTS adds, and checks what each key becomes. Needs no game data.

#include "ini.h"
#include "side.h"
#include "theme.h"
#include "xstraw.h"

#include <cmath>
#include <cstdio>
#include <cstring>

// The side list stands in for the one the rules declare.
SideType SideClass::From_Name(char const * name)
{
	if (stricmp(name, "GDI") == 0) return(SIDE_GDI);
	if (stricmp(name, "Nod") == 0) return(SIDE_NOD);
	return(SIDE_NONE);
}

namespace {

int Failures = 0;
int Checked = 0;


void Check(bool condition, char const * what)
{
	Checked++;
	if (!condition) {
		Failures++;
		std::printf("FAIL: %s\n", what);
	}
}


bool Near(float value, float expect)
{
	return(std::fabs(value - expect) < 0.001f);
}


void Read(INIClass & ini, char const * text)
{
	BufferStraw straw(text, (int)std::strlen(text));
	ini.Load(straw);
}


ThemeControl Track(INIClass const & ini, char const * name)
{
	ThemeControl control;
	std::strcpy(control.Name, name);
	control.Fill_In(ini);
	return(control);
}


void Test_Tiberian_Sun_Shape(void)
{
	INIClass ini;
	Read(ini,
		"[Themes]\n"
		"1=INTRO\n"
		"[INTRO]\n"
		"Name=Intro theme\n"
		"Length=3.27\n"
		"Normal=no\n"
		"Repeat=yes\n");

	ThemeControl intro = Track(ini, "INTRO");
	Check(std::strcmp(intro.Fullname, "Intro theme") == 0, "Name= is the title");
	Check(Near(intro.Duration, 3.27f), "Length= is kept as written");
	Check(!intro.Normal && intro.Repeat, "Normal= and Repeat= are read");
	Check(intro.Sound[0] == '\0', "without Sound= the file is named after the section");
	Check(Near(intro.Volume, 1.0f), "Volume= defaults to full");
	Check(intro.RequiredAddon == 0, "RequiredAddon= defaults to none");
	Check(intro.Owners.empty() && intro.Allows_Side(SIDE_GDI) && intro.Allows_Side(SIDE_NOD), "without Side= every side hears it");

	ThemeControl missing;
	std::strcpy(missing.Name, "NOSUCH");
	Check(!missing.Fill_In(ini), "a track without a section reports it");
}


void Test_New_Keys(void)
{
	INIClass ini;
	Read(ini,
		"[LOOSE]\n"
		"Sound=MYTRACK\n"
		"Volume=0.5\n"
		"RequiredAddon=1\n"
		"[PERCENT]\n"
		"Volume=40\n"
		"[JUNK]\n"
		"Volume=loud\n");

	ThemeControl loose = Track(ini, "LOOSE");
	Check(std::strcmp(loose.Sound, "MYTRACK") == 0, "Sound= names the file");
	Check(Near(loose.Volume, 0.5f), "Volume= as a fraction");
	Check(loose.RequiredAddon == 1, "RequiredAddon= is read");
	Check(Near(Track(ini, "PERCENT").Volume, 0.4f), "Volume= above 1 is a percentage");
	Check(Near(Track(ini, "JUNK").Volume, 1.0f), "a Volume= that is not a number is ignored");
}


void Test_Sides(void)
{
	INIClass ini;
	Read(ini,
		"[ONE]\n"
		"Side=GDI\n"
		"[TWO]\n"
		"Side=Nod, GDI\n"
		"[SOME]\n"
		"Side=Bogus,Nod\n"
		"[BAD]\n"
		"Side=Bogus\n"
		"[NONE]\n"
		"Side=<none>\n");

	ThemeControl one = Track(ini, "ONE");
	Check(one.Allows_Side(SIDE_GDI) && !one.Allows_Side(SIDE_NOD), "one side");
	ThemeControl two = Track(ini, "TWO");
	Check(two.Owners.size() == 2 && two.Allows_Side(SIDE_GDI) && two.Allows_Side(SIDE_NOD) && !two.Allows_Side(SIDE_MUTANT), "a list of sides");
	ThemeControl some = Track(ini, "SOME");
	Check(some.Owners.size() == 1 && some.Allows_Side(SIDE_NOD), "an undeclared side in a list is skipped");

	ThemeControl bad;
	std::strcpy(bad.Name, "BAD");
	bad.Owners.push_back(SIDE_NOD);
	bad.Fill_In(ini);
	Check(bad.Owners.size() == 1 && bad.Allows_Side(SIDE_NOD), "a list naming no declared side keeps the sides before it");

	ThemeControl none;
	std::strcpy(none.Name, "NONE");
	none.Owners.push_back(SIDE_NOD);
	none.Fill_In(ini);
	Check(none.Owners.empty(), "<none> allows every side");
}

} // namespace


int main(void)
{
	Test_Tiberian_Sun_Shape();
	Test_New_Keys();
	Test_Sides();

	std::printf("themeini: %d checks, %d failures\n", Checked, Failures);
	return(Failures == 0 ? 0 : 1);
}
