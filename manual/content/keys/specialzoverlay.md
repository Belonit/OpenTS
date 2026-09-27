---
key: SpecialZOverlay
summary: Parsed shape name that the engine never draws.
no_effect: true
see_also: ["SpecialZOverlayZAdjust"]
when_omitted:
  kind: value
  value: ""
---

The value names a shape file without its extension. The engine loads that shape with the structure's artwork and never draws it, so the value has no effect whether or not the file exists.

Structures drawn with a depth shape all use one shared shape, `BUILDNGZ.SHP`, which decides where the structure covers other objects and where they cover it. No key replaces it. [`ZShapePointMove`](/keys/zshapepointmove/) covers where that shape is placed and which structures are drawn without it.
