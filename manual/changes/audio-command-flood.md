---
title: Stop placed sounds from crowding out other sound commands
category: fix
release: 0.2.0
targets:
- type: system
  id: sound-effects
  effect: changed
- type: system
  id: music
  effect: changed
credit: [ZivDero]
---

On a map with several ambient or placed sounds in view, the game re-sent their unchanged volume and pan many times a frame. That filled the audio engine's command queue, so other commands were lost: a sound could keep playing after it was stopped, and a music track could keep playing instead of fading out, which held back the next track. Unchanged values are no longer sent.
