---
key: Attack
scope: sounds
label: Attack sample count
see_also: [Decay, Sounds, Control]
when_omitted:
  kind: context-dependent
  note: "`1` when the section's `Control=` sets `ATTACK`, else `0`. A section with no `Control=` line takes the `[Defaults]` count."
---

How many of the first names in [`Sounds=`](/keys/sounds/) are attack samples. Each play draws one attack sample at random and plays it once, before the body. A looping sound plays it only before its first cycle.

`Attack=` sets the count even when [`Control=`](/keys/control/) has no `ATTACK`.

```ini title="sound01.ini"
[ENGINE]
Sounds=START1 START2 RUN
Control=LOOP ATTACK
Attack=2
```

Each play of `ENGINE` starts with `START1` or `START2` and then repeats `RUN` until the game stops the sound.

An endless loop placed by the [Play Sound Effect At](/mapping/actions/taction-play-sound-at/) trigger action stops while its waypoint is out of range. It restarts without its attack when the waypoint comes back into range, and after a saved game is loaded.

The attack and [`Decay=`](/keys/decay/) samples must leave at least one body sample in the list. When they do not, every sample is body and no attack or decay plays.
