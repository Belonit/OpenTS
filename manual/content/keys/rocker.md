---
key: Rocker
summary: The blast tips the vehicles around it, with the force taken from the damage.
see_also: [Weight]
when_omitted:
  kind: value
  value: "no"
---

A blast from this warhead rocks the voxel-drawn objects around it: each one tilts and then eases back to level. Rocking costs no strength.

```ini title="rules.ini"
[MyShellWH] ; example WarheadType
Rocker=yes
```

The rocking force is the blast's damage divided by 100, capped at 4. This is the blast's raw damage, before armor and distance reduce it for any target. A blast of 30 damage or less rocks nothing, and every blast of 400 or more rocks with the same force.

The blast rocks every object in the seven-by-seven block of cells centered on its cell, as long as the object's type is drawn as a voxel. Infantry, structures and other objects drawn from shape art do not rock.

How far an object tilts depends on three things:

- A stronger force tilts it further.
- A heavier [`Weight`](/keys/weight/) tilts it less, so a heavy vehicle rocks less than a light one at the same distance.
- A greater distance from the blast tilts it less. An object far enough away that the tilt would be negligible does not rock at all.

The speed at which a blast starts an object tipping is capped. Past that cap, a stronger blast, a lighter object or a shorter distance no longer makes the object tip faster or further.

Each object tips away from the blast. An object standing in the blast's cell tips away from the object credited with the blast instead, when there is one.

An object stops tilting at 45 degrees, forward or sideways, and then eases back to level over the following frames. A vehicle crushing something at the time stops at 18 degrees forward.
