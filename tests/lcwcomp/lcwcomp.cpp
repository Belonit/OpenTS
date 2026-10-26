/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Holds LCW_Comp in lcw.cpp to the output recorded in lcwgolden.h. Those vectors match the
// inline assembly the function replaced, apart from the one byte blocks, which the assembly
// padded with a byte read past the source.
//
// Compressed blocks are written into save games, so the contract is the exact bytes emitted,
// not merely that they expand again correctly. Both are checked here. Needs no game data.

#include <cstring>

#include "lcw.h"

#include "lcwgolden.h"

#include "doctest/doctest.h"

namespace {

int const SRCMAX = 65536;
int const DSTMAX = 262144;

unsigned char Source[SRCMAX];
unsigned char Dest[DSTMAX];
unsigned char Roundtrip[SRCMAX * 2];

unsigned int Seed = 0;


unsigned int Next_Random(void)
{
	Seed = Seed * 1103515245u + 12345u;
	return(Seed >> 8);
}


unsigned long long Hash(unsigned char const * data, int size)
{
	unsigned long long hash = 1469598103934665603ULL;
	for (int i = 0; i < size; i++) {
		hash ^= (unsigned long long)data[i];
		hash *= 1099511628211ULL;
	}
	return(hash);
}


// Must reproduce the generator's inputs exactly or every vector misses.
void Fill_Source(int shape, unsigned int seed, int size)
{
	Seed = seed;

	for (int i = 0; i < size; i++) {
		switch (shape) {
			case 0:
				Source[i] = (unsigned char)(Next_Random() & 0xFF);
				break;

			case 1:
				Source[i] = 0x7E;
				break;

			case 2:
				Source[i] = (unsigned char)((i / 17) & 0xFF);
				break;

			case 3:
				Source[i] = (unsigned char)((Next_Random() % 4) == 0 ? (Next_Random() & 0xFF) : 0x20);
				break;

			case 4:
				Source[i] = (unsigned char)("OpenTS voxel terrain"[i % 20]);
				break;

			default:
				Source[i] = (unsigned char)((Next_Random() & 0x03) * 0x40);
				break;
		}
	}
}

}	// namespace


TEST_CASE("LCW compression matches the recorded vectors and round-trips")
{
	for (int i = 0; i < LcwCompGoldenCaseCount; i++) {
		LcwCompGoldenCase const & test = LcwCompGoldenCases[i];

		Fill_Source(test.Shape, test.Seed, test.Size);
		std::memset(Dest, 0xA5, sizeof(Dest));

		INFO("shape ", test.Shape, " size ", test.Size);
		int const packed = LCW_Comp(Source, Dest, test.Size);
		CHECK(packed == test.Compressed);
		if (packed == test.Compressed) {
			CHECK_MESSAGE(Hash(Dest, packed) == test.Hash, "the compressed bytes match the vectors");
		}

		std::memset(Roundtrip, 0, sizeof(Roundtrip));
		int const unpacked = LCW_Uncomp(Dest, Roundtrip, (unsigned long)test.Size);
		CHECK_MESSAGE(unpacked == test.Size, "the round trip returns every byte");
		CHECK_MESSAGE(std::memcmp(Roundtrip, Source, test.Size) == 0, "the round trip returns the source");
	}

}
