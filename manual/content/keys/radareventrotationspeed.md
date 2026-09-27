---
key: RadarEventRotationSpeed
summary: Radians a radar event's box turns each time the screen is redrawn while it closes in.
see_also: ["system:map-visibility", RadarEventSpeed, RadarEventMinRadius]
when_omitted:
  kind: value
  value: ".1"
---

A [radar event](/reference/enums/radar-event/)'s box turns by this many radians each time the screen is redrawn while it closes in. The default of `.1` is a little under 6 degrees per redraw, a full turn in about 63 redraws. One degree is about `.017`. [`RadarEventSpeed`](/keys/radareventspeed/) sets how long the closing sweep lasts.

Once the box has shrunk to [`RadarEventMinRadius`](/keys/radareventminradius/), it settles on the first redraw on which it stands less than one step past upright. The box opens upright, and because it is square, every quarter turn from there counts as upright too. Each redraw that misses turns the box again and cuts its step by 2 percent of this value, down to a third of it. A box that has to come round another quarter turn therefore turns more slowly.

On the redraw it settles, the box turns once more by the angle it stood past upright, then stops. It can therefore come to rest tilted by up to twice its last step. Settling starts the event's [`RadarEventDurations`](/keys/radareventdurations/) and [`RadarEventVisibilityDurations`](/keys/radareventvisibilitydurations/) counts, and an event that has not settled is never removed.

:::caution[Keep the value above 0]
At `0` the box never turns and can never stand less than zero past upright, so it never settles. The event stays on the radar for the rest of the game, and a combat, harvester-attacked or enemy-sensed event goes on [suppressing](/keys/radareventsuppressiondistances/) later events of its kind nearby. A negative value turns the box the other way. It still settles, but not before the box has turned back more than a quarter turn from where it opened.
:::
