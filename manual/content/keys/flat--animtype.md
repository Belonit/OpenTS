---
key: Flat
scope: animtype
label: Animation ground plane
see_also: ["Tiled", "Surface"]
when_omitted:
  kind: value
  value: "no"
---

With `Flat=yes`, the animation is drawn as if painted on the terrain, and anything standing in its cell covers it. Without the flag, the animation is depth-tested as an upright image, the same way standing objects are. The fogged copy of a structure's animation follows the same setting.

On the live map, [`Tiled=yes`](/keys/tiled/) takes precedence: a tiled animation is always drawn upright.
