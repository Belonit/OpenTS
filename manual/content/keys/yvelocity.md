---
key: YVelocity
summary: The other horizontal axis of the spread of speeds a spark is thrown at.
see_also: ["XVelocity", "MinZVelocity", "ZVelocityRange", "BehavesLike"]
when_omitted:
  kind: value
  value: "1"
---

`YVelocity` sets the spread of speeds a spark is thrown at along the second horizontal axis, the same way [`XVelocity`](/keys/xvelocity/) does for the first. That page explains how the three axis settings set a spark's speed and direction, what the spark system adds to them, and which systems read them.

Giving the two horizontal axes different values makes a burst spread further along one axis than the other. The stock spark types keep them equal.

:::danger[Keep YVelocity nonzero]
`YVelocity=0` divides by zero and crashes the game when a spark system holding the type throws its first burst.
:::
