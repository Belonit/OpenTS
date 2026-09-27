---
key: SortCameoAsBaseDefense
summary: Sorts a BuildingType's cameo into the base-defense group of the structures strip.
see_also: ["system:sidebar", "SidebarSorting"]
when_omitted:
  kind: inherited
  note: "Follows [`IsBaseDefense=`](/keys/isbasedefense/#scope-buildingtype)."
---

With `yes`, the structure's cameo sorts after ordinary structures, walls and gates that share its [`CameoSortOrder`](/keys/cameosortorder/). The group decides only between cameos with equal `CameoSortOrder` values, so a base defense with a lower value still comes before an ordinary structure with a higher one. [The order of the strips](/systems/sidebar/#the-order-of-the-strips) gives the full comparison.

A wall or a gate stays in its own group whatever this key says, because those groups are tested first.

A mod that sets [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-buildingtype) only so the computer rates a structure as a base defense can write `SortCameoAsBaseDefense=no` to keep its cameo among the ordinary structures.

With [`SidebarSorting=no`](/keys/sidebarsorting/), the strips are not sorted and this key has no effect.
