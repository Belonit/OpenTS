---
key: VeinholeMonsters
summary: Veinhole monsters the random map generator plants.
see_also: ["system:veins", "VeinholeTypeClass"]
when_omitted:
  kind: value
  value: "0"
  note: No veinhole monsters.
---

```ini title="map seed file"
[RandomMap]
VeinholeMonsters=3
```

The generator tries to place this many veinhole monsters. It makes at most 200 placement attempts in total, so a crowded map can get fewer monsters than requested.

Each monster placed starts with a ring of veins along the border of the five-by-five block centered on it. [Map generation](/systems/map-generation/#veinholes) lists the placement test.

Monsters are placed only on a map built in the temperate theater. A map whose [`Biome`](/keys/biome/) is tundra or taiga gets none, whatever the setting.

Unless the Firestorm addon is enabled, the setting becomes `0` before the map is built. When a map is [generated from a file](/systems/map-generation/#the-dialog-path-and-the-scenario-path), a value below `0` becomes `0` and one above `5` becomes `5`.
