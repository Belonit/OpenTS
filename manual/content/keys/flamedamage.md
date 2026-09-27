---
key: FlameDamage
summary: The warhead a napalm crate's damage uses.
see_also: ["FlameDamage2", "C4Warhead", "system:crates"]
when_omitted:
  kind: value
  value: none
---

Only the napalm result of a pickup crate uses this warhead. The result damages the object that collected the crate, then sets off a blast of the same damage halfway between the crate's cell and the collector. Both use this warhead. [Damaging results](/systems/crates/#damaging-results) covers the result and where its damage comes from.

Fires, flames and other damaging animations do not use this key. They deal their damage through [`FlameDamage2`](/keys/flamedamage2/).

With the key unset, the napalm result loses its blast, because a blast with no warhead damages nothing. The collector still takes the full damage, because that hit is not reduced by the collector's armor.
