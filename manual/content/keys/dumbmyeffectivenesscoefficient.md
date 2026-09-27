---
key: DumbMyEffectivenessCoefficient
summary: A house-wide replacement for MyEffectivenessCoefficient that no house ever uses.
see_also: ["system:target-selection"]
no_effect: true
when_omitted:
  kind: value
  value: "0"
---

Every house scores targets with the [`MyEffectivenessCoefficient`](/keys/myeffectivenesscoefficient/) of the choosing object's type.

This key is one of five house-wide coefficients that were meant to replace all five per-type coefficients for a house without an [`IsThreatRatingNode`](/keys/isthreatratingnode/) upgrade. Every house uses the per-type coefficients from the moment it is created, so neither the house-wide set nor `IsThreatRatingNode` changes anything. [Where the coefficients come from](/systems/target-selection/#where-the-coefficients-come-from) explains how the per-type value is chosen.
