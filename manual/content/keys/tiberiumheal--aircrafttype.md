---
key: TiberiumHeal
scope: aircrafttype
label: Heals on Tiberium
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "no"
---

An infantry, vehicle or aircraft of this type heals while its cell holds Tiberium and it is below maximum strength. Each time the [global interval](/keys/tiberiumheal/#scope-global-rules) elapses, it regains the game-wide repair step: [`IRepairStep`](/keys/irepairstep/) for infantry, [`RepairStep`](/keys/repairstep/) for vehicles and aircraft. A structure never heals this way. The `TIBERIUM_HEAL` ability from [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/) gives the same healing.

This healing continues to maximum strength. [`SelfHealing=yes`](/keys/selfhealing/) healing, by contrast, stops at `ConditionYellow` unless [`SelfHealingCap`](/keys/selfhealingcap/) or [`SelfHealCap`](/keys/selfhealcap/) sets a different ceiling. [Repair](/systems/repair/) covers both kinds of healing.

When an object whose type sets the flag is destroyed, structures included, it spills Tiberium of the first type in the rules into the five cells north-west, north, east, south and west of it; its own cell gets none. An empty cell that can take Tiberium receives it at a random growth stage from the first to the third. A cell that already holds that Tiberium grows by up to two stages. The `TIBERIUM_HEAL` ability does not cause the spill.
