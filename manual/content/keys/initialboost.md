---
key: InitialBoost
summary: The speed a levitating unit gains at once when a thrust begins.
see_also: ["Acceleration", "AccelerationDuration", "Drag", "IntentionalDriftVelocity"]
when_omitted:
  kind: value
  value: "1.5"
---

Every thrust opens by adding this speed to the unit at once, in the direction of the thrust. [`Acceleration`](/keys/acceleration/#scope-levitation-controls) then adds more speed on each frame of the thrust. The figure applies to every thrust, whether the unit is wandering or heading for a target or destination.

The figure is in leptons per frame, with 256 leptons to a cell and 15 frames to the second. At `8`, a thrust starts at 8 leptons per frame, about half a cell per second, before [`Drag`](/keys/drag/) and `Acceleration` change it. When [`AccelerationDuration`](/keys/accelerationduration/) is `0`, this boost is all a thrust does.

The boost adds to the motion the unit already has instead of replacing it. This matters for a wandering unit, which can start a new thrust while it is still coasting: on the same heading the speeds add up, and on a different heading they combine as vectors.

Nothing caps the speed that results. [`IntentionalDriftVelocity`](/keys/intentionaldriftvelocity/) describes the hang that a movement of more than a cell per frame can cause.

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
