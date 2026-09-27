---
key: CarryOverMoney
summary: The share of the previous mission's leftover money the player begins this one with.
see_also: [CarryOverCap, TimerInherit, "system:campaign-progression"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="map file"
[Basic]
CarryOverMoney=0.5
CarryOverCap=-1
```

The value is the fraction of the previous mission's money that the player starts this mission with. The money counted is what the player held when winning the previous campaign mission: credits plus the value of stored Tiberium. The result is added to the player's credits, and the score screen counts it as money the player started with.

The mission being entered sets the fraction, not the mission being left. A mission reached by two different routes therefore carries over the same fraction from either.

Values above `1` are treated as `1`, so a mission cannot hand over more money than the player finished with. [`CarryOverCap`](/keys/carryovercap/) limits the result, and leaving that key out cancels the carry-over.

The money arrives just after the mission has loaded. A mission restarted from the menu or replayed after a loss grants the same amount again. [What survives the boundary](/systems/campaign-progression/#what-survives-the-boundary) covers what else is carried over on the same terms.
