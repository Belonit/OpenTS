---
title: Let the rules refuse a carryall a vehicle
category: feature
release: 0.2.0
targets:
- type: key
  id: Totable
  effect: added
- type: key
  id: Carryall
  effect: changed
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, CCHyper]
---

`Totable=no` in a vehicle type's section of `rules.ini` now stops carryalls from lifting that vehicle. The cursor offers no lift, and neither a force-move nor a computer-controlled carryall picks the vehicle up. A carryall used to lift any allied vehicle.
