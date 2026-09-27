---
title: Read a malformed number as its default instead of keeping garbage
category: fix
release: 0.2.0
targets:
- type: format
  id: ini-syntax
  effect: changed
credit: [ZivDero]
---

A floating-point number, point, offset, vector, color or rectangle whose value does not start with a number, or holds fewer numbers than the key needs, now reads as the key's default: the value the key takes when it is absent. The debug log records the file, section, key and value. The game used to leave the missing numbers of most such values undefined, which could stop it while it read the rules or give a color random channels.
