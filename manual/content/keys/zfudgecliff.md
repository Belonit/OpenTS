---
key: ZFudgeCliff
summary: The depth bias applied to an object standing at the foot of a cliff.
see_also: ["ZFudgeBridge", "ZFudgeColumn", "ZFudgeTunnel"]
when_omitted:
  kind: value
  value: "10"
---

`ZFudgeCliff` moves an object back in drawing order while it stands at the foot of a cliff, so the cliff draws over it. A larger value moves it further back.

The value is multiplied by a strength taken from the ground to the south-east of the object. A cell counts as a cliff when it stands four or more height levels above the object's cell. The strength is:

1. `1` when the cell two steps to the south-east is a cliff.
2. Otherwise, `2` when the cell one step to the south-east is a cliff.
3. Otherwise, `0`.

An object riding a bridge deck gets no cliff fudge.

Only the largest of the four depth fudges applies; [`ZFudgeBridge`](/keys/zfudgebridge/) describes how they combine.
