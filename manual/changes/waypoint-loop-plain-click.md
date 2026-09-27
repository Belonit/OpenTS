---
title: Close a waypoint loop with a plain click
category: feature
release: 0.2.0
targets:
- type: command
  id: WaypointMode
  effect: changed
- type: system
  id: waypoint-paths
  effect: added
credit: [ZivDero, dkeeton]
---

In waypoint mode, a plain click on an earlier waypoint of the selected path now closes the loop there, as long as the path is not already a loop and is below its waypoint limit. Closing a loop used to need Shift, and a plain click picked the waypoint up to move it; Shift-click now picks it up. A plain click still picks up the path's last waypoint, any waypoint of another path, and any waypoint of a path that is already a loop or at its limit.

dkeeton is credited for the ts-patches change this follows.
