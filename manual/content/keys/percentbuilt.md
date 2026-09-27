---
key: PercentBuilt
summary: A base completion figure that is read but has no effect.
no_effect: true
see_also: [NodeCount, "system:ai-base-building"]
when_omitted:
  kind: value
  value: "0"
---

The name suggests the share of a house's base plan that already stands when the scenario starts, but no part of the game uses the value. A house starts with the structures the scenario places, and [Where the plan comes from](/systems/ai-base-building/#where-the-plan-comes-from) explains how those count against its plan.

`PercentBuilt` is read from the same section as [`NodeCount`](/keys/nodecount/). That includes a spawn house section on a map that sets [`UseMPAIBaseNodes=yes`](/keys/usempaibasenodes/), where it has no effect either.
