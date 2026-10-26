/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Drives the event pool over a mixer rendered by hand and checks the sequences
// it builds, its state machine, the two ways an event ends, per-type limits,
// the effects budget and its stealing order, queued and delayed starts, the
// clock clamp, handles going stale, and that every pinned clip comes back.
// Needs no game data.

#include "audio/audioevent.h"
#include "audio/audiolevel.h"
#include "audio/audiomixer.h"
#include "audio/audiosample.h"
#include "audio/audiostream.h"

#include "doctest/doctest.h"

#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace {

unsigned const RATE = 48000;
unsigned const CLIP_FRAMES = 4800;   // 100 ms


float Distance(float value, float expect)
{
	return(std::fabs(value - expect));
}


// Hands out clips by type name and sound index and counts the pins.
class ProviderClass : public AudioClipProviderClass
{
	public:
		ProviderClass(void) : Acquired(0), Released(0) {}

		AudioSampleClass * Add(char const * type, unsigned sound, float value = 0.0f)
		{
			std::unique_ptr<AudioSampleClass> clip(new AudioSampleClass());
			clip->Rate = RATE;
			clip->Channels = 1;
			clip->Frames = CLIP_FRAMES;
			clip->Pcm.reset(new int16_t[CLIP_FRAMES]);
			for (unsigned i = 0; i < CLIP_FRAMES; i++) {
				clip->Pcm[i] = (int16_t)(value * 32767.0f);
			}
			AudioSampleClass * raw = clip.get();
			Owned.push_back(std::move(clip));
			std::vector<AudioSampleClass *> & list = Table[type];
			if (list.size() <= sound) {
				list.resize(sound + 1, nullptr);
			}
			list[sound] = raw;
			return(raw);
		}

		AudioSampleClass * Clip(char const * type, unsigned sound) const
		{
			auto it = Table.find(type);
			if (it == Table.end() || sound >= it->second.size()) {
				return(nullptr);
			}
			return(it->second[sound]);
		}

		AudioSampleClass * Acquire(AudioEventTypeClass const & type, unsigned sound) override
		{
			AudioSampleClass * clip = Clip(type.Name, sound);
			if (clip != nullptr) {
				clip->PinCount++;
				Acquired++;
			}
			return(clip);
		}

		void Release(AudioSampleClass * clip) override
		{
			clip->PinCount--;
			Released++;
		}

		// Pins a clip the way the cache would for a raw play.
		AudioSampleClass * Pin(AudioSampleClass * clip)
		{
			clip->PinCount++;
			Acquired++;
			return(clip);
		}

		bool Balanced(void) const { return(Acquired == Released); }

		int Acquired;
		int Released;

	private:
		std::vector<std::unique_ptr<AudioSampleClass>> Owned;
		std::map<std::string, std::vector<AudioSampleClass *>> Table;
};


int Fixed_Random(int low, int high, void * context)
{
	return(*(int *)context ? high : low);
}


// A pool over a mixer whose output the test renders and keeps.
class RigClass
{
	public:
		RigClass(void) : Now(0), RandomHigh(0)
		{
			Ready = Mixer.Init(RATE, 2) && Pool.Init(&Mixer, &Provider);
			Pool.Set_Random(Fixed_Random, &RandomHigh);
			Pool.Service(Now);
			REQUIRE_MESSAGE(Ready, "the mixer and the pool start");
		}

		~RigClass(void)
		{
			Pool.Shutdown();
			Mixer.Shutdown();
		}

		// Registers a type with `count` sounds and clips for each.
		AudioEventTypeClass & Type(char const * name, unsigned count, unsigned control = SOUND_CONTROL_NONE, int attack = 0, int decay = 0, float value = 0.0f)
		{
			std::unique_ptr<AudioEventTypeClass> type(new AudioEventTypeClass());
			std::strncpy(type->Name, name, sizeof(type->Name) - 1);
			type->SoundCount = count;
			for (unsigned i = 0; i < count; i++) {
				std::snprintf(type->Sounds[i], sizeof(type->Sounds[i]), "%s%u", name, i);
				Provider.Add(name, i, value);
			}
			type->Control = control;
			type->AttackCount = attack;
			type->DecayCount = decay;
			type->Limit = 0;
			type->Priority = 50;
			Types.push_back(std::move(type));
			return(*Types.back());
		}

		AudioSampleClass * Clip(char const * type, unsigned sound) const { return(Provider.Clip(type, sound)); }

		// Renders the mixer for `ms` and then services the pool at the new time.
		void Tick(unsigned ms)
		{
			Run(ms * (RATE / 1000));
			Now += ms;
			Pool.Service(Now);
		}

		void Run(unsigned frames)
		{
			while (frames > 0) {
				unsigned block = frames < 480 ? frames : 480;
				float buffer[480 * 2];
				Mixer.Render(buffer, block);
				Output.insert(Output.end(), buffer, buffer + block * 2);
				frames -= block;
			}
		}

		float Last_Sample(void) const { return(Output.empty() ? 0.0f : Output[Output.size() - 2]); }
		float Last_Right(void) const { return(Output.empty() ? 0.0f : Output[Output.size() - 1]); }

		// Reads the sequence an event is playing; a stale handle fails the case.
		AudioSequenceClass Sequence(AudioHandle handle)
		{
			AudioSequenceClass sequence;
			REQUIRE(Pool.Get_Sequence(handle, sequence));
			return(sequence);
		}

		bool Ready;
		ProviderClass Provider;
		AudioMixerClass Mixer;
		AudioEventPoolClass Pool;
		unsigned Now;
		int RandomHigh;
		std::vector<float> Output;
		std::vector<std::unique_ptr<AudioEventTypeClass>> Types;
};


struct Fixture
{
	RigClass rig;
};


void Check_Sequence(AudioSequenceClass const & sequence, std::vector<AudioSampleClass const *> const & clips, unsigned loopstart, unsigned loopend, int cycles)
{
	CHECK(sequence.Count == clips.size());
	CHECK(sequence.LoopStart == loopstart);
	CHECK(sequence.LoopEnd == loopend);
	CHECK(sequence.Cycles == cycles);
	for (unsigned i = 0; i < clips.size() && i < sequence.Count; i++) {
		INFO("clip ", i);
		CHECK(sequence.Clips[i] == clips[i]);
	}
}


