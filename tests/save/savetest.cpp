// Exercises the file a saved game is kept in: the field table the load dialog lists from,
// the compressed content block, and every way the reader refuses a file that is not a
// whole, intact save of a version it knows.
//
// Every file it touches it creates itself, in the working directory, so it reads no game data,
// and each case deletes what it wrote.

#include "savefile.h"

#include "doctest/doctest.h"

#include <lzo/lzo1x.h>

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

static std::string Scratch;

static void Check_Result(char const * name, SaveFileClass::ResultType actual, SaveFileClass::ResultType expected)
{
	INFO(name, ": got \"", SaveFileClass::Result_Text(actual), "\", expected \"", SaveFileClass::Result_Text(expected), "\"");
	CHECK(actual == expected);
}


static std::string Scratch_Path(char const * name)
{
	return(Scratch + "\\" + name);
}


static std::vector<unsigned char> Noise(std::size_t length, unsigned int seed)
{
	std::vector<unsigned char> data(length);
	unsigned int state = seed * 2654435761u + 1u;
	for (std::size_t index = 0; index < length; index++) {
		state = state * 1103515245u + 12345u;
		data[index] = (unsigned char)((state >> 16) & 0xFF);
	}
	return(data);
}


static std::vector<unsigned char> Prose(std::size_t length)
{
	static char const text[] = "The quick brown fox jumps over the lazy dog. ";
	std::vector<unsigned char> data;
	while (data.size() < length) {
		data.push_back((unsigned char)text[data.size() % (sizeof(text) - 1)]);
	}
	return(data);
}


static std::vector<unsigned char> Read_Whole_File(char const * path)
{
	std::vector<unsigned char> data;
	HANDLE const file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, nullptr);
	if (file == INVALID_HANDLE_VALUE) return(data);
	DWORD const size = GetFileSize(file, nullptr);
	if (size != INVALID_FILE_SIZE && size > 0) {
		data.resize(size);
		DWORD got = 0;
		if (!ReadFile(file, data.data(), size, &got, nullptr) || got != size) data.clear();
	}
	CloseHandle(file);
	return(data);
}


static bool Write_Whole_File(char const * path, std::vector<unsigned char> const & data)
{
	HANDLE const file = CreateFileA(path, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, nullptr);
	if (file == INVALID_HANDLE_VALUE) return(false);
	DWORD written = 0;
	bool ok = true;
	if (!data.empty()) {
		ok = WriteFile(file, data.data(), (DWORD)data.size(), &written, nullptr) && written == data.size();
	}
	CloseHandle(file);
	return(ok);
}


static bool File_Exists(char const * path)
{
	HANDLE const file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, nullptr);
	if (file == INVALID_HANDLE_VALUE) return(false);
	CloseHandle(file);
	return(true);
}


enum {
	FIELD_TITLE = 2,
	FIELD_HOUSE = 3,
	FIELD_VERSION = 16,
	FIELD_WHEN = 13,
	FIELD_MISSING = 77,
};


static void Fill(SaveFileClass & save, std::vector<unsigned char> const & content)
{
	FILETIME when;
	when.dwLowDateTime = 0x12345678u;
	when.dwHighDateTime = 0x01D2C3B4u;

	save.Set_String(FIELD_TITLE, "GDI 04: Eviction Notice");
	save.Set_String(FIELD_HOUSE, "GDI");
	save.Set_Int(FIELD_VERSION, 0x00010203);
	save.Set_Time(FIELD_WHEN, when);
	save.Content = content;
}


