---
key: Webby
summary: The warhead entangles the infantry it catches instead of damaging them.
see_also: [WebDuration, WebDurationVariation, WebRadius, Particle, IsWebImmune, "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

A projectile with a `Webby=yes` warhead spreads a web when it detonates, instead of raising a blast. An [`EMEffect=yes`](/keys/emeffect/) warhead is the exception: it raises a pulse, and this flag has no effect on the detonation.

```ini title="rules.ini"
[MyWebWH] ; example WarheadType
Webby=yes
Particle=MyWebSys ; example ParticleSystemType
WebDuration=600
WebRadius=2
```

The web covers every cell within [`WebRadius`](/keys/webradius/) cells of the cell where the projectile detonates. Each covered cell releases one particle from the warhead's [`Particle`](/keys/particle/) system, and each object standing in it takes a hit of zero damage. The web catches objects of every owner, including the firer's own.

An infantryman without [`IsWebImmune=yes`](/keys/iswebimmune/) that the web catches is pinned struggling for the web's duration and takes no damage. [`IsWebImmune`](/keys/iswebimmune/) covers what an immune infantryman does instead. Anything else in the covered cells takes no damage.

The web deals no blast damage, so [`Verses`](/keys/verses/), [`Spread`](/keys/spread/#scope-warheadtype) and the other [blast effects](/systems/warheads/#what-one-blast-does-besides-damage) play no part. The web credits no attacker, so nothing it catches fires back at the firer. The impact animation and the flash still play as they would for any other shot.

A web warhead can also be used by an ordinary blast, such as the death explosion of an object whose first weapon carries it. That blast entangles the infantry it reaches that are not `IsWebImmune=yes`, as a web would, and damages everything else as usual. It goes ahead even when its damage is zero, where a blast from any other warhead would do nothing.

The flag also affects targeting. [Which weapon the score assumes](/systems/target-selection/#which-weapon-the-score-assumes) covers how an object with a web weapon in one slot picks between its two weapons, and why a web primary needs a secondary weapon. [`WebDuration`](/keys/webduration/) covers when an entangled infantryman is worth webbing again.

:::caution[Set the other web keys with the flag]
[`WebDuration`](/keys/webduration/), [`WebDurationVariation`](/keys/webdurationvariation/) and [`WebRadius`](/keys/webradius/) are read only when the warhead is already `Webby=yes` as its section is read, whether this file or an earlier one set it. Set them in the same file as `Webby=yes` or in a later one. Values set in an earlier file, before the flag was on, are ignored.
:::

:::danger[A web warhead with no particle system crashes]
A `Webby=yes` warhead that does not name a [`Particle`](/keys/particle/) system crashes the game the first time a shot with it detonates. A negative [`WebRadius`](/keys/webradius/) covers no cells, so no system is built and nothing crashes.
:::
