---
key: HoverHeight
summary: Height in leptons that a hovering unit rides above the ground.
see_also: [HoverBob, HoverDampen, Gravity, "system:emp-pulse"]
when_omitted:
  kind: value
  value: "120"
---

A powered hover unit rides below this height above the ground. The value is in leptons, not cells or terrain levels. A cell is 256 leptons across and a terrain level is about 104 leptons high. With the stock [`Gravity`](/keys/gravity/) and [`HoverDampen`](/keys/hoverdampen/), a unit rising from the ground stops climbing at about three quarters of this height and then [bobs](/keys/hoverbob/) about that point. The stock `120` therefore holds a unit between about 80 and 104 leptons up, no higher than one terrain level.

The cushion pushes harder the lower the unit is. While a powered unit's clearance, its height above the ground, is below this value, each frame adds `(2 × HoverHeight − clearance) ÷ HoverHeight × Gravity` to its vertical motion. `Gravity` is taken off every frame. Heights are kept in whole leptons, so the unit stops climbing once it would rise less than one lepton in a frame, which happens well short of this height. A smaller `Gravity` or `HoverDampen` leaves the unit lower.

Below a quarter of this height the unit gets a further `Gravity ÷ 3`, rounded down to whole leptons, with or without power. A `Gravity` below 3 makes this extra zero.

While the next step of the unit's path climbs to a higher cell, the cushion treats the unit as this much lower than it is. The unit therefore starts rising a cell before the slope.

The levitation locomotor, which the stock Tiberium Floater uses, floats at the same height.

:::caution[An unpowered hover unit sinks to the ground]
Without power the cushion adds only the quarter-height extra, which is less than `Gravity`. The unit sinks until it rests on the ground and tilts to the slope beneath it, and it rises again when power returns. An [EMP pulse](/systems/emp-pulse/), or an ion storm for an ion-sensitive type, cuts the power; the unit also drops its move order and swings its facing as it sinks.
:::
