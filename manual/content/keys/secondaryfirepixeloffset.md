---
key: SecondaryFirePixelOffset
summary: Parsed screen offset that the engine never uses.
no_effect: true
see_also: ["PrimaryFirePixelOffset", "SecondaryFireFLH", "Secondary"]
when_omitted:
  kind: value
  value: 65535,65535
---

A building's second weapon has no fixed firing point of its own. [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) serves both weapon slots. When it is set, it moves the mounting and the muzzle of whichever weapon fires, and the point the building turns to face its target from.

When `PrimaryFirePixelOffset` is left at `65535,65535`, the second weapon fires from [`SecondaryFireFLH`](/keys/secondaryfireflh/). A [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building is the exception: it fires both weapons from the end of its voxel barrel. An upgrade plugged into the building that brings its own second weapon fires it from the upgrade's `SecondaryFireFLH`.
