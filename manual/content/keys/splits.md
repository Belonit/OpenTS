---
key: Splits
summary: Breaks the projectile into a burst of bomblets when it detonates.
see_also: [Airburst, AirburstWeapon, Cluster, RetargetAccuracy]
when_omitted:
  kind: context-dependent
  note: "The value of `Airburst` in the same section, so `Airburst=yes` alone makes the projectile split."
---

A splitting projectile detonates once and then releases [`Cluster`](/keys/cluster/) bomblets of its [`AirburstWeapon`](/keys/airburstweapon/). An ordinary projectile instead detonates `Cluster` times around the point of impact. The `AirburstWeapon` page describes what each bomblet takes from that weapon, and [`RetargetAccuracy`](/keys/retargetaccuracy/) decides what each one is aimed at.

The splitting projectile's blast is never pulled onto a nearby target. That is the third move in [Where the blast lands](/systems/projectile-flight/#where-the-blast-lands); the first two apply as they do to an ordinary projectile.

:::danger[A splitting projectile with no `AirburstWeapon` crashes the game]
When a splitting projectile with a [`Cluster`](/keys/cluster/) above `0` detonates, the game crashes unless [`AirburstWeapon`](/keys/airburstweapon/) names a weapon with a `Projectile`. The `AirburstWeapon` page lists the settings that leave it without one. Because this key defaults to `Airburst`, an `Airburst=yes` projectile that does not set `Splits=no` counts as a splitting projectile here.
:::

:::caution[Repeat `Splits=no` in every rules file that declares the section]
Each rules file that contains the projectile's section resets this key to the value of `Airburst` unless that file sets `Splits` itself. This happens even when the file changes a different key. On an `Airburst=yes` projectile, `Splits=no` must therefore be written in every file that declares the section.
:::
