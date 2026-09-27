---
key: Credits
summary: The money a scenario's house begins a campaign mission with, counted in hundreds.
see_also: [Money, CarryOverMoney, CarryOverCap]
when_omitted:
  kind: value
  value: "0"
---

The house starts the mission with 100 times this value, so `Credits=50` gives it 5,000 credits.

```ini title="scenario map file"
[GDI] ; a house record in the scenario's own house list
Credits=50
```

Only a campaign mission reads its house records, so this is a campaign setting. A skirmish or multiplayer house starts with the session's starting-credits option instead.

The same amount is also recorded as the house's starting money for the score screen. The money half of the mission's efficiency rating compares the money the house has left with its starting money plus everything it harvested. [Carry-over money](/keys/carryovermoney/) that the player's house brings from the previous mission is added to both its balance and its starting money, so the rating counts it as starting money, not as income.
