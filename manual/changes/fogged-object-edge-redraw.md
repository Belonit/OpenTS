---
title: Keep fogged object redraws inside safe bounds
category: fix
release: 0.2.0
credit: [Krisztiaan]
targets:
- type: system
  id: map-visibility
  effect: changed
---

A game with fog of war no longer crashes while loading or playing when a fogged structure, terrain object, overlay or smudge lies at the edge of the tactical view. Such an object could be drawn outside the screen buffer; it is now clipped to the view.

A fogged structure now draws in its owner's colors, as a visible one does, unless it uses the terrain palette. It used to take its colors from the map cell's data, which could corrupt the cell and crash the game during a later redraw.
