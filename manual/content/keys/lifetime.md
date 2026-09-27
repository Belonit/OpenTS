---
key: Lifetime
summary: How many frames a particle system runs before it winds down.
see_also: [BehavesLike, SpawnCutoff, SparkSpawnFrames]
when_omitted:
  kind: value
  value: "-1"
---

A positive value ends the system that many frames after it is created, whatever its [behavior](/keys/behaveslike/#scope-particlesystemtype). From then on, the system is removed as soon as it holds no particles, which can be on that same frame. [Ending a system](/systems/particle-systems/#ending-a-system) covers the other ways a system ends.

What the system still does until it is removed depends on its behavior:

- A `Smoke` or `Fire` system stops emitting at once.
- A `Spark` system keeps throwing bursts until its [`SparkSpawnFrames`](/keys/sparkspawnframes/) run out. If every particle it holds expires between two bursts, it is removed early.
- A `Railgun` system is unaffected, because it ends by itself after laying its trace.
- A `Gas`, `WeakGas` or `Web` system emits nothing anyway. Its particles still turn into their successors until the chain ends.

```ini title="rules.ini"
[MyGasPuffSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=WeakGas
HoldsWhat=MyWeakGas ; a ParticleType registered in [Particles]
Lifetime=3
```

`Gas`, `WeakGas` and `Web` systems, and systems with no behavior, have no end condition of their own. Without a positive `Lifetime`, such a system ends only through an outside route, such as the loss of the object it is attached to. A system that belongs to no object, such as a `WeakGas` or `Web` system built by a warhead's blast, then stays on the map, empty once its particles are gone, unless a [Remove particle anim at...](/mapping/actions/taction-remove-particle-anim/) action names a waypoint in its cell.

:::caution[Zero and below never end the system]
The count drops by one on each of the system's turns, and the system ends only when the result is exactly `0`. A value of `0` drops to `-1` on the first turn, and a negative value drops further, so neither ever ends the system.
:::

:::danger[Leave `Lifetime` unset on `GasCloudSys`]
The scenario's shared gas cloud is never rebuilt. A positive `Lifetime` in its section removes the cloud once its last particle expires, and the next gas warhead or veinhole gas release after that crashes the game. [Keep the shared gas cloud alive](/systems/particle-systems/#systems-that-no-attachment-holds) has the details.
:::
