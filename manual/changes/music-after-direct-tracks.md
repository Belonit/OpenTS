---
title: Keep the music going after a track started outside the playlist ends
category: fix
release: 0.2.0
targets:
- type: system
  id: music
  effect: changed
credit: [ZivDero]
---

During a game, a track that the game started outside the playlist is now followed by the next allowed track when it ends. The music used to stop for the rest of the mission. A track whose file cannot be played is now followed by the next allowed track instead of being retried every frame.
