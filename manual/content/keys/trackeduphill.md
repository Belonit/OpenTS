---
key: TrackedUphill
summary: Speed multiplier for a tracked vehicle stepping to a higher cell.
see_also: [TrackedDownhill, WheeledUphill, WheeledDownhill, SpeedType]
when_omitted:
  kind: value
  value: "1"
---

A tracked vehicle climbs into a higher cell at the speed the terrain allows, multiplied by this value. The stock `.5` halves its speed on a climb.

The speed the terrain allows is the vehicle's [`SpeedType`](/keys/speedtype/) figure in the [terrain table](/systems/movement-and-terrain/#the-terrain-table) section for the destination cell's land type. When the destination's ground is two or more levels from the height the vehicle travels at, as on a bridge deck, the `[Road]` figure is used instead.

This value applies when the ground at the destination cell is higher than the ground under the vehicle. A ramp counts as a climb just as a cliff edge does. A step between cells of equal height takes neither this value nor [`TrackedDownhill`](/keys/trackeddownhill/).

Only vehicles with `SpeedType=Track` use this value. A vehicle with any other SpeedType uses [`WheeledUphill`](/keys/wheeleduphill/) instead, whatever its name suggests, and infantry and aircraft use neither. The multiplier belongs to the ordinary driving [`Locomotor`](/keys/locomotor/), so a vehicle with any other locomotor, such as hover or tunnel, climbs at the unmodified speed.

Only the speed of the step changes. The route search does not read this value, so a slow climb does not make a vehicle route around a hill.

The terrain speed is capped at full speed before this value applies, and the result is capped at full speed again. A value above `1` therefore speeds up a climb only across terrain slower than full speed, and never beyond full speed.

:::caution[Keep TrackedUphill above 0]
A climb whose speed works out to exactly zero is made at half speed instead, so `TrackedUphill=0` does not forbid climbing. A negative value leaves the vehicle no speed for the step, and it slows to a stop on the slope.
:::
