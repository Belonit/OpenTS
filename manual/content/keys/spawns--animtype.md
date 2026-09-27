---
key: Spawns
scope: animtype
label: Animation impact spawn
see_also: ["SpawnCount", "Bouncer", "IsMeteor"]
when_omitted:
  kind: value
  value: none
---

`Spawns` names the animation type that a thrown animation breaks into when it lands. A thrown animation is one with [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype); the setting does nothing on any other animation.

All the new animations appear at once, at the point of impact. [`SpawnCount`](/keys/spawncount/#scope-animtype) sets how many, and with it at `0` none appear. A thrown animation that lands in water creates none, unless it lands on a bridge.

The named type does not need an entry in `[Animations]`. An unlisted name still creates an animation type of that name, which reads the `art.ini` section of that name if one exists. If it has no section and no artwork, the spawned animations show nothing and disappear almost at once.

:::caution[A type that spawns itself can multiply without limit]
If an animation names its own type here, or a chain of thrown types leads back to it, each impact creates new copies of it. With `SpawnCount=1`, each impact replaces the animation with one copy on average. With `2` or more, the number of copies grows with every impact.
:::
