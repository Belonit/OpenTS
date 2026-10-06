---
key: FirepowerCrateStacks
scope: global-rules
label: Let firepower crates stack
summary: Lets a firepower crate upgrade an object that an earlier firepower crate already upgraded.
see_also: [FirepowerCrateStacksAdditively, ArmorCrateStacks, "system:crates"]
when_omitted:
  kind: value
  value: "no"
  note: A later rules file or map that omits this key keeps its current value.
---

At `yes`, a firepower crate can upgrade objects whose firepower multiplier is no longer `1`. At `no`, only objects whose firepower multiplier is exactly `1` can receive the upgrade.

Outside a campaign, a drawn firepower result becomes money for an upgraded collector at `no` and stays firepower at `yes`. Either way, it becomes money when the collector has no primary weapon.

[`FirepowerCrateStacksAdditively`](/keys/firepowercratestacksadditively/) chooses whether each upgrade adds to or multiplies the current firepower multiplier. [Crates](/systems/crates/#results-that-sweep-a-radius) describes which objects a crate reaches and how the upgrade changes damage.
