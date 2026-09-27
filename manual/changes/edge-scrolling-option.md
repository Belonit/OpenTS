---
title: Turn edge scrolling off with AutoScroll
category: feature
release: 0.2.0
breaking: true
migration:
- Where `sun.ini` sets `AutoScroll=no` under `[Options]`, change it to `AutoScroll=yes` to keep edge scrolling. The setting had no effect before and now turns edge scrolling off.
targets:
- type: key
  id: AutoScroll
  effect: changed
credit:
- ZivDero
- dkeeton
---

`AutoScroll=no` under `[Options]` in `sun.ini` now stops the tactical map from scrolling when the pointer rests against the edge of the screen. The game read and saved the key, but the map scrolled at the edges whatever it said. The Edge Scrolling check box in the game controls dialog sets the key. With edge scrolling off, the scroll keys, right-button coasting and the radar still move the view.

dkeeton is credited for the ts-patches option this follows, which calls the same setting `DisableEdgeScrolling`.
