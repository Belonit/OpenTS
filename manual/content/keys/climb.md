---
key: Climb
summary: The leptons of altitude a jumpjet unit gains or loses each game frame.
see_also: [CruiseHeight, WobbleDeviation]
when_omitted:
  kind: value
  value: "5"
---

```ini title="rules.ini"
[JumpjetControls]
Climb=10 ; reaches a 400-lepton cruise height in 40 frames
```

`Climb` sets how far a jumpjet rises or sinks in one frame to reach the height it wants. The distance is in leptons, 256 to a cell. At the default `5`, a jumpjet takes 80 frames, a little over five seconds at 15 frames a second, to climb to the default [`CruiseHeight`](/keys/cruiseheight/) of `400`.

Use a whole number. A jumpjet's height is kept in whole leptons, so a climb drops the fraction and a descent rounds it up. `Climb=5.5` climbs 5 leptons a frame and descends 6. A value below `1` never climbs at all.

A descent stops at ground level. A climb has no such limit, so the jumpjet can rise up to one step past its flight level and sink back on the next frame. That overshoot adds to the bobbing of a hovering jumpjet.

`Climb` also sets how quickly a jumpjet lifts over terrain and structures. While moving, a jumpjet raises the height it wants to clear the cell ahead. It also slows down while it is well below that height. A small value therefore makes a jumpjet slow down and climb late at each obstacle.
