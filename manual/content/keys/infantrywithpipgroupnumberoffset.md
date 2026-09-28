---
key: InfantryWithPipGroupNumberOffset
summary: Where a selected infantry unit whose type has pips prints its control group number.
see_also: [InfantryGroupNumberOffset, MaxPips]
when_omitted:
  kind: value
  value: "-4,-8"
---

`InfantryWithPipGroupNumberOffset=` sets where a selected infantry unit whose type has pips prints its control group number. The value is a horizontal and a vertical offset in pixels. [Control group numbers](/formats/ui-ini/#control-group-numbers) covers the point it is measured from and which types count as having pips.

```ini title="UI.INI"
[Pips]
InfantryWithPipGroupNumberOffset=-4,-15
```
