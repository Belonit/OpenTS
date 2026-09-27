---
key: MaxEC
summary: The base lifetime of a particle, in frames.
see_also: ["MaxDC", "DeleteOnStateLimit", "NextParticle", "BehavesLike"]
when_omitted:
  kind: value
  value: "1"
---

A particle lives for `MaxEC` frames plus a random extra, and is removed when that time runs out. For most behaviors the extra is from 0 to one frame less than `MaxEC`, so a particle lives between `MaxEC` and nearly twice `MaxEC` frames. For a [`Railgun`](/keys/behaveslike/#scope-particletype) particle the extra is 0 to 9 frames. At fifteen frames a second, `MaxEC=900` gives most particles one to two minutes. Because the extra varies, a cloud created in one burst thins out gradually.

A particle can end before its lifetime runs out, for example through [`DeleteOnStateLimit`](/keys/deleteonstatelimit/) or by rising into a bridge deck. In gas, weak gas, web and smoke [particle systems](/systems/particle-systems/), a particle is replaced by its [`NextParticle`](/keys/nextparticle/) successors however it ends. Particles removed along with their system get none.

:::danger[Never set MaxEC to 0]
Except for `Railgun` particles, `MaxEC=0` crashes the game as soon as the first particle of the type is created.
:::

:::caution[Keep MaxEC between 1 and 32,768]
The lifetime counter holds 0 to 65,535 frames. A negative `MaxEC`, a total lifetime of exactly 0, or a total above 65,535 wraps around instead of being capped. A negative value usually gives a particle nearly 65,535 frames, over an hour of game time, instead of ending it at once. With `MaxEC=0`, about one `Railgun` particle in ten lives that long. A system that waits for its last particle to expire stays on the map for the same time.
:::
