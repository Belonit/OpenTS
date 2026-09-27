---
key: MaximumAIDefensiveTeams
summary: The number of defensive teams above which a house passes over its defensive AI triggers, one entry per difficulty.
see_also: ["system:ai-team-production", MinimumAIDefensiveTeams, TotalAITeamCap, IsBaseDefense]
when_omitted:
  kind: value
  value: ""
  note: The list stays empty and the difficulty slot is used to index it anyway, reading storage that was never allocated.
---

A house passes over its [defensive AI triggers](/systems/ai-team-production/#defensive-teams-and-the-enemy) while it owns more defensive teams than its entry. A defensive team is one made from an [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-teamtype) TeamType. The comparison is strict, so an entry of `2` stops defensive triggers only once the house owns three defensive teams.

The limit deletes no team, and it holds only for the current AI trigger pass; the next pass counts again. It is tested only while the house has fewer teams than [`TotalAITeamCap`](/keys/totalaiteamcap/), or fewer defensive teams than half its team count, rounded down. Otherwise [the team budget](/systems/ai-team-production/#the-team-budget) deletes the house's oldest defensive team instead.

Each house reads the entry for its [difficulty slot](/systems/difficulty/#the-per-difficulty-lists). For a computer house, entry 0 applies at the Hard setting and entry 2 at Easy.
