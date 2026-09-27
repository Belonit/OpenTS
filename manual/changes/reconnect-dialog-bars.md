---
title: Draw every player's connection bar in its own box
category: fix
release: 0.2.0
targets:
- type: system
  id: reconnect-dialog
  effect: changed
credit:
- ZivDero
---

In the reconnect dialog, the second player's connection bar was drawn in the first player's box, and the second player's box stayed empty. Each player's bar now appears in that player's own box.
