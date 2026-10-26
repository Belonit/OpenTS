/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Drives the mixer through the null device and checks what comes out: levels
// and the loudness curve, the pan law, resampling, gapless sequences and
// looping, the two ways a sequence ends, fades and stops, stale commands,
// pausing, the command ring's limit, the render token, streams, and that two
// identical runs produce identical output. Needs no game data.

#include "audio/audiodevice.h"
#include "audio/audiolevel.h"
#include "audio/audiomixer.h"
#include "audio/audiosample.h"
#include "audio/audiostream.h"
#include "audio/audiovoice.h"

#include "doctest/doctest.h"

#include <cmath>
#include <cstring>
#include <memory>
#include <vector>

namespace {

unsigned const RATE = 48000;
float const PI = 3.14159265f;
float const SINE_RMS = 0.5f / 1.41421f;


float Distance(float value, float expect)
{
	return(std::fabs(value - expect));
}


std::unique_ptr<AudioSampleClass> Make_Clip(unsigned rate, unsigned channels, unsigned frames)
{
	std::unique_ptr<AudioSampleClass> clip(new AudioSampleClass());
	clip->Rate = rate;
	clip->Channels = channels;
	clip->Frames = frames;
	clip->Pcm.reset(new int16_t[(size_t)frames * channels]());
	return(clip);
}


std::unique_ptr<AudioSampleClass> Make_Constant(unsigned rate, unsigned frames, float value)
{
	std::unique_ptr<AudioSampleClass> clip = Make_Clip(rate, 1, frames);
	for (unsigned i = 0; i < frames; i++) {
		clip->Pcm[i] = (int16_t)(value * 32767.0f);
	}
	return(clip);
}


std::unique_ptr<AudioSampleClass> Make_Sine(unsigned rate, unsigned frames, float hertz, float amplitude)
{
	std::unique_ptr<AudioSampleClass> clip = Make_Clip(rate, 1, frames);
	for (unsigned i = 0; i < frames; i++) {
		clip->Pcm[i] = (int16_t)(amplitude * 32767.0f * std::sin(2.0f * PI * hertz * (float)i / (float)rate));
	}
	return(clip);
}


AudioSequenceClass Single(AudioSampleClass const * clip, int cycles = 1)
{
	AudioSequenceClass sequence;
	std::memset(&sequence, 0, sizeof(sequence));
	sequence.Clips[0] = clip;
	sequence.Count = 1;
	sequence.LoopStart = 0;
	sequence.LoopEnd = 1;
	sequence.Cycles = cycles;
	return(sequence);
}


AudioCommand Play(unsigned slot, uint32_t generation, AudioSequenceClass const * sequence, float level = 1.0f, float pan = 0.0f, float pitch = 1.0f, AudioGroupType group = AUDIO_GROUP_SFX)
{
	AudioCommand command;
	std::memset(&command, 0, sizeof(command));
	command.Type = AudioCommandType::PLAY_SEQUENCE;
	command.Group = (uint8_t)group;
	command.Slot = (uint8_t)slot;
	command.Generation = generation;
	command.A = level;
	command.B = pan;
	command.C = pitch;
	command.Ptr = sequence;
	return(command);
}


AudioCommand Simple(AudioCommandType type, unsigned slot, uint32_t generation, float a = 0.0f, float b = 0.0f, uint8_t mode = 0)
{
	AudioCommand command;
	std::memset(&command, 0, sizeof(command));
	command.Type = type;
	command.Slot = (uint8_t)slot;
	command.Generation = generation;
	command.Mode = mode;
	command.A = a;
	command.B = b;
	return(command);
}


// A mixer wired to the null device with a capture buffer.
class RigClass
{
	public:
		RigClass(void) : Device(480, 3)
		{
			Ready = Mixer.Init(RATE, 2) && Device.Open(RATE, 2, AudioMixerClass::Render_Callback, &Mixer) && Device.Start();
			REQUIRE_MESSAGE(Ready, "the mixer and the null device start");
		}

