---
key: PrerequisiteBarracks
summary: The BuildingTypes that satisfy a BARRACKS prerequisite.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: ""
---

A player meets a `BARRACKS` entry in a [`Prerequisite=`](/keys/prerequisite/) list by owning a structure of any type on this list. One is enough, and the order of the list does not matter.

A computer house skips prerequisites when it produces, and its [base planner](/systems/ai-base-building/#building-the-plan) does not read this list. The planner treats `BARRACKS` as met once the first [`BuildBarracks`](/keys/buildbarracks/) entry the house's country may own is in the plan.

Separate the BuildingType IDs with commas and no spaces. IDs are matched without regard to case, and an ID that matches no BuildingType is dropped. An empty value leaves the list already loaded in place.

List only BuildingType IDs. A group name such as `POWER` or `FACTORY` stays in the list but never satisfies it.

If the list holds no valid ID, `BARRACKS` can never be met, and a player cannot build any type that names it.
