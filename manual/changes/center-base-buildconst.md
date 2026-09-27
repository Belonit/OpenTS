---
title: Center Base finds any construction yard type
category: fix
release: 0.2.0
targets:
- type: command
  id: CenterBase
  effect: changed
credit: [ZivDero]
---

Center Base used to find only the construction yard the base unit deploys into, so a base built around another construction yard type could center on some other structure. It now centers on any structure whose type is in `BuildConst`, the construction yard list under `[AI]` in `rules.ini`, and prefers the primary one.
