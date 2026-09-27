---
key: AlphaImage
scope: animtype
label: Animation light shape
when_omitted:
  kind: value
  value: ""
  note: No light shape is loaded and the animation contributes nothing to the lighting pass.
---

An animation's light shape is named and drawn the same way as [any other object type's](/keys/alphaimage/#scope-aircrafttype). The light is placed where the animation starts, and it stays there if the animation moves.

:::caution[The light outlasts the animation]
Give `AlphaImage=` only to an animation whose spot should stay lit for the rest of the scenario. Ending the animation does not remove its light, which stays where the animation started until the scenario ends.
:::
