---
title: Do not repeat a music track the game does not have
category: fix
release: 0.2.0
targets:
- type: key
  id: Repeat
  effect: changed
credit: [ZivDero]
---

A repeating music track whose audio file was missing was tried again on every frame, and the game played no music until the player chose a track by hand. This affected a track set to restart when it ends with `Repeat=yes` in its `theme.ini` section, and any track while the sound options' repeat setting was on. During a game, another track from the playlist now plays instead.
