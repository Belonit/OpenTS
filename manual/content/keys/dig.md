---
key: Dig
summary: The animation played where a subterranean vehicle breaks the surface.
see_also: [DigSound, TunnelSpeed, Locomotor]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
Dig=MYDIGCLOUD ; an AnimType registered in [Animations]
```

A vehicle with the tunnel [`Locomotor`](/keys/locomotor/) creates this animation at its position at three points of a trip underground:

1. when it has turned to face its destination and starts to dig in;
2. when the nose-down dig-in finishes and it starts to sink;
3. when, rising at its destination, it comes within 50 leptons of ground level.

Each time, [`DigSound`](/keys/digsound/) plays with it.

A cancelled move can skip points. If the move is cancelled during the dig-in, the vehicle levels out on the surface after the first point. If it is cancelled while the vehicle sinks, the vehicle rises again where it is, and the third point plays only if it had already sunk 50 leptons or more.

:::danger[Set Dig before using tunneling vehicles]
With the key unset or set to `none`, the game crashes the first time a tunneling vehicle turns to face a destination and starts to dig in.
:::
