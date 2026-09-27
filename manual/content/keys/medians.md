---
key: Medians
summary: Fourteen-tile set of the divider strips laid down the middle lane of a paved road.
see_also: [ClearToPaveLat]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The [random map generator](/systems/map-generation/#settlements) lays median strips only down the north-south roads of a town. East-west roads get none. It uses four tiles of the set, counted from the set's first tile as offset 0:

| Offset | Where the generator lays it |
| --- | --- |
| 5 | The head of a strip, just past a junction |
| 4 | Each following cell of the strip |
| 3 | The tail, where the next junction interrupts the strip or the road ends |
| 12 | One cell to each side of a junction where the road crosses another |

A strip starts after a junction only when more than five cells of road remain before the road's end. If the road instead stops at an end cap partway down, the generator replaces the strip above the cap with plain road.

All fourteen tiles count as pavement for the [`ClearToPaveLat`](/keys/cleartopavelat/) blend, so a strip does not cut blended edges into the pavement around it.

:::caution[Set Medians in any theater that gets towns]
The generator does not check that this role is bound. Without it, the generator lays unrelated tiles from the start of the theater where the medians belong. It also takes any of the theater's first thirteen tiles for a median when it checks the road it has already laid, so a junction can be laid over ground that holds one of those tiles.
:::
