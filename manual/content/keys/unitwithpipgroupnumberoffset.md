---
key: UnitWithPipGroupNumberOffset
summary: Where a selected vehicle whose type has pips prints its control group number.
see_also: [UnitGroupNumberOffset, MaxPips]
when_omitted:
  kind: value
  value: "-4,-8"
---

`UnitWithPipGroupNumberOffset=` sets where a selected vehicle whose type has pips prints its control group number. The value is a horizontal and a vertical offset in pixels. [Control group numbers](/formats/ui-ini/#control-group-numbers) covers the point it is measured from and which types count as having pips.

```ini title="UI.INI"
[Pips]
UnitWithPipGroupNumberOffset=-4,-15
```
