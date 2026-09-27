---
key: Firepower
summary: The multiplier a country applies to the damage its houses deal by firing a weapon.
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1.0"
---

When an object of a house of this country fires a weapon, the projectile carries the weapon's [`Damage`](/keys/damage/#scope-weapontype) multiplied by this value, so a value above 1 hits harder. A healing weapon, one with a negative `Damage`, is not scaled.

```ini title="rules.ini"
[GDI]
Firepower=1.1 ; example: GDI's weapons deal 10% more damage
```

Damage that does not come from an object firing a weapon is never scaled by this value. That includes a nuke silo's launch, either kind of EM pulse, a superweapon, a trigger action, a projectile splitting into more, a hunter-seeker's detonation, a drop pod's weapon as the pod descends, and a jellyfish's sting. Sonic weapons and weapons that use fire particles are not scaled either: their projectiles carry no damage, and the damage they deal comes from elsewhere.

Outside a campaign game, the house multiplies this value by [the difficulty section's `FirePower=`](/keys/firepower-difficulty-settings/) once, [when it is given its difficulty slot](/systems/difficulty/#how-the-figures-are-combined). A campaign game leaves the country's value out, so it affects skirmish and multiplayer games only.
