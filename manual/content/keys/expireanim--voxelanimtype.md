---
key: ExpireAnim
scope: voxelanimtype
label: Voxel debris impact effect
see_also: ["Damage", "Warhead", "ExpireSound", "Duration"]
when_omitted:
  kind: value
  value: none
---

An animation of the named type plays where the piece ends its life, unless it ends low over water. Low over water means in a water cell and below the height of a bridge deck, 416 leptons above the ground. A piece on land, on a bridge deck, or higher up plays this animation.

A piece that ends low over water plays a splash instead and never uses this setting. Ordinary debris plays [`Wake`](/keys/wake/) and the first animation in [`SplashList`](/keys/splashlist/). A meteor plays only the last animation in `SplashList`.

:::caution[Blast damage needs this animation]
The end-of-life blast happens only when this setting names an animation. That covers both the [`Damage`](/keys/damage/#scope-voxelanimtype) dealt through the [`Warhead`](/keys/warhead/#scope-voxelanimtype) and the light flash of a bright warhead. A piece with no animation named here deals no blast damage, whatever its damage and warhead say. Bounce damage does not depend on this setting.
:::