static void Check_Fields(char const * prefix, SaveFileClass const & save)
{
	char text[64];
	int value = 0;
	FILETIME when = {};

	CHECK_MESSAGE(save.Get_String(FIELD_TITLE, text, sizeof(text)), (std::string(prefix) + ": title present"));
	CHECK_MESSAGE(strcmp(text, "GDI 04: Eviction Notice") == 0, (std::string(prefix) + ": title text"));
	CHECK_MESSAGE(save.Get_String(FIELD_HOUSE, text, sizeof(text)), (std::string(prefix) + ": house present"));
	CHECK_MESSAGE(strcmp(text, "GDI") == 0, (std::string(prefix) + ": house text"));
	CHECK_MESSAGE(save.Get_Int(FIELD_VERSION, &value), (std::string(prefix) + ": version present"));
	CHECK_MESSAGE(value == 0x00010203, (std::string(prefix) + ": version value"));
	CHECK_MESSAGE(save.Get_Time(FIELD_WHEN, &when), (std::string(prefix) + ": time present"));
	CHECK_MESSAGE(when.dwLowDateTime == 0x12345678u, (std::string(prefix) + ": time value"));
	CHECK_MESSAGE(when.dwHighDateTime == 0x01D2C3B4u, (std::string(prefix) + ": time value"));
	CHECK_MESSAGE(!save.Get_String(FIELD_MISSING, text, sizeof(text)), (std::string(prefix) + ": a missing field is absent"));
	CHECK_MESSAGE(!save.Get_Int(FIELD_TITLE, &value), (std::string(prefix) + ": a field is not found under another kind"));

	CHECK_MESSAGE(save.Get_String(FIELD_TITLE, text, 4), (std::string(prefix) + ": a short buffer is clipped"));
	CHECK_MESSAGE(strcmp(text, "GDI") == 0, (std::string(prefix) + ": a short buffer is clipped"));
}


// The files the cases write, deleted after each one.
static char const * const ScratchFiles[] = { "ROUNDTRIP.SAV", "NOISE.SAV", "EMPTY.SAV", "REPLACE.SAV",
	"LIMITS.SAV", "PLAIN.SAV", "GOOD.SAV", "DAMAGED.SAV" };


struct SaveFixture
{
	SaveFixture(void)
	{
		REQUIRE(lzo_init() == LZO_E_OK);
		Scratch = ".";
	}

	~SaveFixture(void)
	{
		for (char const * name : ScratchFiles) {
			DeleteFileA(Scratch_Path(name).c_str());
		}
	}
};


TEST_CASE_FIXTURE(SaveFixture, "a save round-trips its fields and compressed content, leaving no temporary file")
{
	std::string const path = Scratch_Path("ROUNDTRIP.SAV");
	std::vector<unsigned char> const content = Prose(300000);

	SaveFileClass written;
	Fill(written, content);
	Check_Result("round trip: write", written.Write(path.c_str()), SaveFileClass::RESULT_OK);
	CHECK_MESSAGE(!File_Exists((path + ".tmp").c_str()), "round trip: no temporary file is left behind");

	std::vector<unsigned char> const image = Read_Whole_File(path.c_str());
	REQUIRE_MESSAGE(!image.empty(), "round trip: the prose was compressed");
	CHECK_MESSAGE(image.size() < content.size() / 4, "round trip: the prose was compressed");

	SaveFileClass read;
	Check_Result("round trip: read", read.Read(path.c_str()), SaveFileClass::RESULT_OK);
	Check_Fields("round trip", read);
	CHECK_MESSAGE(read.Content == content, "round trip: content reads back whole");

	SaveFileClass listed;
	Check_Result("round trip: fields alone", listed.Read_Fields(path.c_str()), SaveFileClass::RESULT_OK);
	Check_Fields("fields alone", listed);
	CHECK_MESSAGE(listed.Content.empty(), "fields alone: no content is read");
}


