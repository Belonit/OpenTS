---
key: TunnelSpeed
summary: Multiplier on how fast a subterranean unit sinks and rises, and divisor of its dig-in wait.
see_also: [ROT, MovementZone, AllowShroudedSubteranneanMoves]
when_omitted:
  kind: value
  value: "1"
---

A higher value makes a tunneling unit dig in sooner and sink and rise faster. It does not change how fast the unit travels underground.

A unit whose [`Locomotor`](/keys/locomotor/) tunnels goes through these steps:

1. It turns to face its destination.
2. It tips nose down for `(64 ÷ ROT) ÷ TunnelSpeed` frames, where [`ROT`](/keys/rot/#scope-aircrafttype) is the unit's rate of turn.
3. It sinks, moving its travel speed times `TunnelSpeed` in leptons of height each frame.
4. It crosses underground at a fixed 19 leptons a frame.
5. It rises at the same rate it sank.
6. It levels out on the surface for `64 ÷ ROT` frames, which `TunnelSpeed` does not divide.

The sink and the rise never move less than 5 leptons a frame. Once a unit's travel speed times `TunnelSpeed` falls below 6, lowering the value further no longer slows them. The dig-in wait has no such limit: the closer the value gets to `0`, the longer the wait.

:::caution[Keep the value above 0]
A negative value skips the dig-in wait, and at `0` the length of the wait is undefined.
:::
