---
title: Show indicators on hover and rank without selection
category: feature
release: 0.2.0
targets:
- type: system
  id: veterancy
  effect: changed
- type: key
  id: EnemyHealth
  effect: changed
credit:
- ZivDero
- AlexB
- dkeeton
---

A selectable object under the mouse pointer now shows its health bar without being selected. Veterancy insignia and the medic's cross on an infantry healer now show without a selection too, when the viewer is allied to the object's owner, has spied on that house, or is an observer. Neither shows on an object under shroud or fog, or on another house's object that is invisible or is cloaked and undetected.

`EnemyHealth=no` under `[AudioVisual]` in `rules.ini` hides neither, because the key has no effect. Cargo pips, the group number and the "Primary" tag still show only on a selected object.
