---
key: CellAnim
summary: Animation created on a cell when this overlay is laid on it.
see_also: ["system:tiberium", Overrides, Tiberium]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[MYCRYSTAL]           ; example Tiberium overlay
Tiberium=yes
CellAnim=MYSPARKLE    ; example AnimType registered in rules.ini
```

Each time an overlay of this type is laid on a cell, an animation of the named type starts there at ground level. This includes overlays read from a map and Tiberium that spreads to a new cell. The overlay does not need [`Tiberium=yes`](/keys/tiberium/#scope-overlaytype); a decorative overlay gets its animation too.

Walls, the veinhole, overlays with `Land=Railroad`, the four low-bridge end pieces, and veins laid during play never create the animation. Neither does an overlay laid on a slope other than the four simple slopes.

Otherwise the animation starts even when the overlay itself is refused. For example, a placement refused because the cell is blocked, or because the overlay already in the cell sets [`Overrides=yes`](/keys/overrides/), still leaves the animation behind.

If the cell holds Tiberium when the animation starts, the animation is drawn in that Tiberium type's color scheme and at the cell's brightness, so an effect over a crop is tinted with it.

The animation also stands in for missing overlay artwork:

- A map's overlay data places an overlay only when the type has artwork or names an animation here. An overlay type with no artwork of its own can therefore still be placed from a map.
- When the overlay has no artwork, its radar and map-preview color comes from the animation's artwork. On the in-game radar, a Tiberium overlay that names an animation always takes its color from the animation.

The overlay does not remove the animation. An animation with [`IsAnimatedTiberium=yes`](/keys/isanimatedtiberium/) removes itself once its cell no longer holds an overlay that names it. Any other animation plays its loops and ends, whether or not the overlay is still there.
