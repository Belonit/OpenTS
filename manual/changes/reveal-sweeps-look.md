---
title: Give the alliance and spied-radar sweeps an ordinary look
category: fix
release: 0.2.0
targets:
- type: key
  id: AllyReveal
  effect: changed
- type: system
  id: map-visibility
  effect: changed
credit: [ZivDero]
---

Two events reveal the map around every object a house owns. One is the house becoming your ally, when `AllyReveal=yes` in `[AudioVisual]` of `rules.ini` makes allies share their sight. The other is you spying on the house's radar. Each object now reveals the area it normally sees, where it used to reveal a circle of its bare `Sight=` around its center.

Other than an aircraft, an object now gets its height bonus and veteran sight bonus, and it reveals nothing until it has entered the playable area. A structure reveals around the top cell of its foundation. An aircraft reveals its bare `Sight=`, or 1 cell once it has landed.
