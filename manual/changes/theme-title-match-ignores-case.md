---
title: Track titles match without regard to letter case
category: fix
release: 0.2.0
targets:
- type: key
  id: Theme
  effect: changed
credit: [ZivDero, CCHyper]
---

A value that names a track, such as a scenario's `Theme=`, falls back to matching text within each track's displayed title when no track ID matches. That fallback used to require the same letter case as the title. It now ignores case, as the ID match already did.

CCHyper is credited for the Vinifera fix this follows.
