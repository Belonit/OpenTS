---
key: BarrelParticle
summary: The particle system released by an exploding overlay, on one blast in four.
see_also: [AmmoCrateDamage, BarrelExplode, BarrelDebris, Explodes]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
BarrelParticle=MyGraySmokeSys ; a ParticleSystemType registered in [ParticleSystems]
```

An exploding overlay starts a particle system of this type on a 25% chance. The system starts where the triggering explosion landed, which need not be the center of the overlay's cell. If the system type holds a particle type, one particle of it is released at once, on the same frame as the blast. [`Explodes=yes`](/keys/explodes/#scope-overlaytype) covers the rest of the explosion.

:::danger[Set a particle system before any overlay explodes]
If `BarrelParticle` names no particle system, the game crashes on the first explosion that wins the 25% chance. Earlier explosions that lose the chance do not crash, so the fault can appear only after several.
:::
