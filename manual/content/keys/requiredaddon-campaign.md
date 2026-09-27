---
key: RequiredAddon
summary: The expansion a campaign belongs to, which decides when the mission list offers it.
see_also: ["Description", "Scenario"]
when_omitted:
  kind: value
  value: "0"
---

`0` marks a base-game campaign and `1` a Firestorm campaign. The mission list offers base-game campaigns only while no expansion is running, and Firestorm campaigns only while Firestorm is running, so the two sets never appear together.

A number from `2` to `31` names no expansion, so that campaign is never offered. `-1` is offered whenever any expansion is running. Other numbers are not supported.
