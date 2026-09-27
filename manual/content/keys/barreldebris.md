---
key: BarrelDebris
summary: The voxel wreckage thrown clear when an exploding overlay is set off.
see_also: [AmmoCrateDamage, BarrelExplode, BarrelParticle, Explodes]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[AudioVisual]
BarrelDebris=MYTANKPIECE,MYSHRAPNEL ; VoxelAnimTypes registered in [VoxelAnims]
```

An exploding overlay throws at most one piece of this debris. The engine tries the entries in list order, giving each a 15% chance, and throws the first one that succeeds. If every entry fails, no debris is thrown. With the stock pair `GASTANK` and `PIECE`, that happens in a little over seven explosions out of ten.

List order therefore decides how often each piece appears. The first entry is thrown in 15 explosions out of 100. The second is tried only in the 85 where the first failed, so it appears in about 13, and each later entry in fewer still.

An empty list throws no debris. [`Explodes=yes`](/keys/explodes/#scope-overlaytype) covers the rest of the explosion.
