---
title: Remove the SoundLatency setting
category: feature
release: 0.2.0
targets:
- type: key
  id: SoundLatency
  effect: removed
credit:
- Belonit
---

`SoundLatency` no longer affects movie playback and is no longer written to
`sun.ini`. Existing entries are ignored.
