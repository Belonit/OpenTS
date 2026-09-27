---
key: AvoidThreats
summary: Fixes every member's threat avoidance at `1` while it is on the team.
see_also: ["system:base-attacked", ThreatAvoidanceCoefficient]
when_omitted:
  kind: value
  value: "no"
---

`AvoidThreats=yes` gives each member a threat avoidance coefficient of `1` while it is on the team. The value replaces the coefficient from the member's type, [`ThreatAvoidanceCoefficient`](/keys/threatavoidancecoefficient/), whether that is higher or lower. The pathfinder reads the coefficient on every route, so a member that leaves the team goes back to its type's coefficient.

The coefficient scales [the region threat figures](/systems/base-attacked/#what-reads-the-map) the pathfinder weighs. At `1`, any cell whose region has a threat figure above zero counts as threatened: a diagonal shortcut that starts there is refused, and a straight-line shortcut counts the cell against its limit. The coarse corridor search also adds each region's full threat figure to the price of a step.

A type that leaves `ThreatAvoidanceCoefficient` at its default ignores threat entirely. For members of such types, this setting is what turns threat avoidance on.
