---
key: ZFudgeColumn
summary: The depth bias applied to an object passing a bridge support column.
see_also: ["ZFudgeBridge", "ZFudgeCliff", "ZFudgeTunnel"]
when_omitted:
  kind: value
  value: "5"
---

`ZFudgeColumn` moves an object back in drawing order while it passes the support columns of a road bridge, so the columns draw over it. A larger value moves it further back.

The value is multiplied by a strength from `0` to `2`. The strength is `0` unless the object is under a bridge as [`ZFudgeBridge`](/keys/zfudgebridge/) defines it, or under the place where a destroyed span stood.

The strength counts the middle span tiles of a road bridge, the pieces between the two ends of a span, in any state of damage:

- A middle span tile to the south or to the east adds `1`. Tiles in both places still add only `1`.
- A middle span tile to the south-east adds another `1`.

Railway bridge tiles never count.

Only the largest of the four depth fudges applies; [`ZFudgeBridge`](/keys/zfudgebridge/) describes how they combine.

The stock rules set this value on 23 vehicles, between `7` and `18`.
