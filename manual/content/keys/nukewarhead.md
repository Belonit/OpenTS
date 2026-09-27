---
key: NukeWarhead
summary: Parsed WarheadType that the engine never uses.
no_effect: true
see_also: [AtomDamage, NukeProjectile, NukeDown, "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

A nuclear missile does not detonate with this warhead. Like any other shot, it deals damage with the warhead of the weapon it was launched from. [Multi missile and chem missile](/systems/superweapons/#multi-missile-and-chem-missile) says which weapon that is.

The game has one fallback that would use this warhead, and it never runs. When a projectile carrying this warhead explodes and its explosion animation cannot be created, the game would apply the [`AtomDamage`](/keys/atomdamage/) wide-area blast with this warhead. Creating an animation never fails, so that blast never happens.
