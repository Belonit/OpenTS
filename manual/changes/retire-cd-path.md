---
title: Retire the -CD launch option
category: feature
release: 0.2.0
breaking: true
migration:
- Replace `-CD<path>` with `-DATADIR=<path>` for the game data directory.
- For player overrides, use `-USERDIR=<path>`; settings and saves will also be written there.
- For an additional deployment folder, add the path to `SearchPaths` under `[Paths]` in `OPENTS.INI`.
targets:
- type: command
  id: launch:cd-path
  effect: removed
credit: [ZivDero]
---

`-CD<path>` no longer adds folders for the game to search for files. The game now ignores an argument beginning with `-CD`, as it ignores any argument it does not recognize.
