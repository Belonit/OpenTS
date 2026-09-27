---
title: Take the band-selection threshold from the system
category: fix
release: 0.2.0
targets:
- type: system
  id: band-selection
  effect: changed
credit: [ZivDero, dkeeton]
---

A selection box used to start once the pointer had moved more than four pixels from where the button was pressed. It now starts once the pointer has moved farther than the Windows drag distance along either axis. On a standard display that distance is four pixels; display scaling and the Windows drag setting can change it.
