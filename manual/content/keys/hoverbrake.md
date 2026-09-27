---
key: HoverBrake
summary: Time in minutes a hovering unit takes to close its throttle again.
see_also: [HoverAcceleration, HoverBoost]
when_omitted:
  kind: value
  value: ".03"
---

Like [`HoverAcceleration`](/keys/hoveracceleration/), this value is a length of time, not a rate: raising it makes a hover unit slow down more gradually. The time is in game minutes of 900 frames. Each frame the throttle falls by `1 ÷ (HoverBrake × 900)` of full, and it stops at zero. The stock `.03` closes a fully open throttle in 27 frames.

```ini title="rules.ini"
[General]
HoverBrake=.01   ; 9 frames to close a fully open throttle
```

The unit brakes whenever the drive's ceiling drops below the throttle it is holding. The ceiling drops in two cases:

- **Within a cell of its destination,** the ceiling is half of full.
- **While the unit faces more than 45 degrees away from its next stop,** the ceiling is zero, so the unit slows to a stop to turn.

A unit pushed a cell aside to make way for another is exempt from the facing test until it reaches that cell.
