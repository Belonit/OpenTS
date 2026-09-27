---
key: BuildRefinery
summary: The refineries a computer house plans and measures its income against, in order of preference.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: ""
---

The list does not add a refinery to [a computer house's generated base plan](/systems/ai-base-building/#building-the-plan). A refinery enters that plan through the ordinary candidate test. The list picks which queued refinery gets the plan's extra copies: the first entry that the country the house [acts as](/keys/actslike/) [may own](/keys/owner/). When the plan never queued that entry, or queued it only as its last entry, no extra refineries are added.

A computer house counts a structure of any listed type as a refinery when it judges these two things:

- whether it can still earn money, which decides whether it [sells off its base](/systems/ai-base-building/#power-and-money-interventions) to pay for a refinery or harvester;
- whether to [replace a lost harvester](/keys/harvester/#scope-global-rules).

When the house prices a refinery, or adds one to its plan after selling, it uses the first entry its country may own, or the list's first entry when it may own none.

A unit crate gives a free harvester to a house that owns a structure of any listed type and no harvester. This applies to human players as well. [Money and free units](/systems/crates/#money-and-free-units) gives the order of the unit crate's choices.

With an empty list, a computer house always judges that it can still earn, so it never sells off its base to pay for a refinery or harvester. It also never replaces lost harvesters, and no crate gives a free harvester.
