---
key: WaterAmount
summary: How much of a generated map is put under water, as a figure from 0 to 100.
see_also: [Biome, Accessibility]
when_omitted:
  kind: value
  value: "0"
  note: The water pass is skipped, so the map has no river and no lake.
---

`WaterAmount` sets a generated map's water budget, a number of cells. The budget is the figure times the playable area's width times its height times the biome's factor, plus 100 cells. [Map seed files](/formats/map-seed/) gives the playable area's width and height, and covers the section the key is written in.

| Biome | Factor |
| --- | --- |
| Tundra | 0.008 |
| Taiga, temperate | 0.007 |
| Mutated | 0.006 |
| Desert | 0.002 |

At `WaterAmount=100`, a temperate map's budget is 70 percent of its width times its height, plus 100 cells.

```ini title="map seed file"
[RandomMap]
Biome=2
WaterAmount=45
```

The pass lays at most one river, then tries one lake:

1. A river is tried only when the figure is above `20` and the biome is not desert, with up to ten attempts. The budget does not stop a river, but each step along it counts as one cell against the budget, however wide the river is. A higher figure allows a wider river.

   A river that stops inside the map, and not at its edge, ends in a lake of its own. That lake is sized like the lake in step 2, but against the budget before the river's steps are counted. An ordinary river is abandoned if its end lake cannot be placed.
2. The pass's own lake is then tried, with up to ten attempts. Its size is drawn at random, centered on a third of the budget the river left and never more than all of it. No lake is placed when 75 cells or fewer remain.

Because of the extra 100 cells, even `WaterAmount=1` leaves room for a lake. A failed attempt leaves the ground as it was, so a map can end up with less water than its budget, or none.

On tundra, the river and lake are laid as ice. The ice lake's size is centered on a quarter of what the river left, at least 75 cells, and it is tried whenever any budget remains. A tundra river that stops inside the map tries an ice lake at its end, and the river is kept whether or not that lake is placed. [Random map generation](/systems/map-generation/#water) covers the biome variants.
