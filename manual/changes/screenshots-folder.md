---
title: Save screenshots as PNG in a folder of their own
category: feature
release: 0.2.0
targets:
- type: command
  id: ScreenCapture
  effect: changed
credit:
- ZivDero
- Rampastring
- dkeeton
---

Screen captures are now saved as PNG files in a `Screenshots` folder, beside the game or in the user directory when one is named. They used to be PCX files saved beside the game. Captures from earlier releases are not moved.

A capture now shows the frame at the resolution the game renders, whatever the window size. It used to be scaled and offset at some window sizes.

Rampastring and dkeeton are credited for the ts-patches patches that first moved captures into a folder and saved them as PNG.
