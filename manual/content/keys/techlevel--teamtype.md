---
key: TechLevel
scope: teamtype
label: Team tech level
no_effect: true
when_omitted:
  kind: value
  value: "0"
---

An AI trigger's tech level requirement comes from the [`TechLevel`](/keys/techlevel/#scope-aircrafttype) of the object types in its TeamTypes' TaskForces, not from this key. [Which triggers are eligible](/systems/ai-team-production/#which-triggers-are-eligible) describes that requirement.
