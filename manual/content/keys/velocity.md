---
key: Velocity
summary: The speed a particle is created with, in leptons per frame.
see_also: ["Deacc", "BehavesLike", "XVelocity", "MinZVelocity"]
when_omitted:
  kind: value
  value: "0"
---

What this speed moves depends on the particle's [behavior](/keys/behaveslike/#scope-particletype):

| Behavior | Effect of the speed |
| --- | --- |
| `Fire` | Each frame the flame moves toward its target by this speed times a random factor from `0.72` to `1.08`. A flame whose speed is `0` or less is removed, so a flame with no `Velocity` is removed on its first logic frame. |
| `Smoke` | The puff climbs this many whole leptons a frame. When the puff is created, a random `-1`, `0` or `1` is added to the speed, so a plume does not rise as a solid column. |
| `Railgun` | The particle drifts outward from the beam at this speed plus a random amount set by the railgun system's [`VelocityPerturbationCoefficient`](/keys/velocityperturbationcoefficient/), and the speed changes by a small random amount each frame. |
| `Gas`, `WeakGas`, `Spark`, `Web` | The particle does not move by this speed. A spark's motion comes from [`XVelocity`](/keys/xvelocity/), [`YVelocity`](/keys/yvelocity/) and [`ZVelocityRange`](/keys/zvelocityrange/), and a web particle does not move at all. |

A cell is 256 leptons across. The stock `FireStream` flame, at `28.0`, crosses a cell in about nine frames, while the stock railgun particles, at `0.3` and `0.4`, start at roughly `0.1` to `0.6` leptons a frame.

[`Deacc`](/keys/deacc/) lowers the speed of `Fire` and `Smoke` particles as they travel.

A successor created through [`NextParticle`](/keys/nextparticle/) takes the speed its predecessor had reached, not this value.

A smoke system slows the particles it emits as the system ages. [`SpawnFrames`](/keys/spawnframes/) gives the amount and the minimum speed of `2`.
