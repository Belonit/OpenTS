---
key: TargetLaserTime
summary: Frames the sighting laser stays drawn after a vehicle fires.
see_also: ["system:action-lines", TargetLaser, TargetLaserColor]
when_omitted:
  kind: value
  value: "15"
---

Each time one of the player's vehicles with [`TargetLaser=yes`](/keys/targetlaser/) fires, its sighting laser is drawn for this many game frames. Every new shot restarts the count, so a vehicle that keeps firing keeps its laser up. `0` or a negative value hides the laser entirely.

Because the count is in game frames, the laser stays up longer in real time at a slower game speed. [Action lines](/systems/action-lines/) covers which vehicles draw the laser and when it disappears early.

```ini title="UI.INI"
[Ingame]
TargetLaserTime=30
```
