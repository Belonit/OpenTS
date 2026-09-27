---
title: Read the base and expansion sound and theme files together
category: feature
release: 0.2.0
targets:
- type: format
  id: sound-ini
  effect: changed
- type: format
  id: theme-ini
  effect: changed
breaking: true
migration:
- 'Check a deployment that ships both a base file and its expansion counterpart: both are now read.'
credit:
- ZivDero
---

Startup now reads both `SOUND.INI` and `SOUND01.INI`, and both `THEME.INI` and `THEME01.INI`, whether or not Firestorm is installed. The expansion file is read second, so a key both files set takes the expansion's value, and a key only the base file sets is kept. A game with Firestorm installed used to ignore `SOUND.INI` entirely, and one without it ignored `THEME01.INI`.

One file of each pair is now enough, so a deployment that ships only the expansion's sounds or themes starts. Startup stops only when neither file of a pair can be read.
