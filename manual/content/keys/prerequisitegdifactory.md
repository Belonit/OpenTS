---
key: PrerequisiteGDIFactory
summary: The BuildingTypes that satisfy a GDIFACTORY prerequisite.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: ""
---

A player meets a `GDIFACTORY` entry in a [`Prerequisite=`](/keys/prerequisite/) list by owning a structure of any type on this list. One is enough, and the order of the list does not matter.

A computer house skips prerequisites when it produces, but its [base planner](/systems/ai-base-building/#building-the-plan) checks this list. There, `GDIFACTORY` is met once any listed type is in the plan.

Separate the BuildingType IDs with commas and no spaces. IDs are matched without regard to case, and an ID that matches no BuildingType is dropped. An empty value leaves the list already loaded in place.

List only BuildingType IDs. A group name such as `POWER` or `FACTORY` stays in the list but never satisfies it. When a computer house plans a structure that needs `GDIFACTORY`, such an entry can be read as an invalid BuildingType, which stops a Debug build of the game.

If the list holds no valid ID, `GDIFACTORY` can never be met. A player cannot build any type that names it, and the base planner leaves such types out of the plan.
