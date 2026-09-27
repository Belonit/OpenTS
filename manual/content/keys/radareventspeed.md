---
key: RadarEventSpeed
summary: Pixels of the radar pane a radar event's box loses from its radius each time the screen is redrawn.
see_also: ["system:map-visibility", RadarEventMinRadius, RadarEventRotationSpeed]
when_omitted:
  kind: value
  value: "1"
---

A [radar event](/reference/enums/radar-event/) opens as a box around the flagged cell, with its corners as far from that cell as the pane's furthest edge. Each time the screen is redrawn, the distance from the cell to the box's corners shrinks by this many pixels, until it reaches [`RadarEventMinRadius`](/keys/radareventminradius/). A larger value closes the box faster: the sweep lasts one redraw for each step of this size between the opening distance and that floor.

The screen is redrawn once every game frame while the game window has focus, and again while the game waits for the next frame. The sweep therefore takes less game time on a faster machine or at a slower game speed. While the game window is out of focus or an in-game menu is open, the box does not move.

The box can settle only after it reaches the floor. The event's [`RadarEventDurations`](/keys/radareventdurations/) and [`RadarEventVisibilityDurations`](/keys/radareventvisibilitydurations/) counts start when it settles, and an event that has not settled is never removed.

:::caution[Keep the value above 0]
At `0` the box never shrinks, and a negative value makes it grow. Unless `RadarEventMinRadius` is large enough to catch the box on its first redraw, the box never settles. Every event then stays on the radar for the rest of the game, and each combat, harvester-attacked or enemy-sensed event goes on [suppressing](/keys/radareventsuppressiondistances/) later events of its kind nearby.
:::
