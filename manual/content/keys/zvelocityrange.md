---
key: ZVelocityRange
summary: The spread of upward speeds a spark is thrown at.
see_also: ["MinZVelocity", "XVelocity", "YVelocity", "BehavesLike"]
when_omitted:
  kind: value
  value: "1"
---

A spark system gives each particle an upward speed of [`MinZVelocity`](/keys/minzvelocity/) plus a random amount below this value, in leptons a frame. The stock spark types set `MinZVelocity=40` and `ZVelocityRange=15`, so each spark's upward speed is picked from 40 to 54 leptons a frame. Raising `MinZVelocity` throws the whole shower higher, while a wider range spreads the sparks over more heights. [`XVelocity`](/keys/xvelocity/) explains how the system then steers each spark and which systems read these settings.

A firestorm explosion thrown by [`DefaultFirestormExplosionSystem`](/keys/defaultfirestormexplosionsystem/) adds one random vector to every spark in a burst. That vector's vertical part is a random amount below this value in either direction, without `MinZVelocity`, so it can tilt the whole burst up or down. In those explosions, sparks can be thrown downward only when this value exceeds `MinZVelocity` by at least `2`.

:::danger[Keep ZVelocityRange nonzero]
`ZVelocityRange=0` divides by zero and crashes the game when a spark system holding the type throws its first burst.
:::
