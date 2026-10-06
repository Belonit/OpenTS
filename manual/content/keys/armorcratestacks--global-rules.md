---
key: ArmorCrateStacks
scope: global-rules
label: Let armor crates stack
summary: Lets an armor crate upgrade an object that an earlier armor crate already upgraded.
see_also: [ArmorCrateStacksAdditively, FirepowerCrateStacks, "system:crates"]
when_omitted:
  kind: value
  value: "no"
  note: A later rules file or map that omits this key keeps its current value.
---

At `yes`, an armor crate can upgrade objects whose armor multiplier is no longer `1`. Outside a campaign, an upgraded collector keeps an armor result instead of receiving money.

At `no`, only objects whose armor multiplier is exactly `1` can receive the upgrade. Outside a campaign, a collector whose armor multiplier is no longer `1` converts an armor result to money.

[`ArmorCrateStacksAdditively`](/keys/armorcratestacksadditively/) chooses whether each upgrade adds to or multiplies the current armor multiplier. [Crates](/systems/crates/#results-that-sweep-a-radius) describes which objects a crate reaches and how the upgrade changes incoming damage.
