---
title: Honor the scrap debris option
category: feature
release: 0.2.0
targets:
- type: key
  id: ScrapExplosion
  effect: added
- type: key
  id: ScrapMetal
  effect: added
- type: format
  id: spawn-ini
  effect: changed
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, Rampastring]
---

`ScrapMetal=yes` in `[Settings]` of the client launch file, `SPAWN.INI`, makes a destroyed object play the animations its type lists in `ScrapExplosion=` instead of those in `Explosion=`. A type with no `ScrapExplosion=` list keeps its `Explosion=` animations, so a ruleset can convert part of its arsenal at a time. The setting applies to campaign missions as well as matches, and a campaign mission can set or override it with `ScrapMetal=` in its `[SpecialFlags]` section.
