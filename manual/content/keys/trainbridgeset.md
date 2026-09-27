---
key: TrainBridgeSet
summary: The tile set that supplies the sixteen pieces a railway bridge is built from.
see_also: [BridgeSet, BridgeRepairHut, "system:capture"]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The set is laid out like the road bridge set and uses the same ten `Bridge` position keys. [`BridgeSet`](/keys/bridgeset/) covers how a position selects a tile.

This set decides which kind of bridge an engineer rebuilds. When an engineer enters a [`BridgeRepairHut=yes`](/keys/bridgerepairhut/) structure, the engine searches the five-by-five block of cells centered on the engineer. One tile of this set anywhere in that block selects the railway repair; otherwise the road repair runs. [Repairing a bridge](/systems/capture/#repairing-a-bridge) covers the rest of that visit.

Weapon damage tests the road set first. Both sets are tested for the same middle pieces: the first four middle pieces of either span direction, counted from [`BridgeMiddle1`](/keys/bridgemiddle1/) or [`BridgeMiddle2`](/keys/bridgemiddle2/). A struck cell is damaged as a railway bridge when it holds one of those pieces from this set or carries a railway bridge deck, and none of these apply:

- The cell has a low bridge overlay. A low bridge is damaged as one, and neither set is read.
- The cell holds one of those pieces from the road set.
- The cell carries a road bridge deck.

:::caution[An unresolved role makes the theater's first tiles railway bridge]
The railway bridge test does not check that the role resolved. Left unresolved, it treats the theater's first fifteen tiles as railway bridge pieces, and those include the clear ground tile. An engineer at a repair hut then runs the railway repair whenever such a cell lies in the searched block, and route-finding treats those cells as bridge cells.
:::
