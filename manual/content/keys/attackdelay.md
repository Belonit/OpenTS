---
key: AttackDelay
summary: Parsed multiplier on a house's first-attack countdown, which no decision reads.
no_effect: true
see_also: ["system:ai-team-production", AttackInterval, TeamDelays]
when_omitted:
  kind: value
  value: "5"
---

Each house, computer or human, gets a countdown when it is created: a random 450 to 1800 [frames](/glossary/#frame), multiplied by this value and truncated to a whole number. Nothing happens when it expires.

When a computer house first attacks depends on [the AI trigger pass](/systems/ai-team-production/#when-the-pass-runs) and the teams it raises.
