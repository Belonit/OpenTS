---
title: Order the sidebar cameos by category and rules index
category: feature
release: 0.2.0
targets:
- type: system
  id: sidebar
  effect: changed
- type: key
  id: SidebarSorting
  effect: added
- type: key
  id: CameoSortOrder
  effect: added
- type: key
  id: SortCameoAsBaseDefense
  effect: added
- type: format
  id: save-games
  effect: changed
credit:
- ZivDero
- Rampastring
---

The sidebar used to list cameos in the order they became available, so the same rules could give a different strip from one game to the next. Each strip is now sorted by kind, then by the order the types are listed in the rules, with walls, gates and base defenses after the other structures. `SidebarSorting=no` under `[Options]` in `sun.ini` restores the old arrangement.

In `rules.ini`, `CameoSortOrder=` in a type's or super weapon's section moves its cameo within its kind, lower values first. It reorders no rules list, and it takes precedence over the grouping of walls, gates and defenses. `SortCameoAsBaseDefense=` in a structure's section decides whether it sorts with the base defenses.
