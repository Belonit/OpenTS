---
key: AITriggerFailureWeightDelta
summary: The amount added to an AI trigger's weight each time a team of its first TeamType fails.
see_also: ["system:ai-team-production", AITriggerSuccessWeightDelta, AITriggerTrackRecordCoefficient]
when_omitted:
  kind: value
  value: "-1"
---

Each time a team counts as a failure, this value is added to the current weight of every AI trigger whose first TeamType is the team's TeamType. Because it is added, only a negative value lowers the weight. The trigger's [history term](/systems/ai-team-production/#the-track-record), scaled by [`AITriggerTrackRecordCoefficient`](/keys/aitriggertrackrecordcoefficient/) and counted only when the scaled term is negative, is added at the same time. The new weight is clamped between the trigger's minimum and maximum weight.

A team counts as a failure when it is removed for any reason without having reached the [Success](/mapping/missions/tmission-success/) team mission in its script, however well it fought.
