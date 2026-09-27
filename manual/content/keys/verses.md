---
key: Verses
summary: The percentage of a weapon's damage the warhead delivers against each armor class, in armor order.
see_also: ["system:ai-base-building", "system:target-selection"]
when_omitted:
  kind: value
  value: "100%,100%,100%,100%,100%"
  note: The default is applied whenever the warhead's section is present without the key, so a later file that contains the section and omits the key restores full damage against every armor class.
---

`Verses` lists five percentages, one for each [armor class](/reference/enums/armor/) in the order `none`, `wood`, `light`, `heavy`, `concrete`. Damage from this warhead is multiplied by the entry for the target type's [`Armor`](/keys/armor/#scope-aircrafttype) class. A plain fraction such as `0.5` is accepted in place of `50%`, and entries after the fifth are ignored.

```ini title="rules.ini"
[MyShellWH] ; example WarheadType
Verses=100%,80%,60%,40%,20% ; none, wood, light, heavy, concrete
```

A `0%` entry does not make a class immune. This table never reduces a hit below one point, and targets near a blast still take [`MinDamage`](/keys/mindamage/). [What the target loses](/systems/warheads/#what-the-target-loses) gives the full order.

An empty `Verses=` counts as leaving the key out.

The same table also decides how objects armed with this warhead choose and answer targets:

- An object with two weapons prefers the one whose warhead has the higher entry against the target's class, as [Which weapon the score assumes](/systems/target-selection/#which-weapon-the-score-assumes) describes.
- The [threat score](/systems/target-selection/#the-threat-score) weighs how well each side's warhead does against the other's armor.
- An object whose chosen weapon has `0%` against its attacker's class does not [retaliate](/systems/target-selection/#retaliation).
- When the computer's base is attacked, it does not [call up](/systems/base-attacked/#which-objects-qualify) an object whose primary weapon has `0%` against the attacker's class.
- A `heavy` entry of exactly `0%` confines infantry whose primary weapon uses this warhead to [infantry targets](/systems/target-selection/#what-each-kind-of-object-considers).
- A base defense armed with this warhead takes its anti-air and anti-armor [defense values](/systems/ai-base-building/#defense-values) from the `heavy` entry, and its anti-infantry value from the `none` entry.

:::danger[Give `Verses` all five entries]
A list of one to four entries crashes the game while it reads the rules, before a match begins. Leaving the key out is safe, because the default list is used in its place.
:::
