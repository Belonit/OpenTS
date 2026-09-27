---
key: Sensors
summary: Whether the object reveals a nearby hidden object belonging to a house its owner does not consider allied.
see_also: [SensorArray, "system:cloaking"]
when_omitted:
  kind: context-dependent
  note: "An InfantryType section starts at yes. An AircraftType, BuildingType or UnitType section starts at no."
---

`Sensors=yes` makes an object end the cloak of hidden objects right next to it. It works in two cases:

- A hidden vehicle, infantryman or aircraft is uncloaked when it arrives at the center of a cell and one of the eight neighboring cells, inside the playable area, holds a detector. The test runs only as the hidden object arrives, so a detector that walks up to a hidden object standing still does not reveal it.
- A cloaked structure is uncloaked, and cannot cloak again, while a detector stands within one cell of its footprint.

Only one object is tested in each cell, the one nearest the cell's corner, so a detector that shares a cell with another object can be missed.

Both cases apply only when the detector's owner does not consider the hidden object's house allied. The hidden object's owner may consider the detector allied, and detection still happens.

A detector only ends cloaks. It marks nothing as sensed, so its house cannot see or target anything that is still hidden elsewhere. A [`SensorArray=yes`](/keys/sensorarray/) structure does that instead; [Detection](/systems/cloaking/#detection) compares the two.

The `SENSORS` [veteran ability](/systems/veterancy/#abilities) works like this flag in the first case only. A promoted detector uncloaks a vehicle, infantryman or aircraft that moves past it, but has no effect on a cloaked structure.

:::caution[Every InfantryType is a detector unless told otherwise]
InfantryTypes start with this flag set, so a civilian, an engineer and a rifleman all uncloak hidden objects that move past them. Write `Sensors=no` in the section to turn it off.
:::
