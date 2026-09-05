---
title: Keep movie video synchronized to audio
category: fix
release: 0.2.0
targets:
- type: format
  id: vqa
  effect: changed
credit:
- Belonit
---

Movies with audio now use its playback position to schedule video frames. A late video frame is skipped once its display interval has passed instead of letting the picture drift behind the sound.
