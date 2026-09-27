---
key: ProneDamage
summary: The fraction of the damage a prone infantryman takes, where one is the full amount.
see_also: [Verses, Webby]
when_omitted:
  kind: value
  value: "1"
---

`ProneDamage` multiplies the damage an infantryman takes from this warhead while it is lying down. A value below one reduces that damage, and a value above one increases it. The percentage form is divided by 100, so `300%` and `3` are the same setting.

```ini title="rules.ini"
[MyGasWH] ; example WarheadType
ProneDamage=300% ; prone infantry take three times the damage
```

The multiplier applies only when **all of** these hold:

- the infantryman is prone;
- the damage is above zero, so healing is not scaled;
- the damage is not [forced](/keys/c4warhead/), so forced damage arrives in full however low the value.

The scaled damage is rounded down and then raised to at least one point. Even `ProneDamage=0` therefore passes one point on to the later steps. [`Verses`](/keys/verses/) and the other reductions apply after this step; [What the target loses](/systems/warheads/#what-the-target-loses) gives the full order.

A [`Webby=yes`](/keys/webby/) warhead sets the damage to zero for every infantryman it entangles, after this scaling, so `ProneDamage` changes nothing for them. An infantryman with [`IsWebImmune=yes`](/keys/iswebimmune/) is not entangled and takes the scaled damage.
