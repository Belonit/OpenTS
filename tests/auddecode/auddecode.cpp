/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Checks the AUD reader against the codecs it wraps: SOS chunks decode to what
// the codec produces when called directly with the same running state, the
// Westwood delta codec matches hand-built streams and refuses malformed ones,
// raw samples convert to 16-bit, the header rules hold, a bad chunk ends the
// sample cleanly, the chunk-at-a-time path equals the whole decode, and a WAV
// decodes through miniaudio. Needs no game data.

#include "audio/audiodecode.h"
#include "soscomp.h"

#include "doctest/doctest.h"

#include <algorithm>
#include <cstring>
#include <vector>

namespace {

unsigned int Seed = 12345;


// Every case draws the same random bytes whether it runs alone or after the others.
struct Fixture
{
	Fixture(void) { Seed = 12345; }
};


unsigned int Next_Random(void)
{
	Seed = Seed * 1103515245u + 12345u;
	return(Seed >> 8);
}


void Append(std::vector<uint8_t> & blob, void const * data, size_t size)
{
	uint8_t const * bytes = (uint8_t const *)data;
	blob.insert(blob.end(), bytes, bytes + size);
}


std::vector<uint8_t> Make_Header(unsigned rate, unsigned flags, unsigned codec, int size, int uncompsize)
{
	AUDHeaderType header;
	header.Rate = (uint16_t)rate;
	header.Size = size;
	header.UncompSize = uncompsize;
	header.Flags = (uint8_t)flags;
	header.Compression = (uint8_t)codec;
	std::vector<uint8_t> blob;
	Append(blob, &header, sizeof(header));
	return(blob);
}


void Append_Chunk(std::vector<uint8_t> & blob, std::vector<uint8_t> const & payload, unsigned uncompsize, uint32_t magic = AUD_CHUNK_MAGIC)
{
	AUDChunkHeaderType chunk;
	chunk.CompSize = (uint16_t)payload.size();
	chunk.UncompSize = (uint16_t)uncompsize;
	chunk.Magic = magic;
	Append(blob, &chunk, sizeof(chunk));
	Append(blob, payload.data(), payload.size());
}


void Patch_Size(std::vector<uint8_t> & blob)
{
	int32_t size = (int32_t)(blob.size() - sizeof(AUDHeaderType));
	std::memcpy(&blob[2], &size, sizeof(size));
}


std::vector<uint8_t> Random_Bytes(unsigned count)
{
	std::vector<uint8_t> bytes(count);
	for (unsigned i = 0; i < count; i++) {
		bytes[i] = (uint8_t)(Next_Random() & 0xFF);
	}
	return(bytes);
}


int16_t Widen(unsigned char value)
{
	return((int16_t)(((int)value - 128) << 8));
}


// Decodes the same chunks straight through the codec, keeping one stream state
// across them, and converts the output the way the reader does.
std::vector<int16_t> Reference_Sos(std::vector<std::vector<uint8_t>> const & chunks, std::vector<unsigned> const & sizes, unsigned channels, unsigned bits, int totalcomp)
{
	SosCompressInfo info;
	std::memset(&info, 0, sizeof(info));
	info.ChannelCount = (short)channels;
	info.BitSize = (short)bits;
	info.CompSize = totalcomp;
	info.UnCompSize = totalcomp * (bits / 4);
	bool fast = (bits == 16 && channels == 1);
	if (fast) {
		sosCODECInitStream(&info);
	} else {
		General_sosCODECInitStream(&info);
	}

	std::vector<int16_t> out;
	std::vector<unsigned char> native(AUD_MAX_CHUNK_UNCOMP_BYTES);
	for (size_t i = 0; i < chunks.size(); i++) {
		info.Source = (char *)chunks[i].data();
		info.Dest = (char *)native.data();
		if (fast) {
			sosCODECDecompressData(&info, sizes[i]);
		} else {
			General_sosCODECDecompressData(&info, sizes[i]);
		}
		if (bits == 16) {
			int16_t const * samples = (int16_t const *)native.data();
			out.insert(out.end(), samples, samples + sizes[i] / 2);
		} else {
			for (unsigned b = 0; b < sizes[i]; b++) {
				out.push_back(Widen(native[b]));
			}
		}
	}
	return(out);
}


// Six random SOS chunks in an AUD file, with the samples the codec gives for them.
struct SosStream
{
	unsigned Channels;
	std::vector<std::vector<uint8_t>> Chunks;
	std::vector<unsigned> Sizes;
	std::vector<uint8_t> Blob;
	std::vector<int16_t> Expect;
	AUDHeaderType Header;

