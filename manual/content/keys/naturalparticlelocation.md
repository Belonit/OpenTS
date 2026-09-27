---
key: NaturalParticleLocation
summary: Where a structure's continuous particle plume sits, relative to the structure.
see_also: [NaturalParticleSystem, DamageSmokeOffset, Cloakable]
when_omitted:
  kind: value
  value: 0,0,0
---

```ini title="rules.ini"
[MYSMOKESTACK] ; a BuildingType registered in [BuildingTypes]
NaturalParticleSystem=MYSTEAMSYS ; a ParticleSystemType registered in [ParticleSystems]
NaturalParticleLocation=0,-40,180 ; the chimney mouth
```

The value is an X, Y and Z offset in leptons, 256 to a cell, from the structure's position. The structure's [`NaturalParticleSystem`](/keys/naturalparticlesystem/) starts at that point. Only a BuildingType uses it.

The offset also decides whether a cloaked structure gets its plume back. Cloaking removes the plume when the structure becomes fully transparent. When the structure is fully visible again, the plume is recreated only if this offset is not `0,0,0`. A structure whose plume belongs at its exact position can use an offset such as `0,0,1` to keep the plume through cloaking.

:::danger[Pair a non-zero offset with a particle system]
On a structure that can be cloaked, set `NaturalParticleSystem` whenever this offset is not `0,0,0`. Otherwise the game crashes when the structure finishes uncloaking, because it tries to recreate a plume that has no particle system type.
:::

:::note[Write all three numbers]
A value with fewer than three numbers, such as `0,-40`, is malformed and ignored. [INI syntax](/formats/ini-syntax/#malformed-values) has the rule.
:::
