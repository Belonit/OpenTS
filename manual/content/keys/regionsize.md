---
key: RegionSize
summary: How large a piece of ground a generated map may hold at one height before it is broken up, as a figure from 0 to 100.
see_also: [Accessibility, Ruggedness, Biome]
when_omitted:
  kind: value
  value: "0"
  note: The smallest limit.
---

`RegionSize` sets how large a stretch of dry ground a generated map can keep at one height. Cliffs form where regions at different heights meet, so a higher value allows larger regions and gives the map fewer cliffs. [Regions, cliffs and ramps](/systems/map-generation/#regions-cliffs-and-ramps) describes the whole pass, and [map seed files](/formats/map-seed/) covers the section the key is written in.

```ini title="map seed file"
[RandomMap]
RegionSize=20
```

The generator splits any dry region larger than the limit by cutting off a piece of at most a third of its cells. Each resulting piece larger than 100 cells is given a height picked from the heights of the regions around it. A piece of 100 cells or fewer joins its largest dry neighbor at that neighbor's height. The generator repeats the split until no dry region is over the limit.

The limit, in cells, is the playable area's width times its height, multiplied by 0.1 plus 0.01 for every point of `RegionSize`. On a map whose playable area is 100 by 100 cells, `0` sets a limit of 1,000 cells and each point adds another 100, so `RegionSize=40` sets a limit of 5,000.

The split pass covers the whole playfield, border included, and the playfield holds far more cells than the playable area's width times its height. Measured against the playfield, the limit is about a twenty-fifth of it at `0` and between two fifths and half of it at `100`. Even at `100`, a dry region covering most of the map is still split.

A region that holds water is never split, whatever its size.

When a map is [generated from a file](/systems/map-generation/#the-dialog-path-and-the-scenario-path), a value below `0` becomes `0` and one above `100` becomes `100`.

:::caution[No effect on the tundra biome]
The generator skips the split pass when [`Biome`](/keys/biome/) is `0`, the tundra, so `RegionSize` changes nothing on a tundra map.
:::
