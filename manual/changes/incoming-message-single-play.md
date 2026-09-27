---
title: Play the incoming message sound once per received line
category: fix
release: 0.2.0
targets:
- type: key
  id: IncomingMessage
  effect: changed
credit: [ZivDero]
---

A chat line received from another player during a game now plays the `IncomingMessage` sound, named under `[AudioVisual]` in `rules.ini`, once. It used to play it twice.
