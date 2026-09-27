---
key: TurretNotExportedOnGround
summary: Pivots a building's voxel barrel about its firing offset instead of about the model origin.
see_also: ["PrimaryFireFLH", "TurretAnimIsVoxel", "Voxel"]
when_omitted:
  kind: value
  value: "no"
---

The setting chooses the point a building's voxel barrel pivots about as it elevates. It applies only to a [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) building. Write it in the section of the building's Image ID, not in the turret animation's section.

- **Cleared:** the barrel is shifted by the firing offset and then pitched about the model's origin, so the firing point swings with the barrel. Use this for barrel artwork exported with its pivot resting on the ground.
- **Set:** the barrel is pitched about the point named by the `X` and `Z` components of [`PrimaryFireFLH`](/keys/primaryfireflh/). That point stays still while the barrel elevates. Use this for artwork exported with its pivot already raised.

The `Y` component plays no part in either case.

```ini title="art.ini"
[MYTURRET] ; the Image ID of a BuildingType
PrimaryFireFLH=90,0,110
TurretNotExportedOnGround=yes ; the barrel elevates around 90,-,110
```

A vehicle ignores the setting. A vehicle with a turret model always pitches its barrel as if the setting were set; one without a turret model pitches it as if the setting were cleared.
