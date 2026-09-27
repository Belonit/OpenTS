---
key: TickTank
summary: Marks a structure as the deployed form of a tick tank, which digs in facing east.
see_also: [DeploysInto, UndeploysInto, DeployToFire]
when_omitted:
  kind: value
  value: "no"
---

`TickTank=yes` makes a structure one of the [deployed-vehicle kinds](/keys/deploysinto/), and it shares their rules:

- It is put down on the deploying vehicle's own cell instead of one cell away, and the vehicle it packs up into appears on that same cell.
- If it names an [`UndeploysInto`](/keys/undeploysinto/) vehicle, it can be packed up whether or not the session allows redeploying.
- [An EM pulse](/systems/emp-pulse/#what-a-pulse-reaches) attaches sparks to it as it is stunned.

A tick tank deploys facing east. The vehicle holds its deploy order until it has turned east, and the vehicle created by a later pack-up also faces east.

A computer-controlled vehicle whose [`DeploysInto`](/keys/deploysinto/) names a `TickTank=yes` structure digs in before firing only when both hold:

- its target is a vehicle;
- its own cell is flat, holds no structure and has land that allows building.

Against infantry, a structure or any other target it fires without deploying. [`DeployToFire=yes`](/keys/deploytofire/) on the vehicle overrides this rule and makes it dig in for every target, whoever owns it.

A tick-tank structure given a target beyond its primary weapon's range drops that target, unless the weapon is anti-aircraft. If the structure is computer-owned and not immobilized, it then packs up at once into its `UndeploysInto` vehicle. One with no `UndeploysInto` is sold instead. [`Artillary=yes`](/keys/artillary/) and [`IsJuggernaut=yes`](/keys/isjuggernaut/) structures follow the same rule.
