---
key: AttachedParticleSystem
summary: The particle system a flame, spark or railgun weapon spawns as it fires.
see_also: ["UseFireParticles", "UseSparkParticles", "IsRailgun"]
when_omitted:
  kind: value
  value: none
---

Only three weapon flags use this system: [`UseFireParticles=yes`](/keys/usefireparticles/), [`UseSparkParticles=yes`](/keys/usesparkparticles/) and [`IsRailgun=yes`](/keys/israilgun/). Each flag spawns one system of the named type when the weapon fires. A weapon that sets two of the flags spawns two systems of the same type.

```ini title="rules.ini"
[MyRailgun] ; example WeaponType
IsRailgun=yes
AttachedParticleSystem=LargeRailgunSys ; a ParticleSystemType registered in [ParticleSystems]
AmbientDamage=200
Damage=0
```

While a spawned system is still running, the object cannot fire this weapon again, and cannot fire its other weapon either. The system's lifetime therefore paces the weapon together with its [`ROF`](/keys/rof/#scope-weapontype): the next shot waits until the reload has passed and the system has ended. [Firing geometry](/systems/firing-geometry/#effects-that-hold-the-weapon-shut) covers how each weapon slot is held.

A spark weapon shares its [particle hold](/systems/particle-systems/#the-five-holds-an-object-keeps) with the sparks a damaged object gives off. While those damage sparks are running, an object with a spark weapon cannot fire either of its weapons.

A name the game does not already know is registered as a new particle system type. A misspelled name therefore spawns a system built from default settings. `none` without angle brackets is also taken as a name. `<none>` and an empty value keep whatever an earlier rules file set, so no value can clear a system that an earlier file named.

:::caution[Keep the name to nineteen characters]
A longer name is cut off after its nineteenth character. The shortened name is registered as a new particle system type, and the weapon spawns that system with default settings.
:::

:::danger[Name a system for every flame, spark or railgun weapon]
If a weapon sets `UseFireParticles=yes`, `UseSparkParticles=yes` or `IsRailgun=yes` and no `AttachedParticleSystem=` is set, the game crashes the first time the weapon fires.
:::
