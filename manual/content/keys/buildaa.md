---
key: BuildAA
summary: Parsed anti-aircraft defense list for a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", AALimit, IsBaseDefense]
when_omitted:
  kind: value
  value: ""
---

Computer houses do not take their anti-aircraft defenses from a list. Any structure type with an anti-air rating above zero is a candidate. When the rules load, each [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-buildingtype) type whose primary weapon can hit aircraft gets a rating from that weapon's damage, firing rate and warhead. [The defense planner](/systems/ai-base-building/#base-defenses) then chooses among the candidates.
