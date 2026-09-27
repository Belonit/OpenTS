---
key: Crew
summary: The InfantryType that ordinarily leaves a destroyed or sold object as its survivor.
see_also: ["system:capture", Crewed, Technician]
when_omitted:
  kind: value
  value: none
---

Only a [`Crewed=yes`](/keys/crewed/) structure or vehicle produces survivors. [Survivors](/systems/capture/#survivors) covers how many a structure produces, and [`CrewEscape`](/keys/crewescape/) covers a vehicle's crew. The type of each survivor is chosen separately, by these tests in order:

1. A structure that has never been captured and whose type builds structures produces the `[General]` [`Engineer`](/keys/engineer/#scope-global-rules) type on a one-in-four roll.
2. An object whose house belongs to no side produces the [`Technician`](/keys/technician/) type.
3. An armed object whose house has a side produces the `Technician` type on a 15% roll.
4. Any other survivor is of this type.

The value does not have to be listed under `[InfantryTypes]`. A name the game does not already know registers a new InfantryType, and a section of that name is still read, because object sections are read after `[General]`. A name with no section of its own gives a type with only engine defaults and no animation sequence, and a survivor of that type crashes the game once it animates.

:::danger[Set this before a `Crewed=yes` structure is sold]
The value starts as no type. A sale crashes the game when one of its survivors falls through to step 4 while the value is unset. A destroyed structure or vehicle produces no survivor for that pick instead.
:::
