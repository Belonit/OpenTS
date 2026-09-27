---
key: NSGates
summary: The gates a computer house fits into the north-south runs of its base perimeter, in order of preference.
see_also: [EWGates, "system:ai-base-building"]
when_omitted:
  kind: value
  value: ""
---

The [perimeter planner](/systems/ai-base-building/#walls-and-gates) sets a gate into a wall run on the east or west edge of the base. The gate is the first entry here that [the country this house acts as](/keys/actslike/) [may own](/keys/owner/). Wall runs on those two edges travel north to south. The north and south edges take [`EWGates`](/keys/ewgates/) instead. Nothing checks that the entry is a gate.

:::danger[Give every wall-building country a gate it may own]
If the planner needs a gate on an east or west edge and the list holds no entry that the country this house acts as may own, the game crashes.
:::
