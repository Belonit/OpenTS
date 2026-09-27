---
title: Drop a Tiberium cell that can no longer spread
category: fix
release: 0.2.0
targets:
- type: system
  id: tiberium
  effect: changed
credit:
- ZivDero
---

A queued Tiberium cell that cannot spread when its turn comes is now dropped from the spread queue. This covers a cell whose Tiberium is gone or has been harvested too low, and a cell with an object standing on it. Such a cell used to use up one of the pass's spreads, and went back to the head of the queue when two or more neighboring cells could take Tiberium. A handful of harvested cells could then use up the spreads of every pass and make that Tiberium type look as though it had stopped spreading.
