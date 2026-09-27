---
key: ChainReaction
summary: Whether damage to the overlay's cell can set off the Tiberium standing there.
see_also: ["system:tiberium", "Tiberium", "Power"]
when_omitted:
  kind: value
  value: "no"
---

With `ChainReaction=yes`, explosions in the overlay's cell can detonate the Tiberium there, and the detonation can spread to neighboring Tiberium cells. Without it, an explosion's damage never detonates or thins the cell's Tiberium. [Other effects](/systems/tiberium/#damage), such as a crater, can still remove stages.

On a [`Tiberium=yes`](/keys/tiberium/#scope-overlaytype) overlay, only an explosion whose warhead sets [`Tiberium=yes`](/keys/tiberium/#scope-warheadtype) counts. A sonic wave passing over the cell counts whatever its warhead. A destroyed Tiberium-spawning terrain object also sets off its cell without the warhead test.

Each counting explosion gives the cell a chance to detonate, from stage 2 upward. A counting explosion also removes one growth stage from the cell for every ten points of its damage, whether or not the cell detonates. A sonic wave removes none. [Tiberium damage](/systems/tiberium/#damage) gives the detonation chance, the damage it deals, and how it spreads.

A detonation needs Tiberium in the cell. On an overlay that is not Tiberium, the key has nothing to set off, because a cell holds only one overlay. The one exception is a cell that also holds a Tiberium-spawning terrain object, which counts as Tiberium of the type it spawns.

`ChainReaction` is separate from [`Explodes=yes`](/keys/explodes/#scope-overlaytype), which makes the overlay itself blow up.
