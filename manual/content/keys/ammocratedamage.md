---
key: AmmoCrateDamage
summary: Raw damage of the blast an exploding overlay leaves behind when it is set off.
see_also: ["Explodes", "C4Warhead", "BarrelExplode", "BarrelDebris", "BarrelParticle"]
when_omitted:
  kind: value
  value: "100"
---

An [`Explodes=yes`](/keys/explodes/#scope-overlaytype) overlay deals this much raw damage through [`C4Warhead`](/keys/c4warhead/) when an explosion sets it off. The blast is centered on the point where the triggering explosion landed, inside the overlay's cell.

The blast can reach objects in the overlay's cell and the eight cells around it. Which of them it damages, and how armor and distance adjust each object's damage, follow the rules for any `C4Warhead` blast in [what a blast reaches](/systems/warheads/#what-a-blast-reaches).

No house is credited with the blast, so a unit killed by an exploding overlay counts as no one's kill.

The blast sets off no chain-reactive Tiberium, because a blast sets off Tiberium only in its own cell, and that cell held the exploding overlay.

[`Explodes=yes`](/keys/explodes/#scope-overlaytype) covers the animation, debris, particles and neighbor fires that come with the blast.

```ini title="rules.ini"
[CombatDamage]
AmmoCrateDamage=200  ; raw damage before armor and distance adjustments
```
