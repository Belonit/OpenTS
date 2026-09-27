---
key: RepairRate
summary: The interval between structure repair steps, and the interval self-healing falls back to.
see_also: ["SelfHealRate", "system:repair"]
when_omitted:
  kind: value
  value: ".016"
---

```ini title="rules.ini"
[General]
RepairRate=.1   ; one repair step every 90 frames
```

A structure under repair gains one repair step per interval, and this key sets the interval. The value is a fraction of a minute: the game multiplies it by 900 frames and truncates, so the default gives one step every 14 frames. Steps fall on fixed frames of the game clock, not on a count from when each repair started, so every structure under repair steps on the same frames. [The repair tick](/systems/repair/#the-repair-tick) describes each step.

[Self-healing](/systems/repair/#self-healing) uses the same interval unless another key sets one: [`SelfHealRate`](/keys/selfhealrate/) for every type, or [`SelfHealingRate`](/keys/selfhealingrate/) for one type. A service depot uses [`URepairRate`](/keys/urepairrate/) instead, and a hospital or armory uses [`IRepairRate`](/keys/irepairrate/).

:::danger[Keep `RepairRate` at `1/900` or above]
Any value between `-1/900` and `1/900` (about `0.0011`), including `0`, crashes the game on the first frame a structure is under repair. Self-healing treats such a value as one frame and does not crash.
:::