	SosStream(unsigned channels, unsigned bits) :
		Channels(channels)
	{
		unsigned ratio = bits / 4;
		int totalcomp = 0;
		for (int i = 0; i < 6; i++) {
			unsigned comp = 256 + (Next_Random() % 400);
			comp -= comp % 4;
			Chunks.push_back(Random_Bytes(comp));
			Sizes.push_back(comp * ratio);
			totalcomp += comp;
		}

		Blob = Make_Header(22050, (channels == 2 ? AUD_FLAG_STEREO : 0) | (bits == 16 ? AUD_FLAG_16BIT : 0), AUD_CODEC_SOS, 0, 0);
		for (size_t i = 0; i < Chunks.size(); i++) {
			Append_Chunk(Blob, Chunks[i], Sizes[i]);
		}
		Patch_Size(Blob);
		int32_t uncomp = (int32_t)(totalcomp * ratio);
		std::memcpy(&Blob[6], &uncomp, sizeof(uncomp));

		Expect = Reference_Sos(Chunks, Sizes, channels, bits, totalcomp);
		REQUIRE_MESSAGE(Aud_Read_Header(Blob.data(), Blob.size(), Header), "the header reads");
	}

	unsigned Expected_Frames(void) const { return((unsigned)(Expect.size() / Channels)); }
};


void Check_Sos(unsigned channels, unsigned bits)
{
	SosStream stream(channels, bits);

	SUBCASE("the frame capacity bounds the decoded size, overshooting by no more than the chunk headers")
	{
		unsigned capacity = Aud_Frame_Capacity(stream.Header);
		CHECK(capacity >= stream.Expected_Frames());
		CHECK(capacity <= stream.Expected_Frames() + (unsigned)(stream.Chunks.size() * sizeof(AUDChunkHeaderType)) * 4);
	}

	SUBCASE("the reader decodes every chunk to the codec's own output and writes nothing more")
	{
		unsigned capacity = Aud_Frame_Capacity(stream.Header);
		std::vector<int16_t> out(capacity * channels + 16, (int16_t)0x5A5A);
		AudioPcmFormat format;
		unsigned frames = Aud_Decode(stream.Blob.data(), stream.Blob.size(), out.data(), capacity, format);
		CHECK(frames == stream.Expected_Frames());
		CHECK(format.Rate == 22050u);
		CHECK(format.Channels == channels);
		CHECK(std::equal(stream.Expect.begin(), stream.Expect.end(), out.begin()));
		CHECK(out[stream.Expect.size()] == (int16_t)0x5A5A);
	}

	SUBCASE("a chunk-at-a-time decode equals the whole decode")
	{
		AudChunkDecoderClass decoder;
		decoder.Init(stream.Header);
		std::vector<int16_t> piecewise;
		std::vector<int16_t> piece(decoder.Max_Chunk_Frames() * channels);
		for (size_t i = 0; i < stream.Chunks.size(); i++) {
			INFO("chunk ", i);
			unsigned produced = decoder.Decode_Chunk(stream.Chunks[i].data(), (unsigned)stream.Chunks[i].size(), stream.Sizes[i], piece.data(), decoder.Max_Chunk_Frames());
			CHECK(produced == stream.Sizes[i] / (channels * bits / 8));
			piecewise.insert(piecewise.end(), piece.begin(), piece.begin() + (size_t)produced * channels);
		}
		CHECK(piecewise == stream.Expect);
	}

	SUBCASE("rewinding restarts the codec, so the first chunk decodes the same again")
	{
		AudChunkDecoderClass decoder;
		decoder.Init(stream.Header);
		std::vector<int16_t> piece(decoder.Max_Chunk_Frames() * channels);
		for (size_t i = 0; i < stream.Chunks.size(); i++) {
			decoder.Decode_Chunk(stream.Chunks[i].data(), (unsigned)stream.Chunks[i].size(), stream.Sizes[i], piece.data(), decoder.Max_Chunk_Frames());
		}

		decoder.Rewind();
		unsigned produced = decoder.Decode_Chunk(stream.Chunks[0].data(), (unsigned)stream.Chunks[0].size(), stream.Sizes[0], piece.data(), decoder.Max_Chunk_Frames());
		REQUIRE(produced > 0u);
		CHECK(std::equal(piece.begin(), piece.begin() + (size_t)produced * channels, stream.Expect.begin()));
	}
}


// silence x4, raw 10 20 30, four 2-bit deltas, two 4-bit deltas, one embedded 5-bit delta.
uint8_t const DeltaStream[] = {
	0xC3,
	0x82, 10, 20, 30,
	0x00, 0x4E,
	0x40, 0x8F,
	0xBE
};
unsigned char const DeltaExpect[] = {128, 128, 128, 128, 10, 20, 30, 30, 31, 29, 28, 36, 36, 34};

uint8_t const ClampStream[] = {0x80, 0x01, 0x00, 0x00};
unsigned char const ClampExpect[] = {1, 0, 0, 0, 0};

}


