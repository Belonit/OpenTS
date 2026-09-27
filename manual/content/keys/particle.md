---
key: Particle
summary: The particle system released where the warhead detonates.
see_also: [Webby, WebRadius, BehavesLike, HoldsWhat]
when_omitted:
  kind: value
  value: none
---

An ordinary blast from this warhead creates a particle system of the named type at the point of impact and releases one particle from it. The particle is the one the type's [`HoldsWhat`](/keys/holdswhat/) names, so a type that holds nothing releases nothing. A blast of zero damage releases nothing, unless the warhead is [`Webby=yes`](/keys/webby/).

```ini title="rules.ini"
[MyGasWH] ; example WarheadType
Particle=MyGasSys ; example ParticleSystemType
```

A type with [`BehavesLike=Gas`](/keys/behaveslike/#scope-particlesystemtype) works differently. The blast creates no system and releases one particle into the scenario's [shared gas cloud](/systems/particle-systems/#systems-that-no-attachment-holds) instead. That particle comes from the gas cloud's `HoldsWhat`, so the named type's `HoldsWhat` is not used.

A [`Webby=yes`](/keys/webby/) warhead creates one system of the named type in every cell its web covers, and releases one particle from each. It does this for a `Gas` type too.

A projectile with an [`EMEffect=yes`](/keys/emeffect/) warhead raises a pulse instead of a blast and releases no particle.

A misspelled name is not refused. It creates a new particle system type with default settings, which holds no particle, so an ordinary blast releases nothing.

:::danger[Give every web warhead a particle system]
A [`Webby=yes`](/keys/webby/) warhead without `Particle` crashes the game the first time a shot with it detonates. An ordinary blast with no `Particle` releases nothing and does not crash.
:::
