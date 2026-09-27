---
key: TreeFire
summary: The two flames that burn on a terrain object once it catches.
see_also: [Sparky, Wood, Immune, TreeFlammability, OnFire]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[AudioVisual]
TreeFire=MYTREEFIRE1,MYTREEFIRE2 ; AnimTypes registered in [Animations]
```

A terrain object that catches fire shows one of the first two entries, picked at random with equal odds. The order carries no meaning: naming a small flame first and a large one second does not make small fires more common. Entries past the second are never used.

A terrain object can catch fire only when all of the following hold, tested in this order:

1. It is not crumbling, the animation a destroyed terrain object plays before it disappears.
2. It is not already burning.
3. Its type has [`Armor=wood`](/keys/armor/#scope-aircrafttype), which a TerrainType has unless its section sets another armor.
4. Its type does not set [`SpawnsTiberium=yes`](/keys/spawnstiberium/), so a blossom tree never burns.

Such an object catches fire in two ways:

- A [`Sparky=yes`](/keys/sparky/) warhead damages it. Only a [`Wood=yes`](/keys/wood/) warhead damages a terrain object, and only when the terrain type sets [`Immune=no`](/keys/immune/).
- A burning neighbor spreads the fire, as [`TreeFlammability`](/keys/treeflammability/) describes.

The flame sits 80 leptons above the center of the object.

How long the flame burns depends on its [`LoopCount`](/keys/loopcount/). With `LoopCount=1` it burns until the terrain object is destroyed. With most other values it plays a fixed number of passes and then ends or moves on to its [`Next`](/keys/next/) animation.

:::danger[Give TreeFire at least two entries]
With one entry, half of all fires use a second entry that was never set, and the game can crash in either build. With an empty list or `TreeFire=none`, the first fire stops a Debug build at an assertion and crashes a Release build.
:::
