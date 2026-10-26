/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Exercises the single-producer, single-consumer rings the audio engine hands
// commands and PCM through: capacity limits, wrap-around, partial reads, the
// frame counters, and sequence integrity with a producer and a consumer thread.
// Needs no game data.

#include "audio/audioring.h"

#include "doctest/doctest.h"

#include <thread>
#include <vector>

namespace {

struct Item {
	uint32_t Sequence;
	uint32_t Payload;
};


int16_t Frames[2 * 128];


// A ring of 128 stereo frames, with Frames holding the values 0 to 255 to write into it.
struct PcmFixture
{
	PcmRingClass ring;

	PcmFixture(void)
	{
		for (int i = 0; i < 2 * 128; i++) {
			Frames[i] = (int16_t)i;
		}
		REQUIRE(ring.Init(100, 2));
	}
};

}


TEST_CASE("a command ring holds its capacity, in order")
{
	SpscRingClass<Item, 8> ring;
	CHECK(ring.Is_Empty());
	CHECK(ring.Capacity() == 8u);

	for (uint32_t i = 0; i < 8; i++) {
		INFO("item ", i);
		CHECK(ring.Push(Item{i, i * 3}));
	}
	CHECK_MESSAGE(!ring.Push(Item{99, 99}), "a push fails when the ring is full");
	CHECK(ring.Count() == 8u);

	Item item;
	for (uint32_t i = 0; i < 8; i++) {
		INFO("item ", i);
		REQUIRE(ring.Pop(item));
		CHECK(item.Sequence == i);
		CHECK(item.Payload == i * 3);
	}
	CHECK_MESSAGE(!ring.Pop(item), "a pop fails when the ring is empty");
}


TEST_CASE("a command ring keeps its order across the wrap point")
{
	SpscRingClass<Item, 8> ring;
	Item item;
	uint32_t next = 100;
	uint32_t expect = 100;
	for (int round = 0; round < 50; round++) {
		INFO("round ", round);
		for (int i = 0; i < 5; i++) {
			CHECK(ring.Push(Item{next, 0}));
			next++;
		}
		for (int i = 0; i < 5; i++) {
			REQUIRE(ring.Pop(item));
			CHECK(item.Sequence == expect);
			expect++;
		}
	}
}


TEST_CASE("a command ring shared by two threads delivers every item whole and in order")
{
	SpscRingClass<Item, 64> ring;
	uint32_t const TOTAL = 200000;
	uint32_t misordered = 0;
	uint32_t torn = 0;

	std::thread consumer([&]() {
		uint32_t expect = 0;
		Item item;
		while (expect < TOTAL) {
			if (ring.Pop(item)) {
				if (item.Sequence != expect) misordered++;
				if (item.Payload != item.Sequence * 7u + 1u) torn++;
				expect++;
			}
		}
	});

	for (uint32_t i = 0; i < TOTAL; ) {
		if (ring.Push(Item{i, i * 7u + 1u})) {
			i++;
		}
	}
	consumer.join();

	CHECK(misordered == 0u);
	CHECK(torn == 0u);
}


TEST_CASE("a PCM ring refuses zero frames and rounds its capacity up to a power of two")
{
	PcmRingClass ring;
	CHECK_FALSE(ring.Init(0, 2));
	REQUIRE(ring.Init(100, 2));
	CHECK(ring.Capacity() == 128u);
	CHECK(ring.Channels() == 2u);
	CHECK(ring.Available_Read() == 0u);
	CHECK(ring.Available_Write() == 128u);
}


TEST_CASE_FIXTURE(PcmFixture, "a PCM write clamps to the room left and counts the frames pushed")
{
	CHECK(ring.Write(Frames, 100) == 100u);
	CHECK(ring.Available_Read() == 100u);
	CHECK(ring.Available_Write() == 28u);
	CHECK(ring.Write(Frames, 50) == 28u);
	CHECK(ring.Frames_Pushed() == 128u);
}


TEST_CASE_FIXTURE(PcmFixture, "a PCM read returns the earliest frames and clamps to what is available")
{
	ring.Write(Frames, 100);
	ring.Write(Frames, 50);

	int16_t out[2 * 128];
	CHECK_MESSAGE(ring.Read(out, 60) == 60u, "a partial read");
	CHECK(out[0] == 0);
	CHECK(out[119] == 119);
	CHECK(ring.Frames_Consumed() == 60u);

	CHECK(ring.Read(out, 200) == 68u);
	CHECK_MESSAGE(out[0] == 120, "the read continues where it left off");
	CHECK(ring.Available_Read() == 0u);
	CHECK_MESSAGE(ring.Read(out, 10) == 0u, "a read on an empty ring returns zero");
}


// After 128 frames in and out, the write cursor is at 128, so the next write starts at slot 0.
TEST_CASE_FIXTURE(PcmFixture, "PCM data survives the wrap point")
{
	int16_t out[2 * 128];
	ring.Write(Frames, 128);
	ring.Read(out, 128);

	CHECK(ring.Write(Frames, 96) == 96u);
	CHECK(ring.Read(out, 96) == 96u);
	for (int i = 0; i < 2 * 96; i++) {
		INFO("sample ", i);
		CHECK(out[i] == Frames[i]);
	}
}


TEST_CASE_FIXTURE(PcmFixture, "a PCM discard drops frames, clamped to what is available, and the counters run past the capacity until a reset")
{
	int16_t out[2 * 128];
	ring.Write(Frames, 128);
	ring.Read(out, 128);
	ring.Write(Frames, 96);
	ring.Read(out, 96);

	CHECK(ring.Write(Frames, 40) == 40u);
	CHECK(ring.Discard(15) == 15u);
	CHECK(ring.Available_Read() == 25u);
	CHECK(ring.Discard(100) == 25u);
	CHECK(ring.Frames_Consumed() == 128u + 96u + 40u);

	ring.Reset();
	CHECK(ring.Frames_Consumed() == 0u);
	CHECK(ring.Frames_Pushed() == 0u);
}


TEST_CASE("a PCM stream shared by two threads arrives whole and in order")
{
	PcmRingClass ring;
	REQUIRE(ring.Init(1024, 1));

	uint32_t const TOTAL = 500000;
	uint32_t wrong = 0;

	std::thread consumer([&]() {
		int16_t out[300];
		uint32_t expect = 0;
		while (expect < TOTAL) {
			unsigned got = ring.Read(out, 300);
			for (unsigned i = 0; i < got; i++) {
				if (out[i] != (int16_t)(expect & 0x7FFF)) wrong++;
				expect++;
			}
		}
	});

	// A write the consumer is too far behind to take whole is regenerated from where it stopped.
	int16_t in[257];
	uint32_t next = 0;
	while (next < TOTAL) {
		unsigned count = 257;
		if (TOTAL - next < count) count = TOTAL - next;
		for (unsigned i = 0; i < count; i++) {
			in[i] = (int16_t)((next + i) & 0x7FFF);
		}
		next += ring.Write(in, count);
	}
	consumer.join();

	CHECK(wrong == 0u);
}
