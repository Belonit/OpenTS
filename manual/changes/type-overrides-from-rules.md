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
- 'To keep the previous values in every game type, set `[HMEC] Strength=1200` in `rules.ini`.'
- 'Set `Cost=250` in the `[GAFSDF]`, `[GAWALL]` and `[NAWALL]` sections of `rules.ini`.'
- 'Set `[E2] Explodes=yes` in `rules.ini`.'
- 'Set `[NAFNCE] BaseNormal=no` in `rules.ini`.'
credit:
- ZivDero
---

Seven object types now take [`Strength`](/keys/strength/), [`Cost`](/keys/cost/), [`Explodes`](/keys/explodes/), [`BaseNormal`](/keys/basenormal/) and [`GuardRange`](/keys/guardrange/) from their sections of `rules.ini` in every game type. OpenTS 0.1.0 replaced those values with fixed ones for `HMEC`, `GAFSDF`, `GAWALL`, `NAWALL`, `E2`, `NAFNCE` and `NAPOST`, in campaigns as well as multiplayer, so the migration below applies to single-player too.

Two of the fixed values already matched stock data and need no migration. All three wall sections set `GuardRange=5`, the five cells the fixed value used, and `[NAPOST]` already sets `BaseNormal=no`.
