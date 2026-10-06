---
title: Honor a map's MaxPlayers setting
category: fix
release: 0.1.0
targets:
- type: key
  id: MaxPlayers
  effect: added
credit: [ZivDero, tomsons26]
---

A multiplayer map listing now reads `MaxPlayers` instead of using `MinPlayers` for both counts. The listing can declare different minimum and maximum player counts; neither count is enforced when joining.
