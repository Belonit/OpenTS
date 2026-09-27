---
key: SizeLimit
summary: The largest single passenger a transport will accept.
see_also: [Size, IsVehicleTransport, Passengers, "system:transports"]
when_omitted:
  kind: value
  value: "1"
---

```ini title="rules.ini"
[MYAPC] ; a UnitType registered in [VehicleTypes]
Passengers=5
SizeLimit=3
IsVehicleTransport=yes
```

A transport refuses any passenger whose [`Size`](/keys/size/) is larger than this value, however much room is left. The transport above refuses anything larger than `Size=3`, even when empty.

A passenger must also fit in the room left: its `Size` added to the `Size` of everyone aboard must not exceed [`Passengers`](/keys/passengers/). A passenger that fails either test gets the cannot-enter cursor.

At the default of `1`, a transport takes no passenger larger than the default size. Raising `Passengers` alone therefore does not let it carry a larger passenger; raise `SizeLimit` as well. `SizeLimit=0` refuses every passenger of the default size.

[`IsVehicleTransport`](/keys/isvehicletransport/) decides whether vehicles may board at all, and `SizeLimit` decides how large any passenger may be.

A carryall lifting a vehicle ignores this limit, and so does a reinforcement group created with its passengers already aboard. [Transports](/systems/transports/) covers both.
