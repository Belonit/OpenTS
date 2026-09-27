---
key: StartSound
scope: voxelanimtype
label: Voxel debris creation sound
see_also: ["BounceSound", "ExpireSound", "IsMeteor", "AttachedSystem"]
when_omitted:
  kind: value
  value: none
---

`StartSound` plays once when a piece is created, at the point the piece was created for. Ordinary debris appears at that point. A meteor starts its flight elsewhere and flies in toward it, so its start sound plays at the landing point as the meteor begins its approach.

A value that names no registered sound, `none` included, keeps the sound the section already had. A later file therefore cannot remove a start sound that an earlier file set.
