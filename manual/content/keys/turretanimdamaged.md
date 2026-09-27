---
key: TurretAnimDamaged
summary: The turret animation a building shows once it is damaged.
see_also: ["TurretAnim", "TurretAnimIsVoxel", "ConditionYellow"]
when_omitted:
  kind: computed
  note: The `TurretAnim` value, copied across whenever nothing has set this key.
---

The value is an AnimType ID, as for [`TurretAnim`](/keys/turretanim/). A building switches its turret animation to this one when its health falls to [`ConditionYellow`](/keys/conditionyellow/) or below, and back to `TurretAnim` once repairs lift it above. The new animation continues from the frame the old one had reached, so a turret part way through its sequence does not restart. The building's other animations switch to their damaged forms at the same moment.

A damaged building that starts charging a [`Charges=yes`](/keys/charges/) weapon also uses this animation. The [`TurretAnim` crash warning](/keys/turretanim/) applies to this name in that case.

A [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) building takes its model name from `TurretAnim` alone. This key has no effect on it unless its primary weapon is `Charges=yes`; a damaged one then starts this animation when it begins to charge, and the same crash warning applies.
