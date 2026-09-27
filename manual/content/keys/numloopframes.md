---
key: NumLoopFrames
summary: Parsed frame count that the engine never uses.
no_effect: true
see_also: ["StartFrame", "EndStateAI", "StateAIAdvance"]
when_omitted:
  kind: value
  value: "1"
---

Other keys control a particle's animation loop. [`EndStateAI`](/keys/endstateai/) and [`StateAIAdvance`](/keys/stateaiadvance/) set how long its sequence runs, and [`DeleteOnStateLimit`](/keys/deleteonstatelimit/) whether the particle ends there. No drawing or animation code reads this key.
