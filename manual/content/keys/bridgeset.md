---
key: BridgeSet
summary: The tile set that supplies the sixteen pieces a road bridge is built from.
see_also: [TrainBridgeSet, BridgeMiddle1, BridgeStrength]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

`BridgeSet` names the tile set that holds the road bridge pieces. The sixteen tiles that start at that set's first tile count as road bridge pieces, and the ten `Bridge` position keys say which of them draws each part of a span. The value is a tile-set number, the `NNNN` of a `[TileSetNNNN]` section in the [theater control file](/formats/theater-control/).

The retail temperate theater lays out its road bridge set like this:

```ini title="TEMPERAT.INI"
[General]
BridgeSet = 19          ; road bridge pieces come from [TileSet0019]
BridgeTopLeft1 = 1      ; the first piece of that set
BridgeTopLeft2 = 2
BridgeBottomRight1 = 3
BridgeBottomRight2 = 3  ; a pair may name the same piece
BridgeTopRight1 = 4
BridgeTopRight2 = 5
BridgeBottomLeft1 = 6
BridgeBottomLeft2 = 6
BridgeMiddle1 = 7       ; positions 7 through 11
BridgeMiddle2 = 12      ; positions 12 through 16
```

Damage, collapse and engineer repairs follow the position keys, as [`BridgeMiddle1`](/keys/bridgemiddle1/) describes. Road bridge pieces also link the two banks for route-finding, so units plan paths across the span.

:::caution[Route-finding assumes the retail piece order]
Route-finding locates a span's two ends from the piece order shown above, whatever the position keys say. The same holds for the [railway set](/keys/trainbridgeset/). A set that orders its pieces differently is still damaged and repaired by its keys, but route-finding misreads where its spans start and end.
:::

:::caution[An unresolved set claims the theater's first tiles]
If `BridgeSet` is missing, or names a set the theater never reads, the first fifteen tiles the theater loads count as road bridge pieces.
:::
