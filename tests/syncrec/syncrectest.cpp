/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "syncrec.h"

#include "doctest/doctest.h"

#include <cstdio>
#include <string>

// The core is engine-free, so its global instance is defined here for the harness rather than
// pulled in from _syncrec.cpp (which the engine build owns).
SyncRecorderClass SyncRecorder;

namespace {

char const * Stub_Describe(uint32_t rva)
{
	return((rva == 0x0012ab34) ? "FacingClass::Set()+0x2f [facing.cpp:131]" : nullptr);
}


// The caller context is process-wide, so each case sets its own and leaves none behind.
std::string Format_Caller(uint32_t base, char const * (* describe)(uint32_t), uint32_t rva)
{
	SyncCallerContextType context;
	context.MapImageBase = base;
	context.Describe = describe;
	Sync_Set_Caller_Context(context);

	char buffer[256];
	Sync_Format_Caller(buffer, sizeof(buffer), rva);

	context.MapImageBase = 0x00400000u;
	context.Describe = nullptr;
	Sync_Set_Caller_Context(context);
	return(buffer);
}

}


TEST_CASE("the history ring keeps at most its size, newest first, until a reset empties it")
{
	SyncHistoryClass<int, 8> ring;
	for (int i = 1; i <= 11; i++) {
		ring.Add(i);
	}
	CHECK(ring.Count() == 8);
	CHECK_MESSAGE(ring.Nth_Newest(0) == 11, "the newest entry is the last one added");
	CHECK_MESSAGE(ring.Nth_Newest(7) == 4, "the oldest kept entry is size-1 back");

	ring.Reset();
	CHECK(ring.Count() == 0);
}


TEST_CASE("printing the randoms honors the ring size cap")
{
	SyncRecorderClass rec;
	SyncRandomEntryType e {};
	for (int i = 0; i < 5000; i++) {
		e.Frame = i;
		rec.Add_Random(e);
	}

	std::FILE * fp = std::tmpfile();
	REQUIRE(fp != nullptr);
	SyncNamesType const names = {};
	rec.Print_Randoms(fp, names, 4096);

	std::rewind(fp);
	int data_lines = 0;
	char line[256];
	while (std::fgets(line, sizeof(line), fp) != nullptr) {
		if (line[0] == 'F') {
			data_lines++;
		}
	}
	std::fclose(fp);

	CHECK(data_lines == 4096);
}


TEST_CASE("an in-image caller shows its offset and the map address for the image base given")
{
	CHECK(Format_Caller(0x00400000u, nullptr, 0x0012ab34) == "+0012ab34 (map 0052ab34)");
	CHECK(Format_Caller(0x10000000u, nullptr, 0x0012ab34) == "+0012ab34 (map 1012ab34)");
}


TEST_CASE("an out-of-image caller is flagged extern")
{
	CHECK(Format_Caller(0x00400000u, nullptr, SYNC_CALLER_EXTERN | 0x1234).find("extern") != std::string::npos);
}


TEST_CASE("a named caller keeps its offset and gains the name, and an unnamed one falls back to the offset")
{
	CHECK(Format_Caller(0x00400000u, Stub_Describe, 0x0012ab34) == "+0012ab34 (map 0052ab34) FacingClass::Set()+0x2f [facing.cpp:131]");
	CHECK(Format_Caller(0x00400000u, Stub_Describe, 0x00005678) == "+00005678 (map 00405678)");
}


TEST_CASE("an unknown image base drops the map address rather than inventing one")
{
	CHECK(Format_Caller(0, Stub_Describe, 0x0012ab34) == "+0012ab34 FacingClass::Set()+0x2f [facing.cpp:131]");
}


TEST_CASE("a ranged draw sets the ranged flag until it ends")
{
	SyncRecorderClass rec;
	CHECK_FALSE(rec.In_Ranged_Draw());
	rec.Begin_Ranged_Draw();
	CHECK(rec.In_Ranged_Draw());
	rec.End_Ranged_Draw();
	CHECK_FALSE(rec.In_Ranged_Draw());
}


TEST_CASE("recording starts off, follows Set_Recording, and survives a reset")
{
	SyncRecorderClass rec;
	CHECK_FALSE(rec.Is_Recording());
	rec.Set_Recording(true);
	CHECK(rec.Is_Recording());
	rec.Reset();
	CHECK(rec.Is_Recording());
	rec.Set_Recording(false);
	CHECK_FALSE(rec.Is_Recording());
}
