---
key: UseMinDefenseRule
summary: Whether a house must hold its minimum number of defensive teams before any other AI trigger may spring.
see_also: ["system:ai-team-production", MinimumAIDefensiveTeams, IsBaseDefense]
when_omitted:
  kind: value
  value: "yes"
---

With the rule on, a computer house that holds fewer defensive teams than [`MinimumAIDefensiveTeams`](/keys/minimumaidefensiveteams/) sets for its difficulty may spring only defensive AI triggers. A defensive team is one whose TeamType sets [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-teamtype). A trigger is defensive when every TeamType it names is defensive.

With the rule off, `MinimumAIDefensiveTeams` has no effect, and a house with an enemy may spring any trigger even when it holds no defensive teams.

A house with no enemy is still [held to defensive triggers](/systems/ai-team-production/#defensive-teams-and-the-enemy) whatever this setting says.
