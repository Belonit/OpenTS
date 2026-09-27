---
enum_id: TargetPropertyType
slug: target-property
title: Target property
summary: Selection rules used when a team script picks one building from all those of a named type.
representation: integer
bindings:
  key_value_types: []
  scripting_parameter_types: [target-property]
source_files: [code/target.hh, code/team.cpp, code/map.cpp]
values:
  - { constant: TPROPERTY_LEAST_THREAT, value: 0, input: "0", meaning: "Pick the candidate in the region with the lowest figure on the threat map of the team's house." }
  - { constant: TPROPERTY_GREATEST_THREAT, value: 1, input: "1", meaning: "Pick the candidate in the region with the highest figure on the threat map of the team's house." }
  - { constant: TPROPERTY_NEAREST, value: 2, input: "2", meaning: "Pick the candidate nearest the team member that joined the team most recently." }
  - { constant: TPROPERTY_FARTHEST, value: 3, input: "3", meaning: "Pick the candidate farthest from the team member that joined the team most recently." }
---

The declared enemy of the team's house comes first. The mission picks that house's best-rated structure, however the property rates structures of other houses. Another house's structure is picked only when the declared enemy has none of the named type. [Attack enemy building](/mapping/missions/tmission-attack-building-with-property/) covers which houses qualify.

Values `0` and `1` rank candidates by the [threat map](/systems/base-attacked/#the-threat-map) of the team's house. That map holds one figure for each **region**, a block of 4 by 4 cells, and each candidate is rated by the figure for the region that holds its center cell. The candidate's own [`ThreatPosed`](/keys/threatposed/) is one contribution to that figure; its strength and cost play no part.

A region's figure also counts objects outside it, because each object's `ThreatPosed` raises the regions around its own as well. Ownership, alliances and map rebuilds decide which objects count at all. [The threat map](/systems/base-attacked/#the-threat-map) describes both.

A value outside `0` to `3` gives every candidate the same rating, so the mission picks no structure.
