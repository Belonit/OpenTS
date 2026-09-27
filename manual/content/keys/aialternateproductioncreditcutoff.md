---
key: AIAlternateProductionCreditCutoff
summary: Credit total below which a computer house builds structures and units in alternation instead of together.
see_also: ["system:ai-base-building", "system:production"]
when_omitted:
  kind: value
  value: "1000"
---

A computer house with money at or above this figure orders structures, vehicles, infantry and aircraft at the same time. Below it, the house orders one group at a time: either structures, or vehicles, infantry and aircraft. A higher figure makes a computer house start alternating while it still has more money.

The house's money here is its credits plus the value of the Tiberium in its storage. The house compares it with the figure each time one of its factories delivers something.

Below the figure, each delivery decides the next group:

- A structure delivery switches the house to vehicles, infantry and aircraft.
- A vehicle, infantry or aircraft delivery switches the house to structures. A house that is already ordering vehicles, infantry and aircraft switches only when **any of** these holds:
  - it owns none of the [`BuildWeapons`](/keys/buildweapons/) types;
  - it owns none of the [`BuildBarracks`](/keys/buildbarracks/) types;
  - it is [drawing more power than it makes](/systems/power/);
  - it wins a one-in-two draw.

A house limited to one group still orders from the other in these cases:

- A house ordering structures also orders vehicles, infantry and aircraft when it has chosen no structure, or when no factory it owns can build the structure it chose. [Choosing what to build next](/systems/ai-base-building/#choosing-what-to-build-next) covers that choice.
- A house ordering vehicles, infantry and aircraft skips infantry and aircraft while the vehicle it has on order is one of the [`HarvesterUnit`](/keys/harvesterunit/) types. It also orders structures when it has nothing on order, or when no factory it owns can build something it has on order.

:::note[Campaign games never alternate]
In a campaign, a computer house orders every class at the same time whatever its money, so the figure has no effect.
:::
