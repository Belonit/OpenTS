---
key: Rate
scope: mission-behavior
label: Mission servicing delay
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: ".016"
---

`Rate=` sets how often an object on this mission runs the mission's logic again. The value is a fraction of a minute of game time. The game multiplies it by 900 and drops any fraction to get the interval in game frames, so the default `.016` gives 14 frames. The game stores the value with limited precision, so a value meant to land on a whole frame count can come out one frame lower: `.030` gives 26 frames, not 27. Many missions add a random 0 to 2 frames to each interval.

Each mission reads its own `Rate=`, from its section such as `[Guard]` or `[Repair]`.

```ini title="rules.ini"
[Guard]
Rate=.050  ; 45 frames between passes
```

Work that a mission counts in passes slows down or speeds up with this setting. The visible case is the armory, whose promotion count advances once per `[Repair]` pass; see [Hospitals and armories](/systems/repair/#hospitals-and-armories).

[`AARate`](/keys/aarate/) in the same section is the interval an armed structure on guard uses instead. When `AARate` is absent or `0`, it takes this value.
