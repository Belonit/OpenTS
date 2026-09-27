---
title: Accept launch options carrying a long or quoted path
category: fix
release: 0.2.0
targets: []
credit: [ZivDero]
---

A launch option carrying a quoted path with spaces in it used to be split at each space, so the game did not recognize it. The game now splits its command line by the standard Windows quoting rules, so a quoted path arrives as one argument.

An argument of about 125 characters or more used to crash the game as it started, and only the first nineteen arguments were read. A long argument no longer crashes the game, and every argument is read.

A search folder whose path and a file name together were longer than Windows allows used to overrun the game's memory. The game now skips that folder when looking for that file.
