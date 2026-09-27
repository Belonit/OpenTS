---
key: ProduceCashStartupOneTime
summary: Limits a structure's capture bonus to the first time it is paid, however often the structure changes hands afterward.
see_also: [ProduceCashStartup, Capturable, MultiplayPassive, "system:produce-cash"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[CAOILD]
Capturable=yes
ProduceCashStartup=1000
ProduceCashStartupOneTime=yes ; the bonus is paid once, not on every recapture
```

With `ProduceCashStartupOneTime=yes`, a structure pays its [`ProduceCashStartup`](/keys/producecashstartup/) bonus only once. Later captures from a neutral house transfer the structure without the bonus. With `no`, every capture from a neutral house pays the bonus again, so a structure that returns to a neutral house and is captured again pays twice.

The payment is recorded on the structure itself, not on its type or on a house, and saved games keep the record. A structure that undeploys and is deployed again counts as a new structure and can pay again; [Buildings that produce cash](/systems/produce-cash/#capture) covers that case.
