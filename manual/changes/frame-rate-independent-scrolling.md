---
title: Scroll the tactical map at one speed on every machine
category: fix
release: 0.2.0
targets:
- type: key
  id: ScrollRate
  effect: changed
- type: key
  id: ScrollMethod
  effect: changed
- type: key
  id: ScrollMultiplier
  effect: changed
credit: [ZivDero, FunkyFr3sh]
---

Edge scrolling, and right-button coasting under the default coast method, now move the view by elapsed time. They moved it once per drawn frame, so on a machine drawing several hundred frames a second the view shot across the map as soon as the pointer reached an edge.

The view now takes sixty steps a second, or fewer when the game checks the mouse fewer than fifteen times a second. The step lengths and the pace at which edge scrolling speeds up are unchanged, so the player's scroll speed and `ScrollMultiplier` keep their effect. The scroll speed is `ScrollRate` under `[Options]` in `sun.ini`, where a higher value scrolls more slowly. `ScrollMultiplier`, under `[AudioVisual]` in `rules.ini`, lengthens every edge-scroll step as it rises.

`ScrollMethod`, under `[Options]` in `sun.ini`, selects how right-button coasting moves the view. Methods `1` and `2`, which move the view in proportion to how far the pointer is pulled and then return the pointer, are unchanged. A value outside `0` through `2` used to coast by an unpredictable distance, and now does not coast at all.

FunkyFr3sh is credited for the ts-patches scroll rate limiter, which fixes the same fault a different way.
