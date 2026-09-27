---
key: UrbanPresence
summary: How many settlements a generated map is given, as a figure from 0 to 100.
see_also: [Biome, Vegetation]
when_omitted:
  kind: value
  value: "0"
  note: No settlements are placed.
---

`UrbanPresence` sets how many settlements the generator tries to place. The [`Biome`](/keys/biome/) decides which kind:

- **Tundra and taiga** get rural settlements. Each is a dirt road junction on open ground in the playable area, outside every start point's protected ground, with a few civilian buildings along its roads, and a few civilians and civilian vehicles.
- **Temperate, desert and mutated** get urban areas. Each is a paved district grown outward from a cell, with roads, buildings, traffic and a pavement edge.

[Map seed files](/formats/map-seed/) covers the section it is written in.

```ini title="map seed file"
[RandomMap]
Biome=2
UrbanPresence=3
```

Each point asks for two more rural settlements or three more urban areas. The pass stops after ten attempts, however many settlements were asked for. An attempt that finds nowhere suitable still counts as one of the ten.

:::caution[Only the bottom of the range does anything]
The figure stops making a difference once it asks for ten settlements or more: at `5` on tundra and taiga, and at `4` on the other biomes. Every figure from there to `100` builds the same map. The map generator dialog still offers the whole range as a slider.
:::
