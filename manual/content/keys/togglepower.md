---
key: TogglePower
summary: Whether the player may switch this structure on and off.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: "yes"
---

`TogglePower=no` stops the player switching the structure on or off with the power cursor. [Switching a structure off](/systems/power/#switching-a-structure-off) lists the other tests the cursor applies.

It does not keep the structure switched on. The [Turn off building](/mapping/actions/taction-turn-off-attached/) trigger action and a scenario's structure record can switch it off regardless, and the player then cannot switch it back on.

`TogglePower=no` also changes what a power shortfall does to a [`Powered=yes`](/keys/powered/) structure with drain:

- The structure stays operational, so its powered animations and lights keep running.
- Its weapons still cannot fire, and a [`SAM=yes`](/keys/sam/) launcher still stops tracking.

[Defenses](/systems/power/#defenses) defines operational and sets these tests side by side.
