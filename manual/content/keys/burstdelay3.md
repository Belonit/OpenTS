---
key: BurstDelay3
summary: The gap in frames between the fourth and fifth shot of a burst.
see_also: [Burst, ROF, BurstDelay0, BurstDelay1, BurstDelay2]
when_omitted:
  kind: value
  value: "-1"
---

`BurstDelay3` is the wait, in game frames, after the fourth shot of a burst and before the fifth. `-1` gives a random three to five frames instead.

```ini title="rules.ini"
[MyChaingun] ; example WeaponType
Burst=5
BurstDelay3=3 ; three frames between the fourth shot and the fifth
```

The wait applies only when [`Burst`](/keys/burst/) is above `4`. With `Burst=4`, the fourth shot is the last of the burst and is followed by [`ROF`](/keys/rof/#scope-weapontype) instead.

Any value other than `-1` is used as written. The house rate-of-fire bias, the random extra frames and the veteran rate-of-fire ability change only the `ROF` wait. [`Burst`](/keys/burst/) lists the weapons and structures that never use the short gap.

No key sets the wait after the fifth or a later shot. Those gaps are a random three to five frames.
