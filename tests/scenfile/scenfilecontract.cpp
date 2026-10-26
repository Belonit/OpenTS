/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Pins what the scenario reader relies on from the file holder: a name is matched without
// regard to case and only while bytes are held, a new file replaces the old one, and a file
// with no bytes or a clear empties it.

#include <cstring>
#include <string>
#include <vector>

#include "scenfile.h"

#include "doctest/doctest.h"

namespace {

std::vector<char> Bytes_Of(char const * text)
{
	return(std::vector<char>(text, text + std::strlen(text)));
}

}


TEST_CASE("a holder with nothing in it answers for no name at all")
{
	ScenarioFileClass file;

	CHECK_MESSAGE(!file.Is_Present(), "a fresh holder holds nothing");
	CHECK_MESSAGE(file.Size() == 0, "and has no bytes");
	CHECK_MESSAGE(!file.Matches("SPAWNMAP.INI"), "an empty holder matches no name");
	CHECK_MESSAGE(!file.Matches(NULL), "a null name never matches");
}


// The name is matched the way the game names files, without regard to case, and the bytes come
// back exactly as they were read.
TEST_CASE("the name is matched the way the game names files, without regard to case")
{
	ScenarioFileClass file;
	file.Assign("spawnmap.ini", Bytes_Of("[Basic]\nName=One\n"));

	CHECK_MESSAGE(file.Is_Present(), "an assigned file is present");
	CHECK_MESSAGE(file.Matches("spawnmap.ini"), "the name is matched as given");
	CHECK_MESSAGE(file.Matches("SPAWNMAP.INI"), "the name is matched without regard to case");
	CHECK_MESSAGE(!file.Matches("SPAWNMAP.MAP"), "another name misses");
	CHECK_MESSAGE(!file.Matches(NULL), "a null name misses a held file too");
	CHECK_MESSAGE(std::string(file.Name()) == "spawnmap.ini", "the name is kept as given");
	CHECK_MESSAGE(std::string(file.Data(), file.Size()) == "[Basic]\nName=One\n", "the bytes are kept as read");
}


// A new file replaces the old one outright; nothing of the old name or bytes remains.
TEST_CASE("a new file replaces the old one outright")
{
	ScenarioFileClass file;
	file.Assign("GDI1A.MAP", Bytes_Of("one"));
	file.Assign("GDI2A.MAP", Bytes_Of("second"));

	CHECK_MESSAGE(!file.Matches("GDI1A.MAP"), "a new file replaces the old name");
	CHECK_MESSAGE(file.Matches("GDI2A.MAP"), "and the old bytes");
	CHECK_MESSAGE(file.Size() == 6, "and the old bytes");
}


TEST_CASE("a file with no bytes, or a clear, leaves the holder as it began")
{
	ScenarioFileClass file;
	file.Assign("GDI1A.MAP", Bytes_Of("one"));
	file.Assign("GDI2A.MAP", std::vector<char>());

	CHECK_MESSAGE(!file.Is_Present(), "a file with no bytes clears the holder");
	CHECK_MESSAGE(!file.Matches("GDI2A.MAP"), "a file with no bytes clears the holder");

	file.Assign("GDI1A.MAP", Bytes_Of("one"));
	file.Clear();

	CHECK_MESSAGE(!file.Is_Present(), "clearing empties it");
	CHECK_MESSAGE(!file.Matches("GDI1A.MAP"), "clearing empties it");
	CHECK_MESSAGE(file.Size() == 0, "clearing empties it");
}
