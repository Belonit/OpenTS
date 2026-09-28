---
key: AircraftWithPipGroupNumberOffset
summary: Where a selected aircraft whose type has pips prints its control group number.
see_also: [AircraftGroupNumberOffset, MaxPips]
when_omitted:
  kind: value
  value: "-4,-8"
---

`AircraftWithPipGroupNumberOffset=` sets where a selected aircraft whose type has pips prints its control group number. The value is a horizontal and a vertical offset in pixels. [Control group numbers](/formats/ui-ini/#control-group-numbers) covers the point it is measured from and which types count as having pips.

```ini title="UI.INI"
[Pips]
AircraftWithPipGroupNumberOffset=-4,-15
```
