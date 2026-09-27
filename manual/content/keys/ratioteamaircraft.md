---
key: RatioTeamAircraft
summary: Parsed aircraft share that the engine never uses.
no_effect: true
see_also: [RatioTeamInfantry, RatioTeamUnits, RatioAITriggerTeam, "system:ai-team-production"]
when_omitted:
  kind: value
  value: "75"
---

The house stores this value, but nothing uses it. The [Ratio of team aircraft...](/mapping/actions/taction-set-team-aircraft-ratio/) trigger action can change the value during the scenario, also with no effect.

[`RatioTeamInfantry`](/keys/ratioteaminfantry/) and [`RatioTeamUnits`](/keys/ratioteamunits/) are unused in the same way. [`RatioAITriggerTeam`](/keys/ratioaitriggerteam/) is the only one of the four house ratios that has an effect.