		// Renders frames and appends them to the capture.
		void Run(unsigned frames)
		{
			size_t start = Output.size();
			Output.resize(start + (size_t)frames * 2);
			Device.Pump(Output.data() + start, frames);
		}

		size_t Frames(void) const { return(Output.size() / 2); }

		float Rms(size_t from, size_t to, int channel) const
		{
			double sum = 0.0;
			size_t count = 0;
			for (size_t i = from; i < to && i < Output.size() / 2; i++) {
				float v = Output[i * 2 + channel];
				sum += (double)v * v;
				count++;
			}
			return(count ? (float)std::sqrt(sum / (double)count) : 0.0f);
		}

		bool Silent(size_t from, size_t to) const
		{
			for (size_t i = from; i < to && i < Output.size() / 2; i++) {
				if (Output[i * 2] != 0.0f || Output[i * 2 + 1] != 0.0f) {
					return(false);
				}
			}
			return(true);
		}

		// Counts the frames of the left channel in a range that fall below a level.
		unsigned Frames_Below(size_t from, size_t to, float level) const
		{
			unsigned count = 0;
			for (size_t i = from; i < to && i < Output.size() / 2; i++) {
				if (Output[i * 2] < level) count++;
			}
			return(count);
		}

		size_t Last_Audible(float threshold = 0.0005f) const
		{
			for (size_t i = Output.size() / 2; i > 0; i--) {
				if (std::fabs(Output[(i - 1) * 2]) > threshold || std::fabs(Output[(i - 1) * 2 + 1]) > threshold) {
					return(i - 1);
				}
			}
			return(0);
		}

		bool Start(unsigned slot, AudioCommand const & command)
		{
			return(Mixer.Allocate_Voice(slot) && Mixer.Push(command));
		}

		bool Ready;
		AudioMixerClass Mixer;
		NullAudioDeviceClass Device;
		std::vector<float> Output;
};


struct Fixture
{
	RigClass rig;
};


// 5 ms attack, 5 ms body looping forever, 5 ms decay at a different level.
unsigned const SEG = RATE / 200;

struct SequenceFixture
{
	RigClass rig;
	std::unique_ptr<AudioSampleClass> attack = Make_Constant(RATE, SEG, 0.5f);
	std::unique_ptr<AudioSampleClass> body = Make_Constant(RATE, SEG, 0.5f);
	std::unique_ptr<AudioSampleClass> decay = Make_Constant(RATE, SEG, 0.25f);
	AudioSequenceClass sequence;

	SequenceFixture(void)
	{
		std::memset(&sequence, 0, sizeof(sequence));
		sequence.Clips[0] = attack.get();
		sequence.Clips[1] = body.get();
		sequence.Clips[2] = decay.get();
		sequence.Count = 3;
		sequence.LoopStart = 1;
		sequence.LoopEnd = 2;
		sequence.Cycles = -1;
	}
};


unsigned Decay_Frames(RigClass const & rig, size_t from)
{
	unsigned count = 0;
	for (size_t i = from; i < rig.Frames(); i++) {
		float v = rig.Output[i * 2];
		if (v > 0.15f && v < 0.35f) count++;
	}
	return(count);
}

}


