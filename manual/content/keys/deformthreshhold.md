---
key: DeformThreshhold
summary: Damage at or below this figure never craters the ground.
see_also: [Deform]
when_omitted:
  kind: value
  value: "0"
---

A blast must deal more than this figure before its [`Deform`](/keys/deform/) chance is rolled. A blast that deals exactly the figure never craters. The damage tested is the blast's full damage, not what any object in it takes, so armor never moves a blast across the threshold. Distance matters only in a [wide-area blast](/systems/warheads/#the-wide-area-blast), where each cell's blast is tested with that cell's own figure.

```ini title="rules.ini"
[MyShellWH] ; example WarheadType
Deform=15%
DeformThreshhold=120 ; 121 damage and above may crater
```

The key is spelled with a doubled `h`. A key spelled any other way, such as `DeformThreshold`, is ignored and leaves the threshold unchanged.
