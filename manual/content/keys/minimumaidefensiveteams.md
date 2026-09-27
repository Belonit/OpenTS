---
key: MinimumAIDefensiveTeams
summary: The number of defensive teams a house must hold before any non-defensive AI trigger may spring, one entry per difficulty.
see_also: ["system:ai-team-production", UseMinDefenseRule, MaximumAIDefensiveTeams, IsBaseDefense]
when_omitted:
  kind: value
  value: ""
  note: The list stays empty and the difficulty slot is used to index it anyway, reading storage that was never allocated.
---

While a house owns fewer defensive teams than its entry, it considers only [defensive AI triggers](/systems/ai-team-production/#defensive-teams-and-the-enemy). A defensive team is one made from an [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-teamtype) TeamType, and teams a map trigger creates count too. The limit applies only while [`UseMinDefenseRule=yes`](/keys/usemindefenserule/).

A house with no defensive trigger it can spring therefore springs no AI trigger at all until it owns enough defensive teams.

Each house reads the entry for its [difficulty slot](/systems/difficulty/#the-per-difficulty-lists). For a computer house, entry 0 applies at the Hard setting and entry 2 at Easy.
