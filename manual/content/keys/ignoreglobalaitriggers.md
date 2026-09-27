---
key: IgnoreGlobalAITriggers
summary: Whether the scenario passes over every AI trigger that was not defined by the map itself.
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: "no"
---

With `yes`, the computer houses in this scenario draw only on the AI triggers the map defines. The AI triggers read from `AI.INI`, and from `AIFS.INI` when the Firestorm expansion is enabled, are [rejected as candidates](/systems/ai-team-production/#which-triggers-are-eligible) for every house. A map entry with the same name as one of those triggers replaces it and counts as the map's own.

A map that sets this and defines no AI triggers leaves its computer houses with no AI trigger to build teams from.
