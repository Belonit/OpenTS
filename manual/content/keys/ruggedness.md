---
key: Ruggedness
summary: How hilly a generated map's ground is, as a figure from 0 to 100.
see_also: [RegionSize, Accessibility]
when_omitted:
  kind: value
  value: "0"
  note: The map gets no hills.
---

`Ruggedness` sets how much the ground of a generated map rolls. The generator's hill pass raises and lowers the ground by up to two levels, and a higher value makes those rises and falls steeper and more uneven. At `0` and `1` the map gets no hills. [Map seed files](/formats/map-seed/) covers the section the key is written in.

```ini title="map seed file"
[RandomMap]
Ruggedness=40
```

The hill pass works across the map one cell at a time. Each cell starts from the heights of the neighbors already set and then takes a random step. `Ruggedness` controls two parts of that step. The step tends to continue the slope of the neighboring ground, by a tenth of a level plus a thousandth per point. A higher value also lets the steps vary more widely. [Hills](/systems/map-generation/#hills) lists the cells whose height the pass leaves alone, such as those holding tiberium or a building.

Cliffs are set separately: [`RegionSize`](/keys/regionsize/) controls the sharp height changes between regions, and `Ruggedness` the gentler slopes laid over them afterward.

When a map is [generated from a file](/systems/map-generation/#the-dialog-path-and-the-scenario-path), a value below `0` becomes `0` and one above `100` becomes `100`.
