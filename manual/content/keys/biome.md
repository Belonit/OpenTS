---
key: Biome
summary: The kind of country a generated map is laid out in, as a position from 0 through 4.
see_also: [Time, Vegetation, WaterAmount, UrbanPresence, Theater]
when_omitted:
  kind: value
  value: "0"
  note: Tundra, built in the snow theater.
---

`Biome` picks the kind of country a generated map is laid out in, and with it the theater the map is built in. [Map seed files](/formats/map-seed/) covers the section it is written in.

```ini title="map seed file"
[RandomMap]
Biome=2
```

| Value | Biome | Theater | What the biome changes |
| --- | --- | --- | --- |
| `0` | Tundra | Snow | Arctic river and lake, which lay ice. Large areas of ground are not broken up into different heights, so [`RegionSize`](/keys/regionsize/) has no effect. Rural settlements and arctic ground cover |
| `1` | Taiga | Snow | Ordinary river and lake. Rural settlements and arctic ground cover |
| `2` | Temperate | Temperate | Ordinary river and lake. Urban areas and ordinary ground cover |
| `3` | Desert | Temperate | No river, and the smallest water budget. Urban areas and ordinary ground cover |
| `4` | Mutated | Temperate | Ordinary river and lake, with up to two swamps in the lake. Urban areas, ordinary ground cover, and mold and crystal growths |

A snow-theater map is lit at three quarters of the ambient level its [`Time`](/keys/time/) would otherwise give, and gets no veinholes.

[`WaterAmount`](/keys/wateramount/) is scaled by a factor for each biome. Desert's factor is a third or less of any other biome's, so a desert map gets much less water at the same setting. A river also needs `WaterAmount` above `20` before the factor is applied, and the generator can still fail to fit one.

Structures placed in settlements start damaged more often on a mutated map than on any other biome.

[Map generation](/systems/map-generation/#the-passes-in-order) lists every pass and branch the biome controls.

When a map is [generated from a file](/systems/map-generation/#the-dialog-path-and-the-scenario-path), a value below `0` becomes `0` and one above `4` becomes `4`. Unless the Firestorm addon is enabled, mutated (`4`) becomes temperate (`2`) wherever the value comes from, and the map generator dialog does not offer it.
