---
key: FireAngle
summary: The resting elevation of the object's barrel.
when_omitted:
  kind: context-dependent
  note: The barrel rests 11.25 degrees above level, unless the type's rules.ini section sets FireAngle. That value is counted in steps of about 1.4 degrees, not in degrees.
---

An aircraft, vehicle or infantry soldier returns its barrel to this elevation whenever it has no target, or no weapon in its first slot, and is not unloading. A structure without a target does not return its barrel to this elevation.

While an object has a target, its barrel takes the elevation that its first-slot weapon's projectile needs to reach the target. When no arc at that projectile's speed reaches the target, the barrel falls back to this elevation instead of aiming flat. A structure whose first-slot weapon is a laser does not use this fallback.

In art.ini the value is in degrees. Zero is level, a positive value raises the barrel, 90 points it straight up, and a negative value aims it below level. The engine keeps only whole degrees and converts them to its 256-step direction scale, rounding toward zero, so each step is about 1.4 degrees. `FireAngle=35`, for example, rests the barrel at 33.75 degrees.

```ini title="art.ini"
[MYARTY] ; the Image ID of a UnitType
FireAngle=35 ; the barrel rests about 34 degrees above level
```
