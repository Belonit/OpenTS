---
key: AALimit
summary: Parsed ceiling on anti-aircraft buildings that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", AARatio, BuildAA]
when_omitted:
  kind: value
  value: "10"
---

No count limits a computer base's anti-aircraft defenses. [The defense planner](/systems/ai-base-building/#base-defenses) fills each defense node with the category that makes up the smallest share of defense in the chosen quadrant of the base. A computer base therefore gets as many anti-aircraft defenses as those choices produce.
