/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Pins the byte layout of the match statistics file against the way the CnCNet ladder reads
// it: a size and ID header, then tag, type, length, data and padding, all big-endian.

#include "packet.h"

#include "doctest/doctest.h"

#include <cstdint>
#include <cstring>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace {

struct LadderField
{
	unsigned type;
	std::vector<unsigned char> data;
};


unsigned Read_U16(unsigned char const * at)
{
	return((unsigned)(at[0] << 8 | at[1]));
}


// Reads the file as the ladder's processStatsDmp does: the header is skipped, and each field
// is an 8-byte header, its data, and zero padding to a multiple of four.
std::map<std::string, LadderField> Ladder_Parse(unsigned char const * buffer, int size)
{
	std::map<std::string, LadderField> fields;
	int offset = 4;
	while (offset + 8 <= size) {
		std::string tag((char const *)buffer + offset, 4);
		unsigned type = Read_U16(buffer + offset + 4);
		unsigned length = Read_U16(buffer + offset + 6);
		offset += 8;

		LadderField field;
		field.type = type;
		field.data.assign(buffer + offset, buffer + offset + length);
		fields[tag] = field;

		offset += (int)length;
		offset += (length % 4) ? 4 - (length % 4) : 0;
	}
	return(fields);
}


std::uint32_t Ladder_U32(LadderField const & field)
{
	return((std::uint32_t)field.data[0] << 24 | (std::uint32_t)field.data[1] << 16 | (std::uint32_t)field.data[2] << 8 | field.data[3]);
}


// A packet of one field of each kind, built into the file the ladder reads.
struct StatsFixture
{
	PacketClass stats;
	std::unique_ptr<char[]> packet;
	int size = 0;

	StatsFixture(void)
	{
		stats.Add_Field("OOSY", (unsigned char)1);
		stats.Add_Field("DURA", (unsigned int)0x01020304);
		stats.Add_Field("CRD0", (int)-5);
		stats.Add_Field("NAM0", "ab");
		unsigned char counts[8] = {0, 0, 0, 2, 0, 0, 0, 0x10};
		stats.Add_Field("UNB0", counts, (int)sizeof(counts));
		packet.reset(stats.Create_Comms_Packet(size));
	}

	std::map<std::string, LadderField> Fields(void) const { return(Ladder_Parse((unsigned char const *)packet.get(), size)); }
};

}


// Fields leave in the reverse of the order they were added.
TEST_CASE_FIXTURE(StatsFixture, "the file matches the ladder layout byte for byte, its size counting the header, fields and padding")
{
	unsigned char const expected[] = {
		0x00, 0x44, 0x00, 0x00,
		'U', 'N', 'B', '0', 0x00, 0x14, 0x00, 0x08, 0, 0, 0, 2, 0, 0, 0, 0x10,
		'N', 'A', 'M', '0', 0x00, 0x07, 0x00, 0x03, 'a', 'b', 0, 0,
		'C', 'R', 'D', '0', 0x00, 0x05, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0xFB,
		'D', 'U', 'R', 'A', 0x00, 0x06, 0x00, 0x04, 0x01, 0x02, 0x03, 0x04,
		'O', 'O', 'S', 'Y', 0x00, 0x02, 0x00, 0x01, 0x01, 0, 0, 0,
	};

	REQUIRE(size == (int)sizeof(expected));
	for (int i = 0; i < size; i++) {
		INFO("byte ", i);
		CHECK((unsigned char)packet[i] == expected[i]);
	}
}


TEST_CASE_FIXTURE(StatsFixture, "the ladder reads every field with its type")
{
	std::map<std::string, LadderField> fields = Fields();
	REQUIRE(fields.size() == 5u);

	CHECK_MESSAGE(fields["OOSY"].type == 2u, "a flag is a one-byte boolean");
	REQUIRE(fields["OOSY"].data.size() == 1u);
	CHECK(fields["OOSY"].data[0] == 1);

	CHECK_MESSAGE(fields["DURA"].type == 6u, "an unsigned value is big-endian");
	CHECK(Ladder_U32(fields["DURA"]) == 0x01020304u);

	CHECK_MESSAGE(fields["CRD0"].type == 5u, "a signed value is big-endian");
	CHECK(Ladder_U32(fields["CRD0"]) == 0xFFFFFFFBu);

	CHECK_MESSAGE(fields["NAM0"].type == 7u, "a string carries its terminator");
	REQUIRE(fields["NAM0"].data.size() == 3u);
	CHECK(fields["NAM0"].data[2] == 0);

	CHECK_MESSAGE(fields["UNB0"].type == 20u, "a chunk travels unswapped");
	REQUIRE(fields["UNB0"].data.size() == 8u);
	CHECK(fields["UNB0"].data[3] == 2);
}


// Building the packet swaps each field and swaps it back, so a second pass is identical.
TEST_CASE_FIXTURE(StatsFixture, "building the file twice gives the same bytes")
{
	int again_size = 0;
	std::unique_ptr<char[]> again(stats.Create_Comms_Packet(again_size));
	REQUIRE(again_size == size);
	CHECK(std::memcmp(again.get(), packet.get(), size) == 0);
}


TEST_CASE_FIXTURE(StatsFixture, "every field reads back from the parsed file")
{
	PacketClass parsed(packet.get());
	unsigned char flag = 0;
	unsigned int duration = 0;
	int credits = 0;
	char name[8] = {};
	REQUIRE(parsed.Get_Field("OOSY", flag));
	CHECK(flag == 1);
	REQUIRE(parsed.Get_Field("DURA", duration));
	CHECK(duration == 0x01020304u);
	REQUIRE(parsed.Get_Field("CRD0", credits));
	CHECK(credits == -5);
	REQUIRE(parsed.Get_Field("NAM0", name));
	CHECK(std::string(name) == "ab");
}


TEST_CASE("an empty chunk is a bare field header, which the ladder reads as no counts")
{
	PacketClass stats;
	stats.Add_Field("INB0", (void *)"", 0);

	int size = 0;
	std::unique_ptr<char[]> packet(stats.Create_Comms_Packet(size));
	std::map<std::string, LadderField> fields = Ladder_Parse((unsigned char const *)packet.get(), size);
	CHECK(size == 12);
	REQUIRE(fields.count("INB0") == 1u);
	CHECK(fields["INB0"].data.empty());
}
