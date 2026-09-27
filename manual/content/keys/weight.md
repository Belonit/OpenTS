---
key: Weight
summary: How strongly an object resists being rocked, and how heavily it presses on ice.
when_omitted:
  kind: value
  value: "1"
---

A blast from a warhead with [`Rocker=yes`](/keys/rocker/) rocks the objects near it, and a higher `Weight` rocks an object less. Only an object drawn from a voxel model rocks.

The size of the rocking is `(0.04 - distance × 0.000025) × force ÷ Weight`, with the distance from the blast in leptons and the force that [`Rocker`](/keys/rocker/) takes from the blast's damage. A result below `0.01` produces no rocking, and a result above `0.05` is capped at `0.05`. Once the result reaches the cap, a lower `Weight` adds no more rocking. A blast from ahead or behind rocks the object half as hard as the same blast from the side.

An object in the blast's own cell is measured differently when something is credited with the blast. Its distance is about 10 leptons, and ahead, behind and the side are judged from the direction of the credited object, as [`Rocker`](/keys/rocker/) describes.

A vehicle's `Weight` also decides what it does to ice. Each time a vehicle enters a cell in a theater with [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) on, its weight is tested in this order:

1. At or above [`IceBreakingWeight`](/keys/icebreakingweight/), the vehicle tries to break the ice under it. If the break succeeds, the vehicle sinks and is stunned. [`IceBreakingWeight`](/keys/icebreakingweight/) describes when a break fails and the vehicle drives on, and why a vehicle this heavy also sinks on open water.
2. At or above [`IceCrackingWeight`](/keys/icecrackingweight/), the vehicle cracks intact ice and drives on. On ice that is already cracked, it breaks through as in step 1.
3. Below both, the vehicle leaves the ice alone.

Infantry and aircraft are never tested against the ice thresholds.

Against the stock thresholds of `2` and `4`, the stock harvesters (`Weight=1`) leave ice alone. Trucks (`2`), most tanks (`3.5`), the school bus and the train cars (`3.9`) crack it. The recreational vehicle (`4`) is the only stock type that breaks intact ice.
