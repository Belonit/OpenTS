---
title: Stop the score screen crashing with more than eight scoring houses
category: fix
release: 0.2.0
targets:
- type: system
  id: multiplayer-score-screen
  effect: changed
credit: [ZivDero]
---

A full eight-player match on a map that sets [`MultiplayPassive=no`](/keys/multiplaypassive/) for `Neutral` or `Special` no longer crashes the game when the score screen opens. The screen now lists eight houses at most, and houses past the eighth are not listed.
