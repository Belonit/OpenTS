---
key: TiberiumProof
summary: Stops Tiberium from poisoning an infantry type.
see_also: ["system:tiberium", "Power"]
when_omitted:
  kind: value
  value: "no"
---

Infantry of a `TiberiumProof=yes` type take no [Tiberium damage](/systems/tiberium/#damage) when they finish moving into a Tiberium cell, including a blossom tree's cell. The `TIBERIUM_PROOF` [veteran ability](/systems/veterancy/#abilities) gives the same protection to a type without the flag.

The flag covers only that damage. Weapon hits are unaffected.
