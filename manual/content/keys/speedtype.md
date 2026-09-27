---
key: SpeedType
summary: The terrain table column a vehicle's per-cell throttle and passability are read from.
see_also: ["Crusher", "MovementZone", "TrackedUphill", "WheeledUphill", "Speed"]
when_omitted:
  kind: context-dependent
  note: "`Track` in a `Crusher=yes` section and `Wheel` in every other."
---

`SpeedType` picks which column of the [terrain table](/systems/movement-and-terrain/#the-terrain-table) the vehicle reads. Each land type's section in `rules.ini`, such as `[Clear]`, `[Road]` or `[Water]`, holds one figure per [speed type](/reference/enums/speed-type/). A vehicle with `SpeedType=Hover` reads the `Hover=` figure from each of those sections. A figure of `0` closes that land type to the vehicle. For a vehicle moved by the drive locomotor, any other figure is a fraction of full speed.

```ini title="rules.ini"
[Water]
Track=0
Wheel=0
Hover=1

[MYSKIMMER] ; a UnitType registered in [VehicleTypes]
SpeedType=Hover
MovementZone=AmphibiousDestroyer
```

A land type whose figure is `0` is closed to the vehicle in two ways:

- The vehicle cannot step into such a cell. A vehicle on a bridge deck may still cross above such a cell, but a vehicle at ground level under the bridge is refused as it would be in the open.
- When the game looks for a free cell to place or send the vehicle, such as an arrival or scatter spot, it skips such cells.

A driven vehicle crosses each cell at that cell's fraction of full speed. On a slope, the speed type also picks the slope multiplier applied on top. `Track` uses [`TrackedUphill`](/keys/trackeduphill/) and [`TrackedDownhill`](/keys/trackeddownhill/). Every other speed type, including `Foot`, `Hover` and `Amphibious`, uses [`WheeledUphill`](/keys/wheeleduphill/) and [`WheeledDownhill`](/keys/wheeleddownhill/).

A vehicle moved by any other locomotor uses its column only to close cells. A hovercraft or a tunneler crosses ground priced at `0.1` as fast as ground priced at `1`. [Movement and terrain](/systems/movement-and-terrain/#what-each-locomotor-drives-its-speed-from) lists where each locomotor takes its speed from.

## SpeedType and MovementZone

`SpeedType` does not decide which cells the game treats as connected; [`MovementZone`](/keys/movementzone/) does. The [zone map](/systems/movement-and-terrain/#the-zone-map) that judges whether a destination is reachable reads only the `Wheel` figures, and treats every `Water` and `Beach` cell as water whatever its figures say. A type's movement zone then decides which of those cells count as connected for it.

The two settings must agree:

- A hovercraft whose `[Water] Hover=` is above zero still gets no route across a lake unless its movement zone accepts water.
- A movement zone that accepts water still leaves the hovercraft stranded if its `Hover=` figure for `Water` is `0`, because the vehicle cannot step into any water cell.

To keep a vehicle off one land type, set its column to `0` in that land type's section. To confine it to a single land type, use [`MovementRestrictedTo`](/keys/movementrestrictedto/). That test runs before this one, and no terrain figure overrides it.

:::caution[Spell the value exactly]
A value that matches no speed type leaves the vehicle with no speed type at all. It does not fall back to `Track` or `Wheel`. The game then reads the vehicle's terrain figures from memory outside the terrain table, so its passability and speed follow no terrain section. A later rules file that contains the same section and does not repeat the bad value restores the `Track` or `Wheel` default.
:::
