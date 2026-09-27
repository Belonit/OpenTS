---
key: EnemyHouseThreatBonus
summary: Added to a candidate's threat score when the candidate belongs to the house's declared enemy.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "0"
---

A positive value makes objects prefer targets that belong to their house's [declared enemy](/systems/base-attacked/#anger-and-the-declared-enemy), and a negative value makes them avoid those targets. The value is added once to the [threat score](/systems/target-selection/#the-threat-score) of each such candidate. A house with no declared enemy adds it to no candidate.

Unlike the five threat coefficients, the bonus is the same whichever type of object is choosing. It is on the same scale as the coefficient terms of the threat score, such as a [`Verses`](/keys/verses/) fraction or a health fraction multiplied by its coefficient. The retail `rules.ini` sets it to `400`.
