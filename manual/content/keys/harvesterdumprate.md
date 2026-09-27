---
key: HarvesterDumpRate
summary: Minutes a docked harvester spends handing over each stored unit.
see_also: ["system:tiberium", "HarvesterLoadRate", "Storage"]
when_omitted:
  kind: value
  value: ".016"
---

A docked harvester hands its house one stored unit each time this many minutes of game time pass. A minute is 900 frames, and the wait is rounded up to whole frames: the default `.016` gives 14.4, so one unit every 15 frames. Weeders unload at the same rate.

```ini title="rules.ini"
[General]
HarvesterDumpRate=.03   ; one unit every 27 frames
```

The same rate sets how long a returning harvester expects to wait at a busy refinery. It compares that wait with the extra drive to a free one when it [chooses where to unload](/systems/tiberium/#unloading).
