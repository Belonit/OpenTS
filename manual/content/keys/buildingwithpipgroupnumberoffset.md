---
key: BuildingWithPipGroupNumberOffset
summary: Where a selected structure whose type has pips prints its control group number.
see_also: [BuildingGroupNumberOffset, MaxPips]
when_omitted:
  kind: value
  value: "-4,-8"
---

`BuildingWithPipGroupNumberOffset=` sets where a selected structure whose type has pips prints its control group number. The value is a horizontal and a vertical offset in pixels. [Control group numbers](/formats/ui-ini/#control-group-numbers) covers the point it is measured from and which types count as having pips.

```ini title="UI.INI"
[Pips]
BuildingWithPipGroupNumberOffset=-4,-15
```
