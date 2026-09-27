---
key: ProduceCashAmount
summary: The credits a structure pays its owner each interval, taken from them instead when the figure is negative.
see_also: [ProduceCashDelay, ProduceCashBudget, ProduceCashStartup, Powered, "system:produce-cash"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[MYDERRICK] ; example BuildingType registered in [BuildingTypes]
ProduceCashAmount=100 ; credits
ProduceCashDelay=750  ; frames between payments
```

Each time the [`ProduceCashDelay`](/keys/producecashdelay/) interval runs out, this many credits go to the house that owns the structure. They go straight to its credits: they pass through no refinery, are not counted as harvested, and ignore the silo limit. A damaged structure pays the full amount.

A negative value takes that many credits each interval instead. The charge comes out of the owner's credits first, then out of Tiberium stored in its structures. Once both run out, the rest of the charge is dropped, so the owner never goes into debt.

Zero produces nothing. [Buildings that produce cash](/systems/produce-cash/) owns the interval, the budget, the power test, and everything else that stops a structure paying.
