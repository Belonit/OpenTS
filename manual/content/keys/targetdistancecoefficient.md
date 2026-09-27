---
key: TargetDistanceCoefficient
summary: Weights a candidate target by how far beyond weapon range it lies, and not at all inside it.
see_also: ["system:target-selection"]
when_omitted:
  kind: computed
  note: Takes the value of TargetDistanceCoefficientDefault in [General], which is itself 0 when that key is absent too.
---

The coefficient multiplies how far a candidate target lies beyond the choosing object's weapon range. On most scans, a candidate within range adds nothing to this term, so the coefficient does not separate candidates the object can already shoot. A negative value penalizes distant candidates. A positive value rewards them and draws the object toward the farthest candidate it can find.

The ground part of a whole-map scan works differently. A Hunt, Rescue or team attack mission makes such a scan, and it counts distance to ground candidates in leptons, 256 to the cell, while range stays in cells. The distance is measured from the scan's center, which on a Rescue mission need not be the chooser's position. Nearly every ground candidate on such a scan counts as beyond range, including those the object can shoot, and the same coefficient weights it about 256 times as strongly as on other scans.

The coefficient comes from the type of the object doing the choosing. The range is that of the weapon it would use against the candidate, or its [`GuardRange`](/keys/guardrange/) when it has no weapon for that candidate.

:::caution[An explicit `0` does not last]
A `0` written on a type is replaced by [`TargetDistanceCoefficientDefault`](/keys/targetdistancecoefficientdefault/) at the next rules layer, such as a map, whose copy of the type's section omits this key. To keep a type at zero while that default is not zero, write `0` in every layer that contains the section.
:::
