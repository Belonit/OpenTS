---
title: Show the written briefing when a mission has no briefing movie
category: feature
release: 0.2.0
targets:
- type: key
  id: Brief
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
credit:
- ZivDero
- Rampastring
- CCHyper
- dkeeton
---

A campaign mission whose `Brief` in `[Basic]` names no movie, or a movie whose file is missing, now opens with its written briefing, the page the options menu's Restate Briefing button shows during play. The track named by the mission's `Theme` plays behind the page. Only a fresh start shows the page; a restart, and the replay offered after a loss, go straight to the map.
