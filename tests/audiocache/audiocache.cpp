/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Exercises the sample cache: named lookups try the modded formats before AUD
// and remember the answer, pinned samples survive the budget while unpinned
// ones leave oldest first, blobs are keyed by their whole contents so a
// refilled buffer misses, and a sample too large for the cache is refused.
// Needs no game data.

#include "audio/audiosample.h"
#include "audio/audiodecode.h"

#include "doctest/doctest.h"

#include <cctype>
#include <cstring>
#include <map>
#include <string>

namespace {

void Append(std::vector<uint8_t> & blob, void const * data, size_t size)
{
	uint8_t const * bytes = (uint8_t const *)data;
	blob.insert(blob.end(), bytes, bytes + size);
}


// A raw 16-bit mono AUD holding `frames` frames of the given fill value.
std::vector<uint8_t> Make_Aud(unsigned frames, int16_t fill, unsigned rate = 22050)
{
	AUDHeaderType header;
	header.Rate = (uint16_t)rate;
	header.Size = (int32_t)(frames * 2);
	header.UncompSize = header.Size;
	header.Flags = AUD_FLAG_16BIT;
	header.Compression = AUD_CODEC_PCM;
	std::vector<uint8_t> blob;
	Append(blob, &header, sizeof(header));
	for (unsigned i = 0; i < frames; i++) {
		Append(blob, &fill, sizeof(fill));
	}
	return(blob);
}


std::vector<uint8_t> Make_Wav(unsigned frames, int16_t fill, unsigned rate)
{
	std::vector<uint8_t> wav;
	uint32_t datasize = frames * 2;
	uint32_t riffsize = 36 + datasize;
	Append(wav, "RIFF", 4);
	Append(wav, &riffsize, 4);
	Append(wav, "WAVEfmt ", 8);
	uint32_t fmtsize = 16;
	uint16_t format = 1;
	uint16_t channels = 1;
	uint32_t byterate = rate * 2;
	uint16_t align = 2;
	uint16_t bits = 16;
	Append(wav, &fmtsize, 4);
	Append(wav, &format, 2);
	Append(wav, &channels, 2);
	Append(wav, &rate, 4);
	Append(wav, &byterate, 4);
	Append(wav, &align, 2);
	Append(wav, &bits, 2);
	Append(wav, "data", 4);
	Append(wav, &datasize, 4);
	for (unsigned i = 0; i < frames; i++) {
		Append(wav, &fill, sizeof(fill));
	}
	return(wav);
}


class MemoryReaderClass : public AudioAssetReaderClass
{
	public:
		std::map<std::string, std::vector<uint8_t>> Files;
		int Reads = 0;

		// Case-insensitive, like the game's file layer.
		bool Read(char const * filename, std::vector<uint8_t> & bytes) override
		{
			Reads++;
			std::string upper(filename);
			for (char & c : upper) {
				c = (char)std::toupper((unsigned char)c);
			}
			auto it = Files.find(upper);
			if (it == Files.end()) {
				return(false);
			}
			bytes = it->second;
			return(true);
		}
};


// A reader holding a sample in two formats, one only as AUD, and one that does not decode.
struct NamedFixture
{
	MemoryReaderClass reader;
	AudioSampleCacheClass cache;

	NamedFixture(void)
	{
		reader.Files["BOTH.WAV"] = Make_Wav(50, 7, 44100);
		reader.Files["BOTH.AUD"] = Make_Aud(80, 9);
		reader.Files["ONLYAUD.AUD"] = Make_Aud(30, 3);
		reader.Files["BROKEN.AUD"] = std::vector<uint8_t>(5, 0);
	}
};


size_t const SampleBytes = 100 * sizeof(int16_t);

}


TEST_CASE_FIXTURE(NamedFixture, "a named sample with two formats loads the WAV, reading only that file")
{
	AudioSampleClass * both = cache.Acquire_Named("both", reader);
	REQUIRE(both != nullptr);
	CHECK(both->Frames == 50u);
	CHECK(both->Rate == 44100u);
	CHECK(both->Data()[0] == 7);
	CHECK(reader.Reads == 1);
}


TEST_CASE_FIXTURE(NamedFixture, "a second acquire returns the cached sample, pins it again, and does not re-read it")
{
	AudioSampleClass * both = cache.Acquire_Named("both", reader);
	REQUIRE(both != nullptr);

	AudioSampleClass * again = cache.Acquire_Named("BOTH", reader);
	CHECK(again == both);
	CHECK(both->PinCount == 2);
	CHECK(reader.Reads == 1);
}


