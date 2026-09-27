---
key: BurstDelay1
summary: The gap in frames between the second and third shot of a burst.
see_also: [Burst, ROF, BurstDelay0, BurstDelay2, BurstDelay3]
when_omitted:
  kind: value
  value: "-1"
---

`BurstDelay1` is the wait, in game frames, after the second shot of a burst and before the third. `-1` gives a random three to five frames instead.

```ini title="rules.ini"
[MyTripleCannon] ; example WeaponType
Burst=3
BurstDelay1=6 ; six frames between the second shot and the third
```

The wait applies only when [`Burst`](/keys/burst/) is above `2`. With `Burst=2`, the second shot is the last of the burst and is followed by [`ROF`](/keys/rof/#scope-weapontype) instead.

Any value other than `-1` is used as written. The house rate-of-fire bias, the random extra frames and the veteran rate-of-fire ability change only the `ROF` wait. [`Burst`](/keys/burst/) lists the weapons and structures that never use the short gap.
