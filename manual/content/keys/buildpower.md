---
key: BuildPower
summary: The power plants a computer house plans first, in order of preference.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: ""
---

A computer house puts the first entry that the country it [acts as](/keys/actslike/) [may own](/keys/owner/) into [its base plan](/systems/ai-base-building/#building-the-plan) right after the construction yard. That entry skips the plan's candidate test, so it is planned even with [`AIBuildThis=no`](/keys/aibuildthis/) or a [`TechLevel`](/keys/techlevel/) above the house's. When the entry is also a candidate, the plan queues it a second time once the queue meets its prerequisites.

The same entry is the last resort when the house [inserts a power plant](/systems/ai-base-building/#power-and-money-interventions) ahead of a structure its power cannot support. It is used only when the house chose neither a turbine nor an advanced power plant and its side names no [`RegularPowerPlant`](/keys/regularpowerplant/).

When the country may own no listed type, the plan starts with no power plant, and the last resort inserts none. Nothing else reads the list.
