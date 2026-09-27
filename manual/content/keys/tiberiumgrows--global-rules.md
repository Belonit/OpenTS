---
key: TiberiumGrows
scope: global-rules
label: Multiplayer default
no_effect: true
see_also: ["system:tiberium"]
when_omitted:
  kind: value
  value: "yes"
---

A game against other machines always uses fast Tiberium growth. A single-player mission sets it with the [`TiberiumGrows` entry in `[SpecialFlags]`](/keys/tiberiumgrows/#scope-scenarios), which also describes the skirmish case.
