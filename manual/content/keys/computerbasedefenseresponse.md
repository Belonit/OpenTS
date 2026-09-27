---
key: ComputerBaseDefenseResponse
summary: Multiplies an attacker's ThreatPosed to size the defenders a computer house calls up.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "3"
---

When enemy infantry or an enemy vehicle hits a computer house's structure or one of its [`ToProtect=yes`](/keys/toprotect/) objects, the house calls defenders back to fight the attacker. This value sets how many. The house orders up to six of its infantry and vehicles against the attacker, and stops once their combined [`ThreatPosed`](/keys/threatposed/) exceeds the attacker's `ThreatPosed` multiplied by this value. A higher value calls back more defenders for the same attacker.

Objects already targeting the attacker count toward that total and are not ordered again. An attacker whose type has `ThreatPosed=0` calls back no one, whatever this value is.

No call-up happens when the attacker is an ally, when the damaged type sets [`Insignificant=yes`](/keys/insignificant/), or, in a campaign, when the damaged object has a weapon. [Base defense response](/systems/base-attacked/#calling-defenders-back) gives the full list of refusals, which objects qualify as defenders, and the cooldown that follows a call-up.
