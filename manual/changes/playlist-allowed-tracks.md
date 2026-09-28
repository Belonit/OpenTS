---
title: Pick only allowed music tracks when the playlist runs short
category: fix
release: 0.2.0
targets:
- type: key
  id: Normal
  effect: changed
- type: key
  id: IsScoreShuffle
  effect: changed
credit: [ZivDero]
---

When no other music track was allowed, the playlist fell back to the first track in THEME.INI even if that track had `Normal=no`, was for another side or had no file. It now plays the track that just ended if that one is allowed, and otherwise nothing. Shuffle now makes one random pick among the allowed tracks.
