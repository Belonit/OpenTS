---
key: AmbientDamage
summary: The damage a sonic wave or a railgun beam deals to everything along its path, as opposed to the damage the shot delivers at the target.
see_also: ["IsSonic", "IsRailgun", "Damage", "system:walls-and-gates"]
when_omitted:
  kind: value
  value: "0"
---

Only two kinds of weapon deal this damage: an [`IsSonic=yes`](/keys/issonic/) weapon through its wave, and an [`IsRailgun=yes`](/keys/israilgun/) weapon through its beam. Both deal it as a direct hit through a weapon's [`Warhead=`](/keys/warhead/#scope-weapontype). A railgun beam uses the `AmbientDamage` and `Warhead` of the weapon that fired. A sonic wave uses those of the weapon in the firing object's first weapon slot, whichever slot fired. The warhead's [`Verses`](/keys/verses/) percentage against the victim's armor applies, but its reduction with distance does not.

```ini title="rules.ini"
[MySonicGun] ; example WeaponType
Damage=0        ; the projectile deals nothing
AmbientDamage=3 ; dealt to everything the wave covers, every frame
IsSonic=yes
Range=6
```

A sonic wave deals the damage on every frame to each object on the ground in a cell it covers, so an object that stays under the wave is hit many times. The firing object is skipped. Wall overlay in a covered cell takes a hit of the full `AmbientDamage` each frame, whatever the warhead, as [Walls and gates](/systems/walls-and-gates/#taking-damage) describes. Chain reactive overlay in a covered cell is set off. [`IsSonic`](/keys/issonic/) covers how long the wave lasts and how far it reaches.

At elite rank, the wave uses the elite first-slot weapon. Put a sonic weapon in the first slot, or give the first-slot weapon the values the wave should use.

A railgun beam deals the damage once to each victim, at the moment the weapon fires. [`IsRailgun`](/keys/israilgun/) and [`RailgunDamageRadius`](/keys/railgundamageradius/) cover which objects count as victims. If ground higher than the beam cuts it short, the beam deals no damage to anything, including objects it passed before reaching the hill.

`AmbientDamage` also counts toward the object's attack strength, which is the weapon's [`Damage=`](/keys/damage/#scope-weapontype) plus this value, averaged over the object's two weapon slots. That strength [decides whether an object is treated as a healer and whether it fires back](/systems/target-selection/#retaliation). A positive `AmbientDamage` on a healing weapon can raise the average to zero or more, and the object then stops behaving as a healer.

:::caution[Later occupants of a cell take reduced wave damage]
On each frame, the first object a sonic wave hits in a cell is hit with the full `AmbientDamage`. Each later object in that cell is hit with the damage the previous hit actually dealt, and the later object's armor then reduces it again. If the previous hit destroyed its object, the next object is hit with only the strength that object had left. Wall overlay always takes the full `AmbientDamage`.
:::
