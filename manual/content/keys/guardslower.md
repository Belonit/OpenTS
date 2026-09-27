---
key: GuardSlower
summary: Weights the team's center toward the members it counts as slow.
see_also: [Stray, TechLevel, DeploysInto, "system:ai-team-execution"]
when_omitted:
  kind: value
  value: "no"
---

`GuardSlower=yes` counts each slow member twice when the team averages its members' positions to find its [center](/systems/ai-team-execution/#the-teams-center). The average is usually discarded: the member nearest the team's target becomes the center whenever it could move into the averaged cell. The weighting therefore changes where the team gathers only when that member cannot enter the averaged cell, because the ground is impassable or something is standing there. On open ground the setting has no effect.

A member counts as slow when its type sets [`TechLevel=-1`](/keys/techlevel/#scope-aircrafttype) or names a [`DeploysInto`](/keys/deploysinto/) structure. A member without a primary weapon is not slow for that reason alone.

The setting does not make fast members wait for slow ones; see [Settings and state without effect](/systems/ai-team-execution/#settings-and-state-without-effect).
