---
key: ActiveAnimTwoPowered
summary: Whether the second active slot's animation freezes while the structure has no power.
see_also: ["ActiveAnimTwo", "ActiveAnimTwoPoweredLight", "system:power"]
when_omitted:
  kind: value
  value: "yes"
---

`ActiveAnimTwoPowered=yes` freezes the [`ActiveAnimTwo`](/keys/activeanimtwo/) animation on its current frame when the structure loses power. With `no`, the animation keeps playing, unless [`ActiveAnimTwoPoweredLight=yes`](/keys/activeanimtwopoweredlight/) removes it during a shortage.

A structure loses power when its house falls short of power, when the player or a trigger switches it off, or when an EMP pulse hits it. [Power](/systems/building-animations/#power) covers which structures freeze during a house shortage and when each kind of freeze ends.

The frozen animation stays on screen and normally resumes when power returns. Three events start it playing while its house is still short of power:

- Switching the structure back on, or the structure recovering from an EMP pulse, resumes the animation.
- A damage or repair step that switches the structure between its healthy and damaged forms replaces the frozen animation with a new one, which plays. [The damaged form](/systems/building-animations/#the-damaged-form) covers when the form switches.
- On a [`TurretAnimIsExclusive=yes`](/keys/turretanimisexclusive/) structure, the turret dropping its charge starts a new animation in the slot. A turret that is charging or charged drops its charge when its house falls short of power.
