---
key: SplashList
summary: The animations played where something comes down in water.
see_also: ["Wake", "Conventional", "IsMeteor"]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[CombatDamage]
SplashList=MYSPLASH1,MYSPLASH2,MYSPLASH3 ; AnimTypes registered in [Animations]
```

These animations play where something hits or falls into water. An explosion over water picks an entry by its damage. Every other kind of splash always uses the first entry or the last one.

An explosion over open water picks by damage in steps of 35 points: the first entry for `1` to `34` damage, the second for `35` to `69`, and so on. The last entry covers all damage past the end of the list. This needs a [`Conventional=yes`](/keys/conventional/) warhead and a point that is not on a bridge deck. The splash replaces the warhead's usual explosion animation.

The other splashes use a fixed entry. Some also lay a [`Wake`](/keys/wake/) animation beside the splash:

| Cause | Entry | Also lays `Wake` |
| --- | --- | --- |
| An ordinary bouncing animation that lands in water | First | Yes |
| A piece of voxel debris that lands in water | First | Yes |
| Infantry that falls into water, for example when a bridge collapses under it | First | Yes |
| A burning infantryman that falls into water | First | No |
| A vehicle that falls into water | Last | Yes |
| An ion cannon blast that lands on water | Last | No |
| An `IsMeteor=yes` [animation](/keys/ismeteor/#scope-animtype) or [voxel animation](/keys/ismeteor/#scope-voxelanimtype) that lands in water | Last | No |

:::danger[Keep SplashList non-empty]
Every case except the explosion reads an entry directly, so an empty list crashes the game the first time one of them happens. An explosion over water with an empty list gets no animation, and some explosions crash on that, as [`Conventional`](/keys/conventional/) describes. The list is empty when no rules file sets the key, and `SplashList=none` also empties it. Leaving the key out of a later rules file is harmless, because the list keeps what an earlier file set.
:::
