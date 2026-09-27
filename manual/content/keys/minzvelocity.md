---
key: MinZVelocity
summary: The smallest upward part of the speed picked for each spark.
see_also: ["ZVelocityRange", "XVelocity", "YVelocity", "BehavesLike"]
when_omitted:
  kind: value
  value: "0"
---

A spark system picks an upward component for each spark of this type: this figure plus a random amount below [`ZVelocityRange`](/keys/zvelocityrange/), in leptons a frame. The two keys together set the vertical spread of a burst. Raising this figure throws every spark higher and faster. A negative figure can throw sparks downward. [`XVelocity`](/keys/xvelocity/) says which systems read the axis settings.

The upward component and the two horizontal ones picked from `XVelocity` and [`YVelocity`](/keys/yvelocity/) together set the spark's speed. The system then bends the spark toward its [`SpawnDirection`](/keys/spawndirection/), or toward one random direction for the whole burst, and keeps that speed. The bend changes the direction, so a spark can leave with less upward speed than this figure. The random burst direction does not use this figure; [`ZVelocityRange`](/keys/zvelocityrange/) describes it.

After the throw, [`Gravity`](/keys/gravity/) pulls the spark down every frame and arcs the shower over; that page explains why sparks fall faster than its figure suggests. A spark dies where it meets the ground, a bridge deck, a structure, a wall or a gate.