// A stream holding `seconds` of a constant half-level signal.
struct ConstantStream
{
	AudioStreamClass Stream;

	explicit ConstantStream(unsigned seconds)
	{
		REQUIRE(Stream.Init(RATE * seconds, 1, RATE));
		std::vector<int16_t> constant((size_t)RATE * seconds, (int16_t)(0.5f * 32767.0f));
		Stream.Ring.Write(constant.data(), (unsigned)constant.size());
	}
};

}


TEST_CASE_FIXTURE(Fixture, "a one-shot starts playing at once with its counts and its one clip pinned")
{
	AudioEventTypeClass & type = rig.Type("SHOT", 1);
	AudioHandle handle = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	REQUIRE_FALSE(handle.Is_Null());
	CHECK(rig.Pool.Is_Valid(handle));
	CHECK_MESSAGE(rig.Pool.Is_Playing(handle), "playing before any render");
	CHECK(rig.Pool.State(handle) == AUDIO_EVENT_PLAYING);
	CHECK(rig.Pool.Type(handle) == &type);
	CHECK(rig.Pool.Live_Count() == 1u);
	CHECK(rig.Pool.Live_Count(type) == 1u);
	CHECK(type.LiveCount == 1);
	CHECK(rig.Pool.Effects_In_Use() == 1u);

	Check_Sequence(rig.Sequence(handle), { rig.Clip("SHOT", 0) }, 0, 1, 1);
	CHECK(rig.Provider.Acquired == 1);
}


TEST_CASE_FIXTURE(Fixture, "a one-shot ends after its clip, freeing its voice, counts and pins")
{
	AudioEventTypeClass & type = rig.Type("SHOT", 1);
	AudioHandle handle = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);

	rig.Tick(50);
	CHECK_MESSAGE(rig.Pool.Is_Playing(handle), "still playing mid-clip");
	rig.Tick(100);
	CHECK_FALSE(rig.Pool.Is_Valid(handle));
	CHECK(rig.Pool.Live_Count() == 0u);
	CHECK(type.LiveCount == 0);
	CHECK(rig.Pool.Effects_In_Use() == 0u);
	CHECK(rig.Provider.Balanced());
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::FREE);
}


TEST_CASE_FIXTURE(Fixture, "a type without sounds refuses to start")
{
	CHECK(rig.Pool.Start(rig.Type("EMPTY", 0), AUDIO_GROUP_SFX, 1.0f, 0.0f).Is_Null());
}


TEST_CASE_FIXTURE(Fixture, "an attack and decay type plays the attack, the first body sound, and the decay")
{
	AudioEventTypeClass & plain = rig.Type("ABD", 5, SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY, 1, 1);
	AudioHandle handle = rig.Pool.Start(plain, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("ABD", 0), rig.Clip("ABD", 1), rig.Clip("ABD", 4) }, 1, 2, 1);
	CHECK(plain.Body_Start() == 1u);
	CHECK(plain.Body_Count() == 3u);
}


TEST_CASE_FIXTURE(Fixture, "a random type picks its body sound with the random source")
{
	rig.RandomHigh = 1;
	AudioEventTypeClass & random = rig.Type("RND", 5, SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY | SOUND_CONTROL_RANDOM, 1, 1);
	AudioHandle handle = rig.Pool.Start(random, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("RND", 0), rig.Clip("RND", 3), rig.Clip("RND", 4) }, 1, 2, 1);
}


TEST_CASE_FIXTURE(Fixture, "an all type plays the whole body in order")
{
	AudioEventTypeClass & all = rig.Type("ALL", 5, SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY | SOUND_CONTROL_ALL, 1, 1);
	AudioHandle handle = rig.Pool.Start(all, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("ALL", 0), rig.Clip("ALL", 1), rig.Clip("ALL", 2), rig.Clip("ALL", 3), rig.Clip("ALL", 4) }, 1, 4, 1);
}


TEST_CASE_FIXTURE(Fixture, "a sequential type steps through its body on each start")
{
	AudioEventTypeClass & sequential = rig.Type("SEQ", 3, SOUND_CONTROL_SEQUENTIAL);
	for (unsigned i = 0; i < 4; i++) {
		INFO("start ", i);
		AudioHandle handle = rig.Pool.Start(sequential, AUDIO_GROUP_SFX, 1.0f, 0.0f);
		Check_Sequence(rig.Sequence(handle), { rig.Clip("SEQ", i % 3) }, 0, 1, 1);
	}
}


TEST_CASE_FIXTURE(Fixture, "a start without the attack skips it")
{
	AudioEventTypeClass & noattack = rig.Type("NOATK", 5, SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY, 1, 1);
	AudioHandle handle = rig.Pool.Start(noattack, AUDIO_GROUP_SFX, 1.0f, 0.0f, true);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("NOATK", 1), rig.Clip("NOATK", 4) }, 0, 1, 1);
}


// Too few sounds to spare an attack and a decay: the whole list is the body.
TEST_CASE_FIXTURE(Fixture, "two sounds with attack and decay play as a body")
{
	AudioEventTypeClass & tight = rig.Type("TIGHT", 2, SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY, 1, 1);
	AudioHandle handle = rig.Pool.Start(tight, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("TIGHT", 0) }, 0, 1, 1);
}


