---
title: Price the pad aircraft from the whole list
category: fix
release: 0.2.0
targets:
- type: key
  id: PadAircraft
  effect: changed
credit: [ZivDero]
---

Unless `SeparateAircraft=yes` is set, a new pad comes with the first aircraft that `PadAircraft=` in the `[General]` section of `rules.ini` lists, and the pad's price includes a share of the list's cost. That share is now the average cost of every entry in the list. It used to average the first two entries whatever the list held, so an empty list crashed the game, and a one-entry list could crash it or misprice the pad. An empty list now adds nothing to the price and gives a pad no free aircraft.
