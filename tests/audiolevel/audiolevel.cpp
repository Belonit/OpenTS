/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Holds the loudness curve to the values the DirectSound driver produced for its
// 0..255 volumes, and checks that ramped levels move linearly, settle exactly on
// their targets, and keep the base and adjust ramps apart. Needs no game data.

#include "audio/audiolevel.h"

#include "doctest/doctest.h"

#include <cmath>

namespace {

float Distance(float value, float expect)
{
	return(std::fabs(value - expect));
}

}


// (v / 255) ^ (5 / 3) for the volumes the old driver was fed.
TEST_CASE("the loudness curve gives the old driver's gains")
{
	CHECK_MESSAGE(Distance(Audio_Perceptual_Gain(255.0f / 255.0f), 1.0f) <= 0.0001f, "255 is unity");
	CHECK_MESSAGE(Distance(Audio_Perceptual_Gain(128.0f / 255.0f), 0.317f) <= 0.001f, "128 is 0.317");
	CHECK_MESSAGE(Distance(Audio_Perceptual_Gain(64.0f / 255.0f), 0.100f) <= 0.001f, "64 is 0.100");
	CHECK_MESSAGE(Audio_Perceptual_Gain(0.0f) == 0.0f, "0 is silence");
}


TEST_CASE("the loudness curve clamps to silence and unity")
{
	CHECK(Audio_Perceptual_Gain(-0.5f) == 0.0f);
	CHECK(Audio_Perceptual_Gain(2.0f) == 1.0f);
}


// The curve is a power, so shaping a product equals the product of shaped factors.
TEST_CASE("the loudness curve distributes over products")
{
	float product = Audio_Perceptual_Gain(0.7f * 0.5f);
	float factors = Audio_Perceptual_Gain(0.7f) * Audio_Perceptual_Gain(0.5f);
	CHECK(Distance(product, factors) <= 0.0001f);
}


TEST_CASE("the inverse of the loudness curve round-trips")
{
	for (int v = 0; v <= 255; v += 5) {
		INFO("volume ", v);
		float level = (float)v / 255.0f;
		CHECK(Distance(Audio_Perceptual_Level(Audio_Perceptual_Gain(level)), level) <= 0.0005f);
	}
}


TEST_CASE("the loudness curve is monotonic")
{
	float last = -1.0f;
	for (int v = 0; v <= 255; v++) {
		INFO("volume ", v);
		float gain = Audio_Perceptual_Gain((float)v / 255.0f);
		CHECK(gain >= last);
		last = gain;
	}
}


TEST_CASE("a new level is settled at unity, and a zero-second set snaps")
{
	AudioLevelClass level;
	CHECK(level.Current() == 1.0f);
	CHECK(level.Is_Settled());

	level.Set_Level(0.25f, 0.0f);
	CHECK(level.Current() == 0.25f);
	CHECK(level.Is_Settled());
}


// One second ramp from 0.25 to 1.0, advanced in 64-frame blocks at 48 kHz.
TEST_CASE("a set ramp rises monotonically over the requested time and lands exactly on its target")
{
	AudioLevelClass level;
	level.Set_Level(0.25f, 0.0f);
	level.Set_Level(1.0f, 1.0f);
	CHECK_MESSAGE(!level.Is_Settled(), "the ramp is not settled while running");

	float previous = level.Current();
	unsigned falls = 0;
	unsigned blocks = 0;
	while (!level.Is_Settled() && blocks < 100000) {
		float now = level.Advance(64, 48000);
		if (now < previous) {
			falls++;
		}
		previous = now;
		blocks++;
	}
	CHECK_MESSAGE(falls == 0u, "blocks in which the level fell");
	CHECK(level.Current() == 1.0f);
	CHECK(Distance((float)blocks * 64.0f / 48000.0f, 1.0f) <= 0.002f);
}


TEST_CASE("a linear ramp is half done at half time, and a retarget starts from the current value")
{
	AudioLevelClass level;
	level.Set_Level(0.0f, 2.0f);
	level.Advance(48000, 48000);
	CHECK(Distance(level.Current(), 0.5f) <= 0.002f);

	level.Set_Level(1.0f, 1.0f);
	CHECK_MESSAGE(Distance(level.Current(), 0.5f) <= 0.002f, "the retarget keeps the current value");
	level.Advance(48000, 48000);
	CHECK_MESSAGE(level.Current() == 1.0f, "the retargeted ramp lands on the new target");
}


TEST_CASE("an adjust ramps from unity toward its multiplier and settles there")
{
	AudioLevelClass level;
	level.Set_Level(0.8f, 0.0f);

	level.Adjust_Level(0.5f, 0.25f);
	CHECK(Distance(level.Current(), 0.8f) <= 0.0001f);
	level.Advance(6000, 48000);
	CHECK(Distance(level.Current(), 0.8f * 0.75f) <= 0.002f);
	level.Advance(6000, 48000);
	CHECK(Distance(level.Current(), 0.4f) <= 0.0005f);
	CHECK(level.Is_Settled());
}


// The base can change underneath the adjust without disturbing it.
TEST_CASE("the base and the adjust multiply, and a restore undoes the adjust")
{
	AudioLevelClass level;
	level.Set_Level(0.8f, 0.0f);
	level.Adjust_Level(0.5f, 0.25f);
	level.Advance(12000, 48000);
	REQUIRE(level.Is_Settled());

	level.Set_Level(0.4f, 0.0f);
	CHECK(Distance(level.Current(), 0.2f) <= 0.0005f);

	level.Restore_Level(0.0f);
	CHECK(Distance(level.Current(), 0.4f) <= 0.0005f);
}


TEST_CASE("a restore to the current multiplier and a set to the current level are no-ops")
{
	AudioLevelClass level;
	level.Set_Level(0.4f, 0.0f);

	level.Restore_Level(1.0f);
	CHECK(level.Is_Settled());
	level.Set_Level(0.4f, 1.0f);
	CHECK(level.Is_Settled());
}
