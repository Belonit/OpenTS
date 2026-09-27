---
key: BuildLimit
summary: The cap on how many of the type a house may build, with the sign choosing which tally it is compared against.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "2147483647"
---

A positive value caps how many objects of the type the house owns at once. Losing one lets the house build another.

A negative value caps how many the house finishes building over the whole scenario, at the value's size: `BuildLimit=-2` allows two. Losing one frees nothing.

`BuildLimit=0` makes the type unbuildable.

[Build limits](/systems/production/#build-limits) covers:

- what else counts toward a positive limit;
- why a build already in progress is not canceled when it reaches the limit;
- how the sidebar shows a type at its limit;
- the extra check the production queue applies;
- why a computer house can build past the limit.
