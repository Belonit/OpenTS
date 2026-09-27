---
key: TotalAITeamCap
summary: Team count at which a house stops starting teams from AI triggers, one entry per difficulty.
see_also: ["system:ai-team-production", MaximumAIDefensiveTeams, MinimumAIDefensiveTeams]
when_omitted:
  kind: value
  value: ""
  note: The list stays empty, and the first lookup crashes the game.
---

A house stops starting teams from [AI triggers](/systems/ai-team-production/) once it holds this many teams. Every team the house owns counts, however it was created, including teams the scenario creates.

The list holds one entry per difficulty, hardest first. A computer house uses the first entry when the player chose the hardest setting and the last when they chose the easiest; [From the setting to a slot](/systems/difficulty/#from-the-setting-to-a-slot) gives the mapping. The stock `14,12,10` therefore caps a computer house at 14 teams on the hardest setting and 10 on the easiest.

Give all three entries. With the key omitted, the first time a house draws for an AI trigger stops a Debug build at an assertion and crashes a Release build. A shorter list gives each difficulty without an entry an unpredictable cap.

:::caution[A house at the cap deletes defensive teams]
A house at or above the cap deletes its oldest defensive team if at least half its teams, rounded down, are defensive. It then draws an AI trigger only if that deletion brought it back under the cap. [The team budget](/systems/ai-team-production/#the-team-budget) gives the full rule.
:::
