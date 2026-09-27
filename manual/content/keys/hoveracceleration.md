---
key: HoverAcceleration
summary: Time in minutes a hovering unit takes to work its throttle up to full.
see_also: [HoverBrake, HoverBoost]
when_omitted:
  kind: value
  value: ".03"
---

This value is a length of time, not a rate: raising it makes a hover unit slower off the mark. A hover unit's throttle is the fraction of its travel speed it is using, from zero to full. The time is in game minutes of 900 frames, so the stock `.02` takes a stopped unit to full throttle in 18 frames.

Each frame the throttle rises by `1 ÷ (HoverAcceleration × 900)` of full until it reaches the ceiling the drive allows. A unit pushed a cell aside to make way for another skips this ramp and goes to full throttle at once, unless it is within a cell of its destination. The ceiling is below full near the end of a move and while the unit turns; [`HoverBrake`](/keys/hoverbrake/) lists those cases, and [`HoverBoost`](/keys/hoverboost/) scales the ceiling on a straight path. Closing the throttle runs on `HoverBrake`.
