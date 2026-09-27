---
title: Stop holds units in place instead of pausing their order
category: feature
release: 0.2.0
targets:
- type: command
  id: StopObject
  effect: changed
credit: [ZivDero, dkeeton]
---

The Stop command now puts every stopped object except aircraft on guard where it stands. Before, only a harvesting harvester was put on guard. Any other stopped unit lost its destination and target but kept its order, so a unit on area guard walked back to its guard spot, a hunting unit found a new target, and a transport went on unloading. Aircraft still keep their order.

dkeeton is credited for the ts-patches change this follows.
