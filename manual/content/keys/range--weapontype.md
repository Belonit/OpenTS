---
key: Range
scope: weapontype
label: Firing distance
see_also: ["MinimumRange", "ProjectileRange", "Speed", "GuardRange", "system:target-selection"]
when_omitted:
  kind: value
  value: "0"
---

The weapon reaches a third of a cell less than the distance written. A target exactly at the written distance is therefore out of range. The value is in cells, and a fraction is accepted.

```ini title="rules.ini"
[MyCannon] ; example WeaponType
Range=10.5
MinimumRange=2
```

The distance runs from the firer's center to the target's center and includes the height difference, with two exceptions:

- An aircraft measures the horizontal distance only, however far below it the target lies.
- Any other object in the air is measured as though it were at the target's height, so for it too only the horizontal distance counts.

Against a structure, the reach gains an allowance of a quarter of a cell for each cell of the structure's width plus its depth. A structure 2 cells wide and 2 deep adds one cell, so it can be hit from farther away than a vehicle.

The same test refuses a target in three more cases:

- The target is higher than the firer by at least the horizontal distance between them, and the projectile has neither [`Arcing=yes`](/keys/arcing/) nor [`AA=yes`](/keys/aa/).
- The firer stands beneath a bridge, the target is at or above the height of that bridge's deck, and the projectile does not have `Arcing=yes`.
- The firer is higher than the target by at least the horizontal distance between them, and the firer is on the ground. A firer standing on a bridge counts as on the ground.

:::caution[An arcing projectile does not use the value as a range limit]
When the weapon's [`Projectile=`](/keys/projectile/) has [`Arcing=yes`](/keys/arcing/), the distance comparison and the structure allowance are skipped. The target is in range when the shot's ballistic arc can reach it at the weapon's launch speed. [`MinimumRange=`](/keys/minimumrange/) and the third case above still apply, and a target in a bridge cell that stands three or more terrain levels above the firer is always out of range. For a projectile that does not home, that launch speed is worked out from `Range=`, so `Range=` still sets the reach through the speed. [`Speed=`](/keys/speed/#scope-weapontype) covers how the speed replaces the written one.
:::

`Range=` is also used outside the firing test:

- An object whose [`GuardRange`](/keys/guardrange/) is zero takes its scan radius from its weapons' range, and the threat score measures distance against the range; [target selection](/systems/target-selection/#scan-radius) covers both.
- When a house rates its base defenses against armor and infantry, the range counts for at most four cells.
- An EM pulse cannon can be aimed only at cells within its weapon's range, rounded down to whole cells.
- A weapon named as a projectile's [`AirburstWeapon=`](/keys/airburstweapon/) gives its range to each bomblet as fuel. It is not a firing distance there.

`-1` counts as not set, so it keeps whatever an earlier rules file set.

`Range=0` leaves the reach below zero. A weapon without an arcing projectile can then fire only at structures, and only within the structure allowance above.

A structure whose first-slot weapon has `Range=0` counts as unable to shoot back. A human player's objects outside a team, other than engineers, therefore do not pick it as a target on their own; [target selection](/systems/target-selection/#why-a-candidate-is-rejected) lists the rule and its exceptions.
