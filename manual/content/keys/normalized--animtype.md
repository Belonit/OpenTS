---
key: Normalized
scope: animtype
label: Animation rate
see_also: ["Rate", "RandomRate"]
when_omitted:
  kind: value
  value: "no"
---

`Normalized=yes` rescales the animation's frame delay against the [`GameSpeed`](/keys/gamespeed/) setting, so the animation plays at roughly the same real-time rate at every game speed. The delay is rescaled when the animation is created, and again when another animation switches to this type through [`Next`](/keys/next/).

A [`RandomRate`](/keys/randomrate/) pick is made first, and the rescaling applies to whichever delay it produces.
