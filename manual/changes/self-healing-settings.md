---
title: Give self-healing its own step, interval and ceiling
category: feature
release: 0.2.0
targets:
- type: key
  id: SelfHealStep
  effect: added
- type: key
  id: SelfHealRate
  effect: added
- type: key
  id: SelfHealCap
  effect: added
- type: key
  id: SelfHealingStep
  effect: added
- type: key
  id: SelfHealingRate
  effect: added
- type: key
  id: SelfHealingCap
  effect: added
- type: system
  id: repair
  effect: changed
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, JoyfulShush, Rampastring]
---

`SelfHealStep`, `SelfHealRate` and `SelfHealCap` under `[General]` in `rules.ini` set how much strength a self-healing object regains each time, how many minutes pass between heals, and the share of maximum strength above which it stops healing. `SelfHealingStep`, `SelfHealingRate` and `SelfHealingCap` set the same three in one object type's section, overriding `[General]` for that type.

A type with no value of its own uses the `[General]` one, and without that the game heals as before: one point at a time, every `RepairRate` minutes, up to `ConditionYellow`. Rules that set none of the six keys therefore heal as they did. A step below one counts as one, so the step cannot switch healing off.

An interval shorter than one frame now heals once per frame. It used to crash the game with a division by zero.
