---
key: HealCrateSound
summary: Sound played at the collector when it opens a heal crate for the local player.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: none
---

The sound plays at the collecting object's position, and only when that object belongs to the local player. A heal crate opened by any other house plays nothing. The healing does not depend on this setting; [crates that reach the whole map](/systems/crates/#results-that-reach-the-whole-map) covers what it restores.
