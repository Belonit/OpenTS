---
key: Veinhole
summary: Lets an object damaged with no credited attacker fire back at the veinhole monster that owns the veins under it or just ahead of it.
see_also: ["system:veins", "VeinholeWarhead", "Retaliate"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[VeinholeWH] ; the WarheadType named by [CombatDamage] VeinholeWarhead
Veinhole=yes
```

`Veinhole=yes` lets an object damaged by this warhead fight back even when no attacker is credited with the damage. [Vein damage](/systems/veins/#standing-in-veins) credits none. With no credited attacker, the object turns on the veinhole monster that owns the veins in the cell it stands in, or in the cell it is moving into if it is moving. If no monster owns veins there, it attacks nothing.

Whether the object fights back depends on its owner:

- A computer-owned object always does.
- A player-owned object does only while it has no target and no movement order. One that is already attacking something, or is on its way somewhere, does not fight back.

A player-owned object also needs the monster within its weapon range or its sight. [Retaliation](/systems/target-selection/#retaliation) gives the range rule.

:::caution[Set the flag only on the vein warhead]
The owner rules above replace the usual retaliation checks. On a warhead that a weapon fires, the flag makes its victims turn on the credited attacker even when that attacker is an ally, when the victim's mission forbids retaliation, and when the victim has no weapon that can hurt the attacker.
:::
