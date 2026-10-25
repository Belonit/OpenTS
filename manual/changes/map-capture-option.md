---
title: Draw a map to a PNG with -CAPTUREMAP
category: feature
release: 0.2.0
targets:
- type: command
  id: launch:capture-map
  effect: added
- type: command
  id: launch:capture-output
  effect: added
credit: [ZivDero]
---

The `-CAPTUREMAP=` and `-CAPTUREOUT=` launch options draw one map's LocalSize area as the scenario starts, with the map's own lighting and no shroud or interface, and write it as a PNG. The run shows no window, console or dialog and reports success or failure through its exit code, so a script can regenerate lobby previews for a whole map pack.
