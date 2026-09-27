---
key: HoverDampen
summary: Fraction of its vertical motion a hovering unit keeps from one frame to the next.
see_also: [HoverHeight, HoverBob, Gravity]
when_omitted:
  kind: value
  value: ".8"
---

Each frame the cushion adds its lift, [`Gravity`](/keys/gravity/) pulls the unit down by a fixed amount, and then the unit's remaining vertical motion is multiplied by this fraction. A smaller fraction makes a unit that was shoved down or crossed a rise settle with less bouncing, and it also leaves the unit riding lower.

The unit stops climbing once it would rise less than one lepton in a frame, and with a smaller fraction that happens lower down. With the stock `Gravity` and [`HoverHeight`](/keys/hoverheight/), a unit rising from the ground stops at about 75 leptons at `0.3`, 92 at the stock `0.4` and 103 at `0.5`. At `0.1` it barely leaves the ground.

The stock rules write `40%`, which the engine reads as `0.4`. Only the percent sign divides by a hundred, so a bare `40` means forty. The `.8` fallback applies only when no rules file sets the key.

The levitation locomotor, which the stock Tiberium Floater uses, damps with the same fraction.

:::caution[Keep HoverDampen at 0.8 or less]
Above about `0.8` the unit no longer settles, and its swing grows with the fraction. With the stock `Gravity` and `HoverHeight`, the swing covers more than 100 leptons at `0.9`. From about `0.92` each swing reaches the ground, which clears the unit's vertical motion, and the unit keeps bouncing off the ground for as long as it exists.
:::
