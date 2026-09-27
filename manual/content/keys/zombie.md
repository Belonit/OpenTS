---
key: Zombie
summary: Holds an object on this mission when it runs out of things to do, and after damage if the mission is also marked no threat.
see_also: [NoThreat, Paralyzed, Retaliate]
when_omitted:
  kind: value
  value: "no"
---

`Zombie=yes` keeps an object on its current mission in two cases where it would otherwise pick a new one. The setting is read from the mission the object is currently in.

```ini title="rules.ini"
[Sleep]
Zombie=yes
```

**After damage on a no-threat mission.** A vehicle, infantry or aircraft that belongs to no team normally leaves a [`NoThreat=yes`](/keys/nothreat/) mission when it survives damage from a known attacker and does not retaliate. With `Zombie=yes` it stays, and scans go on ignoring it.

**When it runs out of orders.** A soldier with no target and nowhere to go, or a vehicle with a primary weapon and nowhere to go, stays on this mission. Without the setting it is given Guard or Area Guard. This case works exactly like [`Paralyzed=yes`](/keys/paralyzed/), which lists the objects it does not affect.

The setting does not stop the object from fighting back. An object allowed to [retaliate](/systems/target-selection/#retaliation) switches to attacking its attacker. Set [`Retaliate=no`](/keys/retaliate/) on the same mission to prevent that.
