---
key: URepairRate
summary: The interval between the repair steps a service depot applies to the vehicle or aircraft docked with it.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: ".016"
---

`URepairRate` is the time between a service depot's repair steps, in minutes of game time. The first step comes as soon as the object parks. After each step, the depot counts one per frame and takes the next step once the count reaches `URepairRate` times 900, the number of frames in a game minute. At the default `.016`, steps fall 15 frames apart.

```ini title="rules.ini"
[General]
URepairRate=.033  ; about one repair step every 30 frames
```

The setting controls only the timing. Despite its name, it sets no step size: each step restores [`RepairStep`](/keys/repairstep/) strength, at a cost worked out with the structure repair formula from the vehicle's or aircraft's `Cost` and `Strength`. [One step at a time](/systems/repair/#one-step-at-a-time) describes each step and its cost.
