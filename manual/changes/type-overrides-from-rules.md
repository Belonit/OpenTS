---
title: Read the overridden type values from the rules
category: balance
release: 0.2.0
targets:
- type: key
  id: BaseNormal
  effect: changed
- type: key
  id: Strength
  effect: changed
- type: key
  id: Cost
  effect: changed
- type: key
  id: Explodes
  effect: changed
- type: key
  id: GuardRange
  effect: changed
breaking: true
migration:
- 'Set `[HMEC] Strength=1200` in the rules to keep the Mammoth Mk. II at the strength it had. Stock data says `800`, which is now what it gets.'
- 'Set `Cost=250` in `[GAFSDF]`, `[GAWALL]` and `[NAWALL]` to keep the wall prices, and the build times derived from them. Stock data says `50`.'
- 'Add `[E2] Explodes=yes` to keep the Disc Thrower exploding on death. Stock data leaves the key out, which means no.'
- 'Add `[NAFNCE] BaseNormal=no` to keep laser fence sections from anchoring building placement. Stock data sets `IsBase=no`, which the engine has never read, so without this the section becomes a valid anchor.'
credit:
- ZivDero
---

Seven object types now take [`Strength`](/keys/strength/), [`Cost`](/keys/cost/), [`Explodes`](/keys/explodes/), [`BaseNormal`](/keys/basenormal/) and [`GuardRange`](/keys/guardrange/) from their sections of `rules.ini` in every game type. OpenTS 0.1.0 replaced those values with fixed ones for `HMEC`, `GAFSDF`, `GAWALL`, `NAWALL`, `E2`, `NAFNCE` and `NAPOST`, in campaigns as well as multiplayer, so the migration below applies to single-player too.

Two of the fixed values already matched stock data and need no migration. All three wall sections set `GuardRange=5`, the five cells the fixed value used, and `[NAPOST]` already sets `BaseNormal=no`.
