---
key: SpecialZOverlayZAdjust
summary: Parsed depth bias that the engine never uses.
no_effect: true
see_also: ["SpecialZOverlay"]
when_omitted:
  kind: value
  value: "0"
---

The value is stored with the structure's type, but nothing uses it. Its name pairs it with [`SpecialZOverlay`](/keys/specialzoverlay/), a shape that is also never drawn. [`NormalZAdjust`](/keys/normalzadjust/) biases the depth of the structure's main shape.
