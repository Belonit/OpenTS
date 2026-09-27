---
key: EMPulseCannon
summary: Lets a BuildingType serve as the launch site of an EMPulse superweapon.
see_also: ["system:emp-pulse"]
when_omitted:
  kind: value
  value: "no"
---

A structure with `EMPulseCannon=yes` fires an EM pulse superweapon for its house. When the house fires the superweapon, its cannon nearest the target fires the pulse. [EM Pulse Cannon superweapon](/systems/emp-pulse/#em-pulse-cannon-superweapon) covers which cannons qualify and how the shot is made.

The cannon fires its primary weapon only for such a launch. It never picks a target on its own, and the player cannot order it to attack.
