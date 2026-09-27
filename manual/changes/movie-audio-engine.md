---
title: Play movie sound through the audio engine
category: feature
release: 0.2.0
targets:
- type: format
  id: vqa
  effect: changed
- type: key
  id: SoundLatency
  effect: changed
credit: [ZivDero]
---

A movie's sound now plays through the game's audio engine, the one that plays sound effects and music, and the game no longer uses DirectSound. The picture still follows the sound as the speakers play it, and keeps moving at normal speed while the sound stalls. `SoundLatency` under `[Audio]` in `sun.ini`, which corrected movie timing for the delay of emulated DirectSound drivers, is still read and saved but no longer has any effect.
