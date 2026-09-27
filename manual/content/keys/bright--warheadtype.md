---
key: Bright
scope: warheadtype
label: Explosion flash
see_also: [Explodes, IonStormWarhead, IonCannonWarhead, C4Warhead]
when_omitted:
  kind: value
  value: "no"
---

The explosion lights the ground around it with a brief flash. The flash's size is a quarter of the blast's damage, rounded down and held between 21 and 63 on a scale of 64. A blast of 87 damage or less gives the smallest flash, and one of 252 or more gives the largest. The flash grows to full size within three game frames and shrinks away over the next seven.

```ini title="rules.ini"
[MyShellWH] ; example WarheadType
Bright=yes
```

A projectile's impact ignores this flag. Its flash comes from [the firing weapon's `Bright`](/keys/bright/#scope-weapontype) instead.

The flag applies to these explosions, none of which comes from a projectile:

- an animation or voxel animation that explodes when it expires
- the collateral blast a dying [`Explodes=yes`](/keys/explodes/#scope-aircrafttype) object, or one with the `EXPLODES` [ability](/systems/veterancy/#abilities), makes through its first weapon's warhead
- [`IonStormWarhead`](/keys/ionstormwarhead/) lightning and [`IonCannonWarhead`](/keys/ioncannonwarhead/)
- the [Do Explosion At](/mapping/actions/taction-do-explosion/) trigger action
- the flashes that read [`C4Warhead`](/keys/c4warhead/): a laser fence segment blown up with its post, a stranded vehicle blowing itself up, a flying object that falls to the ground, an explosive crate, a hunter-seeker, and the three lighting trigger actions
