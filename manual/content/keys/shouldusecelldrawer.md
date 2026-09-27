---
key: ShouldUseCellDrawer
summary: Draws a structure's animation in the colors and at the brightness of the structure it belongs to.
see_also: ["ActiveAnim", "AltPalette", "UseNormalLight"]
when_omitted:
  kind: value
  value: "yes"
---

Only an animation that a structure runs in one of its animation slots uses this flag. With `yes`, the animation is drawn in the owning house's color scheme and at the structure's brightness. It keeps following the structure while it plays, so it changes along with the structure's lighting, its flashing, and its owner.

A [`Tiled=yes`](/keys/tiled/) animation is drawn in the shared animation palette with either value; only its brightness follows this flag.

With `no`, the animation is drawn in the shared animation palette, or in the first declared color scheme if it also sets [`AltPalette=yes`](/keys/altpalette/). It takes its brightness from the cell it stands on. Use `no` for a fireball or a light glow that should look the same for every house. Keep `yes` for smoke or machinery that should take the owner's colors.

With either value, [`UseNormalLight=yes`](/keys/usenormallight/) draws the animation at normal brightness instead.

Under the fog of war, the structure's animation is drawn as the player last saw it. That copy follows the same color rule, but it ignores `AltPalette`, and with `yes` it takes the cell's brightness instead of the structure's.

The flag has no effect on any other animation. An animation that belongs to the terrain tile it stands on is always drawn in the same tinted terrain palette as the ground beneath it.

```ini title="art.ini"
[MYREFN_B] ; a refinery's fireball, the same color for every house
Image=MYREFN_B
LoopCount=-1
Rate=350
Surface=yes
ShouldUseCellDrawer=false
UseNormalLight=yes
```
