---
title: Let transports carry vehicles
category: feature
release: 0.2.0
targets:
- type: key
  id: IsVehicleTransport
  effect: added
- type: key
  id: SizeLimit
  effect: added
- type: key
  id: Size
  effect: added
  scope: aircrafttype
- type: key
  id: Passengers
  effect: changed
- type: system
  id: transports
  effect: added
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, Rampastring]
---

`IsVehicleTransport=yes` in a transport's section of `rules.ini` lets the transport carry vehicles as well as infantry.

A transport's `Passengers=` is now its total room, and each passenger takes up as much of it as its own `Size=`. A transport also refuses any passenger whose `Size=` is larger than the transport's `SizeLimit=`. A ruleset that sets neither key keeps the passenger counts it had.

A vehicle unloaded from a transport now stops at the center of its cell. It used to stop on one of the infantry positions within the cell, where it was drawn in the wrong place and could not dock at a repair bay.

When a transport vehicle is destroyed, a vehicle passenger can now escape as infantry can, if it can enter the cell the transport stood on. Only infantry could escape before.