TEST_CASE_FIXTURE(Fixture, "SOS 16-bit mono chunks decode through the reader") { Check_Sos(1, 16); }
TEST_CASE_FIXTURE(Fixture, "SOS 16-bit stereo chunks decode through the reader") { Check_Sos(2, 16); }
TEST_CASE_FIXTURE(Fixture, "SOS 8-bit mono chunks decode through the reader") { Check_Sos(1, 8); }
TEST_CASE_FIXTURE(Fixture, "SOS 8-bit stereo chunks decode through the reader") { Check_Sos(2, 8); }


TEST_CASE_FIXTURE(Fixture, "an uncompressed SOS chunk is copied as is")
{
	std::vector<uint8_t> payload = Random_Bytes(512);
	std::vector<uint8_t> blob = Make_Header(22050, AUD_FLAG_16BIT, AUD_CODEC_SOS, 0, 0);
	Append_Chunk(blob, payload, 512);
	Patch_Size(blob);

	std::vector<int16_t> out(512);
	AudioPcmFormat format;
	unsigned frames = Aud_Decode(blob.data(), blob.size(), out.data(), 512, format);
	CHECK(frames == 256u);
	CHECK(std::memcmp(out.data(), payload.data(), 512) == 0);
}


TEST_CASE("raw 8-bit samples widen around silence and stay inside their frames")
{
	std::vector<uint8_t> blob = Make_Header(11025, 0, AUD_CODEC_PCM, 0, 0);
	uint8_t samples[6] = {0, 128, 255, 64, 192, 1};
	Append(blob, samples, sizeof(samples));
	Patch_Size(blob);

	std::vector<int16_t> out(16, (int16_t)0x7777);
	AudioPcmFormat format;
	unsigned frames = Aud_Decode(blob.data(), blob.size(), out.data(), 16, format);
	CHECK(frames == 6u);
	CHECK(format.Rate == 11025u);
	CHECK(format.Channels == 1u);
	CHECK(out[0] == -32768);
	CHECK(out[1] == 0);
	CHECK(out[2] == 32512);
	CHECK(out[3] == -16384);
	CHECK(out[6] == (int16_t)0x7777);
}


TEST_CASE("raw 16-bit stereo samples pass through, clamped to the capacity")
{
	std::vector<uint8_t> stereo = Make_Header(44100, AUD_FLAG_STEREO | AUD_FLAG_16BIT, AUD_CODEC_PCM, 0, 0);
	int16_t pairs[8] = {1, -1, 2, -2, 3, -3, 4, -4};
	Append(stereo, pairs, sizeof(pairs));
	Patch_Size(stereo);

	std::vector<int16_t> out(16, (int16_t)0x7777);
	AudioPcmFormat format;
	unsigned frames = Aud_Decode(stereo.data(), stereo.size(), out.data(), 16, format);
	CHECK(frames == 4u);
	CHECK(format.Channels == 2u);
	CHECK(format.Rate == 44100u);
	CHECK(std::memcmp(out.data(), pairs, sizeof(pairs)) == 0);

	frames = Aud_Decode(stereo.data(), stereo.size(), out.data(), 2, format);
	CHECK_MESSAGE(frames == 2u, "the decode clamps to the capacity");
}


