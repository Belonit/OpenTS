---
title: Keep Play Sound Effect At sounds at their waypoint
category: feature
release: 0.2.0
targets:
- type: action
  id: TACTION_PLAY_SOUND_AT
  effect: changed
- type: format
  id: save-games
  effect: changed
credit: [ZivDero]
---

A looping sound started by Play Sound Effect At now follows the view. It fades as the view scrolls away from the waypoint, falls silent out of range, and starts again when the waypoint comes back into range, skipping the sound's opening attack samples. Its volume used to be set once, when the trigger fired.

A looping sound started this way is now kept in a saved game and resumes when the game is loaded. A one-shot sound plays once, as before.
