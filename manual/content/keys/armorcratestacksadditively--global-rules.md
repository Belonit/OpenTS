---
key: ArmorCrateStacksAdditively
scope: global-rules
label: Add armor crate amounts
summary: Adds an armor crate's amount to the current armor multiplier instead of multiplying it.
see_also: [ArmorCrateStacks, FirepowerCrateStacksAdditively, "system:crates"]
when_omitted:
  kind: value
  value: "no"
  note: A later rules file or map that omits this key keeps its current value.
---

At `yes`, an armor crate adds the third field of its `Armor` entry in `[Powerups]` to each eligible object's current armor multiplier, including on the first pickup. At `no`, it multiplies the current multiplier by that value.

[`ArmorCrateStacks`](/keys/armorcratestacks/) independently controls whether objects whose armor multiplier is no longer `1` can receive the upgrade again and whether an upgraded collector gets money instead outside campaigns. [Crates](/systems/crates/#results-that-sweep-a-radius) describes the calculation, eligible recipients, and rejected additive results.
