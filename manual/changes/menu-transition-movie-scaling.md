---
title: Keep menu transition movies at their original size
category: fix
release: 0.2.0
targets:
- type: key
  id: StretchMovies
  effect: changed
credit:
- Belonit
---

`TS_TITLE.VQA` and `FS_TITLE.VQA` now retain their original size when they fit the display, even when `StretchMovies` is enabled. Any full-screen movie larger than the display is still scaled down to fit.
