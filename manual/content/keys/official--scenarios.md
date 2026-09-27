---
key: Official
scope: scenarios
label: When the value is read
when_omitted:
  kind: value
  value: "no"
---

The value applies only in a multiplayer or skirmish game. A campaign mission ignores it.

The value is read twice while the scenario loads, and both reads apply the [starting-point rule](/keys/official/#scope-scenarios-2). The first read settles which waypoint each house starts at as soon as the map's waypoints are read, before the map's objects. The second read comes when the starting units are placed, which is also when a house left without a waypoint is given open ground. Houses keep the positions they already hold, so the second read changes nothing on a map read from a file.
