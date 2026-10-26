/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Pins the automatic-save ring a client relies on: the name each slot is written under, the
// order the slots turn in, what a launch file may seed, and when the next save falls due.

#include <string>

#include "autosave.h"

#include "doctest/doctest.h"

namespace {

using KindType = AutosaveClass::KindType;


std::string Next_Name(AutosaveClass & autosave, KindType kind)
{
	return(AutosaveClass::File_Name(kind, autosave.Advance(kind)));
}

}


// A fresh ring writes its first slot, named the way a client reads it back: the prefix, a
// single digit, and the save extension.
TEST_CASE("a fresh ring writes its first slot, named the way a client reads it back")
{
	AutosaveClass autosave;

	CHECK_MESSAGE(Next_Name(autosave, KindType::Campaign) == "AUTOSAVE1.SAV", "the first campaign autosave is slot one");
	CHECK_MESSAGE(Next_Name(autosave, KindType::Skirmish) == "AUTOSAVE_SKIRMISH1.SAV", "a skirmish autosave keeps the prefix a client files by");
}


TEST_CASE("the ring turns through its five slots and starts over, and each ring turns alone")
{
	AutosaveClass autosave;
	std::string names;

	for (int index = 0; index <= AutosaveClass::SLOT_COUNT; index++) {
		names += Next_Name(autosave, KindType::Campaign) + " ";
	}

	CHECK_MESSAGE(names == "AUTOSAVE1.SAV AUTOSAVE2.SAV AUTOSAVE3.SAV AUTOSAVE4.SAV AUTOSAVE5.SAV AUTOSAVE1.SAV ", "the campaign slots turn in order and start over");
	CHECK_MESSAGE(autosave.Campaign_Slot() == 1, "a save records the slot that follows the one written");
	CHECK_MESSAGE(autosave.Skirmish_Slot() == 0, "turning the campaign ring leaves the skirmish ring alone");
}


// A launch file seeds where each ring continues from, and a slot the ring does not hold starts
// it over rather than naming a file outside the ring.
TEST_CASE("a launch file seeds where each ring continues from")
{
	AutosaveClass autosave;

	autosave.Seed_Slots(4, 2);
	CHECK_MESSAGE(Next_Name(autosave, KindType::Campaign) == "AUTOSAVE5.SAV", "a seeded campaign ring continues from the slot named");
	CHECK_MESSAGE(Next_Name(autosave, KindType::Campaign) == "AUTOSAVE1.SAV", "a seeded campaign ring continues from the slot named");
	CHECK_MESSAGE(Next_Name(autosave, KindType::Skirmish) == "AUTOSAVE_SKIRMISH3.SAV", "a seeded skirmish ring continues from its own slot");

	autosave.Seed_Slots(-2, AutosaveClass::SLOT_COUNT);
	CHECK_MESSAGE(autosave.Campaign_Slot() == 0, "a seed the ring does not hold starts it over");
	CHECK_MESSAGE(autosave.Skirmish_Slot() == 0, "a seed the ring does not hold starts it over");
}


// A save falls due one interval after the last one was scheduled, is armed once, and is pushed
// a full interval out by any save that completes in between.
TEST_CASE("a save falls due one interval after the last one was scheduled")
{
	AutosaveClass autosave;

	autosave.Schedule(100);
	CHECK_MESSAGE(!autosave.Is_Due(100000), "no interval means no save ever falls due");

	autosave.Set_Interval(300);
	autosave.Schedule(100);
	CHECK_MESSAGE(!autosave.Is_Due(399), "a save falls due one interval after it was scheduled");
	CHECK_MESSAGE(autosave.Is_Due(400), "a save falls due one interval after it was scheduled");
	CHECK_MESSAGE(autosave.Is_Due(401), "a save falls due one interval after it was scheduled");

	autosave.Arm();
	CHECK_MESSAGE(!autosave.Is_Due(400), "an armed request is not due again");
	CHECK_MESSAGE(autosave.Take_Armed(), "an armed request is taken once");
	CHECK_MESSAGE(!autosave.Take_Armed(), "an armed request is taken once");

	autosave.Arm();
	autosave.Schedule(400);
	CHECK_MESSAGE(!autosave.Take_Armed(), "a completed save drops an armed request");
	CHECK_MESSAGE(!autosave.Is_Due(699), "a completed save pushes the next one a full interval out");
	CHECK_MESSAGE(autosave.Is_Due(700), "a completed save pushes the next one a full interval out");

	autosave.Set_Interval(0);
	autosave.Schedule(700);
	CHECK_MESSAGE(!autosave.Is_Due(100000), "turning the interval off stops the saves");

	autosave.Set_Interval(-5);
	CHECK_MESSAGE(autosave.Interval() == 0, "an interval below zero is off");

	autosave.Arm();
	autosave.Arm();
	CHECK_MESSAGE(autosave.Take_Armed(), "explicit requests coalesce with the timed interval disabled");
	CHECK_MESSAGE(!autosave.Take_Armed(), "explicit requests coalesce with the timed interval disabled");
	CHECK_MESSAGE(!autosave.Is_Due(100000), "an explicit request does not enable timed saves");
}


TEST_CASE("multiplayer saves are numbered in the pattern the client lists")
{
	CHECK_MESSAGE(Multiplayer_Save_File_Name(0) == "SVGM_000.NET", "the first multiplayer save is SVGM_000.NET");
	CHECK_MESSAGE(Multiplayer_Save_File_Name(MULTIPLAYER_SAVE_SLOTS - 1) == "SVGM_999.NET", "the last multiplayer save is SVGM_999.NET");
	CHECK_MESSAGE(Multiplayer_Save_Slot("SVGM_007.NET") == 7, "a numbered name yields its slot");
	CHECK_MESSAGE(Multiplayer_Save_Slot("svgm_007.net") == 7, "the pattern is matched in any case");
	CHECK_MESSAGE(Multiplayer_Save_Slot("SAVEGAME.NET") == -1, "the old fixed name is not a slot");
	CHECK_MESSAGE(Multiplayer_Save_Slot("SVGM_00A.NET") == -1, "a non-digit is refused");
	CHECK_MESSAGE(Multiplayer_Save_Slot("SVGM_0007.NET") == -1, "four digits are refused");
	CHECK_MESSAGE(Multiplayer_Save_Slot("SVGM_007.SAV") == -1, "another extension is refused");
	CHECK_MESSAGE(Multiplayer_Save_Slot("") == -1, "an empty or null name is refused");
	CHECK_MESSAGE(Multiplayer_Save_Slot(nullptr) == -1, "an empty or null name is refused");
}


// A quick save keeps one file per kind of game, so a skirmish never writes over a campaign.
TEST_CASE("a quick save keeps one file per kind of game")
{
	CHECK_MESSAGE(Quick_Save_File_Name(KindType::Campaign) == "QUICKSAVE.SAV", "the campaign quick save has one fixed name");
	CHECK_MESSAGE(Quick_Save_File_Name(KindType::Skirmish) == "QUICKSAVE_SKIRMISH.SAV", "the skirmish quick save keeps a file of its own");
}
