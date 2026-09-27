---
key: AltHomeCell
summary: The waypoint the view opens on instead, when the first global flag is set.
see_also: [HomeCell]
when_omitted:
  kind: value
  value: "98"
---

```ini title="map file"
[Basic]
HomeCell=98
AltHomeCell=42
```

The view opens on this waypoint in place of [`HomeCell`](/keys/homecell/) when global flag `0` was set at the moment the player won the previous campaign mission. A campaign can use it to start the player looking somewhere else because of what happened earlier. The value is a waypoint number, read the same way as [`HomeCell`](/keys/homecell/).

The choice is settled as the map loads, so nothing in this mission can change it. Setting global flag `0` during this mission affects only the next one.

Place the waypoint this key names. Unlike [`HomeCell`](/keys/homecell/), an unplaced alternate gets no fallback cell, and the view opens on cell `0,0`, the corner of the map. A Debug build stops at a failed assertion instead.

Keep the value between `0` and `100`. A number outside that range reads outside the waypoint table, and the view opens on an unpredictable cell. A Debug build stops at a failed assertion instead.

In multiplayer and skirmish games the view opens on the player's own forces, so this key has no effect there.
