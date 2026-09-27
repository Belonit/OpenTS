---
key: LaserFence
summary: Whether the structure is a laser fence segment that a fence post lays, energizes and removes.
see_also: ["system:laser-fences"]
when_omitted:
  kind: value
  value: "no"
---

A `LaserFence=yes` structure is a fence segment. A [`LaserFencePost=yes`](/keys/laserfencepost/) structure creates one segment in each cell of a [run it lays toward another post](/systems/laser-fences/#laying-the-run), switches the run between live and slack, and removes it again. A post lays its segments free of charge.

The flag does not stop a house from building a segment type. The stock segment stays off every build list because it sets [`TechLevel=-1`](/keys/techlevel/#scope-aircrafttype).

Declare only one `LaserFence=yes` BuildingType. Every post lays the first declared type with this flag, so any later one is never laid.

While its run is live, a segment keeps vehicles and infantry out of its cell, stops low projectiles, and destroys any vehicle, aircraft or infantryman in its cell. A slack segment stays on the map and stops nothing. [What a live run stops](/systems/laser-fences/#what-a-live-run-stops) covers the details.

The flag also changes what a segment may stand on and what may be placed on it:

- A segment needs a cell with no building and no terrain object such as a tree. Unlike other structures, it may be placed on Tiberium or veins, unless the cell is a bridge, a ramp, or a cell where a bridge once stood.
- A laser fence post or a [`Gate=yes`](/keys/gate/) structure of the same house may be placed on top of a segment. No other structure may.

:::caution[A segment cannot be shot away]
Ordinary weapon fire and splash never damage a segment, whatever its [`Strength`](/keys/strength/). A segment is removed when its post removes the run, when a post or gate is placed on its cell, or when its house is defeated and everything it owns is blown up.
:::
