---
key: ProduceCashStartup
summary: The credits paid to a house that captures the structure from a neutral house.
see_also: [ProduceCashStartupOneTime, ProduceCashAmount, Capturable, MultiplayPassive, "system:capture", "system:produce-cash"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[CAOILD]
Capturable=yes
ProduceCashStartup=1000 ; credits, paid once as the structure changes hands
```

A house that captures this structure from a neutral house receives this many credits. A neutral house is one whose country sets [`MultiplayPassive=yes`](/keys/multiplaypassive/). Capturing the structure from another player pays no bonus; the new owner receives only whatever the structure pays on a schedule.

No bonus is paid when the value is zero or less, or when the capturing house is itself neutral.

The bonus is independent of the recurring payment. A type can set only this key, for a tech structure that is worth a lump sum on capture and nothing afterward. The bonus does not count against [`ProduceCashBudget`](/keys/producecashbudget/) and is not limited by it.

Each capture from a neutral house pays the bonus again, unless [`ProduceCashStartupOneTime=yes`](/keys/producecashstartuponetime/) limits it to one payment per structure.
