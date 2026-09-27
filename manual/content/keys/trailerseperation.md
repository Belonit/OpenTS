---
key: TrailerSeperation
summary: The number of frames between one trail animation and the next.
see_also: ["TrailerAnim"]
when_omitted:
  kind: value
  value: "0"
---

Trail animations are dropped on game frames whose number is a multiple of this value: `1` drops one every frame and `4` one every fourth frame. The count uses the game's frame number, not the animation's, so two animations of the same type created a frame apart still drop their trails on the same frames.

The value is used only when the animation names a [`TrailerAnim`](/keys/traileranim/#scope-animtype). A negative value acts as its magnitude.

:::danger[Set a separation with every trail]
An animation that names a trail animation and leaves this at `0` crashes the game as soon as it is created. The shipped `art.ini` sets a separation for every animation that names a trail.
:::
