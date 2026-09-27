---
key: MaxWaypointPathLength
summary: The most waypoints one waypoint path can hold.
when_omitted:
  kind: value
  value: "15"
---

A waypoint path holds at most this many waypoints. Once the selected path is full, a click on an empty cell shows the refusal cursor and places nothing. Placing the waypoint that fills the path also ends [Waypoint Mode](/commands/waypointmode/).

A full path cannot be looped, because a path can be looped only while it can still take waypoints. A looped path, in turn, takes no more waypoints whatever its length. [Waypoint paths](/systems/waypoint-paths/) covers plotting, looping and editing.
