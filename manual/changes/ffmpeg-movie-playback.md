---
title: Decode movies with FFmpeg
category: feature
release: 0.2.0
targets:
  - type: system
    id: movie-playback
    effect: changed
  - type: format
    id: vqa
    effect: changed
  - type: command
    id: fixed:skip-vqa
    effect: changed
credit:
  - Belonit
---

Movie playback now uses a static, restricted FFmpeg build. Existing VQA movies remain supported. The player searches for `.webm`, `.bik`, and `.vqa`, in that order, so Bink 1 or Matroska/WebM movies can replace an existing asset without changing its registered name. Loose files and movies in cached or uncached MIX archives use the same playback path.
