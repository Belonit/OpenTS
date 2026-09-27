---
key: DefaultFirestormExplosionSystem
summary: The ParticleSystemType spawned in place of the usual explosion when the firestorm warhead destroys a vehicle or aircraft.
see_also: ["system:laser-fences"]
when_omitted:
  kind: value
  value: none
---

A vehicle or aircraft destroyed by the warhead that [`FirestormWarhead`](/keys/firestormwarhead/) names bursts into seven to nine of these particle systems at its center. When the named type is a [`Spark`](/keys/behaveslike/#scope-particlesystemtype) system, each burst flies in a random direction in place of the type's [`SpawnDirection`](/keys/spawndirection/).

The burst replaces the explosion the victim would otherwise produce: an aircraft's [`Explosion`](/keys/explosion/) animation, or a vehicle's ordinary explosion or water splash.

A vehicle whose art sets [`DeathFrames`](/keys/deathframes/) above `0` never bursts. It plays that death sequence and then explodes the ordinary way, even when the firestorm destroyed it.

:::danger[Set this key whenever FirestormWarhead is set]
If `FirestormWarhead` names a warhead and this key is unset, the game crashes the first time that warhead destroys an aircraft, or a vehicle without `DeathFrames`.
:::
