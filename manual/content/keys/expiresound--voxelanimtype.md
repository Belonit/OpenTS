---
key: ExpireSound
scope: voxelanimtype
label: Voxel debris impact sound
see_also: ["ExpireAnim", "BounceSound", "StartSound"]
when_omitted:
  kind: value
  value: none
---

The sound plays where the piece ends its life, unless it ends low over water, as [`ExpireAnim`](/keys/expireanim/#scope-voxelanimtype) defines it. A piece low over water plays only its splash. The sound does not depend on `ExpireAnim`, so a piece with no impact animation still plays it.

A name that matches no sound, `none` included, keeps the sound the type already held. A later file therefore cannot clear an impact sound that an earlier one set.
