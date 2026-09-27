---
key: BehavesLike
scope: particletype
label: Particle behavior
see_also: ["MaxEC", "NextParticle", "Velocity", "WindEffect", "Warhead"]
when_omitted:
  kind: value
  value: none
  note: A later file that contains the section without this key resets the type to no behavior, even when an earlier file named one.
---

Seven names are recognized, in any mix of upper and lower case. The name decides how a particle of the type moves, how it is drawn and what it does to objects in its cell.

| Value | What a particle of the type does |
| --- | --- |
| `Gas` | Sinks toward the ground and settles just above it, wandering sideways and sliding off sloped ground. Every [`MaxDC`](/keys/maxdc/) frames it applies its [`Damage`](/keys/damage/#scope-particletype) through its [warhead](/keys/warhead/#scope-particletype) to every object in its cell. An object it kills leaves a small visceroid when [`TiberiumDeathToVisceroid`](/keys/tiberiumdeathtovisceroid/) allows it. |
| `WeakGas` | Moves and animates as `Gas` does, but never applies damage. |
| `Smoke` | Rises at about its [`Velocity`](/keys/velocity/), and slows by [`Deacc`](/keys/deacc/) each frame while it rises faster than 3 leptons a frame. It wanders a little to either side, and dies when it rises close under a bridge deck. |
| `Fire` | Travels along the line it was fired on, slowing by [`Deacc`](/keys/deacc/) each frame. It fades at [`Translucent25State`](/keys/translucent25state/) and [`Translucent50State`](/keys/translucent50state/), and dies when it stops or when the ground ahead of it rises. Every [`MaxDC`](/keys/maxdc/) frames it applies its [`Damage`](/keys/damage/#scope-particletype) through its [warhead](/keys/warhead/#scope-particletype) to the objects in its cell. It never damages the object its particle system is attached to, and stops damaging once its state passes [`FinalDamageState`](/keys/finaldamagestate/). |
| `Spark` | Falls under gravity and dies where it strikes the ground, a bridge deck, a wall or a structure. It is drawn as a single pixel colored from its [`ColorList`](/keys/colorlist/), not from artwork. |
| `Railgun` | Travels along its firing direction at a speed that varies slightly from frame to frame. It is drawn as a single pixel colored from its [`ColorList`](/keys/colorlist/), not from artwork. |
| `Web` | Stays where it was created and applies its [warhead](/keys/warhead/#scope-particletype), at zero damage, to every object in its cell every frame. |

At the lowest [detail setting](/keys/detaillevel/#scope-client-settings), `Smoke` and `Spark` particles are not drawn, but they still move and expire.

A name outside the seven, or no name, leaves the type with no behavior. Its particles stay where they were created, show frame 0 of their artwork, and are removed when their [`MaxEC`](/keys/maxec/) lifetime runs out.

The particle's behavior is separate from its holding system's. [The system's `BehavesLike`](/keys/behaveslike/#scope-particlesystemtype) decides how particles are emitted and aimed and whether [`NextParticle`](/keys/nextparticle/) successors are created. This key decides what each particle does once it exists.
