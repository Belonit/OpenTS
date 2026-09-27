---
key: AITriggerSuccessWeightDelta
summary: The amount added to an AI trigger's weight each time a team of its first TeamType succeeds.
see_also: ["system:ai-team-production", AITriggerFailureWeightDelta, AITriggerTrackRecordCoefficient]
when_omitted:
  kind: value
  value: "1"
---

Each time a team counts as a success, this value is added to the current weight of every AI trigger whose first TeamType is the team's TeamType. A team counts as a success once it has reached the [Success](/mapping/missions/tmission-success/) team mission in its script.

The trigger's [history term](/systems/ai-team-production/#the-track-record) is added at the same time when it is positive, and the result is clamped between the trigger's minimum and maximum weight. Once the weight is within that range, a value at least as large as the gap between the minimum and maximum takes the weight to its maximum on one success.
