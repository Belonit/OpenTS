---
key: MaxVeinholeGrowth
summary: Ceiling on the veins one veinhole monster may cover.
see_also: ["system:veins", "VeinholeGrowthRate", "VeinGrowthEnabled"]
when_omitted:
  kind: value
  value: "1000"
---

A veinhole monster takes a [growth step](/systems/veins/#growth) only while both of these hold:

1. It has queued no more than this value minus 40 cells to grow, counted over its whole life.
2. It covers no more than this value minus 100 cells of mature vein.

Each monster is limited separately, and every monster uses the same value.

The first limit is a lifetime budget. The count never goes down, and cells queued to grow back after harvesting add to it. Once a monster passes the budget, it never grows again, and vein harvested from its field after that stays thin. Raise the value for larger fields and longer regrowth.

:::caution[A value below 100 stops all vein growth]
Below `100`, even a monster that covers no mature vein fails the second test. No monster in the scenario ever grows its field.
:::
