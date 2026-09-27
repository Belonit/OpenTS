---
key: Vegetation
summary: How thickly a generated map is planted with green ground and woods, as a figure from 0 to 100.
see_also: [Biome, UrbanPresence]
when_omitted:
  kind: value
  value: "0"
  note: No green ground and no woods are planted. Rough ground, sand and rock patches still appear at their fixed rates.
---

`Vegetation` scales the chance that a cell starts a patch of green ground or a wood, as a percentage of the biome's full chance. Rough ground, sand and the rock patches on tundra and taiga keep fixed chances whatever the figure. [Map seed files](/formats/map-seed/) covers the section it is written in.

```ini title="map seed file"
[RandomMap]
Biome=2
Vegetation=70
```

The table gives each cell's chance at `Vegetation=100`. At `50` each chance is half as large.

| Biome | Green ground | Wood |
| --- | --- | --- |
| Temperate, mutated | 1 in 50 | About 1 in 330 |
| Desert | Never | 1 in 1,000 |
| Tundra | Never | 1 in 2,000 |
| Taiga | Never | About 1 in 670 |

The figure changes how many patches and woods start, not how large they grow or how densely a wood is planted. [Random map generation](/systems/map-generation/#ground-cover) explains which cells can start a patch and how patches spread.
