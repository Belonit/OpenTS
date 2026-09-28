---
title: Set the music fade-out time and crossfade queued tracks
category: feature
release: 0.2.0
targets:
- type: key
  id: FadeOut
  effect: added
- type: key
  id: CrossFade
  effect: added
- type: system
  id: music
  effect: changed
credit: [ZivDero, CCHyper]
---

THEME.INI's `[General]` section now takes `FadeOut=`, the time a track takes to fade out, and `CrossFade=`, which starts a queued track at once and fades it in while the current track fades out.

CCHyper is credited for Vinifera's `FadeOutSeconds=`, `CrossFading=` and `CrossFadeSeconds=`, which these follow.
