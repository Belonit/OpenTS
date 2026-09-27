---
key: AIBuildThis
summary: Allows a computer house to put the BuildingType into the base plan it generates.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "no"
---

`AIBuildThis=yes` makes the BuildingType a candidate when a computer house [generates a base plan](/systems/ai-base-building/#building-the-plan). A candidate still has to pass the plan's other tests, such as [`Owner`](/keys/owner/), [`TechLevel`](/keys/techlevel/) and its prerequisites.

The flag controls only that list of candidates. The planner adds these types whether or not they set it:

- the first [`BuildPower`](/keys/buildpower/) entry the house's country may own;
- the first [`AIWallTowers`](/keys/aiwalltowers/) entry of the house's side that its country may own;
- the [base defenses](/systems/ai-base-building/#base-defenses) chosen to fill placeholder nodes.

The flag has no effect on a house that follows a node list supplied by the scenario. `AIBuildThis=no` does not stop a player, a trigger or a team from building the type.
