---
key: FirepowerCrateStacks
scope: global-rules
label: Let firepower crates stack
summary: Lets a firepower crate upgrade an object that an earlier firepower crate already upgraded.
see_also: [ArmorCrateStacks, "system:crates"]
when_omitted:
  kind: value
  value: "no"
---

With `FirepowerCrateStacks=yes`, each firepower crate multiplies the firepower multiplier of every object it reaches by the `Firepower` value in `[Powerups]`, even when an earlier crate already did. Two crates at `2` leave an object dealing four times its ordinary damage. [Results that sweep a radius](/systems/crates/#results-that-sweep-a-radius) covers which objects a crate reaches.

With `no`, a firepower crate changes only objects whose firepower multiplier is still exactly `1`.

Outside a campaign, the setting also decides when a drawn firepower result turns into money. With `no`, it turns into money when the collector's firepower multiplier is no longer `1`. With `yes`, an upgraded collector keeps the firepower result. Either way, it turns into money when the collector has no primary weapon.
