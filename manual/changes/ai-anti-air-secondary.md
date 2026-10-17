---
title: Computer houses count anti-aircraft secondary weapons
category: fix
release: 0.2.0
targets:
- type: system
  id: ai-base-building
  effect: changed
credit: [ZivDero, Rampastring]
---

The computer rated an object as an anti-aircraft threat only by its first weapon, so an object whose second weapon alone could hit aircraft counted as no air defense. When the first weapon cannot hit aircraft, the rating now comes from the second weapon. This affects how a computer house stations new units and scores its base defense zones.

Rampastring is credited for the Vinifera fix this follows.
