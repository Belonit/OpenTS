---
key: BridgeBottomLeft2
summary: Second position accepted as the bottom-left end of a north-south bridge span.
see_also: [BridgeBottomLeft1, BridgeMiddle2]
when_omitted:
  kind: value
  value: "-1"
  note: The position lands two tiles before the set's first piece, outside the set.
---

`BridgeBottomLeft2` names a second piece for the bottom-left end of a north-south span. The engine treats a cell at this position exactly like one at [`BridgeBottomLeft1`](/keys/bridgebottomleft1/).

Set both keys. If this key is left out, it names a tile of another tile set, and a cell showing subtile `2` of that tile is treated as this end of a span. An end drawn by a single piece gives both the same position, as the retail temperate theater does with `6`.
