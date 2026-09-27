---
key: BurstDelay2
summary: The gap in frames between the third and fourth shot of a burst.
see_also: [Burst, ROF, BurstDelay0, BurstDelay1, BurstDelay3]
when_omitted:
  kind: value
  value: "-1"
---

`BurstDelay2` is the wait, in game frames, after the third shot of a burst and before the fourth. `-1` gives a random three to five frames instead.

```ini title="rules.ini"
[MyQuadCannon] ; example WeaponType
Burst=4
BurstDelay2=6 ; six frames between the third shot and the fourth
```

The wait applies only when [`Burst`](/keys/burst/) is above `3`. With `Burst=3`, the third shot is the last of the burst and is followed by [`ROF`](/keys/rof/#scope-weapontype) instead.

Any value other than `-1` is used as written. The house rate-of-fire bias, the random extra frames and the veteran rate-of-fire ability change only the `ROF` wait. [`Burst`](/keys/burst/) lists the weapons and structures that never use the short gap.