TEST_CASE_FIXTURE(NamedFixture, "an AUD-only sample is found after every other extension is probed once")
{
	AudioSampleClass * onlyaud = cache.Acquire_Named("onlyaud", reader);
	REQUIRE(onlyaud != nullptr);
	CHECK(onlyaud->Frames == 30u);
	CHECK(onlyaud->Data()[0] == 3);
	CHECK(reader.Reads == 5);
}


TEST_CASE_FIXTURE(NamedFixture, "a missing sample is probed once and stays null")
{
	CHECK(cache.Acquire_Named("missing", reader) == nullptr);
	CHECK(reader.Reads == 5);
	CHECK(cache.Acquire_Named("missing", reader) == nullptr);
	CHECK_MESSAGE(reader.Reads == 5, "it is not probed again");
}


TEST_CASE_FIXTURE(NamedFixture, "a sample that does not decode returns null")
{
	CHECK(cache.Acquire_Named("broken", reader) == nullptr);
}


TEST_CASE_FIXTURE(NamedFixture, "a flush with nothing pinned empties the cache and forgets which extension a name resolved to")
{
	AudioSampleClass * onlyaud = cache.Acquire_Named("onlyaud", reader);
	REQUIRE(onlyaud != nullptr);
	cache.Release(onlyaud);

	CHECK(cache.Flush() == 0u);
	CHECK(cache.Count() == 0u);
	CHECK(cache.Bytes() == 0u);

	reader.Reads = 0;
	onlyaud = cache.Acquire_Named("onlyaud", reader);
	CHECK_MESSAGE(onlyaud != nullptr, "the flushed sample reloads");
	CHECK(reader.Reads == 5);
	cache.Release(onlyaud);
}


TEST_CASE_FIXTURE(NamedFixture, "an empty name returns null")
{
	CHECK(cache.Acquire_Named("", reader) == nullptr);
}


TEST_CASE("over budget, the least recently used unpinned sample leaves first")
{
	std::vector<uint8_t> a = Make_Aud(100, 1);
	std::vector<uint8_t> b = Make_Aud(100, 2);
	std::vector<uint8_t> c = Make_Aud(100, 3);
	std::vector<uint8_t> d = Make_Aud(100, 4);
	AudioSampleCacheClass cache(SampleBytes * 3, SampleBytes * 10);

	AudioSampleClass * sa = cache.Acquire_Blob(a.data(), a.size());
	AudioSampleClass * sb = cache.Acquire_Blob(b.data(), b.size());
	AudioSampleClass * sc = cache.Acquire_Blob(c.data(), c.size());
	REQUIRE(sa != nullptr);
	REQUIRE(sb != nullptr);
	REQUIRE(sc != nullptr);
	CHECK_MESSAGE(cache.Bytes() == SampleBytes * 3, "three samples fit the budget");

	uint64_t keya = sa->Key;
	uint64_t keyb = sb->Key;
	cache.Release(sa);
	cache.Release(sb);

	AudioSampleClass * sd = cache.Acquire_Blob(d.data(), d.size());
	CHECK_MESSAGE(sd != nullptr, "a fourth sample loads over budget");
	CHECK_MESSAGE(cache.Count() == 3u, "one sample was evicted to make room");
	CHECK_FALSE(cache.Is_Cached(keya));
	CHECK(cache.Is_Cached(keyb));

	cache.Release(sc);
	cache.Release(sd);
}


// Pinned samples are never evicted, even when that leaves the cache over budget.
TEST_CASE("pinned samples stay over budget until they are released")
{
	std::vector<uint8_t> a = Make_Aud(100, 1);
	std::vector<uint8_t> b = Make_Aud(100, 2);
	std::vector<uint8_t> c = Make_Aud(100, 3);
	std::vector<uint8_t> d = Make_Aud(100, 4);
	AudioSampleCacheClass cache(SampleBytes * 3, SampleBytes * 10);

	AudioSampleClass * pa = cache.Acquire_Blob(a.data(), a.size());
	AudioSampleClass * pb = cache.Acquire_Blob(b.data(), b.size());
	AudioSampleClass * pc = cache.Acquire_Blob(c.data(), c.size());
	AudioSampleClass * pd = cache.Acquire_Blob(d.data(), d.size());
	REQUIRE(pa != nullptr);
	REQUIRE(pb != nullptr);
	REQUIRE(pc != nullptr);
	REQUIRE(pd != nullptr);
	CHECK(cache.Count() == 4u);
	CHECK(cache.Bytes() == SampleBytes * 4);
	CHECK_MESSAGE(cache.Flush() == 4u, "a flush reports the pinned samples it kept");

	cache.Release(pa);
	CHECK_MESSAGE(cache.Count() == 3u, "releasing under pressure evicts at once");
	cache.Release(pb);
	cache.Release(pc);
	cache.Release(pd);
	CHECK_MESSAGE(cache.Count() == 3u, "releases below the budget evict nothing more");
}


