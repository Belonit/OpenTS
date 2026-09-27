---
key: RepairDelay
summary: The wait a computer house takes between starting one building repair and starting the next.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: ".02"
---

After a computer house switches on repair for one of its structures, it waits before it starts another repair. The wait is a random number of frames between `RepairDelay * 225` and `RepairDelay * 1800`, so the default gives 4 to 36 frames. The wait spaces out when repairs start. It does not slow a repair already running, which steps at [`RepairRate`](/keys/repairrate/).

```ini title="rules.ini"
[Normal]
RepairDelay=.05  ; a computer house waits 11 to 90 frames between repair starts
```

Each difficulty section sets a separate value, and a house uses the one for [its difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot).

A human-controlled house has no wait. If a map gives the player's house an [`IQ`](/keys/iq/) at or above [`RepairSell`](/keys/repairsell/), that house switches on repair for its damaged structures one after another, in consecutive frames. [The computer's repair decision](/systems/repair/#when-the-computer-repairs) lists the other tests each structure must pass.

:::caution[A difficulty section in a later file resets this value]
When a later file, such as a map, contains `[Easy]`, `[Normal]` or `[Difficult]` without `RepairDelay`, that section's value returns to `.02`. The value from the rules file is not kept.
:::