TEST_CASE_FIXTURE(Fixture, "levels pass through the loudness curve after the voice, group, duck and master levels multiply")
{
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(RATE, RATE * 3, 440.0f, 0.5f);
	AudioSequenceClass sequence = Single(sine.get());

	REQUIRE(rig.Start(0, Play(0, 1, &sequence, 1.0f)));
	rig.Run(RATE / 2);
	float rms = rig.Rms(1000, RATE / 2, 0);
	CHECK_MESSAGE(Distance(rms, SINE_RMS) <= 0.01f, "full level plays the sine at its own amplitude");
	CHECK_MESSAGE(Distance(rig.Rms(1000, RATE / 2, 1), rms) <= 0.001f, "center pan is equal in both channels");

	// A 0.5 level is the DirectSound curve's 0.317 gain, and 128/255 the same.
	rig.Mixer.Push(Simple(AudioCommandType::SET_GAIN, 0, 1, 0.5f, 0.0f));
	rig.Run(RATE / 2);
	float half = rig.Rms(RATE / 2 + 1000, RATE, 0);
	CHECK_MESSAGE(Distance(half / rms, Audio_Perceptual_Gain(0.5f)) <= 0.01f, "half level follows the loudness curve");
	CHECK_MESSAGE(Distance(Audio_Perceptual_Gain(128.0f / 255.0f), 0.317f) <= 0.002f, "the curve matches the old driver at 128");

	// The group level multiplies the voice level before the curve, so two halves make a quarter.
	AudioCommand group = Simple(AudioCommandType::GROUP_SET_GAIN, 0, 0, 0.5f, 0.0f);
	group.Group = AUDIO_GROUP_SFX;
	rig.Mixer.Push(group);
	rig.Run(RATE / 2);
	float quarter = rig.Rms(RATE + 1000, RATE * 3 / 2, 0);
	CHECK_MESSAGE(Distance(quarter / rms, Audio_Perceptual_Gain(0.25f)) <= 0.01f, "group and voice levels multiply before the curve");

	AudioCommand duck = Simple(AudioCommandType::GROUP_SET_DUCK, 0, 0, 0.5f, 0.0f);
	duck.Group = AUDIO_GROUP_SFX;
	rig.Mixer.Push(duck);
	rig.Mixer.Push(Simple(AudioCommandType::MASTER_SET_GAIN, 0, 0, 0.5f, 0.0f));
	rig.Run(RATE / 2);
	float sixteenth = rig.Rms(RATE * 3 / 2 + 1000, RATE * 2, 0);
	CHECK_MESSAGE(Distance(sixteenth / rms, Audio_Perceptual_Gain(0.0625f)) <= 0.005f, "duck and master multiply in as well");
}


TEST_CASE_FIXTURE(Fixture, "a full pan silences the other channel, the center is unity on both, and a ramped pan moves gradually")
{
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(RATE, RATE * 2, 440.0f, 0.5f);
	AudioSequenceClass sequence = Single(sine.get());

	REQUIRE(rig.Start(0, Play(0, 1, &sequence, 1.0f, 1.0f)));
	rig.Run(4800);
	CHECK_MESSAGE(rig.Rms(100, 4800, 0) < 0.0001f, "full right pan silences the left channel");
	CHECK(rig.Rms(100, 4800, 1) > 0.3f);

	rig.Mixer.Push(Simple(AudioCommandType::SET_PAN, 0, 1, -1.0f, 0.0f));
	rig.Run(4800);
	CHECK_MESSAGE(rig.Rms(4900, 9600, 1) < 0.0001f, "full left pan silences the right channel");
	CHECK(rig.Rms(4900, 9600, 0) > 0.3f);

	rig.Mixer.Push(Simple(AudioCommandType::SET_PAN, 0, 1, 0.0f, 0.0f));
	rig.Run(4800);
	CHECK_MESSAGE(Distance(rig.Rms(9700, 14400, 0), rig.Rms(9700, 14400, 1)) <= 0.001f, "center pan is unity on both sides");
	CHECK_MESSAGE(Distance(rig.Rms(9700, 14400, 0), SINE_RMS) <= 0.01f, "center pan does not attenuate");

	rig.Mixer.Push(Simple(AudioCommandType::SET_PAN, 0, 1, 1.0f, 0.1f));
	rig.Run(2400);
	float mid = rig.Rms(14400 + 2000, 14400 + 2400, 0);
	CHECK_MESSAGE(mid > 0.05f, "a pan ramp is part way at half time");
	CHECK_MESSAGE(mid < 0.3f, "a pan ramp is part way at half time");
}


TEST_CASE_FIXTURE(Fixture, "a looping clip has no gap at the seam and finishes once stopped")
{
	std::unique_ptr<AudioSampleClass> dc = Make_Constant(RATE, 100, 0.5f);
	AudioSequenceClass forever = Single(dc.get(), -1);
	REQUIRE(rig.Start(0, Play(0, 1, &forever)));
	rig.Run(RATE);
	CHECK(rig.Frames_Below(200, RATE, 0.4f) == 0u);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::PLAYING);

	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 1));
	rig.Run(480);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
}


