---
key: BridgeTopLeft2
summary: Second position accepted as the top-left end of an east-west bridge span.
see_also: [BridgeTopLeft1, BridgeMiddle1]
when_omitted:
  kind: value
  value: "-1"
  note: The position lands two tiles before the set's first piece, outside the set.
---

`BridgeTopLeft2` names a second piece for the top-left end of an east-west span. The engine treats a cell at this position exactly like one at [`BridgeTopLeft1`](/keys/bridgetopleft1/).

Set both keys. If this key is left out, it names a tile of another tile set, and a cell showing subtile `8` of that tile is treated as this end of a span. An end drawn by a single piece gives both the same position.
