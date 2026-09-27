---
key: BlendedFog
summary: Parsed choice of fog pattern that makes no visible difference.
no_effect: true
see_also: ["system:map-visibility"]
when_omitted:
  kind: value
  value: "yes"
---

`BlendedFog=no` draws nothing differently. That setting selects a checkerboard fog pattern, but only for a terrain tile drawn as fog, and the game never draws terrain tiles that way.
