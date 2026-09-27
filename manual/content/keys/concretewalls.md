---
key: ConcreteWalls
summary: The walls a computer house builds its base perimeter from, in order of preference.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: ""
---

A computer house builds the walls of its [planned perimeter](/systems/ai-base-building/#walls-and-gates) from the first entry in this list that the country it [acts as](/keys/actslike/) [may own](/keys/owner/). Later entries serve countries that cannot own the earlier ones.

A wall of that type is removed from the plan when a base defense later takes its cell. Only a defense that [plugs into](/keys/powersupbuilding/) one of the side's wall towers removes a wall this way.

Give every country whose side builds walls an entry it may own. The game crashes when the computer plans a wall for a country that may own none of the listed types.
