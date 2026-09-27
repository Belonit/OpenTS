---
key: CameoSortOrder
scope: aircrafttype
label: Cameo sort order on a buildable type
see_also: ["system:sidebar", "SidebarSorting"]
when_omitted:
  kind: value
  value: "0"
---

Lower numbers come first. Types with the same number are ordered by the remaining rules in [the order of the strips](/systems/sidebar/#the-order-of-the-strips).

The number is compared only among cameos of the same kind, so no number moves a vehicle in among the infantry. Among structures it is compared before the wall, gate and base-defense groups. A wall with a lower number therefore sorts ahead of an ordinary building with a higher one.

The key has an effect only while [`SidebarSorting`](/keys/sidebarsorting/) is on.
