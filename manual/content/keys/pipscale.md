---
key: PipScale
summary: The quantity the pip row under a selected object counts, and how many pips that row has.
see_also: [Passengers, Size, Ammo, Storage, MaxCharge, MaxPips, Pip, "system:transports"]
when_omitted:
  kind: value
  value: none
---

`PipScale` chooses what the pip row under a selected object counts, and sets the row's default length. Without a `PipScale` the row has no pips, so a transport or harvester shows nothing however full it is.

The row appears only under objects that the player or an ally owns, and under an enemy structure that one of the player's spies has entered. A player who has been given the whole map sees the row under every object, as [observers and coach mode](/systems/observers/) describes.

| Value | Row length | What fills it |
| --- | --- | --- |
| `Ammo` | [`Ammo`](/keys/ammo/), at most 5 | remaining ammunition as a share of `Ammo`, drawn as filled markers with no empty ones behind them; at least one marker shows while any ammunition is left |
| `Tiberium` | 5 on a vehicle | stored Tiberium as a share of [`Storage`](/keys/storage/) |
| `Passengers` | [`Passengers`](/keys/passengers/), at most 5 | the passengers on board |
| `Power` | 10 | nothing is drawn |
| `Charge` | 8 | a vehicle's charge as a share of [`MaxCharge`](/keys/maxcharge/) |

[`MaxPips`](/keys/maxpips/) replaces these lengths. The `Ammo` and `Passengers` rows stay capped by the type's `Ammo` and `Passengers` values.

This vehicle shows a five-pip row that fills as passengers board:

```ini title="rules.ini"
[MYAPC] ; a UnitType registered in [VehicleTypes]
Passengers=5
PipScale=Passengers
```

On a structure, the `Tiberium` and `Power` rows default to six pips per cell of footprint width, or to [`MaxPips`](/keys/maxpips/) where the type sets it. Under `Tiberium`, that length is capped by the structure's [`Storage`](/keys/storage/), so a structure with no `Storage` shows no row. A [`Weeder=yes`](/keys/weeder/#scope-buildingtype) structure is capped by [`[General] WeedCapacity`](/keys/weedcapacity/) instead, and its row shows how much weed its whole house holds.

A type with [`Passengers`](/keys/passengers/) above zero always shows its passengers, whatever its `PipScale`. Each passenger fills as many pips as its [`Size`](/keys/size/#scope-aircrafttype), and at least one, in the colors that [`Pip`](/keys/pip/) describes. Free space is empty. The scale still sets the row's length, so passengers past the end of the row get no pip. A transport with `PipScale=Ammo`, for example, shows its passengers in a row sized by its ammunition.

A vehicle set to `Tiberium` shows the first Tiberium type as green pips and every other type as blue pips.

Omitting the key keeps the value an earlier rules file set. A value that matches none of the [pip scales](/reference/enums/pip-scale/) replaces it with none, which removes the row.
