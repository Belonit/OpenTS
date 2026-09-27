---
key: IsBaseDefense
scope: buildingtype
label: Base defense building
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "no"
---

The flag marks a structure as a base defense for the computer's [base planner](/systems/ai-base-building/). It has these effects:

- Only a flagged type gets anti-air, anti-armor and anti-infantry [values computed from its primary weapon](/systems/ai-base-building/#defense-values). A type whose three values are all zero is never chosen to fill a defense node.
- A flagged structure does not count toward the prerequisites the [defense planner](/systems/ai-base-building/#base-defenses) checks for its candidates.
- When a computer house places a [`WallTower`](/keys/walltower/), the next node after it in the base plan whose type is flagged moves onto the tower's cell.
- When a flagged structure is taken off the map, a house that is not following a map plan turns its node back into a placeholder. The planner then picks a new type and cell, so the same defense is not [rebuilt](/systems/ai-base-building/#rebuilding) in place.
- When the computer takes over a departed player's house, each standing flagged structure of a type the house can build fills a placeholder node in its base plan.
- A computer house's ion cannon rates a flagged structure that reaches the base defense test with [`AIIonCannonBaseDefenseValue`](/keys/aiioncannonbasedefensevalue/), as [the computer's use](/systems/superweapons/#the-computers-use) describes.
- [`SortCameoAsBaseDefense`](/keys/sortcameoasbasedefense/) defaults to this flag's value.
