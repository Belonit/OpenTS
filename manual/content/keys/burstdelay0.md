---
key: BurstDelay0
summary: The gap in frames between the first and second shot of a burst.
see_also: [Burst, ROF, BurstDelay1, BurstDelay2, BurstDelay3]
when_omitted:
  kind: value
  value: "-1"
---

`BurstDelay0` is the wait, in game frames, after the first shot of a burst and before the second. `-1` gives a random three to five frames instead.

```ini title="rules.ini"
[MyTwinCannon] ; example WeaponType
Burst=2
BurstDelay0=4 ; four frames between the first shot and the second
```

The wait applies only when [`Burst`](/keys/burst/) is above `1`. With `Burst=1`, the first shot is the last of the burst and is followed by [`ROF`](/keys/rof/#scope-weapontype) instead.

Any value other than `-1` is used as written. The house rate-of-fire bias, the random extra frames and the veteran rate-of-fire ability change only the `ROF` wait. [`Burst`](/keys/burst/) lists the weapons and structures that never use the short gap.
