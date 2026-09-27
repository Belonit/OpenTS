---
title: Test defense prerequisites against the acted side's towers
category: fix
release: 0.2.0
targets:
- type: key
  id: WallTower
  effect: changed
- type: key
  id: AIWallTowers
  effect: changed
- type: system
  id: ai-base-building
  effect: changed
credit: [ZivDero]
---

`WallTower` under `[General]` in `rules.ini` names the wall tower type, and `AIWallTowers` in a side's `rules.ini` section lists the towers that side's computer houses build. When a computer house chose a base defense, it used to ignore an owned tower of the `WallTower` type if the `AIWallTowers` of the side its country belongs to left that type out. It then passed over every defense that required that tower. The owned tower now meets the prerequisite.
