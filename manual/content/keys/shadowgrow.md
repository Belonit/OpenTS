---
key: ShadowGrow
summary: Parsed multiplayer default that the engine never uses.
no_effect: true
see_also: [ShroudGrow, ShroudRate]
when_omitted:
  kind: value
  value: "yes"
---

No session option is set from this value, and no setup screen offers one. To make the shroud creep back, set [`ShroudGrow`](/keys/shroudgrow/) in `[AudioVisual]`, with the interval in [`ShroudRate`](/keys/shroudrate/). Those two apply to every game type.
