---
key: Fill
summary: The tile every cell of the map starts out as, either clear ground or water.
see_also: [Size, Level, Theater]
when_omitted:
  kind: value
  value: "Clear"
---

`Fill=Water`, written in any case, fills the map with the theater's water tile. Every other value, including a misspelling of `Water`, fills it with clear ground.

```ini title="map file"
[Map]
Size=0,0,64,64
Fill=Water
```

The fill is only the starting tile. Each cell that the map's [terrain data](/formats/scenario-terrain/) lists takes its tile and height from that data, so the fill shows only on cells the data leaves out. Water laid by the fill has no shoreline. Shore tiles have to come from the terrain data.

:::caution[List every cell in the terrain data]
Give every cell a tile in the terrain data. The fill tile is chosen before this map's [`Theater`](/keys/theater/) is loaded, from whichever tile set was loaded before it, whether by an earlier map, a saved game or a random map. On the first map of a session, or after a change of theater, the cells the data leaves out can take the wrong tile.
:::
