---
key: StartStateAI
summary: The animation state a particle is created at.
see_also: ["EndStateAI", "StateAIAdvance", "DeleteOnStateLimit"]
when_omitted:
  kind: value
  value: "0"
---

The starting state also picks the first artwork frame the particle shows. `Gas`, `WeakGas`, `Smoke` and `Web` particles draw the frame their state names. A [`Fire`](/keys/behaveslike/#scope-particletype) particle draws the state offset into the block of frames for its firing direction, and `Spark` and `Railgun` particles draw no artwork.

```ini title="rules.ini"
[MYPUFF] ; a ParticleType registered in [Particles]
StartStateAI=1 ; open on artwork frame 1 instead of 0
```

The state is held in one signed byte, so a value above 127 wraps to a negative one.

Keep the figure below [`EndStateAI`](/keys/endstateai/). How the sequence plays from here depends on the particle's behavior:

- `Smoke` and `Fire` particles advance only while the state is below `EndStateAI`. Starting at or above it freezes the frame for the particle's whole life, and the [`DeleteOnStateLimit`](/keys/deleteonstatelimit/) ending is never reached.
- A `Fire` particle changes translucency only when its state steps onto [`Translucent25State`](/keys/translucent25state/) or [`Translucent50State`](/keys/translucent50state/). Starting at or past one of those states skips that fade.
- `Gas`, `WeakGas` and `Web` particles advance wherever they start. When they reach `EndStateAI` and `DeleteOnStateLimit` does not end them, they restart at state 0, not at this figure, so a type that starts partway into its sequence plays the opening frames on every loop after the first. One that starts above `EndStateAI` counts on past the end of its sequence instead of looping.
