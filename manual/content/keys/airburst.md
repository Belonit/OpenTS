---
key: Airburst
summary: Holds a homing projectile at cruising height so that it goes off above its target rather than diving onto it.
see_also: [Splits, AirburstWeapon, Cluster, VeryHigh, ROT]
when_omitted:
  kind: value
  value: "no"
---

Only a homing projectile is affected: one whose [`ROT`](/keys/rot/#scope-bullettype) is above zero.

An ordinary homing projectile follows the terrain until its last three cells of approach, or six with [`VeryHigh=yes`](/keys/veryhigh/), and then pitches straight at its target. An airburst projectile never makes that dive. It keeps following the terrain however little distance is left, holding ten terrain levels of clearance above the ground ahead of it.

Terrain following needs a turn rate above `1`, and it does not run during the launch phase. A projectile at `ROT=1` under the stock [`MissileROTVar`](/keys/missilerotvar/) never follows the terrain, so it never holds that clearance. The other changes below still apply to it.

An airburst projectile measures the distance still to run on the horizontal alone. Every other homing projectile counts a quarter of the height difference toward that distance. An airburst projectile therefore counts as having arrived once it is over its target, not once it has reached it.

An airburst projectile goes off where it is. A projectile that arrives while still in the air is normally moved onto the target coordinate first, and one whose fuse trips close to its target is moved onto the victim. An airburst projectile skips both, so the blast happens overhead.

An airburst projectile is also exempt from the check that detonates a homing projectile once it stops gaining on its target, because it is meant to hang above its target.

A projectile chasing an aircraft never follows the terrain; it flies straight at its target. On that shot the clearance above does not apply, but the horizontal distance measure, the detonation changes and the exemption from the stall check all do.

:::danger[This setting also switches splitting on, and a splitting projectile with no weapon crashes the game]
[`Splits`](/keys/splits/) takes its value from this key whenever the projectile's section does not set `Splits` itself, so `Airburst=yes` alone makes the projectile a splitting one. A splitting projectile with a [`Cluster`](/keys/cluster/) above `0` crashes the game when it detonates unless it names a usable [`AirburstWeapon`](/keys/airburstweapon/). Name that weapon in the same section, or write `Splits=no` there; the `Splits` page explains why that line must be repeated in every rules file that declares the section.
:::

```ini title="rules.ini"
[MYCLUSTERMISSILE] ; a BulletType, registered by a weapon naming it as its Projectile
Image=MISLMLTI
ROT=4
Airburst=yes
Cluster=6                ; six bomblets
AirburstWeapon=MyBomblet ; a WeaponType that must also be listed in [Weapons]
```

The example omits the `MyBomblet` weapon section and its `[Weapons]` entry.