TEST_CASE_FIXTURE(SaveFixture, "a field read into a short buffer is cut on a character boundary")
{
	SaveFileClass save;
	save.Set_String(FIELD_TITLE, "ab\xC3\xA9" "cd");

	char text[8];
	CHECK_MESSAGE(save.Get_String(FIELD_TITLE, text, 4), "cuts: a cut never splits a character");
	CHECK_MESSAGE(strcmp(text, "ab") == 0, "cuts: a cut never splits a character");
	CHECK_MESSAGE(save.Get_String(FIELD_TITLE, text, 5), "cuts: a cut after a character keeps it whole");
	CHECK_MESSAGE(strcmp(text, "ab\xC3\xA9") == 0, "cuts: a cut after a character keeps it whole");
	CHECK_MESSAGE(save.Get_String(FIELD_TITLE, text, 8), "cuts: a buffer that fits keeps everything");
	CHECK_MESSAGE(strcmp(text, "ab\xC3\xA9" "cd") == 0, "cuts: a buffer that fits keeps everything");
}


TEST_CASE_FIXTURE(SaveFixture, "content that does not compress is stored as it is and round-trips")
{
	std::string const path = Scratch_Path("NOISE.SAV");
	std::vector<unsigned char> const content = Noise(70000, 7);

	SaveFileClass written;
	Fill(written, content);
	Check_Result("noise: write", written.Write(path.c_str()), SaveFileClass::RESULT_OK);

	std::vector<unsigned char> const image = Read_Whole_File(path.c_str());
	CHECK_MESSAGE(image.size() >= content.size() + SaveFileClass::HEADER_SIZE, "noise: stored as it is when compression does not pay");

	SaveFileClass read;
	Check_Result("noise: read", read.Read(path.c_str()), SaveFileClass::RESULT_OK);
	CHECK_MESSAGE(read.Content == content, "noise: content reads back whole");
}


TEST_CASE_FIXTURE(SaveFixture, "a save with no content is a header alone")
{
	std::string const path = Scratch_Path("EMPTY.SAV");

	SaveFileClass written;
	Check_Result("empty: write", written.Write(path.c_str()), SaveFileClass::RESULT_OK);

	std::vector<unsigned char> const image = Read_Whole_File(path.c_str());
	CHECK_MESSAGE(image.size() == SaveFileClass::HEADER_SIZE, "empty: a header alone");

	SaveFileClass read;
	Check_Result("empty: read", read.Read(path.c_str()), SaveFileClass::RESULT_OK);
	CHECK_MESSAGE(read.Content.empty(), "empty: no content");
	char text[8];
	CHECK_MESSAGE(!read.Get_String(FIELD_TITLE, text, sizeof(text)), "empty: no fields");
}


TEST_CASE_FIXTURE(SaveFixture, "a save written over another replaces it whole, along with a stale temporary file")
{
	std::string const path = Scratch_Path("REPLACE.SAV");

	SaveFileClass first;
	Fill(first, Prose(5000));
	first.Set_String(FIELD_TITLE, "the earlier save");
	Check_Result("replace: first write", first.Write(path.c_str()), SaveFileClass::RESULT_OK);

	CHECK_MESSAGE(Write_Whole_File((path + ".tmp").c_str(), Noise(100, 3)), "replace: a stale temporary is planted");

	SaveFileClass second;
	Fill(second, Noise(20000, 11));
	second.Set_String(FIELD_TITLE, "the later save");
	Check_Result("replace: second write", second.Write(path.c_str()), SaveFileClass::RESULT_OK);
	CHECK_MESSAGE(!File_Exists((path + ".tmp").c_str()), "replace: the stale temporary is gone");

	SaveFileClass read;
	Check_Result("replace: read", read.Read(path.c_str()), SaveFileClass::RESULT_OK);
	char text[64];
	CHECK_MESSAGE(read.Get_String(FIELD_TITLE, text, sizeof(text)), "replace: the later save is the one on disk");
	CHECK_MESSAGE(strcmp(text, "the later save") == 0, "replace: the later save is the one on disk");
	CHECK_MESSAGE(read.Content == second.Content, "replace: the later content is the one on disk");

	SaveFileClass rewritten;
	rewritten.Set_String(FIELD_TITLE, "overwritten field");
	rewritten.Set_String(FIELD_TITLE, "final field");
	Check_Result("replace: field rewrite", rewritten.Write(path.c_str()), SaveFileClass::RESULT_OK);
	Check_Result("replace: field rewrite read", read.Read_Fields(path.c_str()), SaveFileClass::RESULT_OK);
	CHECK_MESSAGE(read.Get_String(FIELD_TITLE, text, sizeof(text)), "replace: a field set twice keeps the last value");
	CHECK_MESSAGE(strcmp(text, "final field") == 0, "replace: a field set twice keeps the last value");
}


