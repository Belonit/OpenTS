---
key: PlacementDelay
summary: Minutes a factory waits before trying again when the object it finished cannot leave yet.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: ".05"
---

```ini title="rules.ini"
[General]
PlacementDelay=.25 ; a quarter of a minute, or 225 game frames
```

The value is truncated to whole game frames.

The wait applies only to a computer house, because only computer production is attached to a producing structure. A player's production is placed from the sidebar and never waits on this timer.

When a finished object tries to leave the structure that built it, one of three things happens:

- It leaves, and the house counts it as built.
- A temporary blockage stops it, and the structure waits this long before trying again.
- It cannot leave at all, and its production is abandoned and refunded at once.

A temporary blockage is one of these:

- A vehicle or infantry waits while the previous object is still leaving a structure that lets out one at a time, such as a barracks.
- A vehicle waits while its war factory is still unloading the previous vehicle, unless the house owns another war factory of the same type that is neither building nor unloading. The new vehicle then leaves through that one.
- A structure waits while [allied vehicles, infantry or aircraft stand on its foundation](/systems/ai-base-building/#clearing-the-site).
