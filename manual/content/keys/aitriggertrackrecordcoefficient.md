---
key: AITriggerTrackRecordCoefficient
summary: The multiplier applied to an AI trigger's history term when one of its teams fails.
see_also: ["system:ai-team-production", AITriggerFailureWeightDelta, AITriggerSuccessWeightDelta]
when_omitted:
  kind: value
  value: "1"
---

The history term is the trigger's successes so far minus half its runs so far. On a [failure](/systems/ai-team-production/#the-track-record), this value multiplies the term, and a positive result is replaced by `0` before it is added to the weight. Successes use the term unscaled, so this value has no effect on them.

Raising a positive value deepens the extra penalty for a trigger that has succeeded in fewer than half its runs. A trigger with at least one success in two gets no extra penalty. At `0`, a failure moves the weight by [`AITriggerFailureWeightDelta`](/keys/aitriggerfailureweightdelta/) alone.

A negative value reverses the effect. A failure then costs a trigger with a good record extra weight, and costs a trigger with a poor record only the failure delta.
