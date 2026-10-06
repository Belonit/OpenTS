---
title: Define sounds with the Yuri's Revenge SOUND.INI keys
category: feature
release: 0.2.0
breaking: true
migration:
- Replace sound-section `Volume=` values above `1` in `SOUND.INI` with the intended percentage. Use `Volume=100` for full volume; values above `1` no longer amplify the sample.
targets:
- type: format
  id: sound-ini
  effect: changed
- type: key
  id: Volume
  effect: changed
  scope: sounds
- type: key
  id: Priority
  effect: changed
- type: key
  id: Range
  effect: added
  scope: sounds
- type: key
  id: Type
  effect: added
  scope: sounds
- type: key
  id: Sounds
  effect: added
- type: key
  id: MinVolume
  effect: added
- type: key
  id: Limit
  effect: added
- type: key
  id: Loop
  effect: added
- type: key
  id: LoopLimit
  effect: added
- type: key
  id: Delay
  effect: added
- type: key
  id: FShift
  effect: added
- type: key
  id: VShift
  effect: added
- type: key
  id: Control
  effect: added
- type: key
  id: Attack
  effect: added
- type: key
  id: Decay
  effect: added
- type: key
  id: Channels
  effect: added
credit: [ZivDero, CCHyper]
---

A sound's section in `SOUND.INI` can now list several samples under `Sounds=`, play them at random or in order, loop them, and add attack and decay samples. It can also wait between cycles, vary pitch and volume at random, limit how many copies play at once, and set how far from the view it can be heard. `[Defaults]` supplies any key a section leaves out, and `Channels=` under `[General]` sets how many sound effects can play at once.

`Priority=` now also accepts the Yuri's Revenge names such as `HIGH`, and a `Volume=` above 1 is read as a percentage, so sections written for Yuri's Revenge play as intended. The shipped files set no `Volume=` and play as before.

CCHyper is credited for the Vinifera additions to the Yuri's Revenge keys that this follows: the `SEQUENTIAL` and `QUEUE` controls and the `SHROUDED` and `UNSHROUDED` types.
