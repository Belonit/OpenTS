---
key: Soylent
summary: A fixed number of credits that selling an object of this type refunds.
see_also: [RefundPercent, Cost]
when_omitted:
  kind: value
  value: "-1"
---

```ini title="rules.ini"
[MYTANK]      ; example UnitType
Cost=1000
Soylent=200   ; selling it at a service depot returns 200 credits
```

`Soylent=` sets the credits every house receives when it sells an object of this type. The amount is paid as written: the owner's [price multipliers](/keys/cost/#what-a-house-pays) and [`RefundPercent`](/keys/refundpercent/) do not scale it. `0` makes the sale refund nothing.

A negative value, including the default `-1`, keeps the usual refund: the object's price with its owner's multipliers, times `RefundPercent` for a human player's house.

The value replaces the refund in every payment `RefundPercent` lists, which covers selling a structure, a vehicle or aircraft at a service depot, or an upgrade, and the compensation for a structure that cannot undeploy. An upgrade's sale uses the upgrade type's `Soylent=`, and undeploy compensation uses the structure's.
