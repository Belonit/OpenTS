---
key: MaxMoney
summary: Upper end of the starting-credits slider on every multiplayer and skirmish setup screen.
see_also: [Money]
when_omitted:
  kind: value
  value: "10000"
---

This is the highest starting credits a player can choose on the skirmish and multiplayer setup screens. Each screen's credits slider runs from `2500` up to this value. The lower end is fixed in the engine, so no rules setting can move it.

The value limits only that choice. Nothing during a match compares a house's credits against it, and a [launch file](/formats/spawn-ini/#the-options-every-house-plays-under) sets starting credits without this limit. [`Money`](/keys/money/) explains how the default starting credits interact with the slider.
