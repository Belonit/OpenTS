---
title: Turn edge scrolling off with AutoScroll
category: feature
release: 0.2.0
breaking: true
migration:
- If `AutoScroll=no` is set under `[Options]` in `sun.ini`, change it to `yes` to keep edge scrolling.
targets:
- type: key
  id: AutoScroll
  effect: changed
credit:
- ZivDero
- dkeeton
---

`AutoScroll=no` under `[Options]` in `sun.ini` now disables edge scrolling; previously the map scrolled at the edges regardless of the setting. The Edge Scrolling checkbox controls it. Keyboard scrolling, right-button coasting and the radar still move the view.

dkeeton is credited for the ts-patches option this follows, which calls the same setting `DisableEdgeScrolling`.
