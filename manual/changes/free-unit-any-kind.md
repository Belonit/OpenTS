---
title: Hand out an infantryman or an aircraft as a free unit
category: feature
release: 0.2.0
breaking: true
targets:
- type: key
  id: FreeUnit
  effect: changed
credit: [ZivDero, dkeeton]
---

`FreeUnit=` in a structure's section of `rules.ini` names the unit the owner receives when that structure is built. It now also accepts an InfantryType or an AircraftType. The name is looked up among vehicles first, then infantry, then aircraft.

A free infantryman is placed beside the structure, as a vehicle is. A free aircraft is placed on the structure itself, and a helipad or hover pad keeps it docked there. A hover pad whose `FreeUnit=` names an aircraft never gets the free `PadAircraft`, even when its own aircraft is refunded or not given at all, as for a pad that starts on the map. Only a free vehicle that harvests is sent to harvest; every free unit used to be.

A name that matches no type now gives nothing and is reported in the debug log. It used to create an empty vehicle type and give that.

dkeeton is credited for the ts-patches version this follows.