// One second at 22050 lasts one second at 48000.
TEST_CASE_FIXTURE(Fixture, "a 22050 clip lasts its length at 48000 and keeps its amplitude")
{
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(22050, 22050, 440.0f, 0.5f);
	AudioSequenceClass once = Single(sine.get());
	REQUIRE(rig.Start(0, Play(0, 1, &once)));
	rig.Run(RATE * 2);
	CHECK_MESSAGE(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE, "a one-shot finishes");
	size_t last = rig.Last_Audible();
	CHECK(last >= RATE - 32);
	CHECK(last <= RATE + 32);
	CHECK(Distance(rig.Rms(2000, RATE - 2000, 0), SINE_RMS) <= 0.02f);
}


// Pitch doubles the rate ratio, so the clip plays in half the time.
TEST_CASE_FIXTURE(Fixture, "double pitch halves the duration")
{
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(22050, 22050, 440.0f, 0.5f);
	AudioSequenceClass once = Single(sine.get());
	REQUIRE(rig.Start(0, Play(0, 1, &once, 1.0f, 0.0f, 2.0f)));
	rig.Run(RATE);
	size_t last = rig.Last_Audible();
	CHECK(last >= RATE / 2 - 32);
	CHECK(last <= RATE / 2 + 32);
}


TEST_CASE_FIXTURE(Fixture, "three cycles of a clip last three clip lengths, then finish")
{
	std::unique_ptr<AudioSampleClass> dc = Make_Constant(RATE, 100, 0.5f);
	AudioSequenceClass three = Single(dc.get(), 3);
	REQUIRE(rig.Start(0, Play(0, 1, &three)));
	rig.Run(2000);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
	size_t last = rig.Last_Audible(0.05f);
	CHECK(last >= 300u - 8);
	CHECK(last <= 300u + 24);
}


TEST_CASE_FIXTURE(SequenceFixture, "five millisecond segments chain without a gap, and an end after the cycle plays the decay once")
{
	REQUIRE(rig.Start(0, Play(0, 1, &sequence)));
	rig.Run(RATE / 2);
	CHECK_MESSAGE(rig.Frames_Below(100, RATE / 2, 0.4f) == 0u, "no gap while no command arrives for half a second");
	CHECK_MESSAGE(rig.Mixer.Voice_State(0) == AudioVoiceState::PLAYING, "the body keeps looping");

	// After the cycle: the rest of the body, then the decay once, then done.
	rig.Mixer.Push(Simple(AudioCommandType::END_SEQUENCE, 0, 1, 0.0f, 0.0f, (uint8_t)AudioEndMode::AFTER_CYCLE));
	size_t mark = rig.Frames();
	rig.Run(RATE / 10);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
	unsigned decayframes = Decay_Frames(rig, mark);
	unsigned bodyframes = 0;
	for (size_t i = mark; i < rig.Frames(); i++) {
		if (rig.Output[i * 2] > 0.4f) bodyframes++;
	}
	CHECK(decayframes >= SEG - 24);
	CHECK(decayframes <= SEG + 24);
	CHECK_MESSAGE(bodyframes <= SEG + 8, "no more than one body cycle plays after the end request");
}


TEST_CASE_FIXTURE(SequenceFixture, "an end now on a long body reaches silence within the ramp, then plays the decay once")
{
	std::unique_ptr<AudioSampleClass> longbody = Make_Constant(RATE, RATE * 2, 0.5f);
	sequence.Clips[1] = longbody.get();
	REQUIRE(rig.Start(0, Play(0, 1, &sequence)));
	rig.Run(RATE / 2);
	rig.Mixer.Push(Simple(AudioCommandType::END_SEQUENCE, 0, 1, 0.0f, 0.0f, (uint8_t)AudioEndMode::NOW));
	size_t mark = rig.Frames();
	rig.Run(RATE / 2);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);

	size_t quiet = mark;
	for (size_t i = mark; i < rig.Frames(); i++) {
		if (rig.Output[i * 2] < 0.01f) {
			quiet = i;
			break;
		}
	}
	CHECK(quiet - mark <= RATE / 4 + 64);
	unsigned decayframes = Decay_Frames(rig, quiet);
	CHECK(decayframes >= SEG - 24);
	CHECK(decayframes <= SEG + 24);
}


