---
key: IsSonic
summary: Sends a visible wave rolling from the muzzle to the target, damaging everything it crosses on the way.
see_also: ["AmbientDamage", "ROF", "Range", "Warhead"]
when_omitted:
  kind: value
  value: "no"
---

`IsSonic=yes` makes the weapon fire a wave that rolls from the muzzle to the target and damages the objects under it. All of the weapon's damage comes from the wave's [`AmbientDamage`](/keys/ambientdamage/). The weapon still fires its projectile, but the projectile carries no damage, so [`Damage=`](/keys/damage/#scope-weapontype) adds nothing to the shot.

```ini title="rules.ini"
[MySonicGun] ; example WeaponType
IsSonic=yes
Projectile=MyBolt ; a BulletType, registered by a weapon naming it as its Projectile
AmbientDamage=3
Damage=1  ; never delivered
Range=6
ROF=120
```

## How long the wave lasts

The wave grows from the muzzle by a twentieth of the distance each frame, and reaches the target after 20 frames. It holds at full length for about 60 more frames, then fades from its trailing edge over the last 20. The whole wave lasts about 100 frames.

The wave damages the objects in every cell it covers on every frame it lasts, so an object that stays under it is hit many times. Even a small `AmbientDamage` adds up. If the firer is destroyed, the wave deals no more damage and fades. [`AmbientDamage`](/keys/ambientdamage/) covers the damage each hit deals, and its effect on walls and chain reactive overlay. On every frame, a destroyable cliff under the wave may also collapse, at the chance [`[CombatDamage] CollapseChance`](/keys/collapsechance/) sets.

:::caution[A wave fired beyond about 8.5 cells dies at once]
The wave keeps growing and holding only while the firer still targets the same object and the two are no more than 2172 leptons apart, a little under 8.5 cells. When that stops being true, the wave fades early from its trailing edge. A wave fired from beyond that distance is removed as soon as it appears and damages nothing, so a sonic weapon whose [`Range=`](/keys/range/#scope-weapontype) reaches further deals no damage at its longest shots.
:::

## Firing rate

While a wave is alive, neither of the object's weapons can fire. The reload delay after a sonic shot is exactly [`ROF`](/keys/rof/#scope-weapontype), with no house rate-of-fire bias, burst delay, random extra frames or veteran bonus. The next shot waits until both `ROF` has passed and the wave is gone. A structure with more than one round of [`Ammo`](/keys/ammo/) left waits only for the wave. [The reload delay](/systems/firing-geometry/#the-reload-delay) gives the full rules.

:::caution[The wave uses the first weapon slot's settings]
The wave's damage and warhead come from the weapon in the object's first slot, whichever slot fired. The wave is also drawn from the first slot's muzzle. A sonic weapon in the second slot therefore rolls out a wave with the first weapon's `AmbientDamage` and warhead.
:::
