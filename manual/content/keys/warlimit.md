---
key: WarLimit
summary: Parsed ceiling on war factories that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", WarRatio, BuildWeapons]
when_omitted:
  kind: value
  value: "2"
---

No part of the computer's base planning counts war factories against a limit. A generated plan queues one of each war factory type the house may build, as [Building the plan](/systems/ai-base-building/#building-the-plan) describes, and a plan the map supplies builds what it lists.
