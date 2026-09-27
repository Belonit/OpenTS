---
key: FreeUnit
summary: The vehicle, infantry or aircraft type a structure gives its owner when its buildup finishes.
see_also: ["system:production", HoverPad, PadAircraft]
when_omitted:
  kind: value
  value: "none"
---

```ini title="rules.ini"
[MYPROC]        ; example refinery BuildingType
Cost=2000       ; already includes MYHARV
FreeUnit=MYHARV ; example harvester UnitType; an InfantryType or AircraftType also works
```

The name is looked up among vehicle types first, then infantry types, then aircraft types, so a name used by more than one kind gives the vehicle. A name that matches none of them gives nothing.

## Where the unit appears

A vehicle or infantryman appears on the cell south of the structure's center, or on a free cell nearby. If no nearby cell can take it, the owner receives the unit's `Cost=` in credits instead, without the owner's price multipliers. A [`Harvester=yes`](/keys/harvester/#scope-unittype) or [`Weeder=yes`](/keys/weeder/#scope-unittype) vehicle starts harvesting; any other unit takes its type's usual idle mission.

An aircraft appears on the structure itself, facing [`PoseDir=`](/keys/posedir/), and is set to guard. A [`HoverPad=yes`](/keys/hoverpad/) or [`Helipad=yes`](/keys/helipad/) structure docks it as if it had landed there; any other structure leaves it undocked. If the aircraft cannot be placed, the owner receives its `Cost=` in credits instead. A structure whose `FreeUnit` is an aircraft never receives a [`PadAircraft=`](/keys/padaircraft/) aircraft, even when its own could not be placed.

## When the owner receives it

The unit is given once, when the structure finishes its buildup. A structure present when the scenario starts gives nothing, and capturing a structure gives the new owner nothing.

A computer-controlled owner always receives the unit. A human owner receives it only when either of these holds:

- Nothing was paid for the structure. This covers a structure deployed from a vehicle or placed by a trigger with its buildup.
- The price paid is more than the structure's reduced price: its `Cost=` minus the unit's `Cost=` and any pad aircraft share. [What a structure gives away](/keys/cost/#what-a-structure-gives-away) defines the reduced price.

The price paid includes the owner's country and difficulty [price multipliers](/keys/cost/#what-a-house-pays), but the reduced price does not. At a combined multiplier of `1` or more, every structure bought from a factory passes the second test as long as its unit's `Cost=` is above `0`. A lower multiplier can make it fail. At `0.25`, the example refinery with a 1400-credit harvester costs 500 credits, which is less than its reduced price of 600, so a human owner gets no harvester.

## Effect on the structure's price

Include the unit's price in the structure's `Cost=`. Naming a free unit then leaves what the structure costs to buy, what selling it refunds and what destroying it is worth unchanged, apart from a few credits of rounding under a price multiplier. It lowers the structure's repair cost and the anger that damage to it raises. [What a structure gives away](/keys/cost/#what-a-structure-gives-away) gives the reduced price behind these effects, and the exception for a `Cost=` below what the structure gives away.
