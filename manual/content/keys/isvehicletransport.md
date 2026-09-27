---
key: IsVehicleTransport
summary: Lets units board this transport, not just infantry.
see_also: [Passengers, Size, SizeLimit, "system:transports"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MYAPC] ; a UnitType registered in [VehicleTypes]
Passengers=5
SizeLimit=3
IsVehicleTransport=yes
```

Without the flag, a transport refuses every vehicle. Over a transport that is standing still, the player gets no enter order and the cursor does not change, exactly as over an allied object that carries nobody. Infantry can board either way.

A moving transport, or one on a team whose [`Loadable`](/keys/loadable/) is off, shows every would-be passenger the no-enter cursor, with or without the flag.

The refusal applies to a player's order, to a computer team loading its transport, and to the final check as the passenger arrives. A carryall lift and a reinforcement group loaded at creation skip it; [Transports](/systems/transports/#being-admitted) lists both.

With the flag set and nothing else changed, a vehicle takes one space in the hold, the same as an infantryman. Raise its [`Size`](/keys/size/) to make it take more, and use the transport's [`SizeLimit`](/keys/sizelimit/) to cap the largest passenger it admits.

The engine does not stop a transport vehicle, loaded or not, from boarding another transport that admits vehicles. Keep the carried transport's `Size` above the carrier's `SizeLimit` to rule this out.
