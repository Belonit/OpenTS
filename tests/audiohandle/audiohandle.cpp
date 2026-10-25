/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Checks the audio handle's packing: the index and generation round-trip, the
// null value is distinct from every made handle, generations skip zero when they
// wrap, and the raw value is never negative as an int. Needs no game data.

#include "audio/audiohandle.h"

#include "doctest/doctest.h"


TEST_CASE("a default handle is null")
{
	AudioHandle handle;
	CHECK(handle.Is_Null());
	CHECK(handle.Raw() == 0u);
	CHECK(handle == AudioHandle());
}


TEST_CASE("index 0 with generation 1 is not null")
{
	CHECK_FALSE(AudioHandle::Make(0, 1).Is_Null());
}


TEST_CASE("clear makes a handle null")
{
	AudioHandle made = AudioHandle::Make(5, 9);
	made.Clear();
	CHECK(made.Is_Null());
}


TEST_CASE("index, generation, and raw value round-trip")
{
	for (unsigned index = 0; index <= AudioHandle::INDEX_MASK; index += 17) {
		for (unsigned generation = 1; generation <= AudioHandle::GENERATION_MASK; generation += 100003) {
			INFO("index ", index, ", generation ", generation);
			AudioHandle handle = AudioHandle::Make(index, generation);
			CHECK(handle.Index() == index);
			CHECK(handle.Generation() == generation);
			CHECK_MESSAGE((int)handle.Raw() >= 0, "the raw value is non-negative as an int");
			CHECK(AudioHandle::From_Raw(handle.Raw()) == handle);
		}
	}
}


TEST_CASE("extreme values round-trip and keep bit 31 clear")
{
	AudioHandle top = AudioHandle::Make(AudioHandle::INDEX_MASK, AudioHandle::GENERATION_MASK);
	CHECK(top.Index() == AudioHandle::INDEX_MASK);
	CHECK(top.Generation() == AudioHandle::GENERATION_MASK);
	CHECK((int)top.Raw() >= 0);
}


TEST_CASE("handles differ by index and by generation")
{
	CHECK(AudioHandle::Make(3, 4) != AudioHandle::Make(3, 5));
	CHECK(AudioHandle::Make(3, 4) != AudioHandle::Make(4, 4));
}


TEST_CASE("the index is masked")
{
	CHECK(AudioHandle::Make(300, 4) == AudioHandle::Make(300 & AudioHandle::INDEX_MASK, 4));
}


TEST_CASE("the generation advances, skips zero, and wraps")
{
	CHECK(AudioHandle::Next_Generation(1) == 2u);
	CHECK(AudioHandle::Next_Generation(0) == 1u);
	CHECK(AudioHandle::Next_Generation(AudioHandle::GENERATION_MASK) == 1u);
	CHECK(AudioHandle::Next_Generation(AudioHandle::GENERATION_MASK - 1) == AudioHandle::GENERATION_MASK);
}


TEST_CASE("a reused slot yields a different handle with the same index")
{
	unsigned generation = 1;
	AudioHandle first = AudioHandle::Make(7, generation);
	generation = AudioHandle::Next_Generation(generation);
	AudioHandle second = AudioHandle::Make(7, generation);
	CHECK(first != second);
	CHECK(first.Index() == second.Index());
}
