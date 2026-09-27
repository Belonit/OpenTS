---
key: TooBigToFitUnderBridge
summary: Splits a vehicle's composed image into two separately sorted pieces while it passes under a bridge.
see_also: ["ZFudgeBridge", "ZFudgeColumn", "Turret"]
when_omitted:
  kind: value
  value: "no"
---

On a vehicle whose hull, turret and barrel are combined into one image, `TooBigToFitUnderBridge=yes` draws that image in two pieces that are depth-sorted separately, under the conditions below. The top of the vehicle and the rest of it can then layer differently against a bridge deck. The flag changes only how the vehicle is drawn.

These vehicles combine their parts into one image:

- a vehicle drawn from shape artwork with [`Turret=yes`](/keys/turret/);
- a voxel vehicle with `Turret=yes` and a turret voxel, or with a barrel voxel.

Any other vehicle is drawn in one piece, and the flag has no effect on it. The stock Wolverine, for example, sets the flag but has `Turret=no`.

The split draws a band 32 pixels deep from the top of the image as one piece and the remainder as the other. Each piece gets its own depth adjustment.

The split applies when either of these holds, tested in this order:

1. The vehicle is under a bridge as [`ZFudgeBridge`](/keys/zfudgebridge/) defines it, and no road bridge middle span tile lies to its south, east or south-east. Those are the tiles [`ZFudgeColumn`](/keys/zfudgecolumn/) counts.
2. The vehicle has a destination and is in radio contact with a [`WeaponsFactory=yes`](/keys/weaponsfactory/) structure, as when it drives out of the structure that built it.

Otherwise the vehicle is drawn in one piece.

The flag does not affect movement. A vehicle with it passes under a bridge deck, or is refused, exactly as one without it would be. [Height, ramps and bridges](/systems/movement-and-terrain/#height-ramps-and-bridges) gives those rules.
