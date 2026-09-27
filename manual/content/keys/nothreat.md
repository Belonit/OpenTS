---
key: NoThreat
summary: Keeps an object that is in this mission from being picked as a target by an automatic scan.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

Automatic target scans never pick an object whose current mission sets `NoThreat=yes`. The mission of the object being considered decides this, not the mission of the object doing the scan. [Why a candidate is rejected](/systems/target-selection/#why-a-candidate-is-rejected) lists the other reasons a scan passes an object over.

```ini title="rules.ini"
[Harmless]
NoThreat=yes
```

Only scans are affected. A player's attack order, a team's [Attack Waypoint](/mapping/missions/tmission-att-waypt/) mission or [retaliation](/systems/target-selection/#retaliation) can still target the object. A team's [Attack](/mapping/missions/tmission-attack/) mission picks its target by scanning, so it passes the object over too.

Damage can end the effect for an object on no team. When a vehicle, infantry or aircraft that belongs to no team survives damage from a known attacker and does not [retaliate](/systems/target-selection/#retaliation), it picks a new mission as it does when it runs out of orders. [`Zombie=yes`](/keys/zombie/) in the same section keeps it on this mission. [`Paralyzed=yes`](/keys/paralyzed/) does the same for a soldier with no target and nowhere to go, or an armed vehicle with nowhere to go. A team member does not change mission this way; it reports the damage to its team instead.

An object that retaliates switches to attacking its attacker, and the effect does not end. Once the attacker is gone, the object can return to this mission, and scans ignore it again.
