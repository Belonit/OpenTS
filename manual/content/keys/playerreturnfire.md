---
key: PlayerReturnFire
summary: Lets human-owned objects fire back automatically outside the guard missions.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[CombatDamage]
PlayerReturnFire=yes
```

At `no`, a player's vehicle, infantry or aircraft fires back at its attacker only while its mission is Guard, Area Guard or Patrol. Damage taken while it moves, attacks, harvests or follows any other mission goes unanswered. At `yes` the mission no longer matters, and the object fires back whenever it passes [the other retaliation tests](/systems/target-selection/#retaliation).

A player's structure is not held to that mission rule, but the setting decides whether it [targets its attacker directly](/systems/target-selection/#a-damaged-building). At `no`, a damaged structure that could fire back turns to a random facing instead. At `yes` it targets the attacker, unless the attacker is an aircraft.

Computer-owned objects and structures are never held back by this setting.
