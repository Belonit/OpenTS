---
title: Mount no-side archives outside a match
category: feature
release: 0.2.0
targets:
- type: format
  id: mix
  effect: changed
- type: system
  id: ui-files
  effect: changed
credit: [ZivDero]
---

Outside a match the game now mounts `SIDEC00.MIX` and `SIDENC00.MIX`, with their expansion copies, where a side's archives go. They are optional, mounted at startup and again whenever a match ends, and replaced by the player's side while a match runs. A mod can keep side-dependent interface pictures and fonts in the side archives, with a neutral copy in these for the menus.

When a match ends and the menus return, the player's side is now cleared, so the menus no longer take the last side's style sheet or archives.
