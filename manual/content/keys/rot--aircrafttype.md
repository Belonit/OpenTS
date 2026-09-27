---
key: ROT
scope: aircrafttype
label: Object rate of turn
when_omitted:
  kind: value
  value: "0"
---

`ROT` is how far an object's facing turns each game frame, in 256ths of a full circle. Values above `127` count as `127`. No facing turns through more than a half circle, so the longest turn takes 128 divided by `ROT` frames, rounded down. At `ROT=5`, the example below turns to face the opposite way in 25 frames.

```ini title="rules.ini"
[MYDROP] ; an AircraftType registered in [AircraftTypes]
ROT=5
```

Vehicles and aircraft turn both their body and their turret at this rate. A structure turns its turret at it. A hover vehicle's direction of travel swings at twice the rate, still capped at `127`. An object with the jumpjet locomotor turns its body in flight at [`TurnRate`](/keys/turnrate/) from `[JumpjetControls]` instead.

`ROT=0` means the facing never turns gradually: it points in each new direction the moment it is given one. Values from `-1` to `-128` do the same. Lower values wrap around, and some of them produce an ordinary turning rate.

An infantryman with the walk locomotor turns to each new facing at once, whatever `ROT` says. `ROT` matters only for an InfantryType whose [`Locomotor`](/keys/locomotor/) turns gradually. Such an infantryman starts at the maximum rate of `127`, which completes any turn within one frame. It switches to its type's `ROT` once a healing weapon hits it or a repair structure services it.

:::caution[Give a tunneling type a ROT above zero]
A type with the tunnel locomotor, [`Locomotor={4A582743-9839-11D1-B709-00A024DDAFD1}`](/keys/locomotor/), times its dig-in and its surfacing from `ROT`. Digging in takes 64 / (`ROT` × [`TunnelSpeed`](/keys/tunnelspeed/)) frames and surfacing takes 64 / `ROT` frames, each rounded down. At `ROT=0` both finish the instant they begin.
:::

A [`LimpetFactor`](/keys/limpetfactor/) warhead slows the vehicle it hits but not its turning, which stays at its type's `ROT`.
