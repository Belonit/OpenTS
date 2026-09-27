---
key: Thief
summary: Makes a soldier take a non-allied vehicle it is walking toward.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "no"
---

A `Thief=yes` soldier takes any non-allied vehicle that is its movement destination, whatever mission it is on. Aircraft, and vehicles that have deployed into structures, do not count. Nothing offers a cursor for the steal.

[`VehicleThief=yes`](/keys/vehiclethief/) is a separate setting, with a cursor and limits this flag lacks.

While the soldier is farther away, it keeps re-aiming at the vehicle as the vehicle moves. Once it is within half a cell and less than one height level of the vehicle, the vehicle changes to the soldier's owner. The soldier is deleted on the spot and never becomes a passenger. [Stealing a vehicle](/systems/capture/#stealing-a-vehicle) lists each step of the takeover.

The vehicle records the thief's type, as a hijacked vehicle does. When the vehicle is destroyed, a soldier of that type appears at the wreck, owned by whoever holds the vehicle at that moment. It has a random strength between `5` and half its maximum. It appears only if the wreck's cell has room for it.

The flag also [widens what the soldier scans for](/systems/target-selection/#what-each-kind-of-object-considers) to capturable structures and Tiberium processors. It changes only which target the scan picks:

- an armed thief fires on the structure it picks;
- an unarmed thief scans for nothing, unless it is also `Infiltrate=yes` or `VehicleThief=yes`.

A `Thief=yes` soldier never enters a structure or takes credits because of this flag. Only the vehicle steal consumes the soldier.
