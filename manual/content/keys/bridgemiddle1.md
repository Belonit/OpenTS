---
key: BridgeMiddle1
summary: Position within a bridge tile set of the first of the five middle pieces of an east-west span.
see_also: [BridgeSet, TrainBridgeSet, BridgeMiddle2, BridgeStrength]
when_omitted:
  kind: value
  value: "-1"
  note: The position lands two tiles before the set's first piece, outside the set.
---

`BridgeMiddle1` is the position of the first of five pieces that draw the middle sections of an east-west span, the kind that runs from a [top-left end](/keys/bridgetopleft1/) to a [bottom-right end](/keys/bridgebottomright1/). The five pieces sit at this position and the four after it.

Positions count from `1` within the bridge tile set: position `1` is the set's first tile, and position `p` is the tile `p - 1` places after it. The ten `Bridge` position keys apply to both kinds of span: road spans draw their pieces from [`BridgeSet`](/keys/bridgeset/), and railway spans from [`TrainBridgeSet`](/keys/trainbridgeset/).

Each piece shows one condition of a middle section:

| Piece | Condition of the section |
| --- | --- |
| `BridgeMiddle1` | whole |
| `BridgeMiddle1` + 1 | broken on the side toward the top-left end |
| `BridgeMiddle1` + 2 | broken on the side toward the bottom-right end |
| `BridgeMiddle1` + 3 | broken on both sides |
| `BridgeMiddle1` + 4 | collapsed |

A section spans several cells drawn from one piece, and they all switch pieces together. Combat damage moves a section down the table, never back up, and a collapse switches every section that falls to the last piece. An engineer's [repair](/systems/capture/#repairing-a-bridge) returns every middle section it passes to the first piece.

A hit can damage a road or rail span only under **All of:**

- bridge destruction is on: [`DestroyableBridges`](/keys/destroyablebridges/) in a campaign, or the [`BridgeDestruction`](/keys/bridgedestruction/) option in any other game;
- the warhead is a [wall destroyer](/keys/wall/#scope-warheadtype);
- the struck cell shows one of the first four middle pieces of either direction, counted from this key or from [`BridgeMiddle2`](/keys/bridgemiddle2/), or lies under the span's deck;
- if the struck cell lies under a deck, the blast goes off near deck height, not on the ground below.

A collapsed section with no deck over it takes no further bridge damage. [`BridgeStrength`](/keys/bridgestrength/) decides how likely each hit is to count.
