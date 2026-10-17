---
title: Accept Verses lists shorter than five entries
category: fix
release: 0.2.0
targets:
- type: key
  id: Verses
  effect: changed
credit: [ZivDero]
---

A `Verses=` list of one to four entries used to crash the game while it read the rules. Such a list now sets only the armor classes it reaches, and the remaining classes keep their earlier values.
