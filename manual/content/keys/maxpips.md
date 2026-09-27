---
key: MaxPips
summary: How many pips a selected object's pip row holds.
see_also: [PipScale, Passengers, Ammo, Storage, MaxCharge, "system:transports"]
when_omitted:
  kind: context-dependent
  note: "The length the object's pip scale gives. That is five for `Tiberium`, ten for `Power` and eight for `Charge`, and for `Ammo` and `Passengers` it is the type's `Ammo` or `Passengers` value, at most five. A structure using `Tiberium` or `Power` gets six pips per cell of footprint width instead."
---

```ini title="rules.ini"
[MYAPC]           ; a UnitType registered in [VehicleTypes]
Passengers=12
PipScale=Passengers
MaxPips=12
```

`MaxPips` sets how many pips the row has, replacing the default length of the type's [`PipScale`](/keys/pipscale/). The example transport shows twelve passenger pips instead of five. A type with no `PipScale` has no row, so the key does nothing for it.

Some rows stay capped by another value:

- Under `PipScale=Ammo` or `PipScale=Passengers`, the row holds at most the type's [`Ammo`](/keys/ammo/) or [`Passengers`](/keys/passengers/) value. `MaxPips=20` on a transport with `Passengers=6` draws six pips.
- On a structure under `PipScale=Tiberium`, the row holds at most the structure's [`Storage`](/keys/storage/), or [`[General] WeedCapacity`](/keys/weedcapacity/) on a [`Weeder=yes`](/keys/weeder/#scope-buildingtype) structure.

On a structure under `PipScale=Tiberium` or `PipScale=Power`, the key replaces the default of six pips per cell of footprint width.

Under `PipScale=Power`, no pips are drawn unless the type also sets `Passengers` above `0`. Such a type shows passenger pips across the length `PipScale=Power` gives.

A negative value counts as `0`, which leaves the row with no pips.

:::caution[Keep a long row within its object]
A vehicle, infantry soldier or aircraft draws its row to the right, four pixels per pip, and the row does not stop at the object's edge. A row much longer than the object is wide is drawn over whatever stands beside it. A structure's default length fits its footprint, but a larger `MaxPips` can run the row past the structure's edge too.
:::
