---
key: AltPalette
summary: Draws the animation through the first declared color scheme instead of the shared animation palette.
see_also: ["ShouldUseCellDrawer", "UseNormalLight", "Tiled"]
when_omitted:
  kind: value
  value: "no"
---

The animation is drawn through the first color scheme declared in `[Colors]` instead of the palette that ordinary animations share. Only the colors change. The animation is lit the same way either way.

The flag applies only to an animation that nothing else gives a palette. These animations ignore it:

- an animation with [`IsVeins=yes`](/keys/isveins/#scope-animtype), which uses the player's color scheme
- a structure's animation, which uses its owner's house colors unless the animation sets [`ShouldUseCellDrawer=no`](/keys/shouldusecelldrawer/)
- animated Tiberium and Tiberium debris, which use the Tiberium's color
- burning infantry, which use the player's color scheme
- a [`Tiled=yes`](/keys/tiled/) animation, which draws every copy through the shared palette
- the picture of a structure's animation remembered under the fog of war
