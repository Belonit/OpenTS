---
key: StateAIAdvance
summary: The frames a particle spends in each animation state.
see_also: ["StartStateAI", "EndStateAI", "Normalized", "DeleteOnStateLimit"]
when_omitted:
  kind: value
  value: "4"
---

A larger figure plays the sequence more slowly. `Gas`, `WeakGas`, `Smoke`, `Fire` and `Web` particles use it; `Spark` and `Railgun` particles have no animation states and ignore it.

Particles of one type do not step in unison. Each particle starts its steps at a different point, and about half the particles stay one frame longer in each state. With the default `4`, those particles step every 5 frames. A burst created together therefore drifts out of step within a few states.

A `Fire` particle marked [`Normalized=yes`](/keys/normalized/#scope-particletype) ignores this figure and works out its own interval from its flight.

The figure is held in one signed byte: `128` to `255` wrap to negative values, and `256` wraps to `0`. A negative interval acts as its positive size: `-4` steps every 4 frames. The half that would stay one frame longer steps one frame sooner instead, every 3 frames.

:::danger[Keep the interval away from 0 and -1]
The interval is used as a divisor with no check for zero. At `0` the particles that step on the interval itself stop the game on their first frame. At `-1` the half that stays one frame longer does, because it divides by one more than the interval. Values that wrap to these, such as `256` and `255`, and a `Normalized` interval that lands on them, do the same. A `Smoke` or `Fire` particle whose state is already at or past `EndStateAI` is not affected.
:::