TEST_CASE("a hand-built Westwood delta stream decodes to the expected samples")
{
	unsigned char out[32];
	REQUIRE(Aud_Decode_Westwood(DeltaStream, sizeof(DeltaStream), out, sizeof(DeltaExpect)));
	CHECK(std::memcmp(out, DeltaExpect, sizeof(DeltaExpect)) == 0);
}


TEST_CASE("Westwood deltas clamp at zero")
{
	unsigned char out[32];
	REQUIRE(Aud_Decode_Westwood(ClampStream, sizeof(ClampStream), out, sizeof(ClampExpect)));
	CHECK(std::memcmp(out, ClampExpect, sizeof(ClampExpect)) == 0);
}


TEST_CASE("a malformed Westwood delta stream fails")
{
	unsigned char out[32];
	CHECK_MESSAGE(!Aud_Decode_Westwood(DeltaStream, sizeof(DeltaStream), out, sizeof(DeltaExpect) + 1), "asking for more output than the stream holds");
	CHECK_MESSAGE(!Aud_Decode_Westwood(DeltaStream, 3, out, sizeof(DeltaExpect)), "a truncated stream");
	uint8_t overrun[] = {0xBF};
	CHECK_MESSAGE(!Aud_Decode_Westwood(overrun, sizeof(overrun), out, 4), "a run past the output");
}


// The VQA loader decodes a frame in place from the end of its buffer.
TEST_CASE("a Westwood delta stream decodes in place from the end of the buffer")
{
	unsigned char inplace[64];
	std::memcpy(inplace + sizeof(inplace) - sizeof(DeltaStream), DeltaStream, sizeof(DeltaStream));
	REQUIRE(Aud_Decode_Westwood(inplace + sizeof(inplace) - sizeof(DeltaStream), sizeof(DeltaStream), inplace, sizeof(DeltaExpect)));
	CHECK(std::memcmp(inplace, DeltaExpect, sizeof(DeltaExpect)) == 0);
}


TEST_CASE("a chunked codec 1 file decodes every chunk, widening like raw 8-bit samples")
{
	std::vector<uint8_t> blob = Make_Header(22050, 0, AUD_CODEC_WESTWOOD, 0, 0);
	Append_Chunk(blob, std::vector<uint8_t>(DeltaStream, DeltaStream + sizeof(DeltaStream)), sizeof(DeltaExpect));
	Append_Chunk(blob, std::vector<uint8_t>(ClampStream, ClampStream + sizeof(ClampStream)), sizeof(ClampExpect));
	Patch_Size(blob);
	int32_t uncomp = sizeof(DeltaExpect) + sizeof(ClampExpect);
	std::memcpy(&blob[6], &uncomp, sizeof(uncomp));

	std::vector<int16_t> pcm(64);
	AudioPcmFormat format;
	unsigned frames = Aud_Decode(blob.data(), blob.size(), pcm.data(), 64, format);
	REQUIRE(frames == (unsigned)uncomp);
	for (unsigned i = 0; i < sizeof(DeltaExpect); i++) {
		INFO("sample ", i);
		CHECK(pcm[i] == Widen(DeltaExpect[i]));
	}
	for (unsigned i = 0; i < sizeof(ClampExpect); i++) {
		INFO("sample ", sizeof(DeltaExpect) + i);
		CHECK(pcm[sizeof(DeltaExpect) + i] == Widen(ClampExpect[i]));
	}
}


TEST_CASE("rates near 22050 play at 22050, and others are left alone")
{
	AUDHeaderType header;
	std::vector<uint8_t> blob = Make_Header(22000, AUD_FLAG_16BIT, AUD_CODEC_SOS, 100, 400);
	blob.resize(sizeof(AUDHeaderType) + 100);
	REQUIRE(Aud_Read_Header(blob.data(), blob.size(), header));

	CHECK_MESSAGE(Aud_Playback_Rate(header) == 22050u, "just under");
	header.Rate = 23999;
	CHECK_MESSAGE(Aud_Playback_Rate(header) == 22050u, "just over");
	header.Rate = 44100;
	CHECK(Aud_Playback_Rate(header) == 44100u);
	header.Rate = 20000;
	CHECK(Aud_Playback_Rate(header) == 20000u);
}


