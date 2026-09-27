---
key: BaseBias
summary: Parsed multiplier that the engine never uses.
no_effect: true
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "1"
---

No part of target selection reads this value. No term in the [threat score](/systems/target-selection/#the-threat-score) measures a candidate against a base.
