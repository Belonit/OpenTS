---
key: ChargingVoice
summary: The EVA line spoken as the superweapon starts charging.
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: none
---

The line plays for the local player's weapon when its countdown starts from a full [`RechargeTime`](/keys/rechargetime/). Three events start the countdown:

- a structure or a plug grants the weapon while its house has full power;
- an ordinary repeating weapon fires and begins its next charge;
- a full [weed pool](/systems/superweapons/#manual-control) starts a [`Type=ChemMissile`](/keys/type/#scope-superweapontype) weapon.

A [`ManualControl=yes`](/keys/manualcontrol/) weapon stops its countdown when it is granted and after each shot, so only the weed pool plays the line for it. A [`UseChargeDrain=yes`](/keys/usechargedrain/) weapon plays it only when a structure or a plug grants it.

No line plays when a trigger action or a crate grants the weapon, when a weapon granted during a power shortfall arrives suspended, or when a suspended weapon resumes. An unrecognized speech name gives the weapon no line.
