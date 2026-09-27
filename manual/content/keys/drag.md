---
key: Drag
summary: The speed a levitating unit sheds each frame while it is coasting.
see_also: ["IntentionalDeacceleration", "Acceleration", "MaxVelocityWhenHappy", "Locomotor"]
when_omitted:
  kind: value
  value: "0.05"
---

A levitating unit moves in bursts. It thrusts for [`AccelerationDuration`](/keys/accelerationduration/) frames, coasts, and often brakes to a stop before it thrusts again. `Drag` is the speed the unit loses on every frame of the thrust and the coast. Braking uses [`IntentionalDeacceleration`](/keys/intentionaldeacceleration/) instead, and a drift at [`IntentionalDriftVelocity`](/keys/intentionaldriftvelocity/) loses no speed at all.

The loss is subtracted from the unit's speed, not applied as a percentage, so a coasting unit slows at a steady rate. When the loss is at least as large as the unit's speed, the unit stops dead on that frame instead of reversing. A `Drag` at least as large as both [`Acceleration`](/keys/acceleration/#scope-levitation-controls) and [`InitialBoost`](/keys/initialboost/) therefore stops the unit on the first frame after each thrust, so it moves only while thrusting.

Speeds and losses in `[LEVITATION]` are in leptons per frame, with 256 leptons to a cell and 15 frames to the second. If nothing else changes its speed, a unit coasting at 4 leptons per frame stops in 80 frames at a `Drag` of `0.05`, a little over five seconds, and in 8 frames at `0.5`.

```ini title="rules.ini"
[LEVITATION]
Drag=0.1
MaxVelocityWhenHappy=5.0

[MYFLOATER] ; a UnitType registered in [VehicleTypes]
Locomotor={3DC0B295-6546-11D3-80B0-00902792494C} ; the levitation drive
```

`[LEVITATION]` applies only to objects whose [`Locomotor`](/keys/locomotor/) is that identifier. Every such object shares the same values; no type can override them. The jumpjet drive reads `[JumpjetControls]` instead, and [what each locomotor drives its speed from](/systems/movement-and-terrain/#what-each-locomotor-drives-its-speed-from) gives the full mapping.

A file's `[LEVITATION]` section is read only when the same file has a `[General]` section with at least one assignment, because the engine reads `[LEVITATION]` while it processes `[General]`. A map that overrides any `[LEVITATION]` value therefore needs a non-empty `[General]` section as well. A `[General]` header with no assignments under it does not count.
