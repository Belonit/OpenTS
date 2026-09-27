---
key: Supress
summary: Discounts a candidate target that stands near buildings allied to the firing object.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

With `Supress=yes`, an object whose primary weapon is this weapon rates targets that stand near its own or allied buildings lower. While it chooses a target for itself, each nearby cell holding such a building halves a candidate's threat score. A candidate hemmed in by friendly structures therefore falls behind an equally attractive one standing in the open. If the discount brings a candidate's score below 1, the object ignores that candidate. The setting has no effect when the weapon is in the object's second slot.

[`FireSupress`](/keys/firesupress/) in `[CombatDamage]` sets how far around the candidate the search reaches, and that page describes the search. At its default distance the search covers no cells, so `Supress=yes` has no effect until `FireSupress` is raised to at least `2`.

The setting does not stop the weapon from firing and does not change the damage it deals. The discount does not apply to a target the player orders the object to attack.
