---
key: EMEffect
summary: A projectile carrying the warhead creates an EM pulse where it detonates instead of dealing blast damage.
see_also: ["system:emp-pulse"]
when_omitted:
  kind: value
  value: "no"
---

The projectile [creates a pulse](/systems/emp-pulse/#firing-a-pulse) where it detonates. The warhead's [`Spread`](/keys/spread/#scope-warheadtype) sets the pulse's radius, and the weapon's [`Damage`](/keys/damage/#scope-weapontype) sets how long the pulse lasts; the linked section explains both. The detonation deals no blast damage and has none of a blast's ground effects, such as cratering or cracking ice.

The pulse forms where the projectile is when it detonates. An ordinary shot first moves its detonation onto a nearby target or its fuse point; an EM pulse projectile does not. It still moves onto the target's center when it ends within 32 leptons (an eighth of a cell), unless the projectile is [`Airburst=yes`](/keys/airburst/) or [`Inaccurate=yes`](/keys/inaccurate/).

Explosions that do not come from a projectile, such as the collateral blast of a dying [`Explodes=yes`](/keys/explodes/#scope-aircrafttype) object or one with the `EXPLODES` [ability](/systems/veterancy/#abilities), deal ordinary blast damage through the warhead.

Every explosion that uses the warhead picks its impact animation at random from the warhead's [`AnimList`](/keys/animlist/), so any entry can appear whatever the damage. Over water, a [`Conventional=yes`](/keys/conventional/) warhead still chooses its splash by damage.
