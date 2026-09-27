---
key: HoverBob
summary: Period in minutes of the vertical bob a hovering unit performs.
see_also: [HoverHeight, HoverDampen]
when_omitted:
  kind: value
  value: "30"
---

This value is how long one rise and fall of a hover unit's bob takes, in game minutes of 900 frames. The stock `.04` is a cycle of 36 frames. The unit bobs about the height its cushion holds it at, which [`HoverHeight`](/keys/hoverheight/) sets.

Only the period can be changed. In each frame of the rising half of the cycle the bob lifts the unit by up to two leptons, and in each frame of the falling half it lowers the unit by as much. These steps add up, so a longer period gives a deeper bob. The cushion pushes back, so `HoverHeight`, [`HoverDampen`](/keys/hoverdampen/) and [`Gravity`](/keys/gravity/) also change the depth. With the stock rules a unit swings through about 20 leptons, between about 80 and 104 leptons above the ground. A cell is 256 leptons across.

Each hover unit bobs with either exactly this period or 1.1 times it, and starts the cycle at its own point, so a group of hover units does not rise and fall in unison. The levitation locomotor, which the stock Tiberium Floater uses, bobs with the same period.

:::danger[Keep HoverBob at 0.0012 or more]
The engine rounds the period down to whole frames and divides by it. A value from `0` up to `1/900` of a minute rounds the period to zero frames for some or all hover and levitating units, and the game crashes once one of those units is on the map.
:::
