---
key: ProduceCashDelay
summary: The frames between one structure's cash payments, and the switch that turns them on at all.
see_also: [ProduceCashAmount, ProduceCashBudget, "system:produce-cash"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[CAOILD]
ProduceCashAmount=100
ProduceCashDelay=750  ; 50 seconds at 15 frames a second
```

A structure pays [`ProduceCashAmount`](/keys/producecashamount/) once every `ProduceCashDelay` frames. The count starts when the structure [opens for business](/systems/produce-cash/#the-interval), and it restarts from the full delay after each payment and on each capture. Each structure keeps its own count, so two structures of the same type built a few seconds apart also pay a few seconds apart.

A value of zero or less turns the recurring payment off. A type that sets `ProduceCashAmount` without this key never pays on a schedule, although it can still pay [`ProduceCashStartup`](/keys/producecashstartup/) on capture.

On a [`Powered=yes`](/keys/powered/) structure, the count pauses while the structure lacks power and resumes with the frames it had left. [Buildings that produce cash](/systems/produce-cash/#power) says what counts as lacking power.
