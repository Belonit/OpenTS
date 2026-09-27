---
key: Artillary
summary: Marks a deployed structure as artillery, which deploys facing north and returns its barrel and facing to their start values before its vehicle is created.
see_also: [DeploysInto, UndeploysInto, StartPitch, StartFacing, TurretAnimIsVoxel]
when_omitted:
  kind: value
  value: "no"
---

`Artillary=yes` marks a structure as deployed artillery. It is one of the eight flags that make a structure [a deployed-vehicle kind](/keys/deploysinto/), so the structure also gets that group's behavior:

- it is put down on the deploying vehicle's cell, not one cell away, and the vehicle returns to that cell when the structure undeploys;
- it can undeploy whether or not the session allows redeploying;
- [an EM pulse](/systems/emp-pulse/#what-a-pulse-reaches) that stuns it also attaches sparks.

A human player's vehicle whose [`DeploysInto`](/keys/deploysinto/) names an `Artillary=yes` structure never fires back on its own when attacked.

## Facing and barrel

Artillery deploys facing north, and no other deployed-vehicle kind uses that facing. A vehicle ordered to deploy turns north first and deploys once it faces north. The vehicle created by a later undeploy also faces north.

When the structure undeploys, it plays its deconstruction animation first. It then waits until its barrel is back at [`StartPitch`](/keys/startpitch/) and its body at [`StartFacing`](/keys/startfacing/), and only then creates the vehicle, with the barrel already at `StartPitch`. An [`IsJuggernaut=yes`](/keys/isjuggernaut/) structure runs the same wait before its deconstruction animation instead.

A structure that draws its turret from a voxel model, [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/), shows the turret at all times when it is artillery. Other voxel-turret structures hide the turret while their buildup plays and again once deconstruction is past its first frame.

## Targets out of range

A computer-owned artillery structure drops a target beyond the range of its primary weapon, unless that weapon is anti-aircraft. Unless the structure is immobilized, it then starts to undeploy if it has an [`UndeploysInto`](/keys/undeploysinto/) vehicle, and is sold if it has none. `TickTank=yes` and `IsJuggernaut=yes` structures do the same.

:::caution[The key is spelled `Artillary`]
The engine reads only this spelling. A section that writes `Artillery=` leaves the structure unflagged.
:::