TEST_CASE_FIXTURE(SequenceFixture, "a sequence with clips at two rates plays both at their full length")
{
	std::unique_ptr<AudioSampleClass> slow = Make_Constant(22050, 2205, 0.5f);
	AudioSequenceClass mixed;
	std::memset(&mixed, 0, sizeof(mixed));
	mixed.Clips[0] = slow.get();
	mixed.Clips[1] = body.get();
	mixed.Count = 2;
	mixed.LoopStart = 1;
	mixed.LoopEnd = 2;
	mixed.Cycles = 1;
	REQUIRE(rig.Start(0, Play(0, 1, &mixed)));
	rig.Run(RATE / 4);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
	size_t last = rig.Last_Audible(0.05f);
	CHECK(last >= 4800 + SEG - 40);
	CHECK(last <= 4800 + SEG + 40);
}


TEST_CASE_FIXTURE(Fixture, "a fading stop lasts the requested time")
{
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(RATE, RATE * 4, 440.0f, 0.5f);
	AudioSequenceClass sequence = Single(sine.get());
	REQUIRE(rig.Start(0, Play(0, 7, &sequence)));
	rig.Run(4800);
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 7, 0.1f));
	rig.Run(RATE / 5);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);

	// The level ramps linearly and the curve makes the tail inaudible a little early.
	size_t last = rig.Last_Audible();
	CHECK(last >= 4800 + RATE / 10 - 200);
	CHECK(last <= 4800 + RATE / 10 + 64);
}


// A voice of generation 8 playing a sine for the generation and pause cases.
struct PlayingFixture
{
	RigClass rig;
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(RATE, RATE * 4, 440.0f, 0.5f);
	AudioSequenceClass sequence = Single(sine.get());

	PlayingFixture(void)
	{
		REQUIRE(rig.Start(0, Play(0, 8, &sequence)));
		rig.Run(480);
	}
};


TEST_CASE_FIXTURE(PlayingFixture, "a command with a stale generation is dropped and has no effect")
{
	unsigned dropped = rig.Mixer.Dropped_Commands();
	rig.Mixer.Push(Simple(AudioCommandType::SET_GAIN, 0, 9, 0.0f, 0.0f));
	size_t mark = rig.Frames();
	rig.Run(480);
	CHECK(rig.Mixer.Dropped_Commands() == dropped + 1);
	CHECK(rig.Rms(mark, mark + 480, 0) > 0.3f);
}


TEST_CASE_FIXTURE(PlayingFixture, "a paused voice is silent and reports paused, and plays again once resumed")
{
	rig.Mixer.Push(Simple(AudioCommandType::PAUSE, 0, 8));
	size_t mark = rig.Frames();
	rig.Run(480);
	CHECK(rig.Silent(mark, mark + 480));
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::PAUSED);

	rig.Mixer.Push(Simple(AudioCommandType::RESUME, 0, 8));
	mark = rig.Frames();
	rig.Run(480);
	CHECK(rig.Rms(mark + 64, mark + 480, 0) > 0.3f);
}


// Pausing everything ramps down, freezes, and resumes where it left off.
TEST_CASE_FIXTURE(PlayingFixture, "pause all freezes the mix after its ramp, and resume all plays again")
{
	rig.Mixer.Set_Pause_All(true);
	size_t mark = rig.Frames();
	rig.Run(4800);
	CHECK(rig.Silent(mark + 1000, mark + 4800));

	rig.Mixer.Set_Pause_All(false);
	mark = rig.Frames();
	rig.Run(480);
	CHECK(rig.Rms(mark + 300, mark + 480, 0) > 0.3f);
}


