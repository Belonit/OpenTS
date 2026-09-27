---
key: RailgunDamageRadius
summary: How far an object's center may stand from a railgun beam and still be caught by it.
see_also: ["IsRailgun", "AmbientDamage", "CollapseChance"]
when_omitted:
  kind: value
  value: "128"
---

A railgun beam damages an object when the object's center is closer to the beam than this distance. The distance is in leptons, 256 to a cell, and is measured straight out from the line between the muzzle and the target's center.

```ini title="rules.ini"
[CombatDamage]
RailgunDamageRadius=256   ; catches centers less than one cell from the beam line
```

Only units, infantry, aircraft and structures in the cells the beam passes through are measured. The cell the beam starts in, usually the firer's own, is never checked, and a cell whose corner the beam only clips can be missed. An object in a cell beside the beam is never caught, however large the value. Raising the value therefore catches more of the objects that share a crossed cell with the beam, such as infantry standing near a cell's edge.

Two victims are caught at any distance from the line. A structure in a cell the beam crosses is caught whenever this value is above `0`. The unit, infantry, aircraft or structure the shot was aimed at is caught whatever this value. [`IsRailgun`](/keys/israilgun/) covers the damage every victim takes.

When [rising ground stops the beam](/keys/israilgun/#rising-ground-stops-the-beam) before the target, no object takes beam damage, whatever this value.
