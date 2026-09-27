---
key: IsThreatRatingNode
summary: Marks a building upgrade meant to put its house on the per-type threat coefficients, which every house already uses.
see_also: ["system:target-selection"]
no_effect: true
when_omitted:
  kind: value
  value: "no"
---

Every house uses per-type threat coefficients from the moment it is created, and nothing turns them off. These are the coefficients set on the type of the object choosing a target. The flag was meant to move its house onto them from the house-wide coefficients, such as [`DumbTargetEffectivenessCoefficient`](/keys/dumbtargeteffectivenesscoefficient/).

Fitting a flagged [`PowersUpBuilding`](/keys/powersupbuilding/) upgrade into its host, or removing a host that has one fitted, only turns the per-type coefficients on again.
