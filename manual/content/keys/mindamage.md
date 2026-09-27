---
key: MinDamage
summary: The smallest damage a warhead may deal to a target close to the impact.
when_omitted:
  kind: value
  value: "1"
---

A target close to the blast loses at least this much strength from an ordinary hit. "Close" means fewer than four distance steps from the impact, where the warhead's [`Spread`](/keys/spread/#scope-warheadtype) sets the size of a step. Beyond that the damage can fall to zero. [How distance thins the damage](/systems/warheads/#how-distance-thins-the-damage) gives the distances.

The floor applies after the warhead's [`Verses`](/keys/verses/) entry, so even a `Verses` of `0%` deals this much to a close target. [`MaxDamage`](/keys/maxdamage/) caps the result afterward. [What the target loses](/systems/warheads/#what-the-target-loses) lists the full order of steps.

```ini title="rules.ini"
[CombatDamage]
MinDamage=10
```

:::caution[The floor also raises the low-power damage tick]
The [structure damage tick](/systems/power/#the-structure-damage-tick) deals 1 point at distance zero, so it deals at least this value instead. With `MinDamage=10`, a power shortfall costs each affected structure ten strength per tick instead of one.
:::
