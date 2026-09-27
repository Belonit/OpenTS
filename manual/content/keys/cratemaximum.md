---
key: CrateMaximum
summary: Most crates placed at the start of a non-campaign scenario.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "255"
---

When crates are switched on, the number of random crates placed as a match starts is the larger of [`CrateMinimum`](/keys/crateminimum/) and the number of human players, cut down to this value.

It does not cap how many crates the map holds later. A crate placed when another is collected or expires is not counted against it.

At most 256 random crates can exist at once, so a value above 256 behaves as 256.
