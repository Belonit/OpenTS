---
key: Size
scope: aircrafttype
label: Passenger size
see_also: [SizeLimit, IsVehicleTransport, Passengers, PipScale, "system:transports"]
when_omitted:
  kind: value
  value: "1"
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
Size=3
```

`Size` is how much of a transport's hold this object takes up. A transport accepts it only if both tests pass:

- its `Size` is no larger than the transport's [`SizeLimit`](/keys/sizelimit/);
- its `Size`, added to the `Size` of every passenger already aboard, is no larger than the transport's [`Passengers`](/keys/passengers/).

A carryall lifting a vehicle, and a reinforcement group created with its passengers already aboard, skip both tests; [Transports](/systems/transports/) covers both.

A `Size=3` passenger in a transport with `Passengers=5` and `SizeLimit=3` leaves room for two passengers of the default size.

At the default of `1`, `Passengers` works as a plain head count. A ruleset that never sets `Size` fits five objects into a five-space hold, whatever they are. A passenger with `Size=0` takes up no room, so a transport accepts any number of them.

A passenger fills one pip of the transport's pip row for each unit of `Size`, so the `Size=3` passenger above shows three pips. A passenger with `Size=0` still shows one pip. [`PipScale`](/keys/pipscale/) and [`MaxPips`](/keys/maxpips/) set the row itself.

Only infantry and vehicles board transports, so the key has no effect on an aircraft or structure type.
