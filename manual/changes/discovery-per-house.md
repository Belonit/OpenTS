---
title: Record discovery the same way on every machine
category: fix
release: 0.2.0
targets:
- type: system
  id: map-visibility
  effect: changed
- type: event
  id: TEVENT_DISCOVERED
  effect: changed
- type: event
  id: TEVENT_HOUSE_DISCOVERED
  effect: changed
credit: [ZivDero]
---

In a network game, Discovered by player and House Discovered... used to depend on which player each machine was running. A trigger could run on one machine and not another, and the game could fall out of sync. Now every machine springs Discovered by player the first time a human player other than the tagged object's owner discovers that object. House Discovered... counts a house as discovered the first time a human player other than that house discovers one of its objects.
