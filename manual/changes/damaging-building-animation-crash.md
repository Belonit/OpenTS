---
title: Stop a damaging building animation crashing the game
category: fix
release: 0.2.0
targets:
- type: key
  id: Damage
  scope: animtype
  effect: changed
- type: system
  id: building-animations
  effect: changed
credit: [ZivDero, Rampastring]
---

A structure animation with `Damage=` no longer crashes the game when its own damage makes the structure replace it. That happened when the damage moved the structure across [`ConditionYellow`](/keys/conditionyellow/) and the animation was one the structure swaps for its other form. One example is a damaged-only animation that keeps running after a repair and then damages the structure below `ConditionYellow` again.

Rampastring is credited for the ts-patches workaround for this crash.
