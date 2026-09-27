---
key: HarvesterLoadRate
summary: Game frames per step of a harvester's loading cycle, which lifts one unit every nine steps.
see_also: ["system:tiberium", "HarvesterDumpRate"]
when_omitted:
  kind: value
  value: "2"
---

A harvester on Tiberium lifts one growth stage from the cell, and stores it as one unit, every 9 times this many frames. The default `2` lifts one unit every 18 frames; higher values slow harvesting.

```ini title="rules.ini"
[General]
HarvesterLoadRate=1   ; one unit every 9 frames
```

A weeder harvests a whole vein cell at once and then waits 27 times this many frames, three times as long, before it moves on. [Finding and loading](/systems/veins/#finding-and-loading) gives its full timing.
