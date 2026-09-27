---
key: Deacc
summary: The speed a particle loses each frame.
see_also: ["Velocity", "MaxEC", "BehavesLike"]
when_omitted:
  kind: value
  value: "0"
---

The value is in leptons per frame, the same unit as [`Velocity`](/keys/velocity/). The speed it reduces is a single value along the particle's direction of travel, not one per axis. Only `Fire` and `Smoke` [particles](/keys/behaveslike/#scope-particletype) use it.

A `Fire` particle loses this amount every frame. When its speed reaches zero it stops, and it is removed on the next frame. `Velocity` divided by this value is therefore how many frames a flame travels: `Velocity=8` with `Deacc=.25` stops after 32 frames. The flame ends sooner if its [`MaxEC`](/keys/maxec/) lifetime runs out first.

A `Smoke` particle loses this amount only while it rises faster than 3 leptons a frame. A puff that starts at 3 or less keeps its starting speed. A faster puff slows until its speed is 3 or less, and keeps that final speed for the rest of its life. The final speed lies between 3 minus `Deacc` and 3, so a small `Deacc` gives a steady climb of about 3 leptons a frame.

:::caution[Keep Deacc at 2 or less on smoke]
A puff rises only by whole leptons each frame. With a larger `Deacc`, a puff's final speed can fall below 1, and the puff then stops rising. A final speed of -1 or lower makes it sink into the ground for the rest of its life.
:::

A negative value adds speed instead. A flame then never stops and keeps accelerating until its lifetime or another limit ends it. A smoke puff that starts faster than 3 leptons a frame keeps accelerating upward.
