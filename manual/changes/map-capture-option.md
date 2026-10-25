---
title: Draw maps to PNG pictures with -CAPTURE
category: feature
release: 0.2.0
targets:
- type: command
  id: launch:capture
  effect: added
- type: command
  id: launch:capture-map
  effect: added
- type: command
  id: launch:capture-output
  effect: added
- type: format
  id: capture-ini
  effect: added
credit: [ZivDero]
---

The `-CAPTURE=` launch option draws the map a description file names to a PNG picture, with the map's own lighting and no interface. The file chooses the shroud, the seated houses, the area drawn and how many game frames run first. `-CAPTUREMAP=` and `-CAPTUREOUT=` make the same capture with the default settings. The run shows no window, console or dialog and reports success or failure through its exit code, so a script can regenerate lobby previews for a whole map pack.
