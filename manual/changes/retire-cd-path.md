---
title: Retire the -CD launch option
category: feature
release: 0.2.0
breaking: true
migration:
- Replace `-CD<path>` with `-DATADIR=<path>` where the path holds the game's data.
- Replace it with `-USERDIR=<path>` where the path held your own files that replace the game's. The game looks in that directory before any other, so those files still take precedence, and it also writes its settings and saved games there.
- Add the folder to `SearchPaths` under `[Paths]` in the deployment's `OPENTS.INI` where it is one of several folders the game should always search.
targets:
- type: command
  id: launch:cd-path
  effect: removed
credit: [ZivDero]
---

`-CD<path>` no longer adds folders for the game to search for files. The game now ignores an argument beginning with `-CD`, as it ignores any argument it does not recognize.
