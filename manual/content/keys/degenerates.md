---
key: Degenerates
summary: Bleeds a point of damage off the projectile for every game frame it stays in flight.
see_also: [Damage, Ranged]
when_omitted:
  kind: value
  value: "no"
---

The loss stops at `5`: the projectile is never worn below 5 points of damage, and one launched with 5 or less keeps its damage. At 15 game frames to the second, a shot launched with 100 damage reaches the floor after 95 frames of flight, a little over six seconds.

The loss starts from the damage the shot was launched with. For an ordinary shot a unit or structure fires at its target, that is the weapon's [`Damage`](/keys/damage/#scope-weapontype) after the firer's firepower bonuses. A shot from another source, such as a bomblet of a splitting projectile or a superweapon's missile, starts from the damage that source gives it, with no firepower bonus. The weapon itself is unchanged, so the next shot starts at full damage again.

The blast uses the reduced damage for everything damage decides, including which explosion from the warhead's [`AnimList`](/keys/animlist/) it plays.
