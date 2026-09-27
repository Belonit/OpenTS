---
key: Turret
summary: Gives a vehicle a turret that aims independently of its hull, and makes a structure turn toward its target before firing.
see_also: ["TurretSpins", "ROT", "RotCount"]
when_omitted:
  kind: value
  value: "no"
---

A vehicle with a turret aims it separately from its hull. The turret turns toward the target, the shot leaves along the turret's facing, and the turret artwork is drawn at that facing. The turret turns at the same [`ROT`](/keys/rot/#scope-aircrafttype) as the hull, so the vehicle can drive one way while its gun points another.

A vehicle without a turret must turn its whole hull onto the target before it fires. It turns to aim only while it is stopped and has no move order.

A vehicle drawn from a shape file rather than a voxel model loads a voxel turret when the flag is set. The model is named for the vehicle's image with `TUR` appended.

A structure with a turret must turn toward its target before it fires, and its turret is drawn at the structure's facing. A structure has only one facing, so its turret never aims apart from it. A structure without the flag fires toward its target at once, whichever way it faces. A structure counts as having a turret when its own type or any upgrade fitted into it sets the flag. An upgrade can therefore add a gun turret to a structure that has none.

On a BuildingType the flag also replaces any [`RotCount`](/keys/rotcount/) value with 32, or with 1 when the flag is off. Nothing uses that number.

Infantry and aircraft do not aim a separate turret, whatever the flag says.
