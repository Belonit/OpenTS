---
key: BarracksLimit
summary: Parsed ceiling on barracks that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", BarracksRatio, BuildBarracks]
when_omitted:
  kind: value
  value: "2"
---

No step of computer base planning counts barracks against a limit. A barracks type enters [the base plan](/systems/ai-base-building/#building-the-plan) once its prerequisites are met, like any other candidate structure, and the house builds that plan.
