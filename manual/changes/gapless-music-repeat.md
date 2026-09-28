---
title: Repeat music tracks without a gap and let queued tracks replace them
category: fix
release: 0.2.0
targets:
- type: key
  id: Repeat
  effect: changed
- type: key
  id: IsScoreRepeat
  effect: changed
- type: system
  id: music
  effect: changed
credit: [ZivDero]
---

A repeating music track now starts over without a gap, and changing the repeat option applies to the track already playing. A repeating track started directly, such as the ion storm or main menu track, no longer blocks Play music theme trigger actions and Play music team missions.
