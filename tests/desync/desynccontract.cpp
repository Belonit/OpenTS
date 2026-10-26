/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Exercises the out-of-sync bookkeeping and the pending multiplayer load without the engine.

#include "desync.h"
#include "mpload.h"

#include "doctest/doctest.h"

#include <string>


TEST_CASE("nobody is silent when the dialog opens, and a heartbeat pushes the timeout out")
{
	DesyncClass desync;
	desync.Begin(1000);
	CHECK_MESSAGE(!desync.Is_Silent(2, 1000 + DesyncClass::HEARTBEAT_TIMEOUT_MS), "a house is not silent at the timeout");
	CHECK_MESSAGE(desync.Is_Silent(2, 1000 + DesyncClass::HEARTBEAT_TIMEOUT_MS + 1), "a house is silent past the timeout");

	desync.Heard(2, 20000);
	CHECK(!desync.Is_Silent(2, 20000 + DesyncClass::HEARTBEAT_TIMEOUT_MS));
	CHECK_MESSAGE(desync.Is_Silent(3, 20000 + DesyncClass::HEARTBEAT_TIMEOUT_MS), "another house keeps its own clock");
}


TEST_CASE("a house outside the table is never silent")
{
	DesyncClass desync;
	desync.Begin(1000);
	CHECK_FALSE(desync.Is_Silent(8, 999999));
	CHECK_FALSE(desync.Is_Silent(-1, 999999));
}


TEST_CASE("the first heartbeat is due at once and the next one an interval later")
{
	DesyncClass desync;
	desync.Begin(5000);
	CHECK(desync.Heartbeat_Is_Due(5000));
	desync.Heartbeat_Sent(5000);
	CHECK_MESSAGE(!desync.Heartbeat_Is_Due(5000 + DesyncClass::HEARTBEAT_INTERVAL_MS - 1), "no heartbeat inside the interval");
	CHECK(desync.Heartbeat_Is_Due(5000 + DesyncClass::HEARTBEAT_INTERVAL_MS));
}


TEST_CASE("a departed player's name survives an empty name, and Begin forgets it")
{
	DesyncClass desync;
	desync.Begin(0);
	desync.Mark_Left(4, "Rampa");
	CHECK(desync.Has_Left(4));
	CHECK(std::string(desync.Left_Name(4)) == "Rampa");

	desync.Mark_Left(4, "");
	CHECK_MESSAGE(std::string(desync.Left_Name(4)) == "Rampa", "an empty name does not replace the kept one");

	desync.Begin(1);
	CHECK_FALSE(desync.Has_Left(4));
	CHECK(desync.Left_Name(4)[0] == '\0');
}


TEST_CASE("an unmarked house has not left, and one outside the table has no name")
{
	DesyncClass desync;
	desync.Begin(0);
	CHECK_FALSE(desync.Has_Left(1));
	CHECK(std::string(desync.Left_Name(9)).empty());
}


TEST_CASE("only a slot the numbered saves can hold may be requested")
{
	CHECK(MultiplayerLoadClass::Slot_Is_Valid(0));
	CHECK(MultiplayerLoadClass::Slot_Is_Valid(MULTIPLAYER_SAVE_SLOTS - 1));
	CHECK_FALSE(MultiplayerLoadClass::Slot_Is_Valid(MULTIPLAYER_SAVE_SLOTS));
	CHECK_FALSE(MultiplayerLoadClass::Slot_Is_Valid(-1));
}


TEST_CASE("nothing is pending at first")
{
	MultiplayerLoadClass load;
	CHECK_FALSE(load.Is_Pending());
	CHECK(load.Seconds_Left(0) == 0);
	CHECK(load.Slot() == -1);
}


TEST_CASE("only a valid slot can be scheduled, and only one load can be pending")
{
	MultiplayerLoadClass load;
	CHECK_FALSE(load.Schedule(-1, 100));
	REQUIRE(load.Schedule(3, 100));
	CHECK(load.Is_Pending());
	CHECK(load.Slot() == 3);
	CHECK_FALSE(load.Schedule(4, 200));
	CHECK_MESSAGE(load.Slot() == 3, "the refused request changes nothing");
}


TEST_CASE("a load is due a countdown after it is scheduled, showing at least one second while pending")
{
	MultiplayerLoadClass load;
	REQUIRE(load.Schedule(3, 100));
	CHECK_FALSE(load.Is_Due(100 + MultiplayerLoadClass::COUNTDOWN_MS - 1));
	CHECK(load.Is_Due(100 + MultiplayerLoadClass::COUNTDOWN_MS));
	CHECK(load.Seconds_Left(100) == 5);
	CHECK(load.Seconds_Left(100 + 1) == 5);
	CHECK(load.Seconds_Left(100 + 4001) == 1);
	CHECK(load.Seconds_Left(100 + MultiplayerLoadClass::COUNTDOWN_MS) == 1);
	CHECK_MESSAGE(load.Seconds_Left(100 + MultiplayerLoadClass::COUNTDOWN_MS + 5000) == 1, "never below one when overdue");
}


TEST_CASE("Clear ends the pending load, and a load can be scheduled again")
{
	MultiplayerLoadClass load;
	REQUIRE(load.Schedule(3, 100));
	load.Clear();
	CHECK_FALSE(load.Is_Pending());
	CHECK(load.Slot() == -1);
	CHECK(load.Schedule(4, 300));
}
