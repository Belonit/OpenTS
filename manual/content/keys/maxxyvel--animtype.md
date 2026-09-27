---
key: MaxXYVel
scope: animtype
label: Animation lateral speed
see_also: ["MinZVel", "Bouncer", "IsMeteor"]
when_omitted:
  kind: value
  value: "15"
---

The value is in leptons per game frame, and a cell is 256 leptons across. When an animation is thrown, each of its two horizontal speeds is drawn separately from a range around zero. For a whole-number setting, the range runs from minus the setting up to one less than the setting: the default `15` gives `-15` to `14` on each axis.

A negative setting throws the animation only one way: `-15` gives `15` to `44` on each axis, toward the bottom of the screen.

A meteor draws its horizontal speeds from the same range, then reverses them if they would point up the screen, as [`IsMeteor`](/keys/ismeteor/#scope-animtype) describes.

:::danger[A setting near zero crashes the game]
A value above `-0.5` and below `0.5`, including `0`, causes a division by zero. The game crashes when a [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype) animation of the type is created. Animations with neither flag do not use the setting.
:::