static void Put_U32(std::vector<unsigned char> & image, std::size_t at, unsigned int value)
{
	image[at] = (unsigned char)(value & 0xFF);
	image[at + 1] = (unsigned char)((value >> 8) & 0xFF);
	image[at + 2] = (unsigned char)((value >> 16) & 0xFF);
	image[at + 3] = (unsigned char)((value >> 24) & 0xFF);
}


TEST_CASE_FIXTURE(SaveFixture, "a field, table or content beyond its limit is refused, and the earlier save stays")
{
	std::string const path = Scratch_Path("LIMITS.SAV");

	SaveFileClass kept;
	Fill(kept, Prose(3000));
	kept.Set_String(FIELD_TITLE, "the save that stays");
	Check_Result("limits: the save that stays", kept.Write(path.c_str()), SaveFileClass::RESULT_OK);

	SaveFileClass wide;
	Fill(wide, Prose(3000));
	wide.Set_String(FIELD_TITLE, std::string(0x10001, 'x').c_str());
	Check_Result("limits: a field beyond its limit is refused", wide.Write(path.c_str()), SaveFileClass::RESULT_TOO_LARGE);

	SaveFileClass many;
	Fill(many, Prose(3000));
	for (int id = 100; id < 117; id++) {
		many.Set_String(id, std::string(0x10000, 'y').c_str());
	}
	Check_Result("limits: a table beyond its limit is refused", many.Write(path.c_str()), SaveFileClass::RESULT_TOO_LARGE);

	SaveFileClass huge;
	huge.Content.resize(0x10000001);
	Check_Result("limits: content beyond its limit is refused", huge.Write(path.c_str()), SaveFileClass::RESULT_TOO_LARGE);

	CHECK_MESSAGE(!File_Exists((path + ".tmp").c_str()), "limits: no temporary is left behind");
	SaveFileClass read;
	Check_Result("limits: the earlier save still reads", read.Read(path.c_str()), SaveFileClass::RESULT_OK);
	char text[64];
	CHECK_MESSAGE(read.Get_String(FIELD_TITLE, text, sizeof(text)), "limits: the earlier save is the one on disk");
	CHECK_MESSAGE(strcmp(text, "the save that stays") == 0, "limits: the earlier save is the one on disk");
}


// Recomputes the header checksum after a test has changed a header byte on purpose.
static void Reseal_Header(std::vector<unsigned char> & image, unsigned int table)
{
	unsigned int crc = SaveFileClass::Checksum(image.data(), SaveFileClass::HEADER_SIZE - 4);
	crc = SaveFileClass::Checksum(image.data() + SaveFileClass::HEADER_SIZE, table, crc);
	Put_U32(image, 28, crc);
}


// Rebuilds a save image around a field table of the test's own making, with the content
// kept and every checksum made good.
static std::vector<unsigned char> Forge_Table(std::vector<unsigned char> const & image, unsigned int table,
	std::vector<unsigned char> const & newtable)
{
	std::vector<unsigned char> forged(image.begin(), image.begin() + SaveFileClass::HEADER_SIZE);
	forged.insert(forged.end(), newtable.begin(), newtable.end());
	forged.insert(forged.end(), image.begin() + SaveFileClass::HEADER_SIZE + table, image.end());
	Put_U32(forged, 8, (unsigned int)newtable.size());
	Put_U32(forged, 12, SaveFileClass::HEADER_SIZE + (unsigned int)newtable.size());
	Reseal_Header(forged, (unsigned int)newtable.size());
	return(forged);
}


