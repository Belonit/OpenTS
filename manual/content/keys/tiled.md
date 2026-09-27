---
key: Tiled
summary: Repeats the animation's current frame upward until the copies leave the top of the view.
see_also: ["Flat", "AltPalette", "Surface", "YDrawOffset"]
when_omitted:
  kind: value
  value: "no"
---

The animation's current frame is drawn again and again up the screen, so a column such as the shipped ion cannon beam (`IONBEAM`) reaches the top of the view at any resolution. The first copy sits half a frame-height above the animation's position, and each further copy one frame-height above the last. Copies stop once one has been drawn above the top edge of the view. Every copy shows the same frame, so the whole column animates together.

The step between copies is the height the shape file records for its first frame, whichever frame is showing. It is not the shape's overall height. A shape whose frames differ in height tiles every frame by the first frame's height.

A tiled animation is drawn differently from an ordinary one:

- Every copy uses the shared animation palette. [`AltPalette=yes`](/keys/altpalette/), the house colors that [`ShouldUseCellDrawer`](/keys/shouldusecelldrawer/) gives a structure's animation, and the tinted terrain palette of an animation that a terrain tile starts are ignored.
- [`Flat=yes`](/keys/flat/#scope-animtype) has no effect.

The animation's brightness and fade still apply, and every copy is drawn at the same fade level.

:::danger[Give the first frame a height]
If the shape records a height of zero for its first frame, or has no frames at all, the copies never move up the screen. The game then hangs as soon as the animation is drawn on screen.
:::
