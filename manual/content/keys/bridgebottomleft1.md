---
key: BridgeBottomLeft1
summary: Position within a bridge tile set of the piece that closes a north-south span at its bottom-left end.
see_also: [BridgeBottomLeft2, BridgeTopRight1, BridgeMiddle2]
when_omitted:
  kind: value
  value: "-1"
  note: The position lands two tiles before the set's first piece, outside the set.
---

`BridgeBottomLeft1` is the position of the piece that draws the bottom-left end of a north-south span, where the span finishes. [`BridgeBottomLeft2`](/keys/bridgebottomleft2/) names a second piece for the same end, and [`BridgeMiddle1`](/keys/bridgemiddle1/) covers how positions are counted.

A repair starts where the [top-right end](/keys/bridgetopright1/) search found the span and works south one cell at a time, returning each middle section it passes to whole. It finishes at the first cell at this position showing subtile `2`: it marks that end whole and lays the bridge deck back down along the span. A repair that meets no such cell within 29 cells stops there. The middle sections it passed stay whole, but the deck is not put back.

A collapse works south the same way to find the far end of the fallen stretch. It stops at the first cell at this position showing subtile `2`, or at the first middle section that has not collapsed.

An end piece has two looks, whole and damaged. Damage or a repair changes the end only when the cell it reaches is one the tile file marks as randomized. The change then spreads to every connected cell drawn from the same piece. A damaged end draws the piece's first [lettered alternate](/formats/theater-control/) on its randomized cells, if the piece has one, and a whole end draws the base tile there.
