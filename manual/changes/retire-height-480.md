---
title: Retire the -480 launch option
category: feature
release: 0.2.0
breaking: false
targets:
- type: command
  id: launch:height-480
  effect: removed
credit: [ZivDero]
---

`-480` is no longer a separate launch option. The resolution option still reads it, so it sets the initial screen width to 480 pixels as before.
