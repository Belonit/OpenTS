---
title: Make the multiple-factory discount cumulative, as in Red Alert 2
category: balance
release: 0.2.0
breaking: true
migration:
- If `MultipleFactory` under `[General]` in `rules.ini` is positive or omitted, set it to the intended build-time multiplier per extra factory. For example, `0.8` gives about 20% shorter builds per extra factory; `0` disables the bonus.
targets:
- type: key
  id: MultipleFactory
  effect: changed
- type: key
  id: MultipleFactoryCap
  effect: added
- type: system
  id: production
  effect: changed
credit: [ZivDero, CCHyper, dkeeton, Krnyoshi]
---

Each factory of a category past the first now multiplies that category's build times by `MultipleFactory` in `[General]` of `rules.ini`: at `0.8`, two factories build in about 80% of the time and three in about 64%. Before, the build time was divided once by `(factories - 1) × MultipleFactory`. At `1` a second factory gave no discount and a third halved build times, and below `1` a second factory lengthened them. The stock rules set `MultipleFactory=0`, which still gives no discount.

`MultipleFactoryCap` in the same section limits how many factories count toward the discount.

CCHyper is credited for the Vinifera version this follows, dkeeton for the ts-patches port of the Red Alert 2 formula, and Krnyoshi for the fix to Vinifera's cap.
