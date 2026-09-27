---
key: ProduceCashResetOnCapture
summary: Hands each new owner of a cash-producing structure a fresh budget, reviving one that had already spent it.
see_also: [ProduceCashBudget, ProduceCashAmount, ProduceCashStartup, Capturable, "system:produce-cash"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[CAOILD]
ProduceCashAmount=100
ProduceCashDelay=750
ProduceCashBudget=1000
ProduceCashResetOnCapture=yes
```

`ProduceCashResetOnCapture=yes` refills the structure's [`ProduceCashBudget`](/keys/producecashbudget/) to the full amount every time the structure is captured. A structure that had spent its budget and stopped paying starts paying again for its new owner. With `no`, the remaining budget carries over, so a structure that has spent its budget earns nothing for whoever captures it.

The refill applies to every capture, including a capture from another player. The [`ProduceCashStartup`](/keys/producecashstartup/) bonus differs: it is paid only on a capture from a neutral house. [Buildings that produce cash](/systems/produce-cash/#the-budget) covers the budget.

The key has no effect unless `ProduceCashBudget` is above zero, because a structure without a budget pays without limit.
