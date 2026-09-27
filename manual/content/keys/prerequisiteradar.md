---
key: PrerequisiteRadar
summary: The BuildingTypes that satisfy a RADAR prerequisite.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: ""
---

A human player's house satisfies a `RADAR` entry in a [`Prerequisite=`](/keys/prerequisite/) list by owning at least one structure of any type on this list. Any one of them is enough, and their order does not matter. A structure counts from the moment it is placed until it is taken off the map or captured.

Computer houses do not use this list. A computer house's [production](/systems/production/#computer-houses) ignores prerequisites, and its [base planner](/systems/ai-base-building/#building-the-plan) tests `RADAR` against [`BuildRadar`](/keys/buildradar/) instead.

Write BuildingType IDs; case does not matter. A name that matches no BuildingType never counts. An empty list leaves `RADAR` impossible to satisfy, so a human player can never build a type that names it.
