---
key: WarRatio
summary: Parsed war factory share of a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", WarLimit, BuildWeapons]
when_omitted:
  kind: value
  value: ".1"
---

Nothing in the computer's base planning sets aside a share of the base for war factories. A war factory enters a generated plan like any other type, once its [`Prerequisite`](/keys/prerequisite/) list is met. The only special treatment goes to the first [`BuildWeapons`](/keys/buildweapons/) entry the house may own: it moves to second place in the order the planner tests types, as [Building the plan](/systems/ai-base-building/#building-the-plan) describes.
