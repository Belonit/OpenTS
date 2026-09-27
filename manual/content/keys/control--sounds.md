---
key: Control
scope: sounds
label: How the samples are played
see_also: [Sounds, Loop, Delay, Attack, Decay, Limit]
when_omitted:
  kind: value
  value: NORMAL
---

Flags that decide how each play is built from the samples in [`Sounds=`](/keys/sounds/). Separate the flags with spaces or commas; they combine. The flags follow Yuri's Revenge, with `SEQUENTIAL` and `QUEUE` from Vinifera. A `Control=` line in a sound section replaces the flags from `[Defaults]` instead of adding to them.

- `NORMAL` sets no flag. On its own, the sound plays its first body sample once.
- `LOOP` repeats the body [`Loop=`](/keys/loop/) times, or until the game stops the sound when `Loop=0`. [`Delay=`](/keys/delay/) can put a silence between cycles.
- `RANDOM` draws one body sample at random for each play and keeps it for every cycle of that play.
- `SEQUENTIAL` gives each play the next body sample in list order, returning to the first after the last.
- `ALL` plays every body sample in list order, and a loop repeats the whole run. `ALL` wins over `RANDOM`, and `RANDOM` wins over `SEQUENTIAL`.
- `PREDELAY` makes each play wait one `Delay=` silence before its first sample. This applies to one-shots as well as loops, and a loop still waits between cycles.
- `INTERRUPT` lets a new copy that reaches [`Limit=`](/keys/limit/) replace the quietest copy when the two are within one percent in loudness. Without it, that new copy is refused.
- `ATTACK` makes the first sample an attack sample, and `DECAY` makes the last sample a decay sample. [`Attack=`](/keys/attack/) and [`Decay=`](/keys/decay/) set other counts.
- `QUEUE` lets a play refused when it starts keep trying for up to two seconds before it is dropped, whether `Limit=` refused it or no voice was free. It does not cover a `PREDELAY` play refused when its silence ends, or a later cycle of a loop with a `Delay=`.
- `AMBIENT` is accepted and has no effect.

A flag the engine does not recognize is ignored.

```ini title="sound01.ini"
[MYLOOP]
Sounds=LOOPIN LOOPBODY1 LOOPBODY2 LOOPOUT
Control=LOOP RANDOM ATTACK DECAY
Loop=4
```

Each play of `MYLOOP` plays `LOOPIN`, then one of `LOOPBODY1` and `LOOPBODY2` four times, then `LOOPOUT`.
