---
key: Decay
scope: sounds
label: Decay sample count
see_also: [Attack, Sounds, Control]
when_omitted:
  kind: context-dependent
  note: "`1` when the section's `Control=` sets `DECAY`, else `0`. A section with no `Control=` line takes the `[Defaults]` count."
---

How many of the last names in [`Sounds=`](/keys/sounds/) are decay samples. Each play draws one decay sample at random and plays it once, after the body. A looping sound plays it after its last cycle, so only a loop with [`Loop=`](/keys/loop/) above `0` reaches its decay.

`Decay=` sets the count even when [`Control=`](/keys/control/) has no `DECAY`.

```ini title="sound01.ini"
[DOOR]
Sounds=DOOROPEN DOORSLAM1 DOORSLAM2
Control=DECAY
Decay=2
```

Each play of `DOOR` plays `DOOROPEN` and then `DOORSLAM1` or `DOORSLAM2`.

A sound the game stops early, such as one whose place scrolls out of range, fades out without its decay. An endless loop always ends that way, so it never plays its decay.

The [`Attack=`](/keys/attack/) and decay samples must leave at least one body sample in the list. When they do not, every sample is body and no attack or decay plays.
