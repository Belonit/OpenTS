---
key: Floater
summary: Halves the gravity the projectile is flown and aimed under.
see_also: [Gravity, Arcing, Speed]
when_omitted:
  kind: value
  value: "no"
---

Every gravity calculation for this projectile uses half of [`[AudioVisual] Gravity`](/keys/gravity/):

- the fall of the projectile in flight;
- the arc an [`Arcing=yes`](/keys/arcing/) projectile is launched on;
- the test of whether that arc can reach the target, which decides whether the firer may shoot;
- the barrel elevation the firer sets while tracking a target, when the projectile belongs to its primary weapon;
- the launch speed of a weapon firing a projectile with no [`ROT`](/keys/rot/#scope-bullettype).

The launch speed has the largest effect. A weapon whose projectile has no `ROT` ignores the [`Speed`](/keys/speed/#scope-weapontype) written in its section. Once the rules are read, that speed is replaced by the speed needed to carry the projectile the weapon's full [`Range`](/keys/range/) under the gravity that applies to it. Halving the gravity lowers that speed, so the shot leaves the barrel more slowly and stays in the air longer over the same distance.

A homing projectile, one with `ROT` above `0`, never falls and keeps its weapon's written `Speed`. On such a projectile the setting changes only the aiming.

Write the key in the projectile's own section. A `Floater=` line in a weapon's section is not read.
