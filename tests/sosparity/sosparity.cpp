/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Holds the SOS ADPCM decoders in soscodec.cpp to the output the assembly they replaced
// produced. The vectors in sosgolden.h were recorded from that assembly before it was
// removed; this replays each one and compares the decoded bytes and the stream state left
// behind. Needs no game data.

#include <cstring>

#include "soscomp.h"
#include "vqalib/cmp.h"

#include "sosgolden.h"

#include "doctest/doctest.h"

namespace {

int const SRCMAX = 8192;
int const DSTMAX = 65536;
unsigned char const GUARD = 0xA5;

unsigned char SourceStore[SRCMAX + 16];
unsigned char DestStore[DSTMAX];

unsigned int Seed = 0;


unsigned int Next_Random(void)
{
	Seed = Seed * 1103515245u + 12345u;
	return(Seed >> 8);
}


// Must reproduce the generator's pattern exactly or every vector misses.
void Fill_Source(unsigned int seed)
{
	Seed = seed;
	for (int i = 0; i < SRCMAX + 16; i++) {
		SourceStore[i] = (unsigned char)(Next_Random() & 0xFF);
	}
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


unsigned long long Dest_Hash(int bytes)
{
	return(Hash(DestStore, bytes + 64));
}


void Check_Value(char const * what, long long expected, long long got)
{
	CHECK_MESSAGE(got == expected, what);
}


void Run_Case(SosGoldenCase const & test)
{
	char const * name = "sosCODEC";
	if (test.Codec == 1) {
		name = "General_sosCODEC";
	} else if (test.Codec == 2) {
		name = "VQA_sosCODEC";
	}
	INFO(name, " ", test.BitSize, " bit ", test.Channels, " channel ", test.Bytes, " bytes align ", test.SourceAlign);

	Fill_Source(test.Seed);
	std::memset(DestStore, GUARD, sizeof(DestStore));

	if (test.Codec == 2) {
		_VQA_SOS_COMPRESS_INFO info;
		std::memset(&info, 0, sizeof(info));
		VQA_sosCODECInitStream(&info);

		VQA_sosCODECDecompressData(SourceStore, DestStore, (unsigned short)test.BitSize, (unsigned short)test.Channels, (unsigned long)test.Bytes, &info);

		Check_Value("hash", (long long)test.Hash, (long long)Dest_Hash(test.Bytes));
		Check_Value("predicted", test.Predicted, info.dwPredicted);
		Check_Value("index", test.Index, info.wIndex);
		Check_Value("predicted2", test.Predicted2, info.dwPredicted2);
		Check_Value("index2", test.Index2, info.wIndex2);
		return;
	}

	SosCompressInfo info;
	std::memset(&info, 0, sizeof(info));
	info.BitSize = (short)test.BitSize;
	info.ChannelCount = (short)test.Channels;

	if (test.Codec == 0) {
		sosCODECInitStream(&info);
	} else {
		General_sosCODECInitStream(&info);
	}

	info.BitSize = (short)test.BitSize;
	info.ChannelCount = (short)test.Channels;
	info.Source = (char *)(SourceStore + test.SourceAlign);
	info.Dest = (char *)DestStore;

	unsigned long returned = 0;

	if (test.Codec == 0) {
		returned = sosCODECDecompressData(&info, (unsigned long)test.Bytes);
	} else {
		returned = General_sosCODECDecompressData(&info, (unsigned long)test.Bytes);
	}

	Check_Value("hash", (long long)test.Hash, (long long)Dest_Hash(test.Bytes));
	Check_Value("return", (long long)test.Returned, (long long)returned);
	Check_Value("predicted", test.Predicted, info.Channels[0].Predicted);
	Check_Value("index", test.Index, info.Channels[0].Index);
	Check_Value("predicted2", test.Predicted2, info.Channels[1].Predicted);
	Check_Value("index2", test.Index2, info.Channels[1].Index);
}

}	// namespace


TEST_CASE("SOS ADPCM decode matches the recorded assembly, in the bytes and the stream state left behind")
{
	for (int i = 0; i < SosGoldenCaseCount; i++) {
		Run_Case(SosGoldenCases[i]);
	}
}


// The assembly's countdown was tested only after being decremented, so these requests never
// reached zero and ran away through both buffers. They must now decode nothing and return.
TEST_CASE("a request the assembly's countdown ran away on decodes nothing and returns")
{
	int const bits[] = {8, 8, 16, 16, 8, 16};
	int const channels[] = {1, 2, 1, 2, 2, 2};
	int const bytes[] = {0, 0, 0, 0, 3, 2};

	for (int i = 0; i < 6; i++) {
		Fill_Source(999u);
		std::memset(DestStore, GUARD, sizeof(DestStore));

		SosCompressInfo info;
		std::memset(&info, 0, sizeof(info));
		info.BitSize = (short)bits[i];
		info.ChannelCount = (short)channels[i];
		General_sosCODECInitStream(&info);
		info.BitSize = (short)bits[i];
		info.ChannelCount = (short)channels[i];
		info.Source = (char *)SourceStore;
		info.Dest = (char *)DestStore;

		General_sosCODECDecompressData(&info, (unsigned long)bytes[i]);

		bool untouched = true;
		for (int b = 0; b < 256; b++) {
			if (DestStore[b] != GUARD) {
				untouched = false;
				break;
			}
		}

		INFO("General_sosCODEC ", bits[i], " bit ", channels[i], " channel ", bytes[i], " bytes");
		CHECK_MESSAGE(untouched, "the destination is untouched");
	}
}
