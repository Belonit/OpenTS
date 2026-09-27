---
key: NewINIFormat
summary: The layout revision the rest of the map file is read in.
when_omitted:
  kind: value
  value: "0"
  note: An absent key gives 0, the oldest layout. The previous map's value does not carry over.
---

```ini title="map file"
[Basic]
NewINIFormat=4
```

The value selects how the rest of the map file stores the overlay layer and cell positions. The game reads it from `[Basic]` before any of the map's contents. Two thresholds matter, and no value above `4` changes anything further.

Above `1`, the overlay layer is read from the `[OverlayPack]` and `[OverlayDataPack]` sections. At `1` or below, the map has no overlay layer at all: no Tiberium, no walls, no overlay bridges and no other overlay.

At `4` or above, a vehicle, infantry, aircraft or structure placement stores its cell as two numbers, X and Y. The cell numbers that key the terrain object and cell tag sections are read as `X + Y * 1000`. Below `4`, a placement stores one cell number, and every cell number is read as `X + Y * 128`. That form cannot describe a cell more than 127 columns from the left edge.

The same threshold sets how a [Move to Cell](/mapping/missions/tmission-movecell/) script line's cell number is read: as `X + Y * 128` below `4`, and as `X + Y * 1000` at `4` or above. It applies to every script the scenario loads, both those the map declares and those from the AI files. The number is converted once, as the script is read.

:::caution[Keep NewINIFormat in every map]
A map without this key is read as format `0`. It loses its entire overlay layer, and every vehicle, infantry, aircraft, structure, terrain object and cell tag is placed by the 128-column numbering, which puts it on the wrong cell or off the map.
:::
