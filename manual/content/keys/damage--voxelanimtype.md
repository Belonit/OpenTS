---
key: Damage
scope: voxelanimtype
label: Voxel animation damage
see_also: ["DamageRadius", "Warhead"]
when_omitted:
  kind: value
  value: "0"
---

The damage a piece deals on each bounce and in the blast at the end of its life. Every object reached takes damage calculated from this full figure. The piece's [`Warhead`](/keys/warhead/#scope-voxelanimtype) adjusts it for each object's armor and distance. The warhead page describes when each kind of damage happens. A piece with no warhead deals none.

With a [`Bright=yes`](/keys/bright/#scope-warheadtype) warhead, this figure also sets the size of the light flash at the end-of-life blast. A figure of 87 or less, including `0`, gives the smallest flash. From 88 the flash grows with the figure until it reaches its largest size at 252.
