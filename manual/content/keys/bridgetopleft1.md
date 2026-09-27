---
key: BridgeTopLeft1
summary: Position within a bridge tile set of the piece that starts an east-west span at its top-left end.
see_also: [BridgeTopLeft2, BridgeBottomRight1, BridgeMiddle1]
when_omitted:
  kind: value
  value: "-1"
  note: The position lands two tiles before the set's first piece, outside the set.
---

`BridgeTopLeft1` is the position of the piece that draws the top-left end of an east-west span, where the span starts. [`BridgeTopLeft2`](/keys/bridgetopleft2/) names a second piece for the same end, and [`BridgeMiddle1`](/keys/bridgemiddle1/) covers how positions are counted.

Repairs and collapses both find an east-west span by this end. The search steps back along the bridge toward the top-left. It stops at the first cell of this piece showing subtile `8`, or at the first middle section; a collapse passes over a collapsed section. It then works east from there toward the [bottom-right end](/keys/bridgebottomright1/). A repair that stops at a middle section also starts a new search two cells further toward the top-left, so the sections between that middle section and this end are repaired as well.

An end piece has two looks, whole and damaged. Damage or a repair changes the end only when the cell it reaches is one the tile file marks as randomized. The change then spreads to every connected cell drawn from the same piece. A damaged end draws the piece's first [lettered alternate](/formats/theater-control/) on its randomized cells, if the piece has one, and a whole end draws the base tile there.
