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

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>

namespace {

int Failures = 0;


void Check(bool condition, char const * what)
{
	std::printf("%-64s %s\n", what, condition ? "ok" : "FAILED");

	if (!condition) {
		Failures++;
	}
}


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


void Test_Layout(void)
{
	PacketClass stats;
	stats.Add_Field("OOSY", (unsigned char)1);
	stats.Add_Field("DURA", (unsigned int)0x01020304);
	stats.Add_Field("CRD0", (int)-5);
	stats.Add_Field("NAM0", "ab");
	unsigned char counts[8] = {0, 0, 0, 2, 0, 0, 0, 0x10};
	stats.Add_Field("UNB0", counts, (int)sizeof(counts));

	int size = 0;
	char * packet = stats.Create_Comms_Packet(size);

	// Fields leave in the reverse of the order they were added.
	unsigned char const expected[] = {
		0x00, 0x44, 0x00, 0x00,
		'U', 'N', 'B', '0', 0x00, 0x14, 0x00, 0x08, 0, 0, 0, 2, 0, 0, 0, 0x10,
		'N', 'A', 'M', '0', 0x00, 0x07, 0x00, 0x03, 'a', 'b', 0, 0,
		'C', 'R', 'D', '0', 0x00, 0x05, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0xFB,
		'D', 'U', 'R', 'A', 0x00, 0x06, 0x00, 0x04, 0x01, 0x02, 0x03, 0x04,
		'O', 'O', 'S', 'Y', 0x00, 0x02, 0x00, 0x01, 0x01, 0, 0, 0,
	};

	Check(size == (int)sizeof(expected), "the size counts the header, fields and padding");
	Check(size == (int)sizeof(expected) && std::memcmp(packet, expected, sizeof(expected)) == 0, "the bytes match the ladder layout");

	std::map<std::string, LadderField> fields = Ladder_Parse((unsigned char const *)packet, size);
	Check(fields.size() == 5, "the ladder reads every field");
	Check(fields["OOSY"].type == 2 && fields["OOSY"].data.size() == 1 && fields["OOSY"].data[0] == 1, "a flag is a one-byte boolean");
	Check(fields["DURA"].type == 6 && Ladder_U32(fields["DURA"]) == 0x01020304, "an unsigned value is big-endian");
	Check(fields["CRD0"].type == 5 && Ladder_U32(fields["CRD0"]) == 0xFFFFFFFBu, "a signed value is big-endian");
	Check(fields["NAM0"].type == 7 && fields["NAM0"].data.size() == 3 && fields["NAM0"].data[2] == 0, "a string carries its terminator");
	Check(fields["UNB0"].type == 20 && fields["UNB0"].data.size() == 8 && fields["UNB0"].data[3] == 2, "a chunk travels unswapped");

	// Building the packet swaps each field and swaps it back, so a second pass is identical.
	int again_size = 0;
	char * again = stats.Create_Comms_Packet(again_size);
	Check(again_size == size && std::memcmp(again, packet, size) == 0, "building twice gives the same bytes");
	delete [] again;

	PacketClass parsed(packet);
	unsigned char flag = 0;
	unsigned int duration = 0;
	int credits = 0;
	char name[8] = {};
	Check(parsed.Get_Field("OOSY", flag) && flag == 1, "a parsed flag reads back");
	Check(parsed.Get_Field("DURA", duration) && duration == 0x01020304, "a parsed unsigned value reads back");
	Check(parsed.Get_Field("CRD0", credits) && credits == -5, "a parsed signed value reads back");
	Check(parsed.Get_Field("NAM0", name) && std::strcmp(name, "ab") == 0, "a parsed string reads back");

	delete [] packet;
}


void Test_Empty_Chunk(void)
{
	PacketClass stats;
	stats.Add_Field("INB0", (void *)"", 0);

	int size = 0;
	char * packet = stats.Create_Comms_Packet(size);
	std::map<std::string, LadderField> fields = Ladder_Parse((unsigned char const *)packet, size);
	Check(size == 12, "an empty chunk is a bare field header");
	Check(fields.count("INB0") == 1 && fields["INB0"].data.empty(), "the ladder reads an empty chunk as no counts");
	delete [] packet;
}

}


int main(void)
{
	Test_Layout();
	Test_Empty_Chunk();
	return(Failures == 0 ? 0 : 1);
}
