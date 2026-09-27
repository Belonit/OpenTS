---
key: Passengers
summary: How much passenger space the type can carry at once.
see_also: [Size, SizeLimit, IsVehicleTransport, PipScale, MaxPips, CrewEscape, Crewed, VisibleLoad, AIIonCannonAPCValue, "system:transports"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[MYAPC] ; a UnitType registered in [VehicleTypes]
Passengers=5
PipScale=Passengers
```

The capacity is hold space, not a head count. Each passenger takes space equal to its [`Size`](/keys/size/), which defaults to `1`, so with default sizes `Passengers=5` holds five passengers. A passenger with a larger `Size` takes more of the same space.

A transport accepts a passenger only when all of these hold, tested in this order:

1. this capacity is above `0`;
2. the passenger is allied with the transport's owner;
3. the passenger is not a vehicle, or the transport sets [`IsVehicleTransport=yes`](/keys/isvehicletransport/);
4. the passenger's `Size` is no larger than the transport's [`SizeLimit`](/keys/sizelimit/);
5. the space already taken plus the passenger's `Size` is no more than this capacity;
6. if the transport is a vehicle, it is not standing on a water or shore cell.

Any capacity above `0` also changes these behaviors:

- **Pips.** The selection pips show the hold. Each unit of taken space draws one pip, in the passenger's [`Pip`](/keys/pip/) color for infantry and green for any other passenger. [`PipScale`](/keys/pipscale/) still sets how many pips the row has. Under `PipScale=Passengers` that is this capacity, capped at `5`, or at [`MaxPips`](/keys/maxpips/) when that is set.
- **Deploying.** A vehicle can deploy, because unloading is its deploy action. A vehicle with no capacity, no [`DeploysInto`](/keys/deploysinto/) and no [`IsMobileEMP=yes`](/keys/ismobileemp/) cannot deploy at all. A vehicle with capacity cannot deploy or unload while it is on a bridge, or while its cell or any of the four cells beside it is under a bridge.
- **Crew.** A destroyed vehicle with capacity produces no escaping crew, whatever [`Crewed=yes`](/keys/crewed/) says. [`CrewEscape`](/keys/crewescape/) covers that exclusion.
- **Computer houses.** Team scripts treat the type as a transport. A computer house choosing an ion cannon target values a vehicle of this type that the strike would destroy at [`AIIonCannonAPCValue`](/keys/aiioncannonapcvalue/), unless it is a harvester or deploys into a construction yard.
