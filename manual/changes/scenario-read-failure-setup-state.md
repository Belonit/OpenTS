---
title: Leave scenario setup after a scenario fails to load
category: fix
release: 0.2.0
targets: []
credit: [ZivDero]
---

A scenario that failed to load, for example because it needs an expansion that is not installed, used to leave the game marked as still setting up a scenario. Every scenario started later in the same session then ran with the setup-only rules in force. The game now leaves that state whenever a scenario fails to load.
