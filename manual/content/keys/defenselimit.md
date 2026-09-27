---
key: DefenseLimit
summary: Parsed ceiling on defensive buildings that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", DefenseRatio, MaximumBaseDefenseValue]
when_omitted:
  kind: value
  value: "40"
---

This value does not limit how many defensive structures a computer house builds. The number of defenses a computer house plans follows from [the plan's cost, the side's defense settings and the difficulty](/systems/ai-base-building/#building-the-plan). [The defense planner](/systems/ai-base-building/#base-defenses) later fills each defense placeholder, or deletes it when it cannot.
