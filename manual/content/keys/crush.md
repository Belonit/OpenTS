---
key: Crush
summary: How close a crushable target must be before a crusher drives over it instead of shooting.
see_also: ["Crusher", "Crushable", "PlayerAutoCrush", "AutoCrush", "system:difficulty"]
when_omitted:
  kind: value
  value: "1.5"
---

The value is a distance in cells between a crusher and its target. Only computer-controlled vehicles use it, in the two decisions below. Raising the value makes them drive at targets from farther away instead of using their weapons.

A crusher is a vehicle with [`Crusher=yes`](/keys/crusher/), or one that has reached a rank whose [`VeteranAbilities=`](/keys/veteranabilities/) or [`EliteAbilities=`](/keys/eliteabilities/) list includes the crusher ability. The target must have [`Crushable=yes`](/keys/crushable/#scope-aircrafttype).

When a computer-controlled crusher moves in on its target, it drives onto the target instead of stopping at weapon range if the target is closer than this distance.

When a computer-controlled crusher that is not in a team and not docked is hit by an enemy, it drives at the attacker to run it over if **all of** these hold:

- the attacker is no farther away than this distance;
- the house's IQ is at or above [`[IQ] AutoCrush`](/keys/autocrush/#scope-global-rules);
- the house is not in difficulty slot 2, the `[Difficult]` section;
- the attacker is not infantry whose type has [`Disguised=yes`](/keys/disguised/).

With the menu's settings, a computer house takes slot 2 when the player chooses Easy, so its vehicles do not run over their attackers. [Difficulty settings and handicaps](/systems/difficulty/) covers the cases that move a computer house to another slot, such as a launch file's handicaps or [`CompEasyBonus`](/keys/compeasybonus/).
