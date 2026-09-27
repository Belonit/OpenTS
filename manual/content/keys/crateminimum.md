---
key: CrateMinimum
summary: Fewest crates placed at the start of a non-campaign scenario.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "1"
---

The number of crates placed at the start is the larger of this setting and the number of human players, capped by [`CrateMaximum`](/keys/cratemaximum/). [At scenario start](/systems/crates/#at-scenario-start) covers which matches record a human player count.

The setting applies only to that one placement, made as a non-campaign scenario finishes loading with crates switched on for the match. Replacements for expired and collected crates are placed one at a time, and neither limit applies to them.

A starting crate can still fail to appear. [Where a random crate can land](/systems/crates/#where-a-random-crate-can-land) covers the cells that are refused.
