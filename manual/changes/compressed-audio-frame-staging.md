---
title: Decode compressed audio frames in isolation
category: fix
release: 0.2.0
targets:
- type: format
  id: aud
  effect: changed
credit:
- ZivDero
---

A sound effect that started while the music track or another compressed sound was decoding its next block could turn that other sound into loud static until it ended. Each sound now decodes on its own, so a new sound effect no longer affects one already playing. A compressed block whose sizes exceed the decoder's limits now ends the sample before that block, as a block without the marker does.