TEST_CASE("blobs are keyed by their whole contents")
{
	AudioSampleCacheClass cache;
	std::vector<uint8_t> first = Make_Aud(200, 5);
	std::vector<uint8_t> second = Make_Aud(200, 5);
	second[second.size() - 2] = 0x12;
	second[second.size() - 1] = 0x34;
	REQUIRE(first.size() == second.size());
	REQUIRE(std::memcmp(first.data(), second.data(), 64) == 0);

	AudioSampleClass * sfirst = cache.Acquire_Blob(first.data(), first.size());
	AudioSampleClass * ssecond = cache.Acquire_Blob(second.data(), second.size());
	REQUIRE(sfirst != nullptr);
	REQUIRE(ssecond != nullptr);
	CHECK_MESSAGE(sfirst != ssecond, "blobs differing only in their tail get different entries");
	CHECK_MESSAGE(ssecond->Data()[199] == 0x3412, "the differing tail is what decoded");

	AudioSampleClass * same = cache.Acquire_Blob(first.data(), first.size());
	CHECK_MESSAGE(same == sfirst, "the same blob hits its entry");
	CHECK(sfirst->PinCount == 2);

	cache.Release(sfirst);
	cache.Release(same);
	cache.Release(ssecond);
}


// The same buffer refilled with a different sample must not replay the old one.
TEST_CASE("a refilled buffer decodes its new contents")
{
	AudioSampleCacheClass cache;
	std::vector<uint8_t> buffer = Make_Aud(150, 11);
	AudioSampleClass * before = cache.Acquire_Blob(buffer.data(), 0);
	REQUIRE_MESSAGE(before != nullptr, "size zero trusts the header");
	CHECK(before->Frames == 150u);
	CHECK(before->Data()[0] == 11);
	cache.Release(before);

	std::vector<uint8_t> replacement = Make_Aud(150, 22);
	std::memcpy(buffer.data(), replacement.data(), replacement.size());
	AudioSampleClass * after = cache.Acquire_Blob(buffer.data(), 0);
	REQUIRE(after != nullptr);
	CHECK(after != before);
	CHECK(after->Data()[0] == 22);
	cache.Release(after);
}


TEST_CASE("invalidating a buffer drops its unpinned entries and keeps pinned ones")
{
	AudioSampleCacheClass cache;
	std::vector<uint8_t> first = Make_Aud(200, 5);
	AudioSampleClass * pinned = cache.Acquire_Blob(first.data(), first.size());
	REQUIRE(pinned != nullptr);

	std::vector<uint8_t> buffer = Make_Aud(150, 11);
	cache.Release(cache.Acquire_Blob(buffer.data(), 0));
	std::vector<uint8_t> replacement = Make_Aud(150, 22);
	std::memcpy(buffer.data(), replacement.data(), replacement.size());
	cache.Release(cache.Acquire_Blob(buffer.data(), 0));

	unsigned count = cache.Count();
	cache.Invalidate_Blob(buffer.data());
	CHECK(cache.Count() < count);
	CHECK(cache.Is_Cached(pinned->Key));

	cache.Release(pinned);
}


TEST_CASE("a blob that is no sample returns null")
{
	AudioSampleCacheClass cache;
	CHECK_MESSAGE(cache.Acquire_Blob(nullptr, 0) == nullptr, "a null blob");
	std::vector<uint8_t> junk(40, 0xEE);
	CHECK_MESSAGE(cache.Acquire_Blob(junk.data(), junk.size()) == nullptr, "a blob without a valid header");
	std::vector<uint8_t> first = Make_Aud(200, 5);
	CHECK_MESSAGE(cache.Acquire_Blob(first.data(), 20) == nullptr, "a blob smaller than its header claims");
}


TEST_CASE("a sample above the per-sample cap is refused, and one under it loads")
{
	AudioSampleCacheClass cache(1u << 20, 100);
	std::vector<uint8_t> big = Make_Aud(100, 1);
	CHECK(cache.Acquire_Blob(big.data(), big.size()) == nullptr);

	std::vector<uint8_t> small = Make_Aud(40, 1);
	AudioSampleClass * sample = cache.Acquire_Blob(small.data(), small.size());
	CHECK(sample != nullptr);
	cache.Release(sample);
}


TEST_CASE("releasing null is harmless")
{
	AudioSampleCacheClass cache(1u << 20, 100);
	std::vector<uint8_t> small = Make_Aud(40, 1);
	cache.Release(cache.Acquire_Blob(small.data(), small.size()));
	cache.Release(nullptr);
	CHECK(cache.Count() == 1u);
}
