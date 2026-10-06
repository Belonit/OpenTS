---
title: Remove CD-ROM-dependent startup behavior
category: feature
release: 0.1.0
breaking: true
targets:
- type: command
  id: launch:cd-path
  effect: changed
- type: key
  id: PlayIntro
  effect: added
- type: key
  id: CD
  effect: removed
  scope: map-packets
- type: key
  id: CD
  effect: removed
  scope: multiplayer-maps
- type: key
  id: CD
  effect: changed
  scope: campaign
credit: [ZivDero]
---

`-CD<path>` now adds a local data search path in both Debug and Release builds. It no longer selects a CD-ROM or changes which map and movie archives are mounted.

`[Intro] PlayIntro` replaces the former per-disc intro flags with one startup setting for `EVA.VQA`. When the setting selects the intro, the game writes it back as `no`.

A campaign's `CD` number now controls only its opening cinematic and loading backdrop; the game no longer asks for a disc. `CD=` in map packets and multiplayer maps is ignored.