TEST_CASE_FIXTURE(Fixture, "a loop count becomes the cycles played")
{
	AudioEventTypeClass & twice = rig.Type("TWICE", 1, SOUND_CONTROL_LOOP);
	twice.Loop = 2;
	AudioHandle handle = rig.Pool.Start(twice, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK(rig.Sequence(handle).Cycles == 2);
	rig.Tick(150);
	CHECK_MESSAGE(rig.Pool.Is_Playing(handle), "the second cycle is still playing");
	rig.Tick(100);
	CHECK_MESSAGE(!rig.Pool.Is_Valid(handle), "two cycles, then done");
}


TEST_CASE_FIXTURE(Fixture, "an endless loop plays until end-looping lets its cycle finish")
{
	AudioEventTypeClass & forever = rig.Type("EVER", 1, SOUND_CONTROL_LOOP);
	AudioHandle handle = rig.Pool.Start(forever, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK(rig.Sequence(handle).Cycles == -1);
	CHECK(forever.Never_Ends());
	for (int i = 0; i < 10; i++) {
		rig.Tick(100);
	}
	CHECK(rig.Pool.Is_Playing(handle));

	rig.Pool.End_Looping(handle);
	rig.Tick(30);
	CHECK_MESSAGE(rig.Pool.Is_Playing(handle), "the cycle finishes after end-looping");
	rig.Tick(200);
	CHECK_MESSAGE(!rig.Pool.Is_Valid(handle), "done after the cycle");
}


TEST_CASE_FIXTURE(Fixture, "end-looping is a no-op on a one-shot")
{
	AudioEventTypeClass & oneshot = rig.Type("ONCE", 1);
	AudioHandle handle = rig.Pool.Start(oneshot, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Pool.End_Looping(handle);
	CHECK(rig.Pool.Is_Playing(handle));
	CHECK_MESSAGE(rig.Provider.Acquired == rig.Provider.Released + 1, "only the live event holds a pin");
}


TEST_CASE_FIXTURE(Fixture, "a stop is immediate to the caller and frees the voice within the ramp")
{
	AudioEventTypeClass & type = rig.Type("SE", 3, SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY | SOUND_CONTROL_LOOP, 1, 1);
	AudioHandle stop = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(150);
	rig.Pool.Stop(stop);
	CHECK_FALSE(rig.Pool.Is_Playing(stop));
	CHECK_FALSE(rig.Pool.Is_Valid(stop));
	CHECK(rig.Pool.Live_Count() == 0u);
	rig.Tick(20);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::FREE);
	CHECK(rig.Provider.Balanced());
}


TEST_CASE_FIXTURE(Fixture, "an end keeps the event alive to fade and play its decay")
{
	AudioEventTypeClass & type = rig.Type("SE", 3, SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY | SOUND_CONTROL_LOOP, 1, 1);
	AudioHandle end = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(150);
	rig.Pool.End(end);
	CHECK(rig.Pool.Is_Playing(end));
	rig.Tick(100);
	CHECK_MESSAGE(rig.Pool.Is_Playing(end), "still fading");
	rig.Tick(300);
	CHECK_MESSAGE(!rig.Pool.Is_Valid(end), "the decay played after the fade");
	CHECK(rig.Provider.Balanced());
}


TEST_CASE_FIXTURE(Fixture, "a fade ends the event for the caller but finishes only once the voice is quiet")
{
	AudioEventTypeClass & type = rig.Type("SE", 3, SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY | SOUND_CONTROL_LOOP, 1, 1);
	AudioHandle fade = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Pool.Fade(fade, 500);
	CHECK_FALSE(rig.Pool.Is_Valid(fade));
	CHECK_FALSE(rig.Pool.Is_Finished(fade));
	rig.Tick(200);
	CHECK(rig.Mixer.Voice_State(0) != AudioVoiceState::FREE);
	CHECK_FALSE(rig.Pool.Is_Finished(fade));
	rig.Tick(400);
	CHECK(rig.Mixer.Voice_State(0) == AudioVoiceState::FREE);
	CHECK(rig.Pool.Is_Finished(fade));
}


TEST_CASE_FIXTURE(Fixture, "operations on a stale handle are no-ops")
{
	AudioHandle unknown = AudioHandle::Make(5, 77);
	rig.Pool.Stop(unknown);
	rig.Pool.End(unknown);
	rig.Pool.Retarget(unknown, 0.5f, 0.0f);
	CHECK_FALSE(rig.Pool.Is_Valid(unknown));
	CHECK(rig.Pool.State(unknown) == AUDIO_EVENT_DONE);
}


TEST_CASE_FIXTURE(Fixture, "a predelay waits without a voice, then starts")
{
	AudioEventTypeClass & pre = rig.Type("PRE", 1, SOUND_CONTROL_PREDELAY);
	pre.DelayMin = 100;
	pre.DelayMax = 100;
	AudioHandle handle = rig.Pool.Start(pre, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK(rig.Pool.Is_Playing(handle));
	CHECK(rig.Pool.State(handle) == AUDIO_EVENT_PENDING);
	CHECK(rig.Pool.Effects_In_Use() == 0u);
	rig.Tick(50);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_PENDING, "still waiting at 50 ms");
	rig.Tick(50);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_PLAYING, "starts at 100 ms");
}


TEST_CASE_FIXTURE(Fixture, "a delayed loop rests in a gap between cycles: attack and body, body only, body and decay")
{
	AudioEventTypeClass & cycles = rig.Type("CYC", 3, SOUND_CONTROL_LOOP | SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY, 1, 1);
	cycles.Loop = 3;
	cycles.DelayMin = 100;
	cycles.DelayMax = 100;
	AudioHandle handle = rig.Pool.Start(cycles, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("CYC", 0), rig.Clip("CYC", 1) }, 1, 2, 1);

	rig.Tick(210);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_GAP, "a gap after the first cycle");
	rig.Tick(50);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_GAP, "the gap lasts the delay");
	rig.Tick(50);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_PLAYING, "the second cycle starts after the delay");
	Check_Sequence(rig.Sequence(handle), { rig.Clip("CYC", 1) }, 0, 1, 1);

	rig.Tick(110);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_GAP, "a second gap");
	rig.Tick(100);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("CYC", 1), rig.Clip("CYC", 4 - 2) }, 0, 1, 1);

	rig.Tick(210);
	CHECK_MESSAGE(!rig.Pool.Is_Valid(handle), "done after three cycles");
	CHECK(rig.Provider.Balanced());
}


TEST_CASE_FIXTURE(Fixture, "an end during the gap of an endless delayed loop plays the decay at once")
{
	AudioEventTypeClass & ended = rig.Type("ENDGAP", 3, SOUND_CONTROL_LOOP | SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY, 1, 1);
	ended.DelayMin = 500;
	ended.DelayMax = 500;
	AudioHandle handle = rig.Pool.Start(ended, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(210);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_GAP, "the loop rests in the gap");

	rig.Pool.End(handle);
	rig.Tick(10);
	CHECK(rig.Pool.State(handle) == AUDIO_EVENT_PLAYING);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("ENDGAP", 2) }, 0, 0, 1);
	rig.Tick(110);
	CHECK_MESSAGE(!rig.Pool.Is_Valid(handle), "the decay finished the event");
}


