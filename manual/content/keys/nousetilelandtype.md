---
key: NoUseTileLandType
summary: Overlay whose own land type stands instead of the land type of the tile beneath it.
see_also: [Land, Wall, Tiberium]
when_omitted:
  kind: value
  value: "yes"
---

With the flag set, the cell reports the overlay's [`Land`](/keys/land/) and ignores the land type of the tile beneath. With the flag off, the tile's land type usually wins. An overlay whose `Land` is `Wall` or `Railroad` keeps that value either way.

```ini title="rules.ini"
[MYRUBBLE]              ; example overlay that should not change the ground
Land=Clear
NoUseTileLandType=no    ; the tile underneath keeps deciding
```

With the flag off, a cell that holds a Tiberium overlay, or in which a [`SpawnsTiberium=yes`](/keys/spawnstiberium/) tree stands, takes its land type from the first rule that matches:

1. On a corner, steep or double slope, the overlay is removed and the cell reports the tile's land type.
2. If the overlay's `Land` is `Clear`, the cell reports `Tiberium`.
3. Otherwise the cell reports the overlay's `Land`.

While the overlay is on the cell, and the flag is set or the overlay's `Land` is `Wall` or `Railroad`, the cell still takes its slope from the tile but ignores the tile's other effects. The cell does not re-blend with the neighboring ground, does not start the animation its tile names, and does not mark the cells its tile casts shadow over.

[`CliffBackImpassability`](/keys/cliffbackimpassability/) can still turn the cell to `Rock` with the flag set.
