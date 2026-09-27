---
key: Sounds
scope: sounds
label: Sample list
see_also: [Attack, Decay, Control]
when_omitted:
  kind: computed
  note: The one sample named like the section.
---

The samples the sound plays, named without an extension and separated by spaces or commas. The engine reads the first 32 names and ignores the rest. The first [`Attack=`](/keys/attack/) names are attack samples and the last [`Decay=`](/keys/decay/) names are decay samples. The rest are the body, and [`Control=`](/keys/control/) decides how the body plays.

```ini title="sound01.ini"
[MYLOOP]
Sounds=LOOPIN LOOPBODY1 LOOPBODY2 LOOPOUT
Control=LOOP RANDOM ATTACK DECAY
Loop=4
```

Here `LOOPIN` is the attack sample, `LOOPOUT` the decay sample, and `LOOPBODY1` and `LOOPBODY2` the body.

Each name is looked up the first time a play needs it, as a loose file or in any mounted archive. The extensions are tried in the order `.WAV`, `.OGG`, `.FLAC`, `.MP3` and `.AUD`. [Sound effects](/systems/sound-effects/#samples) covers the sample formats and sizes the engine accepts.

A sample that cannot be found is left out of the play. When the body is one chosen sample, the next body sample in the list stands in for a missing one. A play that finds none of the samples it needs does not play.
