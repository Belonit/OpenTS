---
key: BridgeTopRight1
summary: Position within a bridge tile set of the piece that starts a north-south span at its top-right end.
see_also: [BridgeTopRight2, BridgeBottomLeft1, BridgeMiddle2]
when_omitted:
  kind: value
  value: "-1"
  note: The position lands two tiles before the set's first piece, outside the set.
---

`BridgeTopRight1` is the position of the piece that draws the top-right end of a north-south span, where the span starts. [`BridgeTopRight2`](/keys/bridgetopright2/) names a second piece for the same end, and [`BridgeMiddle1`](/keys/bridgemiddle1/) covers how positions are counted.

Repairs and collapses both find a north-south span by this end. The search steps back along the bridge toward the top-right. It stops at the first cell of this piece showing subtile `12`, or at the first middle section; a collapse passes over a collapsed section. It then works south from there toward the [bottom-left end](/keys/bridgebottomleft1/). A repair that stops at a middle section also starts a new search two cells further toward the top-right, so the sections between that middle section and this end are repaired as well.

An end piece has two looks, whole and damaged. Damage or a repair changes the end only when the cell it reaches is one the tile file marks as randomized. The change then spreads to every connected cell drawn from the same piece. A damaged end draws the piece's first [lettered alternate](/formats/theater-control/) on its randomized cells, if the piece has one, and a whole end draws the base tile there.
