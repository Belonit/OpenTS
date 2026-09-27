---
key: Translucent25State
summary: The animation state at which a flame particle thins to a quarter faded.
see_also: ["Translucent50State", "Translucency", "EndStateAI", "StartStateAI"]
when_omitted:
  kind: value
  value: "-1"
---

A [`Fire`](/keys/behaveslike/#scope-particletype) particle becomes a quarter faded when its animation state reaches this number. No other behavior reads the setting.

The flame checks this number only when its state advances. To be matched, the number must therefore be above [`StartStateAI`](/keys/startstateai/), where the state begins, and no higher than [`EndStateAI`](/keys/endstateai/), where it stops. With [`DeleteOnStateLimit=yes`](/keys/deleteonstatelimit/) the number must be below `EndStateAI`, because the flame is removed in the frame it reaches that state, before the fade is drawn.

The flame must also reach the state before it is removed for another reason: its speed runs out, its [`MaxEC`](/keys/maxec/) lifetime ends, or the ground ahead of it rises.

The engine keeps only the low byte of the value, so `-1` becomes `255` and `266` becomes `10`. A result from `128` to `255` never matches, because a particle's state never climbs past `127`. That is why the default `-1` leaves a flame that never thins.

If this and [`Translucent50State`](/keys/translucent50state/) name the same state, the flame ends at the half fade, because the half fade is applied second.

Fading is drawn only at the High detail setting. [`Translucency`](/keys/translucency/#scope-particletype) describes the three fade levels and the lower detail settings.
