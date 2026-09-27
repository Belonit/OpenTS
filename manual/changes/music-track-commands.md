---
title: Skip to the previous or next music track from the keyboard
category: feature
release: 0.2.0
targets:
- type: command
  id: PrevTheme
  effect: added
- type: command
  id: NextTheme
  effect: added
credit: [ZivDero, CCHyper]
---

Two commands play the previous or next music track, wrapping at either end of the list, and name the new track on screen for four seconds. They skip a track whose file is missing, one marked `Normal=no` in `theme.ini`, one reserved for another side, and in a campaign one the current mission has not yet unlocked. Neither command has a default key.

CCHyper is credited for the Vinifera commands this follows.
