---
key: EMPulseSparkles
summary: The animation attached to an object an EM pulse stuns.
see_also: ["system:emp-pulse"]
when_omitted:
  kind: value
  value: none
---

Every vehicle, aircraft and infantryman [a pulse stuns](/systems/emp-pulse/#what-a-pulse-reaches) gets a copy of this animation, attached so that it moves with the object. A stunned structure gets one only if it is one of the deployed-vehicle kinds [listed under `DeploysInto`](/keys/deploysinto/). Other stunned structures get none.

Each copy starts after a random delay of up to 25 frames and plays for the animation's normal length, which can end before the stun does. When the object recovers, a copy that is still playing stops at the end of its current loop.

:::danger[Name an animation before any pulse can stun]
With no animation named here, the game crashes the first time a pulse stuns an object that gets one.
:::
