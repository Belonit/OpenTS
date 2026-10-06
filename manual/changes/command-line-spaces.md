---
title: Accept launch options carrying a long or quoted path
category: fix
release: 0.2.0
targets: []
credit: [ZivDero]
---

Quoted paths with spaces now reach the game as one argument. Long arguments no longer crash startup, and arguments after the nineteenth are no longer ignored.

A search path too long for Windows is skipped instead of overrunning memory.
