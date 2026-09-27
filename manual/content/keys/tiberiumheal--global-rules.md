---
key: TiberiumHeal
scope: global-rules
label: Healing interval
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: ".0167"
---

The value sets the time between Tiberium healing steps, in minutes. The game multiplies it by 900 frames and drops the fraction: the default gives one step every 15 frames, and the stock `.010` one every 9. Every infantry, vehicle and aircraft healing on Tiberium through [`TiberiumHeal=yes`](/keys/tiberiumheal/#scope-aircrafttype) heals on the same frames, because the interval is counted from the start of the game, not from when each object reached Tiberium.

:::danger[Keep the interval at one frame or more]
Any value strictly between `-1/900` and `1/900`, including `0`, rounds to zero frames. The game then crashes as soon as a damaged object that heals on Tiberium stands in Tiberium. Keep the value at `.0012` or above.
:::
