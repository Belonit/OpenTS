---
key: Carryall
summary: Gives an aircraft a move mission that lifts and sets down whole vehicles.
see_also: ["Landable", "Passengers", "Dock", "Totable"]
when_omitted:
  kind: value
  value: "no"
---

`Carryall=yes` replaces the aircraft's move mission with one that picks up a single vehicle, carries it and sets it down elsewhere. The lift ignores [`Passengers`](/keys/passengers/): a carryall with no passenger capacity still lifts vehicles, and the capacity governs only the ordinary loading a transport does.

```ini title="rules.ini"
[MYLIFTER]    ; an AircraftType registered in [AircraftTypes]
Carryall=yes
Landable=yes  ; keeps the carryall selectable; see Landable
```

## Picking up a vehicle

An empty carryall sent to a vehicle lifts it when the vehicle's type is [`Totable=yes`](/keys/totable/) and the two owners are allied. The carryall asks the vehicle for a ride first, and the vehicle refuses when any of these is true:

- it is already in radio contact with another object, as it is while boarding a transport or docking;
- it is unloading passengers, emptying its harvest at a refinery, or deploying into a structure;
- it is already tethered;
- it is inside a tunnel;
- it stands under a bridge, or is driving into a cell under one. A vehicle on the bridge deck can be lifted.

After a refusal the carryall abandons the order. When the vehicle agrees, it drops its orders and waits in place. The carryall flies over it, picks it up and carries it as cargo. A move order given to the waiting vehicle cancels the lift.

## Setting a vehicle down

A loaded carryall sent anywhere flies there and sets the vehicle down. When the destination cell is taken or unsuitable, it sets down in a clear cell nearby, chosen as described in [Choosing a landing zone](/systems/aircraft-operations/#choosing-a-landing-zone). If the vehicle still cannot be placed, it stays aboard and the carryall chooses a landing zone again. After a successful drop the carryall moves off to a nearby cell.

## Player orders

When the player's empty carryall is selected, the cursor over an allied `Totable=yes` vehicle becomes the tote cursor. The tote cursor is not offered over a vehicle standing on a [`WeaponsFactory=yes`](/keys/weaponsfactory/) building's cell, so the player cannot order a lift for a vehicle still on its factory.

## Flight and landing

The carried vehicle is drawn at the carryall's position, underneath the aircraft, and turns with it.

A carryall that is loaded, or in radio contact with another object such as a vehicle it is collecting, settles 100 leptons above the ground instead of landing. A cell is 256 leptons wide. The exception is an empty carryall entering a helipad or repair bay, which lands on it. An empty carryall in contact with nothing lands on the ground.

Each time a carryall descends below 300 leptons, it plays the `CARYLAND` animation on the ground beneath it. The animation name is fixed. A type that also sets [`IsDropship=yes`](/keys/isdropship/) plays the dropship's landing animation instead.
