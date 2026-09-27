---
key: TiberiumExplosive
scope: scenarios
label: Scenario flag
no_effect: true
see_also: ["system:tiberium"]
when_omitted:
  kind: value
  value: "no"
  note: The special options are initialized with this built-in default when the game starts.
---

Nothing in the game reads this entry. To make a destroyed vehicle carrying Tiberium explode, set [`TiberiumExplosive`](/keys/tiberiumexplosive/#scope-global-rules) in `[CombatDamage]` instead.