TEST_CASE_FIXTURE(Fixture, "an end mid-cycle of a delayed loop still owes the decay after the fade")
{
	AudioEventTypeClass & ended = rig.Type("ENDGAP", 3, SOUND_CONTROL_LOOP | SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY, 1, 1);
	ended.DelayMin = 500;
	ended.DelayMax = 500;
	AudioHandle handle = rig.Pool.Start(ended, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(150);
	rig.Pool.End(handle);
	rig.Tick(300);
	CHECK(rig.Pool.State(handle) == AUDIO_EVENT_PLAYING);
	Check_Sequence(rig.Sequence(handle), { rig.Clip("ENDGAP", 2) }, 0, 0, 1);
	rig.Tick(110);
	CHECK_FALSE(rig.Pool.Is_Valid(handle));
	CHECK(rig.Provider.Balanced());
}


TEST_CASE_FIXTURE(Fixture, "a stop during the gap ends the event at once")
{
	AudioEventTypeClass & stopped = rig.Type("STOPGAP", 1, SOUND_CONTROL_LOOP);
	stopped.DelayMin = 500;
	stopped.DelayMax = 500;
	AudioHandle handle = rig.Pool.Start(stopped, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(110);
	REQUIRE(rig.Pool.State(handle) == AUDIO_EVENT_GAP);
	rig.Pool.Stop(handle);
	CHECK_FALSE(rig.Pool.Is_Valid(handle));
	CHECK(rig.Pool.Live_Count() == 0u);
}


TEST_CASE_FIXTURE(Fixture, "the clock is clamped, so a long stall does not fire a delay early")
{
	AudioEventTypeClass & pre = rig.Type("CLAMP", 1, SOUND_CONTROL_PREDELAY);
	pre.DelayMin = 1000;
	pre.DelayMax = 1000;
	AudioHandle handle = rig.Pool.Start(pre, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Now += 5000;
	rig.Pool.Service(rig.Now);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_PENDING, "a five second stall does not fire the delay");
	rig.Tick(250);
	rig.Tick(250);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_PENDING, "the delay still runs after the clamped ticks");
	rig.Tick(250);
	CHECK_MESSAGE(rig.Pool.State(handle) == AUDIO_EVENT_PLAYING, "the delay fires once the clamped clock catches up");
}


TEST_CASE_FIXTURE(Fixture, "at its limit, a type evicts its quietest event and refuses a quieter newcomer")
{
	AudioEventTypeClass & type = rig.Type("LIM", 1);
	type.Limit = 2;
	AudioHandle loud = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	AudioHandle quiet = rig.Pool.Start(type, AUDIO_GROUP_SFX, 0.5f, 0.0f);
	AudioHandle mid = rig.Pool.Start(type, AUDIO_GROUP_SFX, 0.8f, 0.0f);
	CHECK_FALSE(mid.Is_Null());
	CHECK_FALSE(rig.Pool.Is_Playing(quiet));
	CHECK(rig.Pool.Is_Playing(loud));
	CHECK(rig.Pool.Is_Playing(mid));
	CHECK(rig.Pool.Live_Count(type) == 2u);
	CHECK(type.LiveCount == 2);

	AudioHandle softer = rig.Pool.Start(type, AUDIO_GROUP_SFX, 0.3f, 0.0f);
	CHECK(softer.Is_Null());
	CHECK(rig.Pool.Live_Count(type) == 2u);
	CHECK(type.LiveCount == 2);
}


TEST_CASE_FIXTURE(Fixture, "at its limit, a type refuses a newcomer of equal volume")
{
	AudioEventTypeClass & single = rig.Type("ONE", 1);
	single.Limit = 1;
	AudioHandle first = rig.Pool.Start(single, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	AudioHandle second = rig.Pool.Start(single, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK(second.Is_Null());
	CHECK(rig.Pool.Is_Playing(first));
}


TEST_CASE_FIXTURE(Fixture, "at its limit, an interrupt type evicts its oldest event on a tie")
{
	AudioEventTypeClass & interrupt = rig.Type("INT", 1, SOUND_CONTROL_INTERRUPT);
	interrupt.Limit = 1;
	AudioHandle first = rig.Pool.Start(interrupt, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	AudioHandle second = rig.Pool.Start(interrupt, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK_FALSE(second.Is_Null());
	CHECK_FALSE(rig.Pool.Is_Playing(first));
	CHECK(rig.Pool.Is_Playing(second));
}


TEST_CASE_FIXTURE(Fixture, "a type without a limit admits every start")
{
	AudioEventTypeClass & unlimited = rig.Type("ANY", 1);
	unlimited.Limit = 0;
	for (int i = 0; i < 6; i++) {
		INFO("start ", i);
		CHECK_FALSE(rig.Pool.Start(unlimited, AUDIO_GROUP_SFX, 1.0f, 0.0f).Is_Null());
	}
}


TEST_CASE_FIXTURE(Fixture, "at its limit, a queue type parks the newcomer until the slot frees")
{
	AudioEventTypeClass & queued = rig.Type("QUE", 1, SOUND_CONTROL_QUEUE);
	queued.Limit = 1;
	AudioHandle first = rig.Pool.Start(queued, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	AudioHandle second = rig.Pool.Start(queued, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	REQUIRE_FALSE(second.Is_Null());
	CHECK(rig.Pool.State(second) == AUDIO_EVENT_PENDING);
	rig.Tick(50);
	CHECK(rig.Pool.State(second) == AUDIO_EVENT_PENDING);
	CHECK(rig.Pool.Is_Playing(first));
	rig.Tick(60);
	CHECK_FALSE(rig.Pool.Is_Valid(first));
	CHECK(rig.Pool.State(second) == AUDIO_EVENT_PLAYING);

	AudioHandle third = rig.Pool.Start(queued, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Pool.Stop(second);
	for (int i = 0; i < 25; i++) {
		rig.Tick(100);
	}
	CHECK_MESSAGE(!rig.Pool.Is_Valid(third), "a queued event that waited out its turn was dropped or finished");
}


TEST_CASE_FIXTURE(Fixture, "a full effects budget steals by priority, then age, then volume, and leaves streams alone")
{
	rig.Pool.Set_Budget(2);
	CHECK(rig.Pool.Budget() == 2u);

	AudioEventTypeClass & low = rig.Type("LOW", 1);
	low.Priority = 10;
	AudioEventTypeClass & high = rig.Type("HIGH", 1);
	high.Priority = 50;
	AudioEventTypeClass & lowest = rig.Type("LOWEST", 1);
	lowest.Priority = 5;

	AudioHandle a = rig.Pool.Start(low, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	AudioHandle b = rig.Pool.Start(low, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK_MESSAGE(rig.Pool.Effects_In_Use() == 2u, "the budget is full");

	AudioHandle c = rig.Pool.Start(high, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK_MESSAGE(!c.Is_Null(), "a higher priority steals");
	CHECK_MESSAGE(!rig.Pool.Is_Playing(a), "the older of two equals is stolen");
	CHECK(rig.Pool.Is_Playing(b));
	CHECK_MESSAGE(rig.Pool.Effects_In_Use() == 2u, "a stolen voice leaves the budget at once");

	AudioHandle d = rig.Pool.Start(lowest, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK_MESSAGE(d.Is_Null(), "a lower priority is refused when the budget is full");

	AudioHandle e = rig.Pool.Start(high, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK_FALSE(e.Is_Null());
	CHECK_MESSAGE(!rig.Pool.Is_Playing(b), "the lowest priority is the victim, not the oldest");
	CHECK(rig.Pool.Is_Playing(c));

	CHECK_MESSAGE(rig.Pool.Start(high, AUDIO_GROUP_SFX, 0.5f, 0.0f).Is_Null(), "same priority, quieter: refused");
	CHECK_MESSAGE(rig.Pool.Start(high, AUDIO_GROUP_SFX, 1.0f, 0.0f).Is_Null(), "same priority, same volume: refused");

	rig.Pool.Retarget(c, 0.5f, 0.0f);
	AudioHandle h = rig.Pool.Start(high, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK_FALSE(h.Is_Null());
	CHECK_MESSAGE(!rig.Pool.Is_Playing(c), "same priority: the one quieter by ten percent is stolen");
	CHECK(rig.Pool.Is_Playing(e));

	AudioStreamClass stream;
	stream.Init(4800, 1, RATE);
	AudioHandle music = rig.Pool.Start_Stream(&stream, AUDIO_GROUP_MUSIC, 1.0f, 0.0f);
	CHECK_MESSAGE(!music.Is_Null(), "a stream is outside the budget");
	CHECK(rig.Pool.Effects_In_Use() == 2u);
	AudioHandle speech = rig.Pool.Start_Stream(&stream, AUDIO_GROUP_SPEECH, 1.0f, 0.0f);
	CHECK_MESSAGE(!speech.Is_Null(), "streams start while the effects budget is full");
	rig.Pool.Stop(music);
	rig.Pool.Stop(speech);

	rig.Tick(20);
	CHECK_MESSAGE(rig.Pool.Effects_In_Use() == 2u, "after the ramps only the two winners remain");
	CHECK(rig.Pool.Live_Count() == 2u);
	rig.Tick(200);
	CHECK(rig.Pool.Live_Count() == 0u);
	CHECK(rig.Provider.Balanced());
}


TEST_CASE_FIXTURE(Fixture, "an event's volume follows the loudness curve and its pan places it")
{
	AudioEventTypeClass & type = rig.Type("LVL", 1, SOUND_CONTROL_LOOP, 0, 0, 0.5f);
	AudioHandle handle = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(20);
	CHECK_MESSAGE(Distance(rig.Last_Sample(), 0.5f) <= 0.01f, "full level passes the clip through");

	rig.Pool.Set_Volume(handle, 0.5f);
	rig.Tick(100);
	CHECK_MESSAGE(Distance(rig.Last_Sample(), 0.5f * Audio_Perceptual_Gain(0.5f)) <= 0.01f, "a set volume goes through the loudness curve");

	rig.Pool.Retarget(handle, 1.0f, -1.0f);
	rig.Tick(100);
	CHECK_MESSAGE(Distance(rig.Last_Sample(), 0.5f) <= 0.01f, "hard left pan keeps the left channel");
	CHECK_MESSAGE(Distance(rig.Last_Right(), 0.0f) <= 0.01f, "hard left pan silences the right channel");
}


TEST_CASE_FIXTURE(Fixture, "a type's volume scales the level")
{
	AudioEventTypeClass & half = rig.Type("HALF", 1, SOUND_CONTROL_LOOP, 0, 0, 0.5f);
	half.Volume = 0.5f;
	rig.Pool.Start(half, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(20);
	CHECK(Distance(rig.Last_Sample(), 0.5f * Audio_Perceptual_Gain(0.5f)) <= 0.01f);
}


TEST_CASE_FIXTURE(Fixture, "a volume shift attenuates once per event")
{
	AudioEventTypeClass & shifted = rig.Type("VSH", 1, SOUND_CONTROL_LOOP, 0, 0, 0.5f);
	shifted.VShiftMin = -50;
	shifted.VShiftMax = -50;
	rig.Pool.Start(shifted, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(20);
	CHECK(Distance(rig.Last_Sample(), 0.5f * Audio_Perceptual_Gain(0.5f)) <= 0.01f);
}


TEST_CASE_FIXTURE(Fixture, "a doubled pitch halves the play time")
{
	AudioEventTypeClass & pitched = rig.Type("FSH", 1, SOUND_CONTROL_NONE, 0, 0, 0.0f);
	pitched.FShiftMin = 100;
	pitched.FShiftMax = 100;
	AudioHandle handle = rig.Pool.Start(pitched, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(60);
	CHECK_FALSE(rig.Pool.Is_Valid(handle));
}


TEST_CASE_FIXTURE(Fixture, "a paused event does not advance, and finishes once resumed")
{
	AudioEventTypeClass & paused = rig.Type("PAUSE", 1, SOUND_CONTROL_NONE);
	AudioHandle handle = rig.Pool.Start(paused, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Pool.Pause(handle);
	rig.Tick(300);
	CHECK(rig.Pool.Is_Playing(handle));
	rig.Pool.Resume(handle);
	rig.Tick(120);
	CHECK_FALSE(rig.Pool.Is_Valid(handle));
}


TEST_CASE_FIXTURE(Fixture, "a raw play has no type, counts toward the budget, and stops by its tag")
{
	AudioSampleClass * clip = rig.Provider.Add("RAW", 0, 0.25f);
	int tag = 0;
	AudioHandle raw = rig.Pool.Start_Sample(rig.Provider.Pin(clip), AUDIO_GROUP_SYSTEM, 1.0f, 255, &tag);
	REQUIRE_FALSE(raw.Is_Null());
	CHECK(rig.Pool.Type(raw) == nullptr);
	CHECK(rig.Pool.Is_Tag_Playing(&tag));
	CHECK_MESSAGE(rig.Pool.Effects_In_Use() == 1u, "the system group counts toward the budget");
	rig.Tick(20);
	CHECK_MESSAGE(Distance(rig.Last_Sample(), 0.25f) <= 0.01f, "the raw clip plays at its level");

	rig.Pool.Stop_Tag(&tag);
	CHECK_FALSE(rig.Pool.Is_Tag_Playing(&tag));
	CHECK_FALSE(rig.Pool.Is_Valid(raw));
	rig.Tick(20);
	CHECK_MESSAGE(rig.Provider.Balanced(), "the raw pin is returned");
}


TEST_CASE_FIXTURE(Fixture, "a reused slot takes a new generation, and the stale handle stays invalid")
{
	AudioEventTypeClass & type = rig.Type("REUSE", 1);
	AudioHandle first = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	unsigned index = first.Index();
	rig.Tick(120);
	REQUIRE_FALSE(rig.Pool.Is_Valid(first));

	AudioHandle again;
	for (int i = 0; i < AUDIO_MAX_EVENTS && (again.Is_Null() || again.Index() != index); i++) {
		again = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	}
	CHECK(again.Index() == index);
	CHECK(again.Generation() != first.Generation());
	CHECK_FALSE(rig.Pool.Is_Valid(first));
	CHECK(rig.Pool.Is_Valid(again));

	rig.Pool.Stop_Group(AUDIO_GROUP_SFX, 0);
	CHECK_MESSAGE(rig.Pool.Live_Count() == 0u, "stopping the group empties it");
}


TEST_CASE_FIXTURE(Fixture, "an unplayable clip is handed to the mixer, which skips it, and the pool cleans up")
{
	AudioEventTypeClass & missing = rig.Type("GAP", 3);
	rig.Provider.Add("GAP", 0)->Frames = 0;
	AudioHandle skipped = rig.Pool.Start(missing, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	AudioSequenceClass sequence = rig.Sequence(skipped);
	CHECK(sequence.Count == 1u);
	CHECK(sequence.Clips[0] == rig.Clip("GAP", 0));
	rig.Tick(20);
	CHECK_FALSE(rig.Pool.Is_Valid(skipped));
	CHECK(rig.Provider.Balanced());
}


TEST_CASE_FIXTURE(Fixture, "a type whose clips are all missing refuses cleanly")
{
	AudioEventTypeClass & none = rig.Type("NONE", 2);
	std::strcpy(none.Name, "OTHER");
	CHECK(rig.Pool.Start(none, AUDIO_GROUP_SFX, 1.0f, 0.0f).Is_Null());
	CHECK(none.LiveCount == 0);
}


TEST_CASE_FIXTURE(Fixture, "stopping everything ends every live event and releases every pin")
{
	AudioEventTypeClass & live = rig.Type("LIVE", 1, SOUND_CONTROL_LOOP);
	rig.Pool.Start(live, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Pool.Start(live, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	CHECK(rig.Pool.Live_Count() == 2u);
	rig.Pool.Stop_All();
	CHECK(rig.Pool.Live_Count() == 0u);
	CHECK(live.LiveCount == 0);
	rig.Tick(20);
	CHECK(rig.Provider.Balanced());
}


// A start between two service calls must not take the voice of an event whose
// clip has ended but which has not been serviced yet.
TEST_CASE_FIXTURE(Fixture, "a start reaps an ended but unserviced event without taking over its voice")
{
	AudioEventTypeClass & type = rig.Type("OWN", 1);
	AudioHandle first = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Run(120 * (RATE / 1000));
	CHECK_MESSAGE(rig.Mixer.Voice_State(0) == AudioVoiceState::DONE, "the first voice is done but not yet serviced");
	CHECK_MESSAGE(rig.Pool.Is_Playing(first), "the first event is not yet reaped");

	AudioHandle second = rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	REQUIRE_FALSE(second.Is_Null());
	CHECK_MESSAGE(!rig.Pool.Is_Valid(first), "starting another event reaps the finished one");
	rig.Tick(50);
	CHECK_MESSAGE(rig.Pool.Is_Playing(second), "the second event keeps its voice through the next service");
	CHECK(rig.Pool.Effects_In_Use() == 1u);
	CHECK(rig.Pool.Live_Count() == 1u);
	rig.Tick(100);
	CHECK_MESSAGE(!rig.Pool.Is_Valid(second), "the second event finishes on its own");
	CHECK(rig.Provider.Balanced());
}


TEST_CASE_FIXTURE(Fixture, "a loop started over another type's finished voice keeps playing")
{
	AudioEventTypeClass & type = rig.Type("OWN", 1);
	AudioEventTypeClass & other = rig.Type("OWN2", 1, SOUND_CONTROL_LOOP);
	rig.Pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Run(120 * (RATE / 1000));
	AudioHandle second = rig.Pool.Start(other, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	for (int i = 0; i < 10; i++) {
		rig.Tick(100);
	}
	CHECK(rig.Pool.Is_Playing(second));
	CHECK(rig.Pool.Effects_In_Use() == 1u);
}


TEST_CASE_FIXTURE(Fixture, "a stream's volume ramps up, pauses silent, resumes, and a long fade can be cut short")
{
	ConstantStream stream(4);

	// A fade in: start silent, then ramp the volume up.
	AudioHandle handle = rig.Pool.Start_Stream(&stream.Stream, AUDIO_GROUP_MUSIC, 0.0f, 0.0f);
	REQUIRE_MESSAGE(!handle.Is_Null(), "a silent stream starts");
	rig.Pool.Set_Volume(handle, 1.0f, 200);
	rig.Tick(100);
	float middle = std::fabs(rig.Last_Sample());
	rig.Tick(150);
	float full = std::fabs(rig.Last_Sample());
	CHECK_MESSAGE(middle > 0.01f, "the volume rises over the requested time");
	CHECK_MESSAGE(middle < full, "the volume rises over the requested time");
	CHECK_MESSAGE(full > 0.45f, "the volume reaches the requested level");

	rig.Pool.Pause(handle, 50);
	rig.Tick(100);
	CHECK_MESSAGE(rig.Last_Sample() == 0.0f, "a paused stream is silent");
	CHECK_MESSAGE(rig.Pool.Is_Playing(handle), "a paused stream keeps its event");
	CHECK_FALSE(rig.Pool.Is_Finished(handle));
	rig.Pool.Resume(handle, 50);
	rig.Tick(100);
	CHECK_MESSAGE(std::fabs(rig.Last_Sample()) > 0.45f, "a resumed stream plays at its level again");

	rig.Pool.Fade(handle, 1000);
	rig.Tick(100);
	CHECK_FALSE(rig.Pool.Is_Valid(handle));
	CHECK_MESSAGE(!rig.Pool.Is_Finished(handle), "a fading stream is not finished");
	rig.Pool.Cut(handle, 20);
	rig.Tick(50);
	CHECK_MESSAGE(rig.Pool.Is_Finished(handle), "a cut fade finishes early");
}


TEST_CASE_FIXTURE(Fixture, "a cut never lengthens a fade")
{
	ConstantStream stream(4);
	AudioHandle kept = rig.Pool.Start_Stream(&stream.Stream, AUDIO_GROUP_MUSIC, 1.0f, 0.0f);
	rig.Pool.Fade(kept, 20);
	rig.Pool.Cut(kept, 1000);
	rig.Tick(50);
	CHECK(rig.Pool.Is_Finished(kept));
}


TEST_CASE_FIXTURE(Fixture, "a stopped paused stream is finished at once")
{
	ConstantStream stream(4);
	AudioHandle paused = rig.Pool.Start_Stream(&stream.Stream, AUDIO_GROUP_MUSIC, 1.0f, 0.0f);
	rig.Pool.Pause(paused);
	rig.Tick(10);
	rig.Pool.Stop(paused);
	rig.Tick(10);
	CHECK(rig.Pool.Is_Finished(paused));
}


// A stop during a slow fade in ends with the stop's own ramp.
TEST_CASE_FIXTURE(Fixture, "a stop during a fade in finishes at once")
{
	ConstantStream stream(4);
	AudioHandle rising = rig.Pool.Start_Stream(&stream.Stream, AUDIO_GROUP_MUSIC, 0.0f, 0.0f);
	rig.Pool.Set_Volume(rising, 1.0f, 2000);
	rig.Tick(100);
	rig.Pool.Stop(rising);
	rig.Tick(20);
	CHECK(rig.Pool.Is_Finished(rising));
}


TEST_CASE_FIXTURE(Fixture, "a crossfade drops no commands, and both streams finish their fades")
{
	ConstantStream one(4);
	ConstantStream two(4);

	AudioHandle old = rig.Pool.Start_Stream(&one.Stream, AUDIO_GROUP_MUSIC, 1.0f, 0.0f);
	rig.Tick(100);
	unsigned dropped = rig.Mixer.Dropped_Commands();
	rig.Pool.Fade(old, 3000);
	rig.Tick(16);
	AudioHandle next = rig.Pool.Start_Stream(&two.Stream, AUDIO_GROUP_MUSIC, 0.0f, 0.0f);
	rig.Pool.Set_Volume(next, 0.5f, 3000);
	for (int i = 0; i < 300; i++) {
		rig.Tick(16);
	}
	CHECK(rig.Mixer.Dropped_Commands() == dropped);

	for (int i = 0; i < 100; i++) {
		rig.Tick(16);
	}
	CHECK_MESSAGE(rig.Pool.Is_Finished(old), "a stream faded out finishes");

	rig.Pool.Fade(next, 1500);
	for (int i = 0; i < 120; i++) {
		rig.Tick(16);
	}
	CHECK_MESSAGE(rig.Pool.Is_Finished(next), "a stream faded while its volume rose finishes");
}


TEST_CASE_FIXTURE(Fixture, "under load, faded songs finish within their fades and no command reaches a voice its event no longer owns")
{
	rig.Pool.Set_Budget(4);
	rig.RandomHigh = 0;

	AudioEventTypeClass * types[] = {
		&rig.Type("S1", 1),
		&rig.Type("S2", 2, SOUND_CONTROL_RANDOM),
		&rig.Type("S3", 3, SOUND_CONTROL_LOOP | SOUND_CONTROL_ATTACK | SOUND_CONTROL_DECAY, 1, 1),
		&rig.Type("S4", 1, SOUND_CONTROL_LOOP),
		&rig.Type("S5", 1, SOUND_CONTROL_QUEUE),
		&rig.Type("S6", 1, SOUND_CONTROL_PREDELAY),
		&rig.Type("S7", 2, SOUND_CONTROL_LOOP | SOUND_CONTROL_INTERRUPT),
	};
	types[1]->Limit = 2;
	types[3]->Loop = 3;
	types[3]->DelayMin = 30;
	types[3]->DelayMax = 80;
	types[4]->Limit = 1;
	types[5]->DelayMin = 20;
	types[5]->DelayMax = 60;
	types[6]->Limit = 1;
	for (int t = 0; t < 7; t++) {
		types[t]->Priority = 10 + t * 10;
	}

	AudioStreamClass rings[3];
	std::vector<int16_t> constant((size_t)RATE * 8, (int16_t)(0.5f * 32767.0f));
	for (AudioStreamClass & ring : rings) {
		ring.Init(RATE * 8, 1, RATE);
		ring.Ring.Write(constant.data(), (unsigned)constant.size());
	}

	unsigned seed = 12345u;
	auto next = [&seed](unsigned range) {
		seed = seed * 1103515245u + 12345u;
		return((seed >> 16) % range);
	};

	std::vector<AudioHandle> handles;
	int music = 0;
	AudioHandle current = rig.Pool.Start_Stream(&rings[0], AUDIO_GROUP_MUSIC, 1.0f, 0.0f);
	AudioHandle fading;
	unsigned fadedat = 0;
	unsigned latefades = 0;
	unsigned dropped = rig.Mixer.Dropped_Commands();

	for (int tick = 0; tick < 3000; tick++) {
		for (unsigned n = next(4); n > 0; n--) {
			AudioHandle h = rig.Pool.Start(*types[next(7)], AUDIO_GROUP_SFX, 0.2f + 0.1f * (float)next(8), 0.0f);
			if (!h.Is_Null()) {
				handles.push_back(h);
			}
		}
		for (AudioHandle h : handles) {
			rig.Pool.Retarget(h, 0.2f + 0.1f * (float)next(8), (float)next(3) - 1.0f);
		}
		if (!handles.empty() && next(5) == 0) {
			AudioHandle h = handles[next((unsigned)handles.size())];
			switch (next(3)) {
				case 0: rig.Pool.Stop(h); break;
				case 1: rig.Pool.End(h); break;
				default: rig.Pool.Fade(h, 50 + (int)next(500)); break;
			}
		}
		if (handles.size() > 200) {
			handles.erase(handles.begin(), handles.begin() + 100);
		}

		// A song change every two seconds: the old one fades over 1.5 s, the next waits for it.
		if (tick % 125 == 0 && tick > 0 && fading.Is_Null()) {
			rig.Pool.Fade(current, 1500);
			fading = current;
			fadedat = rig.Now;
			current.Clear();
		}
		if (!fading.Is_Null() && rig.Pool.Is_Finished(fading)) {
			if (rig.Now - fadedat > 1700) {
				latefades++;
			}
			fading.Clear();
			music = (music + 1) % 3;
			rings[music].Ring.Write(constant.data(), rings[music].Ring.Available_Write());
			current = rig.Pool.Start_Stream(&rings[music], AUDIO_GROUP_MUSIC, 1.0f, 0.0f);
		} else if (!fading.Is_Null() && rig.Now - fadedat > 1700) {
			latefades++;
		}
		rig.Tick(16);
	}

	CHECK_MESSAGE(latefades == 0u, "ticks at which a song had been fading for more than 1.7 s");
	CHECK(rig.Mixer.Dropped_Commands() == dropped);
}


TEST_CASE_FIXTURE(Fixture, "unchanged re-aims send no commands, and a stop after many still arrives")
{
	AudioEventTypeClass & loop = rig.Type("AMB", 1, SOUND_CONTROL_LOOP);
	AudioHandle hum = rig.Pool.Start(loop, AUDIO_GROUP_SFX, 0.5f, 0.25f);
	rig.Tick(16);

	// Placed sounds are re-aimed on every update, many times between two renders.
	unsigned dropped = rig.Mixer.Dropped_Commands();
	for (int i = 0; i < AUDIO_COMMAND_QUEUE_SIZE * 4; i++) {
		rig.Pool.Retarget(hum, 0.5f, 0.25f);
		rig.Pool.Set_Volume(hum, 0.5f);
		rig.Pool.Set_Pan(hum, 0.25f);
	}
	rig.Pool.Fade(hum, 100);
	for (int i = 0; i < 20; i++) {
		rig.Tick(16);
	}
	CHECK(rig.Mixer.Dropped_Commands() == dropped);
	CHECK(rig.Pool.Is_Finished(hum));
}


TEST_CASE_FIXTURE(Fixture, "a change the full command ring refused is sent when it is repeated")
{
	AudioEventTypeClass & loop = rig.Type("DRONE", 1, SOUND_CONTROL_LOOP, 0, 0, 0.5f);
	AudioHandle drone = rig.Pool.Start(loop, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(20);
	REQUIRE_MESSAGE(rig.Last_Sample() > 0.4f, "the drone plays at full level");

	AudioCommand filler = {};
	filler.Type = AudioCommandType::SET_PITCH;
	filler.Slot = AUDIO_MAX_VOICES - 1;

	SUBCASE("a volume change")
	{
		while (rig.Mixer.Push(filler)) {
		}
		rig.Pool.Set_Volume(drone, 0.25f);
		rig.Tick(20);
		rig.Pool.Set_Volume(drone, 0.25f);
		rig.Tick(100);
		CHECK(Distance(rig.Last_Sample(), 0.5f * Audio_Perceptual_Gain(0.25f)) <= 0.01f);
	}

	SUBCASE("a pan change")
	{
		while (rig.Mixer.Push(filler)) {
		}
		rig.Pool.Set_Pan(drone, -1.0f);
		rig.Tick(20);
		rig.Pool.Set_Pan(drone, -1.0f);
		rig.Tick(100);
		CHECK(Distance(rig.Last_Right(), 0.0f) <= 0.01f);
	}
}


// A change with its own time replaces a slower one to the same volume.
TEST_CASE_FIXTURE(Fixture, "an immediate change is not held to an earlier slow one")
{
	AudioEventTypeClass & loop = rig.Type("DRONE", 1, SOUND_CONTROL_LOOP, 0, 0, 0.5f);
	AudioHandle drone = rig.Pool.Start(loop, AUDIO_GROUP_SFX, 1.0f, 0.0f);
	rig.Tick(20);
	rig.Pool.Set_Volume(drone, 0.25f);
	rig.Tick(100);

	rig.Pool.Set_Volume(drone, 1.0f, 5000);
	rig.Tick(20);
	rig.Pool.Set_Volume(drone, 1.0f, 0);
	rig.Tick(20);
	CHECK(Distance(rig.Last_Sample(), 0.5f) <= 0.01f);
}


TEST_CASE("a pool refuses a second init, and its shutdown releases the pins and counts and invalidates the handles")
{
	ProviderClass provider;
	AudioMixerClass mixer;
	AudioEventTypeClass type;
	std::strcpy(type.Name, "SD");
	type.SoundCount = 1;
	type.Control = SOUND_CONTROL_LOOP;
	provider.Add("SD", 0);
	{
		AudioEventPoolClass pool;
		REQUIRE(mixer.Init(RATE, 2));
		REQUIRE(pool.Init(&mixer, &provider));
		CHECK_FALSE(pool.Init(&mixer, &provider));
		AudioHandle handle = pool.Start(type, AUDIO_GROUP_SFX, 1.0f, 0.0f);
		CHECK(pool.Is_Playing(handle));
		pool.Shutdown();
		CHECK(provider.Balanced());
		CHECK(type.LiveCount == 0);
		CHECK_FALSE(pool.Is_Valid(handle));
	}
	mixer.Shutdown();
}