TEST_CASE("the blob size and frame capacity follow the header")
{
	AUDHeaderType header;
	std::vector<uint8_t> blob = Make_Header(22000, AUD_FLAG_16BIT, AUD_CODEC_SOS, 100, 400);
	blob.resize(sizeof(AUDHeaderType) + 100);
	REQUIRE(Aud_Read_Header(blob.data(), blob.size(), header));

	CHECK(Aud_Blob_Bytes(header) == sizeof(AUDHeaderType) + 100);
	CHECK_MESSAGE(Aud_Frame_Capacity(header) == 200u, "SOS 16-bit holds four samples per byte");
}


TEST_CASE("a blob shorter than its header claims is rejected, and size zero trusts the header")
{
	AUDHeaderType header;
	std::vector<uint8_t> blob = Make_Header(22000, AUD_FLAG_16BIT, AUD_CODEC_SOS, 100, 400);
	blob.resize(sizeof(AUDHeaderType) + 100);
	CHECK_FALSE(Aud_Read_Header(blob.data(), blob.size() - 1, header));
	CHECK(Aud_Read_Header(blob.data(), 0, header));
}


TEST_CASE("a header the reader cannot play is rejected")
{
	AUDHeaderType header;
	std::vector<uint8_t> bad = Make_Header(22050, AUD_FLAG_16BIT, 33, 100, 400);
	CHECK_MESSAGE(!Aud_Read_Header(bad.data(), 0, header), "an unknown codec");
	bad = Make_Header(22050, 4, AUD_CODEC_SOS, 100, 400);
	CHECK_MESSAGE(!Aud_Read_Header(bad.data(), 0, header), "unknown flag bits");
	bad = Make_Header(22050, AUD_FLAG_16BIT, AUD_CODEC_WESTWOOD, 100, 400);
	CHECK_MESSAGE(!Aud_Read_Header(bad.data(), 0, header), "a 16-bit delta file");
	bad = Make_Header(22050, 0, AUD_CODEC_PCM, 0, 0);
	CHECK_MESSAGE(!Aud_Read_Header(bad.data(), 0, header), "an empty file");
	CHECK_MESSAGE(!Aud_Read_Header(nullptr, 0, header), "null data");
	CHECK_MESSAGE(!Aud_Read_Header(bad.data(), 4, header), "a fragment shorter than a header");
}


TEST_CASE_FIXTURE(Fixture, "a bad chunk magic ends the sample after the good chunks, writing nothing past them")
{
	std::vector<uint8_t> good = Random_Bytes(256);
	std::vector<uint8_t> blob = Make_Header(22050, AUD_FLAG_16BIT, AUD_CODEC_SOS, 0, 0);
	Append_Chunk(blob, good, 1024);
	Append_Chunk(blob, good, 1024);
	Append_Chunk(blob, good, 1024, 0xBEEF);
	Append_Chunk(blob, good, 1024);
	Patch_Size(blob);

	std::vector<int16_t> out(4096, (int16_t)0x1111);
	AudioPcmFormat format;
	CHECK(Aud_Decode(blob.data(), blob.size(), out.data(), 4096, format) == 1024u);
	CHECK(out[1024] == (int16_t)0x1111);
}


TEST_CASE_FIXTURE(Fixture, "an oversize chunk ends the sample")
{
	std::vector<uint8_t> good = Random_Bytes(256);
	std::vector<uint8_t> blob = Make_Header(22050, AUD_FLAG_16BIT, AUD_CODEC_SOS, 0, 0);
	Append_Chunk(blob, good, 1024);
	Append_Chunk(blob, good, AUD_MAX_CHUNK_UNCOMP_BYTES + 4);
	Patch_Size(blob);

	std::vector<int16_t> out(4096);
	AudioPcmFormat format;
	CHECK(Aud_Decode(blob.data(), blob.size(), out.data(), 4096, format) == 512u);
}


