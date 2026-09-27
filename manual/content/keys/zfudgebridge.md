---
key: ZFudgeBridge
summary: The depth bias applied to an object while it is under a bridge.
see_also: ["ZFudgeCliff", "ZFudgeColumn", "ZFudgeTunnel"]
when_omitted:
  kind: value
  value: "0"
---

`ZFudgeBridge` moves an object back in drawing order while it is under a bridge, so the bridge deck draws over it. A larger value moves it further back. The value applies as written, with no strength multiplier.

An object counts as under a bridge when either of these holds:

- Its own cell is covered by the bridge.
- The cell beside it across the bridge's width is covered: the cell to the north or south for an east-west bridge, or the cell to the east or west for a north-south bridge.

An object riding on the deck never counts.

Only the largest of an object's four depth fudges applies: this one, [`ZFudgeCliff`](/keys/zfudgecliff/), [`ZFudgeColumn`](/keys/zfudgecolumn/) and [`ZFudgeTunnel`](/keys/zfudgetunnel/). It is added to the object's other depth adjustments, such as those for its height and its locomotor. A fudge whose condition does not hold counts as `0`, so a negative value takes effect only when the conditions of all four fudges hold at once.

Only aircraft, infantry and vehicles use the depth fudges. A structure reads all four values and never applies them.

The stock rules set this value on three types only: the Titan (`2`), the harvester (`7`) and the Mammoth Mk. II (`25`).
