---
key: TrackedDownhill
summary: Speed multiplier for a tracked vehicle stepping to a lower cell.
see_also: [TrackedUphill, WheeledUphill, WheeledDownhill, SpeedType]
when_omitted:
  kind: value
  value: "1"
---

A tracked vehicle descends into a lower cell at the speed the terrain allows, multiplied by this value. The stock `1.1` makes a descent a tenth faster than the terrain allows, up to full speed. On terrain that already allows full speed, a descent is no faster.

The speed the terrain allows is the vehicle's [`SpeedType`](/keys/speedtype/) figure in the [terrain table](/systems/movement-and-terrain/#the-terrain-table) section for the destination cell's land type. When the destination's ground is two or more levels from the height the vehicle travels at, as on a bridge deck, the `[Road]` figure is used instead.

This value applies when the ground at the destination cell is lower than the ground under the vehicle. A ramp counts as a descent just as a cliff edge does. A step between cells of equal height takes neither this value nor [`TrackedUphill`](/keys/trackeduphill/).

Only vehicles with `SpeedType=Track` use this value. A vehicle with any other SpeedType uses [`WheeledDownhill`](/keys/wheeleddownhill/) instead, whatever its name suggests, and infantry and aircraft use neither. The multiplier belongs to the ordinary driving [`Locomotor`](/keys/locomotor/), so a vehicle with any other locomotor, such as hover or tunnel, descends at the unmodified speed.

Only the speed of the step changes. The route search does not read this value, so a fast descent does not draw a vehicle toward downhill routes.

The terrain speed is capped at full speed before this value applies, and the result is capped at full speed again. A value above `1` therefore speeds up a descent only across terrain slower than full speed, and never beyond full speed.

:::caution[Keep TrackedDownhill above 0]
A descent whose speed works out to exactly zero is made at half speed instead, so `TrackedDownhill=0` does not forbid descending. A negative value leaves the vehicle no speed for the step, and it slows to a stop on the slope.
:::
