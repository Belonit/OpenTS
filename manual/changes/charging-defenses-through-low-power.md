---
title: Keep charging defenses working through low power
category: balance
release: 0.2.0
targets:
- type: key
  id: Charges
  effect: changed
- type: system
  id: power
  effect: changed
credit: [ZivDero, dkeeton]
---

A structure whose primary weapon has `Charges=yes` now charges and fires while its house is short of power, unless its type is `Powered=yes` and draws power. In the stock rules this lets Cabal's `AAOB` and `CROB` obelisks keep firing. A structure of that kind, such as the Obelisk of Light, keeps a charge it already holds and can fire it once power returns.

dkeeton is credited for the ts-patches change this follows.
