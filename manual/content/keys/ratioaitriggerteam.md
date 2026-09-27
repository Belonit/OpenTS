---
key: RatioAITriggerTeam
summary: The percent chance that a house reads its AI triggers when its team countdown expires.
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: "100"
---

Each time the house's [team pass](/systems/ai-team-production/#when-the-pass-runs) runs, it rolls a number from `1` to `100`. The pass draws an AI trigger only when the roll is at or below this value and the house's [AI-trigger switch](/systems/ai-team-production/#when-the-pass-runs) is on. A failed roll raises no team and restarts the countdown, so a lower value makes the house raise AI trigger teams less often. At `100` or above the roll always passes, and at `0` or below the house never raises an AI trigger team.

Only a campaign mission reads its house records, so this is a campaign setting. The [Ratio of AI trigger teams...](/mapping/actions/taction-set-ai-trigger-team-ratio/) trigger action replaces the value during the scenario, in any game type.
