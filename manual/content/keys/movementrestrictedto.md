---
key: MovementRestrictedTo
summary: Confines a vehicle to cells of one land type, which is how rolling stock is held to the rails.
see_also: ["IsTrain", "Passive", "SpeedType"]
when_omitted:
  kind: value
  value: none
---

Naming a [land type](/reference/enums/land-type/) refuses the vehicle every cell of any other land type. This test comes first when the vehicle checks whether it may enter a cell, ahead of terrain cost, occupancy, walls and gates, so none of those can make an exception to it.

```ini title="rules.ini"
[MYRAILCAR] ; a UnitType registered in [VehicleTypes]
MovementRestrictedTo=Railroad
IsTrain=yes
```

Two kinds of cell are exceptions:

- A `Tunnel` cell passes the land type test whatever is named. On a tunnel mouth five or four cells wide and three deep, only subtile 2 is accepted. On one three cells wide and four or five deep, only subtile 6 is. The rest of those mouths is refused, so a train enters through the portal and not through the hillside. A `Tunnel` cell on a tile of any other size is accepted on every subtile.
- A cell of the wrong land type is accepted when it has a rail bridge overlay and the vehicle is not at that cell's ground height. A restricted vehicle may therefore cross a rail bridge over ground it could never drive on.

A value that names no land type sets no restriction. The vehicle then travels wherever its [`SpeedType`](/keys/speedtype/) allows.
