---
key: DeleteOnStateLimit
summary: Kills a particle the moment its animation reaches the last state.
see_also: ["EndStateAI", "StartStateAI", "MaxEC"]
when_omitted:
  kind: value
  value: "no"
---

With `DeleteOnStateLimit=yes`, a particle is removed as soon as its animation state reaches [`EndStateAI`](/keys/endstateai/).

Without it, reaching that state does not end the particle. What happens depends on its [behavior](/keys/behaveslike/#scope-particletype):

- A `Gas`, `WeakGas` or `Web` particle restarts its animation at state 0.
- A `Smoke` or `Fire` particle stays at its last state and keeps showing that frame.

Either way, the particle then lives until its [`MaxEC`](/keys/maxec/) lifetime runs out or its behavior ends it in another way.

The flag cannot extend a particle's life. A particle whose lifetime runs out before its animation finishes is removed mid-animation, with the flag set or not.

`Spark` and `Railgun` particles have no animation states, so the flag has no effect on them.
