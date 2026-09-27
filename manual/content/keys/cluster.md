---
key: Cluster
summary: The number of blasts an ordinary projectile delivers, or the number of bomblets a splitting one releases.
see_also: [Splits, AirburstWeapon, RetargetAccuracy]
when_omitted:
  kind: value
  value: "1"
---

[`Splits`](/keys/splits/) decides which of the two the value counts.

An ordinary projectile detonates this many times, and each blast deals the projectile's full damage around its point. The first blast lands at the point of impact. Each later blast lands one to two cells from that point in a random direction, with the distance drawn again for every blast. Only the first blast therefore strikes the point of impact at full strength.

A splitting projectile detonates once and then releases this many bomblets of its [`AirburstWeapon`](/keys/airburstweapon/). [`RetargetAccuracy`](/keys/retargetaccuracy/) decides what each bomblet aims at. [Clusters and splitting](/systems/projectile-flight/#clusters-and-splitting) gives the order of the split.

```ini title="rules.ini"
[MYSHRAPNELSHELL] ; a BulletType, registered by a weapon naming it as its Projectile
Image=120MM
Arcing=yes
Cluster=4 ; four full-damage blasts, one where the shell lands and three scattered around it
```

:::caution[Splashes from a cluster over a shoreline]
Over water, a [`Conventional=yes`](/keys/conventional/) warhead plays a splash from [`SplashList`](/keys/splashlist/) in place of its explosion. Every blast of a cluster uses the ground under the projectile to choose between the two, so a cluster falling across a shoreline shows only splashes or only explosions, whatever each blast lands on. A blast two or more terrain levels above the ground beneath it always shows the explosion. The damage and the animation are still placed at each blast's point.
:::

:::caution[Keep `Cluster` at `1` or more on an ordinary projectile]
With `Cluster=0` or below, an ordinary projectile deals no damage, shows no explosion and throws no lighting flash. It is removed when it goes off. A splitting projectile still detonates once at `0` and releases no bomblets.
:::
