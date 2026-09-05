---
title: Preserve full color in full-screen movies
category: feature
release: 0.2.0
targets:
- type: system
  id: movie-playback
  effect: changed
credit:
- Belonit
---

Full-screen movies now retain 32-bit color through presentation instead of being reduced to RGB565 first. Movies in the radar pane remain RGB565 to match its surface.
