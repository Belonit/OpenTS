---
key: SpotlightLocationRadius
summary: Distance ahead of a structure, in leptons, that its spotlight beam is aimed at.
see_also: [SpotlightMovementRadius, SpotlightRadius, HasSpotlight]
when_omitted:
  kind: value
  value: "1000"
---

A spotlight starts this far in front of its structure, along the direction the structure faces, and begins its sweep from there. The built-in value is a little under four cells. Only a structure whose type sets [`HasSpotlight=yes`](/keys/hasspotlight/) has a beam.

```ini title="rules.ini"
[General]
SpotlightLocationRadius=1536  ; the beam starts six cells in front of the structure
```

Once a beam is farther than this from its structure, it gains one sweep stage for every further tenth of the gap between this key and [`SpotlightMovementRadius`](/keys/spotlightmovementradius/). Each stage enlarges the radius at which the beam detects intruders, as [`SpotlightRadius`](/keys/spotlightradius/) describes. A beam closer to its structure than this distance is at stage zero.

A beam [set to follow a target](/mapping/actions/taction-change-spotlight-behavior/) also casts a larger pool of light once it is beyond this distance. The pool grows one size step for each sweep stage, up to nine steps.

:::danger[Keep this key at least 10 leptons from `SpotlightMovementRadius`]
A sweep stage is a tenth of the gap between the two keys, rounded down to whole leptons. A gap under 10 leptons makes the stage zero leptons wide. The game then crashes with a division by zero as soon as a beam this far from its structure is drawn or checks for intruders, which a sweeping beam soon is.
:::
