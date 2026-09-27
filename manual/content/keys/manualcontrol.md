---
key: ManualControl
summary: Whether the superweapon's charge timer is left stopped instead of counting down on its own.
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: "no"
---

`ManualControl=yes` sets the weapon's countdown to a full [`RechargeTime`](/keys/rechargetime/) and stops it, when the weapon is granted and again after every shot. The weapon therefore never charges on its own.

Only one event starts the countdown: a house's [weed pool](/systems/veins/#the-weed-pool) reaching [`WeedCapacity`](/keys/weedcapacity/) starts its [`Type=ChemMissile`](/keys/type/#scope-superweapontype) weapon. [Manual control](/systems/superweapons/#manual-control) covers that start. A weapon of any other behavior never charges, although a one-time grant from a trigger action or a crate still arrives fully charged.

Resuming from suspension does not restart the countdown either. A weapon suspended partway through its charge stays stopped until its next start, which begins again from a full delay. A full weed pool does not start a suspended weapon, but the pool is still emptied.

While the countdown is stopped, clicking the cameo plays [`SuspendVoice=`](/keys/suspendvoice/), not [`ImpatientVoice=`](/keys/impatientvoice/).
