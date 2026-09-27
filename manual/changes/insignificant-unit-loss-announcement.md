---
title: Say nothing when an insignificant unit dies
category: fix
release: 0.2.0
targets:
- type: key
  id: Insignificant
  effect: changed
- type: command
  id: CenterOnRadarEvent
  effect: changed
credit:
- ZivDero
- Iran
---

When one of the player's vehicles, infantry or aircraft dies and its type sets `Insignificant=yes` in `rules.ini`, EVA no longer announces a lost unit, and the Goto Radar Event command no longer jumps to where it died. The hunter seeker is the shipped case: every launch used to be announced as a lost unit.