TEST_CASE_FIXTURE(PlayingFixture, "stop all finishes every voice")
{
	rig.Mixer.Push(Simple(AudioCommandType::STOP_ALL, 0, 0));
	rig.Run(480);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
}


TEST_CASE_FIXTURE(PlayingFixture, "a play on an unallocated voice is dropped and the voice stays free")
{
	rig.Mixer.Push(Simple(AudioCommandType::STOP_ALL, 0, 0));
	rig.Run(480);
	unsigned dropped = rig.Mixer.Dropped_Commands();
	rig.Mixer.Free_Voice(0);
	rig.Mixer.Push(Play(0, 10, &sequence));
	rig.Run(64);
	CHECK(rig.Mixer.Dropped_Commands() == dropped + 1);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::FREE);
}


// A looping sine for the pause ramp and stop cases.
struct LoopFixture
{
	RigClass rig;
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(RATE, RATE, 440.0f, 0.5f);
	AudioSequenceClass sequence = Single(sine.get(), -1);
};


TEST_CASE_FIXTURE(LoopFixture, "a ramped pause and resume fade the voice down and back up, and a resume during the ramp turns it around")
{
	REQUIRE(rig.Start(0, Play(0, 1, &sequence)));
	rig.Run(4800);
	rig.Mixer.Push(Simple(AudioCommandType::PAUSE, 0, 1, 0.05f));
	size_t mark = rig.Frames();
	rig.Run(RATE / 10);
	CHECK_MESSAGE(rig.Rms(mark, mark + 480, 0) > 0.2f, "a ramped pause is still audible at its start");
	CHECK_MESSAGE(rig.Silent(mark + RATE / 20 + 64, mark + RATE / 10), "a ramped pause is silent once its ramp is over");
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::PAUSED);

	rig.Mixer.Push(Simple(AudioCommandType::RESUME, 0, 1, 0.05f));
	mark = rig.Frames();
	rig.Run(RATE / 10);
	CHECK_MESSAGE(rig.Rms(mark, mark + 480, 0) < rig.Rms(mark + RATE / 20 + 64, mark + RATE / 10, 0), "a ramped resume rises");
	CHECK_MESSAGE(rig.Rms(mark + RATE / 20 + 64, mark + RATE / 10, 0) > 0.3f, "a ramped resume reaches the full level");

	rig.Mixer.Push(Simple(AudioCommandType::PAUSE, 0, 1, 0.1f));
	rig.Run(RATE / 50);
	rig.Mixer.Push(Simple(AudioCommandType::RESUME, 0, 1, 0.01f));
	mark = rig.Frames();
	rig.Run(RATE / 10);
	CHECK_MESSAGE(rig.Mixer.Voice_State(0) == AudioVoiceState::PLAYING, "a resume during a pause ramp keeps the voice playing");
	CHECK_MESSAGE(rig.Rms(mark + RATE / 50, mark + RATE / 10, 0) > 0.3f, "and brings it back to the full level");
}


TEST_CASE_FIXTURE(LoopFixture, "a stopped paused voice is done at once and stays silent")
{
	REQUIRE(rig.Start(0, Play(0, 1, &sequence)));
	rig.Run(4800);
	rig.Mixer.Push(Simple(AudioCommandType::PAUSE, 0, 1));
	rig.Run(480);
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 1, 0.5f));
	size_t mark = rig.Frames();
	rig.Run(480);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
	CHECK(rig.Silent(mark, mark + 480));
}


// A stop during a long volume change ends with its own fade.
TEST_CASE_FIXTURE(LoopFixture, "a stop during a volume change is done after its own fade")
{
	REQUIRE(rig.Start(0, Play(0, 2, &sequence, 0.0f)));
	rig.Mixer.Push(Simple(AudioCommandType::SET_GAIN, 0, 2, 1.0f, 2.0f));
	rig.Run(RATE / 10);
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 2, 0.01f));
	rig.Run(RATE / 20);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
}


