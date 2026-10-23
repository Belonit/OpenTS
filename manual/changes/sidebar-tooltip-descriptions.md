---
title: Add descriptions to sidebar tooltips
category: feature
release: 0.2.0
targets:
- type: system
  id: sidebar
  effect: changed
- type: system
  id: superweapons
  effect: changed
- type: key
  id: Description
  scope: aircrafttype
  effect: added
- type: key
  id: Description
  scope: superweapontype
  effect: added
credit:
- JoyfulShush
---

Buildable type sections now accept `Description=`. The sidebar tooltip always shows the type's name and price, and adds the description below them when it is set; `SidebarCameoText=` now changes only the cameo caption.

Superweapon sections also accept `Description=`. When it is set, the text appears below the weapon's name in its sidebar tooltip.
