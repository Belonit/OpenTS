---
title: Preserve full color in full-screen movies
category: feature
release: 0.2.0
targets:
- type: format
  id: vqa
  effect: changed
credit:
- Belonit
---

Full-screen movies now retain 32-bit color through presentation instead of being reduced to RGB565 first. Movies embedded in the radar pane and mission screens remain RGB565 to match those surfaces.
