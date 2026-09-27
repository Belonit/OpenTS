---
key: FreeMCV
summary: Parsed flag that the engine never uses.
no_effect: true
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "no"
---

Nothing reads this flag, so no value changes which crates hand out an MCV. Outside a campaign, a crate still gives a free MCV to a house that has lost its base, whatever result the crate drew, unless [`UnitCrateType`](/keys/unitcratetype/) names another vehicle. The conditions for that are fixed, and a later conversion can still turn the MCV into money. [Outside a campaign](/systems/crates/#outside-a-campaign) lists both.
