---
title: Delete waypoints from the end of the selected path
category: feature
release: 0.2.0
targets:
- type: command
  id: DeleteWaypoint
  effect: changed
credit: [ZivDero, dkeeton]
---

Delete Waypoint with no waypoint picked up now removes the last waypoint of the selected path, so repeated presses take the path apart from the end. It used to do nothing unless a waypoint was picked up.

A looping path now stays a loop when a waypoint other than its last is deleted; any deletion used to open the loop. The loop keeps returning to the same waypoint when an earlier one is removed, and returns to the next waypoint when the one it returned to is removed. Removing the path's last waypoint still opens the loop.

dkeeton is credited for the ts-patches change the first part follows.
