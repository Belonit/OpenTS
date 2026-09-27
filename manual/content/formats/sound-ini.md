---
format_id: sound-ini
title: SOUND.INI
summary: Registers sound IDs and defines each one's samples, loudness, priority, range, and playback behavior.
kind: file
filenames:
  - SOUND.INI
  - SOUND01.INI
key_scopes:
  - file: sound01.ini
    section:
      kind: identifier
      source: sound
related:
  - { type: format, id: aud }
  - { type: format, id: opents-ini }
source_files:
  - code/init.cpp
  - code/vocini.cpp
  - code/voc.cpp
---

The game reads `SOUND.INI` and `SOUND01.INI` at startup and combines them into one set of sound definitions. Both files are read whether or not Firestorm is installed. The `Sound` and `SoundExpansion` keys in [OPENTS.INI](/formats/opents-ini/) can name other files.

Either file on its own is enough. If neither file can be read, the game does not start.

Any section or key can appear in either file. When both files set the same key in the same section, the value from `SOUND01.INI` is used. A key that only one file sets keeps that file's value. This applies to `[General]`, `[Defaults]` and `[SoundList]` as well as to the sound sections.

```ini title="SOUND.INI"
[General]
Channels=16

[Defaults]
Priority=NORMAL
Limit=3

[SoundList]
0=MYALERT
1=MYLOOP

[MYALERT]
Priority=100

[MYLOOP]
Sounds=LOOPIN LOOPBODY1 LOOPBODY2 LOOPOUT
Control=LOOP RANDOM ATTACK DECAY
Loop=4
Delay=250 750
Range=20
Limit=1
```

`MYALERT` has no `Sounds=`, so it plays the sample named `MYALERT`, with priority 100 and every other value from `[Defaults]`. `MYLOOP` plays `LOOPIN`, then one of `LOOPBODY1` and `LOOPBODY2` four times with 250 to 750 milliseconds of silence between the cycles, then `LOOPOUT`. The body sample is chosen once, so all four cycles play the same one. Only one copy of `MYLOOP` plays at a time, and when it plays at a place on the map it fades out over the 20 cells beyond the edge of the view.

## `[SoundList]`

Each value in `[SoundList]` registers one sound ID. The name to the left of `=` only identifies the entry. Keys that name a sound use this ID, in any letter case. An unregistered name is ignored. A key that takes one sound keeps the value it had, and a list of sounds leaves the name out.

A sound's settings come from the section named after its ID. Without such a section, the sound plays the sample named like the ID, with the values from `[Defaults]`.

Entries merge by the name to the left of `=`, as every other key does. An entry `0=MYSOUND` in `SOUND01.INI` therefore replaces the entry named `0` in `SOUND.INI`, and the sound that the `SOUND.INI` entry named is registered only if another entry also lists it. Give entries you add to one file names the other file does not use. An entry with an empty value is ignored, so it cannot remove an entry from the other file.

Sounds are numbered from 0 in the order they are registered. The `SOUND.INI` entries that `SOUND01.INI` does not replace come first, in their order, followed by every `SOUND01.INI` entry in its order. An ID listed twice is registered once, at its first position. A map trigger that plays a sound stores this number, and so does a save game for each endlessly looping sound a trigger left at a waypoint. Adding, removing or moving an entry ahead of a sound changes which sound those triggers and saves play.

## Samples

Each name in [`Sounds=`](/keys/sounds/) is a sample file name without its extension. A sound without `Sounds=` has one sample, named like its ID. [Sound effects](/systems/sound-effects/#samples) gives the order in which the game tries the extensions, and covers missing samples, the size limit, and how long a decoded sample stays in memory.

A loose file is used instead of an archive member with the same name and extension. The extension order comes first, so an archived `MYGUN.WAV` is used before a loose `MYGUN.AUD`.

## `[General]`

`[General]` holds [`Channels=`](/keys/channels/), the number of sound effects that can play at once.

## `[Defaults]`

`[Defaults]` sets the value that every sound section uses for a key it omits. It accepts every sound-section key except `Sounds=`. A key that `[Defaults]` also omits takes the default shown for it under [Accepted settings](/formats/sound-ini/#accepted-settings).

A key that a sound section sets replaces the `[Defaults]` value. The flags in `Type=` and `Control=` are not added to those in `[Defaults]`.

A sound section that sets `Control=` without `Attack=` has one attack sample when its `Control=` includes `ATTACK`, and none otherwise, whatever `[Defaults]` sets for `Attack=`. `Decay=` and `DECAY` work the same way.

## Sound sections

A sound section is read only when its name is a sound ID registered in `[SoundList]`. Its keys are listed under [Accepted settings](/formats/sound-ini/#accepted-settings), and each key's page gives its values and default.

The keys and the flag names in [`Type=`](/keys/type/#scope-sounds) and [`Control=`](/keys/control/) follow Yuri's Revenge. Separate flags with spaces or commas. A flag the game does not recognize is left out. A value in which no flag is recognized still replaces the `[Defaults]` flags, leaving the sound with none.

[Sound effects](/systems/sound-effects/) explains how the keys work together when a sound plays: which samples play, how a sound at a place on the map fades and pans, and how sounds compete for voices.

## Files written for Tiberian Sun

The sound files shipped with Tiberian Sun and Firestorm read without changes. Their sound sections set at most `Priority=`. An integer priority is kept as written, so a sound with a higher number still wins a voice over one with a lower number. Every other key takes its default. Each shipped sound is therefore a one-shot at full volume, with up to three copies playing at once. When it plays at a place on the map, it fades out over the 28 cells beyond the edge of the view.

Sections copied from a Yuri's Revenge file also read, with two differences:

- `Volume=1` is full volume, where Yuri's Revenge reads it as one percent.
- A `Delay=` number without a decimal point is in milliseconds. Write a delay in seconds with a decimal point, such as `Delay=5.0 15.0`.

A `Volume=` above 1 written for an earlier OpenTS release now reads as a percentage; [`Volume=`](/keys/volume/) explains what to change.
