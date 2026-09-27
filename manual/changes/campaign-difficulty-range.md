---
title: Hold the campaign difficulty setting to the settings it names
category: fix
release: 0.2.0
targets:
- type: key
  id: Difficulty
  effect: changed
credit: [ZivDero]
---

`Difficulty=` under `[Options]` in `sun.ini` sets the campaign difficulty. A hand-edited `3` or `4` used to be accepted, which put both the player and the computer outside the three difficulties the game defines, so the mission ran on undefined difficulty settings. A value above `2` now reads as Hard. A difficulty chosen in the game is unaffected.
