---
key: BarracksRatio
summary: Parsed barracks share of a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", BarracksLimit, BuildBarracks]
when_omitted:
  kind: value
  value: ".16"
---

No step of computer base planning reserves a share of the base for any structure type. A barracks only gets an earlier place in [the base plan](/systems/ai-base-building/#building-the-plan). If the first [`BuildBarracks`](/keys/buildbarracks/) entry the house's [acted country](/keys/actslike/) may own is a candidate for the plan, it is moved to the front of the candidate order. It still enters the plan only once its prerequisites are met, and it is queued first among the structures added in the pass that meets them.