// A second stop brings a long fade's end closer but never moves it later.
TEST_CASE_FIXTURE(LoopFixture, "a shorter second stop ends a long fade early")
{
	REQUIRE(rig.Start(0, Play(0, 3, &sequence)));
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 3, 2.0f));
	rig.Run(RATE / 10);
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 3, 0.01f));
	rig.Run(RATE / 20);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
}


TEST_CASE_FIXTURE(LoopFixture, "a longer second stop keeps the first fade's end")
{
	REQUIRE(rig.Start(0, Play(0, 4, &sequence)));
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 4, 0.05f));
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 4, 2.0f));
	rig.Run(RATE / 10);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
}


// An end during a pause ramp finishes the voice rather than leaving it paused.
TEST_CASE_FIXTURE(LoopFixture, "an end during a pause ramp finishes the voice")
{
	REQUIRE(rig.Start(0, Play(0, 1, &sequence)));
	rig.Run(480);
	rig.Mixer.Push(Simple(AudioCommandType::PAUSE, 0, 1, 0.05f));
	rig.Mixer.Push(Simple(AudioCommandType::END_SEQUENCE, 0, 1, 0.0f, 0.0f, (uint8_t)AudioEndMode::NOW));
	rig.Run(RATE / 2);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
}


TEST_CASE_FIXTURE(LoopFixture, "an end on a paused voice finishes it at once and it stays silent")
{
	REQUIRE(rig.Start(0, Play(0, 2, &sequence)));
	rig.Run(480);
	rig.Mixer.Push(Simple(AudioCommandType::PAUSE, 0, 2));
	rig.Run(480);
	rig.Mixer.Push(Simple(AudioCommandType::END_SEQUENCE, 0, 2, 0.0f, 0.0f, (uint8_t)AudioEndMode::NOW));
	size_t mark = rig.Frames();
	rig.Run(480);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE);
	CHECK(rig.Silent(mark, mark + 480));
}


// A command that reaches a voice after it finished is not lost.
TEST_CASE_FIXTURE(Fixture, "a stop arriving after the sound ended is not dropped, but one for an older use of the voice is")
{
	std::unique_ptr<AudioSampleClass> blip = Make_Sine(RATE, 480, 440.0f, 0.5f);
	AudioSequenceClass once = Single(blip.get());
	REQUIRE(rig.Start(0, Play(0, 3, &once)));
	rig.Run(RATE / 10);
	REQUIRE_MESSAGE(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE, "the short sound finished by itself");

	unsigned dropped = rig.Mixer.Dropped_Commands();
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 3, 0.1f));
	rig.Run(480);
	CHECK(rig.Mixer.Dropped_Commands() == dropped);
	rig.Mixer.Push(Simple(AudioCommandType::STOP, 0, 2, 0.1f));
	rig.Run(480);
	CHECK(rig.Mixer.Dropped_Commands() == dropped + 1);
}


TEST_CASE_FIXTURE(Fixture, "the command ring refuses pushes past its capacity and accepts again once drained")
{
	unsigned pushed = 0;
	for (unsigned i = 0; i < AUDIO_COMMAND_QUEUE_SIZE + 5; i++) {
		if (rig.Mixer.Push(Simple(AudioCommandType::MASTER_SET_GAIN, 0, 0, 1.0f, 0.0f))) {
			pushed++;
		}
	}
	CHECK(pushed == (unsigned)AUDIO_COMMAND_QUEUE_SIZE);
	rig.Run(64);
	CHECK(rig.Mixer.Push(Simple(AudioCommandType::MASTER_SET_GAIN, 0, 0, 1.0f, 0.0f)));
}


