/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Holds Shape_Facing_Index to the facing a shape cut into 8, 16, 32 or 64 facings draws from,
// and to the first facing for any other count. Needs no game data.

#include "face.h"

#include "doctest/doctest.h"

namespace {

// A direction pointing exactly at one index of a grid of the given size.
DirType At(int index, int count)
{
	return(DirType(index * (65536 / count)));
}

// What the eight facing path drew before any other count was drawn per facing.
int Legacy_Eight(DirType dir)
{
	return((int)((dir.Round_To_8() + 1) & 7));
}

int const Supported[] = {8, 16, 32, 64};

}


TEST_CASE("every facing lands on its own index, an eighth of a turn along, inside the range the artwork provides")
{
	for (int count : Supported) {
		for (int index = 0; index < count; index++) {
			INFO("cut into ", count, ", facing ", index);
			int drawn = Shape_Facing_Index(At(index, count), count);
			CHECK(drawn == (index + count / 8) % count);
			CHECK(drawn >= 0);
			CHECK(drawn < count);
		}
	}
}


TEST_CASE("northwest draws index zero, and north the index an eighth of a turn along")
{
	for (int count : Supported) {
		INFO("cut into ", count);
		CHECK(Shape_Facing_Index(At(count - count / 8, count), count) == 0);
		CHECK(Shape_Facing_Index(At(0, count), count) == count / 8);
	}
}


TEST_CASE("a direction between two grid points belongs to the nearer of them")
{
	for (int count : Supported) {
		INFO("cut into ", count);
		int step = 65536 / count;
		CHECK_MESSAGE(Shape_Facing_Index(DirType(step / 2 - 16), count) == Shape_Facing_Index(At(0, count), count),
			"a direction short of the halfway point keeps the index below it");
		CHECK_MESSAGE(Shape_Facing_Index(DirType(step / 2 + 16), count) == Shape_Facing_Index(At(1, count), count),
			"a direction past the halfway point takes the index above it");
	}
}


// The stock layout must come through untouched, whatever else the switch now admits.
TEST_CASE("the eight facing layout draws exactly the facing it always drew")
{
	for (int raw = 0; raw < 65536; raw += 7) {
		INFO("direction ", raw);
		CHECK(Shape_Facing_Index(DirType(raw), 8) == Legacy_Eight(DirType(raw)));
	}
}


// Anything else draws one facing, the way a vehicle declaring a single facing always has.
TEST_CASE("a count no artwork is cut into draws index zero whichever way the vehicle points")
{
	int const unsupported[] = {-8, -1, 0, 1, 2, 3, 4, 5, 6, 7, 9, 12, 15, 24, 31, 33, 48, 63, 65, 128, 256};
	for (int count : unsupported) {
		for (int raw = 0; raw < 65536; raw += 1021) {
			INFO("cut into ", count, ", direction ", raw);
			CHECK(Shape_Facing_Index(DirType(raw), count) == 0);
		}
	}
}


// A direction from a save can carry anything in the upper half, and the rounding reads it.
TEST_CASE("a direction carrying padding from a save still lands inside the range the artwork provides")
{
	for (int count : Supported) {
		for (int high = 1; high < 8; high++) {
			INFO("cut into ", count, ", padding ", high);
			DirType dir;
			dir.Raw = (high << 16) | 0x3FFF;
			int drawn = Shape_Facing_Index(dir, count);
			CHECK(drawn >= 0);
			CHECK(drawn < count);
		}
	}
}
