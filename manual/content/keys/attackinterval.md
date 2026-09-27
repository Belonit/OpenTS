---
key: AttackInterval
summary: Parsed spacing between computer attacks that the engine never uses.
no_effect: true
see_also: ["system:ai-team-production", AttackDelay, TeamDelays]
when_omitted:
  kind: value
  value: "3"
---

No setting spaces a computer house's attacks on a fixed interval. Attacking forces reach the map as ordinary teams, raised one at a time by [the AI trigger pass](/systems/ai-team-production/#when-the-pass-runs). [`TeamDelays`](/keys/teamdelays/) sets how often that pass runs.
