---
title: Repeat the last completed structure, infantry, vehicle or aircraft from the keyboard
category: feature
release: 0.2.0
targets:
- type: command
  id: RepeatLastBuilding
  effect: added
- type: command
  id: RepeatLastInfantry
  effect: added
- type: command
  id: RepeatLastUnit
  effect: added
- type: command
  id: RepeatLastAircraft
  effect: added
credit: [ZivDero, CCHyper, dkeeton]
---

Four new commands each queue another copy of the last structure, infantry unit, vehicle or aircraft the player produced, as long as its cameo is still on the sidebar. Infantry, vehicles and aircraft join the factory's queue, as a click on the cameo would add them. A structure is refused while another structure is being built, is on hold or waits to be placed. The commands have no key until one is assigned in the keyboard options.

CCHyper is credited for the Vinifera commands this follows, and dkeeton for the ts-patches building hotkey.