TEST_CASE_FIXTURE(Fixture, "an oversize compressed chunk decodes nothing")
{
	std::vector<uint8_t> big = Random_Bytes(AUD_MAX_CHUNK_COMP_BYTES + 4);
	std::vector<uint8_t> blob = Make_Header(22050, AUD_FLAG_16BIT, AUD_CODEC_SOS, 0, 0);
	Append_Chunk(blob, big, 2048);
	Patch_Size(blob);

	std::vector<int16_t> out(4096);
	AudioPcmFormat format;
	CHECK(Aud_Decode(blob.data(), blob.size(), out.data(), 4096, format) == 0u);
}


TEST_CASE_FIXTURE(Fixture, "a blob shorter than its header claims decodes nothing")
{
	std::vector<uint8_t> good = Random_Bytes(256);
	std::vector<uint8_t> blob = Make_Header(22050, AUD_FLAG_16BIT, AUD_CODEC_SOS, 0, 0);
	Append_Chunk(blob, good, 1024);
	Append_Chunk(blob, good, 1024);
	Patch_Size(blob);
	blob.resize(blob.size() - 100);

	std::vector<int16_t> out(4096);
	AudioPcmFormat format;
	CHECK(Aud_Decode(blob.data(), blob.size(), out.data(), 4096, format) == 0u);
}


// The header is honest about the blob, but the last chunk claims more than is left.
TEST_CASE_FIXTURE(Fixture, "a chunk claiming more than the blob holds ends the sample")
{
	std::vector<uint8_t> good = Random_Bytes(256);
	std::vector<uint8_t> blob = Make_Header(22050, AUD_FLAG_16BIT, AUD_CODEC_SOS, 0, 0);
	Append_Chunk(blob, good, 1024);
	size_t lastchunk = blob.size();
	Append_Chunk(blob, good, 1024);
	Patch_Size(blob);
	uint16_t claimed = 5000;
	std::memcpy(&blob[lastchunk], &claimed, sizeof(claimed));

	std::vector<int16_t> out(4096);
	AudioPcmFormat format;
	CHECK(Aud_Decode(blob.data(), blob.size(), out.data(), 4096, format) == 512u);
}


TEST_CASE_FIXTURE(Fixture, "a chunk that does not fit the capacity is not started")
{
	std::vector<uint8_t> good = Random_Bytes(256);
	std::vector<uint8_t> blob = Make_Header(22050, AUD_FLAG_16BIT, AUD_CODEC_SOS, 0, 0);
	Append_Chunk(blob, good, 1024);
	Append_Chunk(blob, good, 1024);
	Patch_Size(blob);

	std::vector<int16_t> out(4096);
	AudioPcmFormat format;
	CHECK(Aud_Decode(blob.data(), blob.size(), out.data(), 700, format) == 512u);
}


TEST_CASE("a WAV decodes through miniaudio, its samples passing through")
{
	int16_t samples[100];
	for (int i = 0; i < 100; i++) {
		samples[i] = (int16_t)(i * 300 - 15000);
	}
	std::vector<uint8_t> wav;
	uint32_t datasize = sizeof(samples);
	uint32_t riffsize = 36 + datasize;
	Append(wav, "RIFF", 4);
	Append(wav, &riffsize, 4);
	Append(wav, "WAVEfmt ", 8);
	uint32_t fmtsize = 16;
	uint16_t format = 1;
	uint16_t channels = 1;
	uint32_t rate = 22050;
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
	Append(wav, samples, sizeof(samples));

	std::vector<int16_t> out;
	AudioPcmFormat info;
	REQUIRE(Audio_Decode_Other(wav.data(), wav.size(), out, info));
	CHECK(info.Rate == 22050u);
	CHECK(info.Channels == 1u);
	REQUIRE(out.size() == 100u);
	CHECK(std::memcmp(out.data(), samples, sizeof(samples)) == 0);
}


TEST_CASE_FIXTURE(Fixture, "random bytes are not a known format")
{
	std::vector<uint8_t> junk = Random_Bytes(300);
	std::vector<int16_t> out;
	AudioPcmFormat info;
	CHECK_FALSE(Audio_Decode_Other(junk.data(), junk.size(), out, info));
}
