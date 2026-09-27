---
title: Read the game's data from a directory named on the command line
category: feature
release: 0.2.0
targets:
- type: command
  id: launch:data-directory
  effect: added
credit: [ZivDero]
---

`-DATADIR=<path>` names a directory the game reads its data from, in addition to the directory that holds the executable. `OPENTS.INI`, which describes how the data is laid out, is read from it too.

The game never writes to the data directory. One copy of the data, even in a folder the players cannot write to, can therefore serve several players who each keep their own settings and saves with `-USERDIR`. A path that is not an existing directory stops startup with an error message.
