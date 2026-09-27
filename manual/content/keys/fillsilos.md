---
key: FillSilos
summary: Stocks each house's storage with Tiberium worth about its money when the scenario opens.
see_also: ["system:tiberium", Storage]
when_omitted:
  kind: value
  value: "no"
---

```ini title="map file"
[Basic]
FillSilos=yes
```

As the scenario finishes loading, every house with a storage building receives stored Tiberium worth about as much as its money. The Tiberium is of the first registered Tiberium type and fills the house's storage buildings as a harvester unload would, so silos and refineries start stocked. In a multiplayer or skirmish game, a computer house receives that value as credits instead, as it would from an unload.

Each house receives Tiberium until either its free storage runs out or the Tiberium given is worth at least its money minus one unit's [`Value`](/keys/value/). Like an unload, the delivery adds five points per unit to the house's score.

:::caution[The house keeps its credits]
The house's money only sets how much Tiberium it receives, and none of it is spent. A house with enough storage starts with nearly twice its money in value.
:::

Money carried over by [`CarryOverMoney`](/keys/carryovermoney/) arrives after this conversion and is not counted.

:::danger[Give the first Tiberium type a Value above 0]
With a `Value` of `0`, a multiplayer or skirmish game never finishes loading if a computer house has money and a storage building. Every other house with money has its storage filled completely.
:::
