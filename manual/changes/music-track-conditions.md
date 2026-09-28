---
title: Limit a music track to several sides or to an expansion
category: feature
release: 0.2.0
targets:
- type: key
  id: RequiredAddon
  effect: added
  scope: themes
- type: key
  id: Side
  effect: changed
  scope: themes
credit: [ZivDero, CCHyper]
---

A music track's `Side=` now takes a list of sides, and the new `RequiredAddon=` keeps a track out of the playlist unless that expansion is running.

CCHyper is credited for the Vinifera `RequiredAddon=`, which checks whether the expansion is installed rather than running.
