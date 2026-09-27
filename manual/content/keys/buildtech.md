---
key: BuildTech
summary: The buildings a computer house resolves a generic tech prerequisite to, in order of preference.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: ""
  note: The generic tech prerequisite goes unsatisfied for a computer house, so a generated base plan leaves out every type that has it, and the house never picks such a type as a base defense or advanced power plant; player production is unaffected.
---

A computer house tests a [`Prerequisite=TECH`](/keys/prerequisite/) against this list in three decisions: generating [its base plan](/systems/ai-base-building/#building-the-plan), picking a base defense, and picking an advanced power plant. In each, only the first entry that the country the house [acts as](/keys/actslike/) [may own](/keys/owner/) meets it. While the plan is generated, that entry must already be queued. When the house picks a base defense or an advanced power plant, it must own a structure of that entry's type. Another listed type does not count, even when it is queued or owned.

Outside these three decisions a computer house [ignores prerequisites](/systems/production/#computer-houses), including when it follows [a map plan](/systems/ai-base-building/#where-the-plan-comes-from). The sidebar resolves `TECH` through [`PrerequisiteTech`](/keys/prerequisitetech/) instead.

Nothing else reads the list. A tech building enters the plan through the ordinary candidate test, so naming one here neither adds it to the plan nor keeps it out.
