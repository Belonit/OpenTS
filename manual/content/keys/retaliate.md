---
key: Retaliate
summary: Whether an object in this mission fires back at whatever damages it.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "yes"
---

At `Retaliate=no`, an object on this mission does not [retaliate](/systems/target-selection/#retaliation) when it is damaged, so it does not switch to attacking its attacker. The setting is read from the mission the damaged object is currently in.

```ini title="rules.ini"
[Sleep]
Retaliate=no
```

On a mission that also sets [`NoThreat=yes`](/keys/nothreat/), damage can still change the object's mission. A vehicle, infantry or aircraft on no team that is damaged by a known attacker picks a new mission as it does when it runs out of orders, unless the mission also sets [`Zombie=yes`](/keys/zombie/).

An object refused retaliation can still [scatter](/systems/target-selection/#scattering-after-damage) if the mission's [`Scatter`](/keys/scatter/#scope-mission-behavior) allows it.

A [`Veinhole=yes`](/keys/veinhole/) warhead ignores this setting. An object damaged by one still retaliates, unless a human player owns it and it already has a target or a destination. When the damage has no known attacker, the object targets the veinhole monster that owns the veins under it or at the point it is moving to, if there is one. The usual range rules for [retaliation](/systems/target-selection/#retaliation) apply to the monster as to any attacker.

`Retaliate=no` does not stop a structure from targeting its attacker through [the separate check for damaged buildings](/systems/target-selection/#a-damaged-building).
