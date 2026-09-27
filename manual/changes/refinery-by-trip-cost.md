---
title: Choose a refinery by what the trip really costs
category: feature
release: 0.2.0
targets:
- type: key
  id: Dock
  effect: changed
- type: system
  id: tiberium
  effect: changed
credit: [ZivDero, Rampastring]
---

A loaded harvester now heads for the nearest free refinery of any type in its [`Dock`](/keys/dock/) list; it used to take the first listed type that had a free one. It waits at a busy refinery instead when driving there and waiting takes less time than driving to a free one. The wait is estimated from the loads the harvesters there still have to unload and the drive the docking harvester has left, so it follows a mod's [`Storage`](/keys/storage/), [`Speed`](/keys/speed/) and [`HarvesterDumpRate`](/keys/harvesterdumprate/).
