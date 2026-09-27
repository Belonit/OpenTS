---
key: StartDeathFrame
summary: The frame a shape-drawn vehicle's wreck animation begins at.
see_also: ["DeathFrames", "DeathFrameRate", "MaxDeathCounter", "Facings"]
when_omitted:
  kind: computed
  note: Facings × (FiringFrames + WalkFrames + 1), or -1 for a vehicle with no death frames.
---

The death animation is one run, shared by every facing, starting at this frame.

The default places the death run after one walk run, one firing run and one extra frame for each facing. The extra frame matches the single standing frame per facing that a vehicle with [`FiringFrames`](/keys/firingframes/) gets by default. The default ignores [`StandingFrames`](/keys/standingframes/) and always counts one standing frame per facing. A vehicle whose `StandingFrames` is not `1` must set `StartDeathFrame`.

:::caution[Set MaxDeathCounter to change the wreck's lifetime]
[`MaxDeathCounter`](/keys/maxdeathcounter/) defaults to the default start frame plus [`DeathFrames`](/keys/deathframes/), computed before `StartDeathFrame` is read. Setting `StartDeathFrame` does not change that lifetime. Set `MaxDeathCounter` as well to choose how long the wreck lasts.
:::
