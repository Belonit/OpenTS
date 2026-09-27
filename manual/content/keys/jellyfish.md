---
key: Jellyfish
summary: Replaces a vehicle's whole firing behavior with an automatic sting on everything in the cells around it.
see_also: ["Primary", "IsLimpetDrone", "NonVehicle"]
when_omitted:
  kind: value
  value: "no"
---

A vehicle with the flag never fires its weapon the ordinary way and never approaches a target. Instead, it stings everything hostile in the three-by-three block of cells centered on itself, on a separate schedule. It may still hold a target and turn toward it.

```ini title="rules.ini"
[MYJELLY] ; a UnitType registered in [VehicleTypes]
Jellyfish=yes
NonVehicle=yes ; not required for the sting; keeps repair weapons and vehicle thieves from treating it as a vehicle
Primary=MYSTING ; a WeaponType; only its Damage, its warhead and its Report are read
```

Without a [`Primary`](/keys/primary/) weapon that has a warhead, the jellyfish never stings.

## When it stings

The sting follows the jellyfish's animation counter, not the weapon's rate of fire. The counter starts at 0 when the jellyfish is placed and advances one stage per game frame. A sweep runs on every game frame in which the counter stands at a multiple of 8.

While its sweeps hit nothing, the counter runs from 0 to 16 and starts again, so the jellyfish sweeps every 8 game frames.

A hit on the sweep at stage 16 slows the counter to one stage every three game frames, and it runs on toward 32. The next sweep comes about 22 game frames later, at stage 24.

While the counter is slow, it stays on stage 24 and on stage 32 for three game frames, and a sweep runs on each of those frames. A target that stays in reach can be stung up to three times in a row.

A hit at stage 32 sends the counter back to 16 and keeps it slow. A miss at 16 returns the counter to 0 and to one stage per frame at once. After misses on every frame at 32, the counter returns to 0 when it leaves that stage.

## What it stings

A cell of the block is swept only when its ground lies within 384 [leptons](/glossary/#lepton) of the jellyfish's height, a little under four height levels. An object in a swept cell is stung when **all of** the following hold:

- it is infantry, a vehicle, an aircraft or a structure, and it has strength left;
- it is not the jellyfish itself;
- it is not a visceroid;
- it is not an [`InvisibleInGame=yes`](/keys/invisibleingame/) structure;
- it is not an ally.

Each target is stung for the `Primary` weapon's [`Damage`](/keys/damage/#scope-weapontype) multiplied by the warhead's [`Verses`](/keys/verses/) entry for the target's armor and rounded down, credited to the jellyfish. [The damage calculation](/systems/warheads/#what-the-target-loses) for a target at the point of impact then runs on that figure, so the `Verses` entry applies a second time. A `50%` entry therefore leaves a quarter of the damage. A sting that the first multiplication rounds down to zero, such as one against a `0%` entry, does no damage. No projectile is created.

A structure is stung once for each of its cells inside the block.

The weapon's [`Report`](/keys/report/#scope-weapontype) sound plays for the cell where the first hit lands and again for every later cell of the block, so one sweep can play it up to nine times.

## Movement and drawing

A jellyfish moves into a cell where a stationary allied unit stands, and into a cell another object has reserved, where an ordinary vehicle would wait. Moving allied units, structures and enemies block it as they block any vehicle.

A jellyfish drawn from shape artwork shows the frame matching its counter, with no facing frames. Frames 0 to 15 therefore loop while it drifts, and frames 16 to 32 play after a hit.

An explosion whose center is above the ground includes a nearby jellyfish in its damage, the same way it includes aircraft and jumpjet infantry.
