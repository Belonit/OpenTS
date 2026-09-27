---
key: ICBMLauncher
summary: Marks a deployed structure as an ICBM launcher, which faces east when it deploys.
see_also: [DeploysInto, UndeploysInto, SuperWeapon]
when_omitted:
  kind: value
  value: "no"
---

The flag makes the structure one of the eight [deployed-vehicle kinds](/keys/deploysinto/), which deploy and [pack up](/keys/undeploysinto/) on the vehicle's own cell.

When [an EM pulse](/systems/emp-pulse/#what-a-pulse-reaches) stuns the structure, sparks appear on it.

One effect is specific to this flag: the structure deploys facing east. A deploying vehicle turns east before the structure appears, and the vehicle created when the structure packs up faces east. [`SensorArray=yes`](/keys/sensorarray/) and [`TickTank=yes`](/keys/ticktank/) structures use the same facing.

The flag does not make the structure launch anything. A structure grants a superweapon only through [`SuperWeapon=`](/keys/superweapon/), and [superweapons](/systems/superweapons/) covers what that grants and how it is aimed.
