---
key: EWGates
summary: The gates a computer house fits into the east-west runs of its base perimeter, in order of preference.
see_also: [NSGates, "system:ai-base-building"]
when_omitted:
  kind: value
  value: ""
---

When a computer house plans a perimeter wall, a long wall run along the north or south edge of its base gets a gate in its middle. The gate is the first entry in this list that [the country the house acts as](/keys/actslike/) [may own](/keys/owner/). Runs along those two edges lie east-west, which gives the key its name. The east and west edges use [`NSGates`](/keys/nsgates/) instead. [Walls and gates](/systems/ai-base-building/#walls-and-gates) explains which runs get a gate.

The planner does not check that the entry is a gate. Any structure type listed here is planned into the three cells of the run that the gate takes.

:::danger[List a gate every wall-building country may own]
If the planner lays a gate on the north or south edge and this list holds no entry the country may own, the game crashes.
:::
