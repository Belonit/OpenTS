---
key: RatioTeamUnits
summary: Parsed vehicle share that the engine never uses.
no_effect: true
see_also: [RatioTeamAircraft, RatioTeamInfantry, RatioAITriggerTeam, "system:ai-team-production"]
when_omitted:
  kind: value
  value: "75"
---

The house stores this value, but nothing uses it. The [Ratio of team units...](/mapping/actions/taction-set-team-unit-ratio/) trigger action can change the value during the scenario, also with no effect.

[`RatioTeamAircraft`](/keys/ratioteamaircraft/) and [`RatioTeamInfantry`](/keys/ratioteaminfantry/) are unused in the same way. [`RatioAITriggerTeam`](/keys/ratioaitriggerteam/) is the only one of the four house ratios that has an effect.
