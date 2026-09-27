---
key: FirestormAirAnim
summary: The animation a raised firestorm wall creates when what it catches is more than 100 leptons above the ground.
see_also: ["system:laser-fences"]
when_omitted:
  kind: value
  value: none
---

`FirestormAirAnim` plays when a raised firestorm wall catches something more than 100 [leptons](/glossary/#lepton) above the ground. It appears at the caught object's position. Anything lower gets [`FirestormGroundAnim`](/keys/firestormgroundanim/), drawn at the wall section instead.

Either animation plays when the wall catches:

- an object in a raised section's cell, when the section [sweeps its cell](/systems/laser-fences/#what-a-raised-section-destroys);
- an object with the flying or jumpjet locomotor moving over a raised section;
- a projectile the wall [stops](/systems/laser-fences/#projectiles). The projectile is removed without detonating, and the animation plays only if the projectile's damage is above 0.

The animation plays its type's [`LoopCount`](/keys/loopcount/), once if the type sets none.

:::danger[Set `FirestormAirAnim` before a wall can be raised]
If the key is missing or empty, the game crashes the first time a raised section catches something above 100 leptons.
:::
