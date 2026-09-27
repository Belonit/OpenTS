---
key: CameoSortOrder
scope: superweapontype
label: Cameo sort order on a super weapon
see_also: ["system:sidebar", "SidebarSorting"]
when_omitted:
  kind: value
  value: "0"
---

While [`SidebarSorting`](/keys/sidebarsorting/) is on, `CameoSortOrder=` orders superweapon cameos among themselves, lowest first. Cameos with equal values keep their order in `[SuperWeaponTypes]`. With sorting off, the value has no effect.

Sorting always places superweapon cameos together at the top of the right strip, ahead of infantry, aircraft and vehicles. No value moves a superweapon below them or another cameo into the superweapon block. [The order of the strips](/systems/sidebar/#the-order-of-the-strips) covers the full ordering.
