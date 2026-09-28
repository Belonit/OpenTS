---
title: Play music tracks from WAV, OGG, FLAC and MP3 files, and set each track's file and loudness
category: feature
release: 0.2.0
targets:
- type: key
  id: Sound
  effect: added
- type: key
  id: Volume
  effect: added
  scope: themes
- type: format
  id: theme-ini
  effect: changed
credit: [ZivDero, CCHyper]
---

A music track now plays a `.WAV`, `.OGG`, `.FLAC` or `.MP3` file as well as an `.AUD` file, found by the same search and in the same order as sound effect samples. THEME.INI's new `Sound=` names a track's file when it differs from the track's ID, and `Volume=` sets how loud the track plays.

CCHyper is credited for the Vinifera music loading this follows, which reads the same keys.
