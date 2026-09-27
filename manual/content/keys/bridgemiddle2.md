---
key: BridgeMiddle2
summary: Position within a bridge tile set of the first of the five middle pieces of a north-south span.
see_also: [BridgeMiddle1, BridgeSet, TrainBridgeSet]
when_omitted:
  kind: value
  value: "-1"
  note: The position lands two tiles before the set's first piece, outside the set.
---

`BridgeMiddle2` is the position of the first of five pieces that draw the middle sections of a north-south span, the kind that runs from a [top-right end](/keys/bridgetopright1/) to a [bottom-left end](/keys/bridgebottomleft1/). The five pieces sit at this position and the four after it.

Each piece shows one condition of a middle section:

| Piece | Condition of the section |
| --- | --- |
| `BridgeMiddle2` | whole |
| `BridgeMiddle2` + 1 | broken on the side toward the top-right end |
| `BridgeMiddle2` + 2 | broken on the side toward the bottom-left end |
| `BridgeMiddle2` + 3 | broken on both sides |
| `BridgeMiddle2` + 4 | collapsed |

[`BridgeMiddle1`](/keys/bridgemiddle1/) does the same for east-west spans. Its page covers how positions are counted, how damage and repair move a section through its pieces, and when a hit can damage a span.
