---
key: BounceSound
scope: voxelanimtype
label: Voxel debris bounce sound
see_also: ["BounceAnim", "StartSound", "ExpireSound"]
when_omitted:
  kind: value
  value: none
---

The sound plays at the piece's position each time it strikes something, under the same conditions as [`BounceAnim`](/keys/bounceanim/#scope-voxelanimtype). It does not play in a water cell or on the contact that settles the piece.

A name that matches no sound, `none` included, keeps the sound the type already held. A later file therefore cannot clear a bounce sound that an earlier one set.
