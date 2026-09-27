---
title: Set the random extra money a crate pays
category: feature
release: 0.2.0
targets:
- type: key
  id: CrateMoneyBonus
  effect: added
- type: system
  id: crates
  effect: changed
credit: [ZivDero, Rampastring]
---

`CrateMoneyBonus` in `[CrateRules]` of `rules.ini` sets the most credits a money crate adds at random to its configured amount. A lower value narrows the random extra, and `0` makes a money crate pay its configured amount exactly. Left unset, money crates pay what they always did.

Rampastring is credited for the DTA patch that paid money crates their exact amount.
