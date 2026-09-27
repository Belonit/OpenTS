---
title: Place starting units in a ring around the start position
category: feature
release: 0.2.0
targets:
- type: system
  id: starting-forces
  effect: changed
credit: [ZivDero, CCHyper]
---

A house's random starting vehicles and infantry are now placed outward from a ring about three cells from its start position, and they stay where they are placed. They used to be placed from one cell out, and a human player's units were then each ordered a cell further away, so a match opened with the units still shuffling around the construction vehicle.

The base unit is placed as before, on the start position or the nearest cell that can take it. When bases are off, or the base unit could not be placed on the start position, the first starting unit takes the start position itself.

The same random seed now places the starting units differently, so a seeded launch no longer reproduces an earlier build's opening layout.

CCHyper is credited for the Vinifera implementation this one follows.
