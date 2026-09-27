---
key: ProduceCashBudget
summary: The total one structure produces, counted without regard to sign, before it stops.
see_also: [ProduceCashAmount, ProduceCashDelay, ProduceCashResetOnCapture, "system:produce-cash"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[MYDERRICK] ; example BuildingType registered in [BuildingTypes]
ProduceCashAmount=100
ProduceCashDelay=750
ProduceCashBudget=1000 ; ten payments, then the structure stops producing
```

Each payment of [`ProduceCashAmount`](/keys/producecashamount/) is subtracted from this allowance, and the structure stops producing once the allowance is used up. A negative amount is subtracted by its size, so a charge uses up the budget the same way a payment does.

A budget that is not a whole multiple of the amount ends with a smaller final payment. A budget of `1000` with an amount of `300` pays 300, 300, 300 and then 100.

Zero or a negative value sets no limit.

A structure that has used up its budget keeps standing but produces nothing further, unless [`ProduceCashResetOnCapture=yes`](/keys/producecashresetoncapture/) gives it a fresh allowance when it is captured.

The bonus [`ProduceCashStartup`](/keys/producecashstartup/) pays does not count against the budget and is not limited by it.
