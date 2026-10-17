---
title: A failed undeploy leaves no hidden vehicle behind
category: fix
release: 0.2.0
targets:
- type: key
  id: UndeploysInto
  effect: changed
credit: [ZivDero]
---

When a structure undeployed and its vehicle could not be placed, the house received the refund but also kept an unseen vehicle that never appeared on the map. The vehicle is now removed, and the refund is unchanged.