TEST_CASE_FIXTURE(Fixture, "a render call without the render token writes silence until the token is released")
{
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(RATE, RATE, 440.0f, 0.5f);
	AudioSequenceClass sequence = Single(sine.get(), -1);
	REQUIRE(rig.Start(0, Play(0, 1, &sequence)));
	size_t mark = rig.Frames();
	rig.Run(480);
	CHECK_MESSAGE(rig.Rms(mark + 100, mark + 480, 0) > 0.3f, "the voice is audible before the token is taken");

	REQUIRE_MESSAGE(rig.Mixer.Acquire_Render_Token(), "a second renderer can take the token when it is free");
	mark = rig.Frames();
	rig.Run(480);
	CHECK(rig.Silent(mark, mark + 480));

	rig.Mixer.Release_Render_Token();
	mark = rig.Frames();
	rig.Run(480);
	CHECK(rig.Rms(mark + 64, mark + 480, 0) > 0.3f);
}


TEST_CASE_FIXTURE(Fixture, "a stream plays, rides out an underrun in silence, and finishes once drained at the end of its input")
{
	AudioStreamClass stream;
	REQUIRE(stream.Init(4096, 1, 22050));

	std::vector<int16_t> chunk(2205, (int16_t)(0.5f * 32767.0f));
	REQUIRE(stream.Ring.Write(chunk.data(), (unsigned)chunk.size()) == chunk.size());

	AudioCommand play;
	std::memset(&play, 0, sizeof(play));
	play.Type = AudioCommandType::PLAY_STREAM;
	play.Group = AUDIO_GROUP_MUSIC;
	play.Slot = 3;
	play.Generation = 1;
	play.A = 1.0f;
	play.C = 1.0f;
	play.Ptr = &stream;
	REQUIRE(rig.Start(3, play));

	rig.Run(2400);
	CHECK(rig.Rms(100, 2400, 0) > 0.3f);
	CHECK(stream.Frames_Consumed() > 1000u);

	// Let it run dry: silence, an underrun count, and the voice stays alive.
	rig.Run(RATE / 4);
	CHECK_MESSAGE(stream.Frames_Consumed() == 2205u, "silence during an underrun is not counted as consumed");
	CHECK(stream.Underruns.load() > 0u);
	CHECK(rig.Mixer.Voice_State(3) == AudioVoiceState::PLAYING);
	CHECK(rig.Silent(RATE / 8, RATE / 4));

	REQUIRE(stream.Ring.Write(chunk.data(), (unsigned)chunk.size()) == chunk.size());
	rig.Run(2400);
	CHECK_MESSAGE(rig.Rms(2400 + RATE / 4 + 200, 2400 + RATE / 4 + 2400, 0) > 0.3f, "playback resumes when data arrives");

	stream.EndOfInput.store(true);
	rig.Run(RATE / 4);
	CHECK(rig.Mixer.Voice_State(3) == AudioVoiceState::DONE);
	CHECK_MESSAGE(stream.Frames_Consumed() == 4410u, "every pushed frame was consumed");
}


TEST_CASE("two identical runs render identical output")
{
	std::unique_ptr<AudioSampleClass> sine = Make_Sine(22050, 22050, 330.0f, 0.4f);
	std::unique_ptr<AudioSampleClass> dc = Make_Constant(RATE, 300, 0.3f);
	AudioSequenceClass a = Single(sine.get());
	AudioSequenceClass b = Single(dc.get(), -1);

	std::vector<float> runs[2];
	for (int run = 0; run < 2; run++) {
		RigClass rig;
		rig.Start(0, Play(0, 1, &a, 0.8f, -0.3f));
		rig.Start(5, Play(5, 2, &b, 0.6f, 0.5f));
		rig.Run(4000);
		rig.Mixer.Push(Simple(AudioCommandType::SET_GAIN, 5, 2, 0.2f, 0.05f));
		rig.Mixer.Push(Simple(AudioCommandType::SET_PAN, 0, 1, 0.9f, 0.02f));
		rig.Run(4000);
		rig.Mixer.Push(Simple(AudioCommandType::STOP, 5, 2, 0.03f));
		rig.Run(20000);
		runs[run] = rig.Output;
	}
	REQUIRE(runs[0].size() == runs[1].size());
	CHECK(std::memcmp(runs[0].data(), runs[1].data(), runs[0].size() * sizeof(float)) == 0);
}
