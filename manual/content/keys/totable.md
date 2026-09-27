---
key: Totable
summary: Whether a carryall may pick this vehicle up.
see_also: ["Carryall", "Passengers"]
when_omitted:
  kind: value
  value: "yes"
---

`Totable=no` stops every [`Carryall=yes`](/keys/carryall/) aircraft from lifting the vehicle. The Carryall page describes the lift itself.

```ini title="rules.ini"
[MYBIGTANK] ; a UnitType registered in [VehicleTypes]
Totable=no
```

A player's carryall shows no tote cursor over the vehicle. A carryall ordered onto it anyway, for example with a force-move, treats the vehicle's cell as occupied, lands near it and does not pick it up.

`Totable=no` refuses the lift at all times. The other refusals the Carryall page lists apply only while the vehicle is in the situation they name, such as unloading or standing under a bridge.

The flag affects only carryall lifts. It does not stop an aircraft with [`Passengers`](/keys/passengers/) capacity and [`IsVehicleTransport=yes`](/keys/isvehicletransport/) from loading the vehicle, or a scenario from delivering it as reinforcements aboard an air transport.
