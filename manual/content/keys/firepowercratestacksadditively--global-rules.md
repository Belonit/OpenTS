---
key: FirepowerCrateStacksAdditively
scope: global-rules
label: Add firepower crate amounts
summary: Adds a firepower crate's amount to the current firepower multiplier instead of multiplying it.
see_also: [FirepowerCrateStacks, ArmorCrateStacksAdditively, "system:crates"]
when_omitted:
  kind: value
  value: "no"
  note: A later rules file or map that omits this key keeps its current value.
---

At `yes`, a firepower crate adds the third field of its `Firepower` entry in `[Powerups]` to each eligible object's current firepower multiplier, including on the first pickup. At `no`, it multiplies the current multiplier by that value.

[`FirepowerCrateStacks`](/keys/firepowercratestacks/) independently controls whether objects whose firepower multiplier is no longer `1` can receive the upgrade again and whether an upgraded collector gets money instead outside campaigns. A collector with no primary weapon still gets money outside campaigns. [Crates](/systems/crates/#results-that-sweep-a-radius) describes the calculation, eligible recipients, and rejected additive results.
