---
key: UnitGroupNumberOffset
summary: Where a selected vehicle whose type has no pips prints its control group number.
see_also: [UnitWithPipGroupNumberOffset, MaxPips]
when_omitted:
  kind: value
  value: "-4,-4"
---

`UnitGroupNumberOffset=` sets where a selected vehicle whose type has no pips prints its control group number. The value is a horizontal and a vertical offset in pixels. [Control group numbers](/formats/ui-ini/#control-group-numbers) covers the point it is measured from and which types count as having pips.

```ini title="UI.INI"
[Pips]
UnitGroupNumberOffset=-4,-10
```
