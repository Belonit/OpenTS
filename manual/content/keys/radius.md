---
key: Radius
summary: How far a smoke system throws the two successors of an expiring particle.
see_also: ["NextParticle", "NextParticleOffset"]
when_omitted:
  kind: value
  value: "0"
---

The two [`NextParticle`](/keys/nextparticle/) successors land on opposite sides of the point where the particle expired, at the same height, which is what makes a plume widen as it rises. Along X and along Y, one successor is displaced by a random distance between an eighth and a quarter of this figure, in leptons, and the other by the same distance the opposite way.

Only a smoke system reads the figure. Gas, weak gas and web systems place their single successor with [`NextParticleOffset`](/keys/nextparticleoffset/) instead, and fire, spark and railgun systems create no successors. The figure has no effect on a particle's size, drawing, collision or damage.

:::danger[Set at least 8 on a smoke type that names a successor]
The eighth of this figure is rounded down and then used as a divisor. From `0` to `7` it is zero, and the game stops the first time a particle of the type expires in a smoke system while it names a `NextParticle`. A type that omits the key is in that range too. Negative values do not stop the game.
:::
