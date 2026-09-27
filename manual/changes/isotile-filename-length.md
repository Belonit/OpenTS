---
title: Keep the whole file name on an isometric tile type
category: fix
release: 0.2.0
targets:
- type: key
  id: FileName
  effect: changed
credit: [ZivDero]
---

The `FileName` stem that names a tile set's artwork files, in a `[TileSetNNNN]` section of a theater control file such as `TEMPERAT.INI`, can now be up to 63 characters long. A stem of eight or more characters, or seven for a lettered alternate tile, used to be stored incompletely, so the tile's artwork could fail to load.
