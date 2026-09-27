---
key: IntentionalDeacceleration
summary: The speed a levitating unit sheds each frame while it is deliberately stopping.
see_also: ["Drag", "ProximityDistance", "MaxVelocityWhenFollowing", "MaxVelocityWhenPissedOff"]
when_omitted:
  kind: value
  value: "0.15"
---

A levitating unit that brakes loses this much speed per frame in place of [`Drag`](/keys/drag/). A larger figure shortens braking, and with it the pause between one thrust and the next. Like `Drag`, the loss is subtracted from the speed, and the unit stops dead once the loss is at least as large as its speed.

A unit brakes in two cases:

- Its target or destination comes within [`ProximityDistance`](/keys/proximitydistance/) during a thrust or a coast.
- While coasting, it slows below [`MaxVelocityWhenPissedOff`](/keys/maxvelocitywhenpissedoff/) if it has a target, or below [`MaxVelocityWhenFollowing`](/keys/maxvelocitywhenfollowing/) if it has only a destination.

A wandering unit, with neither a target nor a destination, never brakes. It coasts to rest under `Drag`.

Braking ends when the unit's speed falls below a hundredth of a lepton per frame. The unit then steers at its target or destination again, or comes to rest and reclaims its cell if it has lost both. A unit braking from 5 leptons per frame stops in 34 frames at `0.15` and in 5 frames at `1.0`.

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
