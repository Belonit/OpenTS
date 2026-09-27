---
key: TechLevel
scope: global-rules
label: Multiplayer tech level
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "10"
---

The tech level setting of skirmish and network games starts at this value. The player can move it between 1 and 10 before the game begins. Every human and computer player's house then holds the chosen level. The map's [house sections](/keys/techlevel/#scope-house-per-scenario) are not read in these games.

A [client-launched](/formats/spawn-ini/) game ignores this key and uses its launch file's `TechLevel` instead.