// Replaces the content of a save image with a compressed block of the test's own making,
// declared as expanding to the length given, with every checksum made good.
static std::vector<unsigned char> Forge_Content(std::vector<unsigned char> const & image, unsigned int table,
	std::vector<unsigned char> const & stored, unsigned int expands_to)
{
	std::vector<unsigned char> forged(image.begin(), image.begin() + SaveFileClass::HEADER_SIZE + table);
	forged.insert(forged.end(), stored.begin(), stored.end());
	forged[6] |= 0x01;
	Put_U32(forged, 12, SaveFileClass::HEADER_SIZE + table);
	Put_U32(forged, 16, (unsigned int)stored.size());
	Put_U32(forged, 20, expands_to);
	Put_U32(forged, 24, SaveFileClass::Checksum(stored.data(), (unsigned int)stored.size()));
	Reseal_Header(forged, table);
	return(forged);
}


TEST_CASE_FIXTURE(SaveFixture, "the reader refuses a file that is missing, not a save, of a later version, or damaged anywhere")
{
	SaveFileClass read;

	std::string const missing = Scratch_Path("MISSING.SAV");
	Check_Result("refuse: a missing file", read.Read(missing.c_str()), SaveFileClass::RESULT_MISSING);
	Check_Result("refuse: a missing file's fields", read.Read_Fields(missing.c_str()), SaveFileClass::RESULT_MISSING);

	std::string const plain = Scratch_Path("PLAIN.SAV");
	std::vector<unsigned char> hello = { 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd' };
	Write_Whole_File(plain.c_str(), hello);
	Check_Result("refuse: a file that is not a save", read.Read(plain.c_str()), SaveFileClass::RESULT_NOT_A_SAVE);
	Check_Result("refuse: its fields", read.Read_Fields(plain.c_str()), SaveFileClass::RESULT_NOT_A_SAVE);

	std::string const good = Scratch_Path("GOOD.SAV");
	SaveFileClass written;
	Fill(written, Prose(40000));
	Check_Result("refuse: the reference save", written.Write(good.c_str()), SaveFileClass::RESULT_OK);
	std::vector<unsigned char> const image = Read_Whole_File(good.c_str());
	CHECK_MESSAGE(!image.empty(), "refuse: the reference save is readable");

	std::string const damaged = Scratch_Path("DAMAGED.SAV");

	unsigned int const table = (unsigned int)image[8] | ((unsigned int)image[9] << 8)
		| ((unsigned int)image[10] << 16) | ((unsigned int)image[11] << 24);

	std::vector<unsigned char> future = image;
	future[4] = 99;
	future[5] = 0;
	Reseal_Header(future, table);
	Write_Whole_File(damaged.c_str(), future);
	Check_Result("refuse: a later format version", read.Read(damaged.c_str()), SaveFileClass::RESULT_UNSUPPORTED_VERSION);
	Check_Result("refuse: its fields", read.Read_Fields(damaged.c_str()), SaveFileClass::RESULT_UNSUPPORTED_VERSION);

	std::vector<unsigned char> flagged = image;
	flagged[6] |= 0x02;
	Reseal_Header(flagged, table);
	Write_Whole_File(damaged.c_str(), flagged);
	Check_Result("refuse: a header flag this build does not know", read.Read(damaged.c_str()), SaveFileClass::RESULT_UNSUPPORTED_VERSION);
	Check_Result("refuse: its fields", read.Read_Fields(damaged.c_str()), SaveFileClass::RESULT_UNSUPPORTED_VERSION);

	unsigned int const content_offset = (unsigned int)image[12] | ((unsigned int)image[13] << 8)
		| ((unsigned int)image[14] << 16) | ((unsigned int)image[15] << 24);
	unsigned int const content_length = (unsigned int)image[20] | ((unsigned int)image[21] << 8)
		| ((unsigned int)image[22] << 16) | ((unsigned int)image[23] << 24);
	CHECK_MESSAGE((image[6] & 0x01) != 0, "refuse: the reference save is compressed");
	std::vector<unsigned char> const stored(image.begin() + content_offset, image.end());

	Write_Whole_File(damaged.c_str(), Forge_Content(image, table, stored, content_length + 1));
	Check_Result("refuse: a block that ends before its declared length", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);

	// The reader sizes the output buffer from the declared length, so this block runs past
	// the end of it. The bounds-checked decompressor stops there rather than writing on.
	Write_Whole_File(damaged.c_str(), Forge_Content(image, table, stored, content_length - 1));
	Check_Result("refuse: a block that expands past its declared length", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);

	Write_Whole_File(damaged.c_str(), Forge_Content(image, table, stored, 0x10000001));
	Check_Result("refuse: a block declared larger than any save", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);
	Check_Result("refuse: its fields", read.Read_Fields(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);

	std::vector<unsigned char> const oversized(0x100001, 0);
	Write_Whole_File(damaged.c_str(), Forge_Table(image, table, oversized));
	Check_Result("refuse: a field table longer than any listing", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);
	Check_Result("refuse: its fields", read.Read_Fields(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);

	std::vector<unsigned char> gapped = image;
	gapped.insert(gapped.begin() + content_offset, 8, 0);
	Put_U32(gapped, 12, content_offset + 8);
	Reseal_Header(gapped, table);
	CHECK_MESSAGE(gapped.size() == image.size() + 8, "refuse: the gapped image is longer");
	Write_Whole_File(damaged.c_str(), gapped);
	Check_Result("refuse: a gap between the table and the content", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);
	Check_Result("refuse: its fields", read.Read_Fields(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);

	std::vector<unsigned char> header_hit = image;
	header_hit[9] ^= 0x01;
	Write_Whole_File(damaged.c_str(), header_hit);
	Check_Result("refuse: a header byte flipped", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);
	Check_Result("refuse: its fields", read.Read_Fields(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);

	std::vector<unsigned char> table_hit = image;
	table_hit[SaveFileClass::HEADER_SIZE + 10] ^= 0x20;
	Write_Whole_File(damaged.c_str(), table_hit);
	Check_Result("refuse: a field byte flipped", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);
	Check_Result("refuse: its fields", read.Read_Fields(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);

	std::vector<unsigned char> content_hit = image;
	content_hit[image.size() - 40] ^= 0x80;
	Write_Whole_File(damaged.c_str(), content_hit);
	Check_Result("refuse: a content byte flipped", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);
	Check_Result("refuse: a flipped content byte still lists", read.Read_Fields(damaged.c_str()), SaveFileClass::RESULT_OK);

	std::size_t const cuts[] = { 3, 12, SaveFileClass::HEADER_SIZE - 1, SaveFileClass::HEADER_SIZE + 5,
		SaveFileClass::HEADER_SIZE + table, image.size() / 2, image.size() - 1 };
	for (std::size_t cut : cuts) {
		std::vector<unsigned char> truncated(image.begin(), image.begin() + cut);
		Write_Whole_File(damaged.c_str(), truncated);
		char name[80];
		snprintf(name, sizeof(name), "refuse: a file cut at %u bytes", (unsigned int)cut);
		SaveFileClass::ResultType const result = read.Read(damaged.c_str());
		CHECK_MESSAGE((result == SaveFileClass::RESULT_CORRUPT || (cut < 4 && result == SaveFileClass::RESULT_NOT_A_SAVE)), name);
	}

	std::vector<unsigned char> appended = image;
	appended.push_back(0);
	Write_Whole_File(damaged.c_str(), appended);
	Check_Result("refuse: a file with a trailing byte", read.Read(damaged.c_str()), SaveFileClass::RESULT_CORRUPT);
}
