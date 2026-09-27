---
key: CarryOverCap
summary: The ceiling placed on the money carried into this mission from the previous one.
see_also: [CarryOverMoney]
when_omitted:
  kind: value
  value: "0"
---

```ini title="map file"
[Basic]
CarryOverMoney=0.5
CarryOverCap=5000
```

The cap is a number of credits. The player receives the carried-over amount from [`CarryOverMoney`](/keys/carryovermoney/) or the cap, whichever is smaller.

`-1` removes the cap and lets the full amount through. Any other negative value is still a cap, so the player receives that negative amount and starts with fewer credits.

:::caution[Set the cap to carry money over]
Leaving this key out cancels the carry-over. A mission that carries money forward must set both keys, and a mission that carries the full amount must set `CarryOverCap=-1`.
:::
