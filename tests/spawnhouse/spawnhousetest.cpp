/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Pins the two spellings of a spawn house, with no engine and no game data: which names
// and numbers name a start position, which are refused, and what is written back.

#include <string>

#include "spawnhouse.h"

#include "doctest/doctest.h"

namespace {

constexpr char const * const SpawnSpelling[SPAWN_HOUSE_COUNT] = {
	"Spawn1", "Spawn2", "Spawn3", "Spawn4", "Spawn5", "Spawn6", "Spawn7", "Spawn8"
};

constexpr char const * const PlayerAtSpelling[SPAWN_HOUSE_COUNT] = {
	"<Player @ A>", "<Player @ B>", "<Player @ C>", "<Player @ D>",
	"<Player @ E>", "<Player @ F>", "<Player @ G>", "<Player @ H>"
};

}


TEST_CASE("Spawn1 to Spawn8 and <Player @ A> to <Player @ H> name positions 0 to 7")
{
	for (int spawn_waypoint = 0; spawn_waypoint < SPAWN_HOUSE_COUNT; spawn_waypoint++) {
		INFO("position ", spawn_waypoint);
		CHECK(Spawn_House_Waypoint(SpawnSpelling[spawn_waypoint]) == spawn_waypoint);
		CHECK(Spawn_House_Waypoint(PlayerAtSpelling[spawn_waypoint]) == spawn_waypoint);
	}
}


TEST_CASE("50 to 57 and 4475 to 4482 number positions 0 to 7")
{
	for (int spawn_waypoint = 0; spawn_waypoint < SPAWN_HOUSE_COUNT; spawn_waypoint++) {
		INFO("position ", spawn_waypoint);
		CHECK(Spawn_House_Waypoint(static_cast<HousesType>(50 + spawn_waypoint)) == spawn_waypoint);
		CHECK(Spawn_House_Waypoint(static_cast<HousesType>(4475 + spawn_waypoint)) == spawn_waypoint);
	}
}


TEST_CASE("either spelling is matched without regard to case")
{
	CHECK(Spawn_House_Waypoint("SPAWN3") == 2);
	CHECK(Spawn_House_Waypoint("<player @ c>") == 2);
}


TEST_CASE("the ends of both numeric ranges are spawn houses")
{
	CHECK(Spawn_House_Waypoint(HOUSE_SPAWN_FIRST) == 0);
	CHECK(Spawn_House_Waypoint(HOUSE_SPAWN_LAST) == SPAWN_HOUSE_COUNT - 1);
	CHECK(Spawn_House_Waypoint(HOUSE_PLAYER_AT_FIRST) == 0);
	CHECK(Spawn_House_Waypoint(HOUSE_PLAYER_AT_LAST) == SPAWN_HOUSE_COUNT - 1);
}


TEST_CASE("a name that is not one of the sixteen spellings names nothing")
{
	char const * const rejected[] = {
		"Spawn0", "Spawn9", "Spawn10", "Spawn 1", "Spawn1x", "Spawn", "<Player @ I>",
		"<Player @ A", "Player @ A", "<Player @A>", "GDI", "Neutral", ""
	};
	for (char const * name : rejected) {
		INFO("name \"", name, "\"");
		CHECK(Spawn_House_Waypoint(name) == -1);
	}
	CHECK(Spawn_House_Waypoint(nullptr) == -1);
}


TEST_CASE("a number just past either range, or a country, names nothing")
{
	int const numbers[] = { -1, 0, 1, 3, 49, 58, 59, 60, 4474, 4483 };
	for (int number : numbers) {
		INFO("number ", number);
		CHECK(Spawn_House_Waypoint(static_cast<HousesType>(number)) == -1);
	}
}


TEST_CASE("a position is written back as 50 plus its index and as its Spawn name, and reads back as itself")
{
	for (int spawn_waypoint = 0; spawn_waypoint < SPAWN_HOUSE_COUNT; spawn_waypoint++) {
		INFO("position ", spawn_waypoint);
		CHECK(Spawn_House_Type(spawn_waypoint) == static_cast<HousesType>(50 + spawn_waypoint));
		CHECK(Spawn_House_Waypoint(Spawn_House_Type(spawn_waypoint)) == spawn_waypoint);
		CHECK(Spawn_House_Waypoint(Spawn_House_Name(spawn_waypoint)) == spawn_waypoint);
	}
}


TEST_CASE("the written name is Spawn and the index plus one")
{
	CHECK(std::string(Spawn_House_Name(0)) == "Spawn1");
	CHECK(std::string(Spawn_House_Name(7)) == "Spawn8");
}


TEST_CASE("a start waypoint outside 0 to 7 has no number and no name")
{
	CHECK(Spawn_House_Type(-1) == HOUSE_NONE);
	CHECK(Spawn_House_Type(SPAWN_HOUSE_COUNT) == HOUSE_NONE);
	CHECK(Spawn_House_Name(-1) == nullptr);
	CHECK(Spawn_House_Name(SPAWN_HOUSE_COUNT) == nullptr);
}
