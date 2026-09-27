---
key: WaypointAnimationSpeed
summary: Interval between frame changes in the marker drawn on a plotted waypoint.
see_also: [MaxWaypointPathLength]
when_omitted:
  kind: value
  value: "12"
---

```ini title="rules.ini"
[AudioVisual]
WaypointAnimationSpeed=10 ; the value the stock rules.ini sets
```

Lower values animate the markers on a plotted waypoint path faster. A plotted waypoint path is the move route a player lays down during play, not a waypoint stored in a map file. Every marker cycles through the waypoint cursor's frames, all showing the same frame, and the frame advances each time this interval runs out.

The interval counts system ticks of 16 milliseconds, not game frames, so the animation runs at the same rate at any game speed. The default of 12 advances the frame about every fifth of a second. The frame can advance at most once per game frame, so any value that runs out within one frame gives one step per frame. At 15 frames a second that limit is reached at about 4, and `0` reaches it too.

The value changes only the animation. It does not affect how far or how fast anything moves along the path. [`MaxWaypointPathLength`](/keys/maxwaypointpathlength/) covers how many markers a path may hold.
