---
title: Play each campaign's own intro
category: fix
release: 0.2.0
targets:
- type: system
  id: campaign-progression
  effect: changed
credit: [ZivDero, CCHyper, tomsons26]
---

A campaign's introduction movie is now `INTR<n>.VQA`, where `n` is the `CD=` value in the campaign's section of `battle.ini`, and `INTRO.VQA` plays when that file is missing. Every campaign used to play `INTRO.VQA`, so a deployment holding both original campaigns showed the same introduction for each. As before, it plays when a campaign's first mission starts, not when the mission restarts, and only for a campaign whose `CD=` is below `2`.

The main menu's Intro / Sneak Peek item now plays `INTR0.VQA` when that file is present, and `INTRO.VQA` otherwise.

CCHyper and tomsons26 are credited for the Vinifera `IntroMovie` key, which reaches the same end by another route.
