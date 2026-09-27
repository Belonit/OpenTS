---
key: YDrawOffset
summary: Shifts the animation's artwork down the screen, in pixels, as it is drawn.
see_also: ["YSortAdjust", "Tiled", "ActiveAnimY"]
when_omitted:
  kind: value
  value: "0"
---

Moves the animation's artwork down the screen by this many pixels; a negative value moves it up. Use it to line up artwork that is not centered on the animation's position without editing the shape file.

The offset applies to every live draw of the animation: the ordinary and [`Flat=yes`](/keys/flat/#scope-animtype) draws, each copy of a [`Tiled=yes`](/keys/tiled/) animation, the shadow under a thrown animation, and the shadow of an [`IsFlamingGuy=yes`](/keys/isflamingguy/) animation.

The copy of a structure's animation that the fog of war draws in its place ignores the offset. An animation with a large offset jumps by that many pixels when the fog closes over its structure, and jumps back when the fog lifts.

Moving the artwork does not change what covers it. The animation keeps the depth of its original position, so an object that covered it without the offset still covers it with one. To change what the animation is drawn in front of without moving it, use [`YSortAdjust`](/keys/ysortadjust/).
