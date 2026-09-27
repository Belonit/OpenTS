---
key: HomeCell
summary: The waypoint a single-player mission's view opens on and its bookmarks start at.
see_also: [AltHomeCell]
when_omitted:
  kind: value
  value: "98"
---

```ini title="map file"
[Basic]
HomeCell=98
```

The value is a waypoint number, not a cell number. It names an entry of the map's `[Waypoints]` section, and a single-player mission opens with the view centered on that waypoint's cell. All four view bookmarks start at the same cell, so pressing one before storing a position returns there. The default, `98`, is the number the game sets aside for the home waypoint.

If the map places no waypoint with this number, the engine places it at the center of the [playfield](/glossary/#playable-area) and opens the view there.

When a mission starts with global flag `0` set, the view opens on [`AltHomeCell`](/keys/althomecell/) and this key is not used.

In skirmish and multiplayer games, the view opens over the player's own starting objects, and this key does not move it.

:::danger[Keep the waypoint number between 0 and 100]
The waypoint table holds numbers `0` through `100`. A number outside that range counts as an unplaced waypoint, so the engine writes the fallback cell outside the table, over other scenario data, in every game mode. A number far outside the range can crash the game. A Debug build stops at a failed assertion first.
:::
