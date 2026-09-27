---
title: Plant each player's starting tiberium on their own start point
category: fix
release: 0.2.0
targets:
- type: key
  id: TiberiumLayout
  effect: changed
credit: [ZivDero]
---

On a generated random map, the extra Tiberium field each player gets at their start point now grows from that player's own start waypoint. OpenTS 0.1.0 put each field on the next player's waypoint, so the first player got no field. The last player's field went to an unset waypoint, which tripped an assertion in a debug build and grew the field from cell 0,0 in a release build.
