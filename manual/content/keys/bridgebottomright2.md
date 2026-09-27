---
key: BridgeBottomRight2
summary: Second position accepted as the bottom-right end of an east-west bridge span.
see_also: [BridgeBottomRight1, BridgeMiddle1]
when_omitted:
  kind: value
  value: "-1"
  note: The position lands two tiles before the set's first piece, outside the set.
---

`BridgeBottomRight2` names a second piece for the bottom-right end of an east-west span. The engine treats a cell at this position exactly like one at [`BridgeBottomRight1`](/keys/bridgebottomright1/).

Set both keys. If this key is left out, it names a tile of another tile set, and a cell showing subtile `4` of that tile is treated as this end of a span. An end drawn by a single piece gives both the same position, as the retail temperate theater does with `3`.
