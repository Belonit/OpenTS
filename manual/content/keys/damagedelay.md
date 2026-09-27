---
key: DamageDelay
summary: Minutes between the damage ticks a house takes while it is short of power.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: "1"
---

`DamageDelay` sets the interval, in game minutes, between damage ticks on the structures of a house that is short of power. A smaller value means more frequent damage. One game minute is 900 frames.

The first tick lands up to one `DamageDelay` after a shortfall begins, and a shortfall that ends before then costs nothing. [The structure damage tick](/systems/power/#the-structure-damage-tick) covers which structures take damage.

```ini title="rules.ini"
[General]
DamageDelay=0.25   ; ticks 15 seconds apart
```
