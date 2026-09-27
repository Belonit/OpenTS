---
key: CrateRegen
summary: The range, in minutes, of the random lifetime given to each random crate.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "10"
---

Each random crate gets a lifetime between half this value and twice it, in minutes of game time. The default of `10` gives lifetimes between 5 and 20 minutes; `CrateRegen=3` gives lifetimes between 1.5 and 6 minutes. Raising the value makes crates stay in place longer.

When a crate's lifetime runs out, it is removed and the engine tries to place a new random crate elsewhere. The setting therefore controls how often crates move around the map, not how many there are.

Crates drawn into the map and crates dropped by destroyed vehicles have no lifetime and stay until something collects them. [How long a crate lasts](/systems/crates/#how-long-a-crate-lasts) covers expiry and replacement.
