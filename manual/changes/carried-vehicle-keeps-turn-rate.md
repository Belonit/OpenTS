---
title: Vehicles keep their own turn rate after a carryall drops them
category: fix
release: 0.2.0
targets:
- type: key
  id: Carryall
  effect: changed
credit: [ZivDero]
---

A vehicle carried by a carryall used to take on the carryall's turn rate and keep it after it was dropped. It now follows the carryall's facing while carried and turns at its own rate afterward.
