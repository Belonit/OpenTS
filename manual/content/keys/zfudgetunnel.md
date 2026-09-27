---
key: ZFudgeTunnel
summary: The depth bias applied to an object standing at a tunnel mouth.
see_also: ["ZFudgeBridge", "ZFudgeCliff", "ZFudgeColumn"]
when_omitted:
  kind: value
  value: "10"
---

`ZFudgeTunnel` moves an object back in drawing order while it stands at a tunnel mouth, so the tunnel art draws over it. A larger value moves it further back. The value applies as written when the object is at a tunnel mouth and not at all otherwise.

The object is at a tunnel mouth when both of these hold:

1. Its own cell holds a tunnel, or failing that its neighbor to the north, or failing that its neighbor to the west. The first of these that holds a tunnel is the tunnel cell.
2. The cell two steps north or two steps west of the tunnel cell also holds a tunnel.

An object riding a bridge deck gets no tunnel fudge.

Only the largest of the four depth fudges applies; [`ZFudgeBridge`](/keys/zfudgebridge/) describes how they combine.

The stock rules set this value on the same 23 vehicles that set [`ZFudgeColumn`](/keys/zfudgecolumn/), between `12` and `18`.
