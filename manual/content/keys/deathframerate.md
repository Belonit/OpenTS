---
key: DeathFrameRate
summary: The number of game frames each frame of a vehicle's wreck animation is held for.
see_also: ["DeathFrames", "MaxDeathCounter", "StartDeathFrame"]
when_omitted:
  kind: value
  value: "1"
---
Higher values play the wreck animation more slowly. The whole [`DeathFrames`](/keys/deathframes/) run takes about `DeathFrames × DeathFrameRate` game frames, at 15 game frames to the second.

[`MaxDeathCounter`](/keys/maxdeathcounter/) sets when the wreck explodes, counted in game frames from its destruction. If the run finishes first, the wreck holds its last frame until then. If `MaxDeathCounter` is reached first, the wreck explodes partway through the run.

Keep the value between `1` and `127`. The engine stores it in a single signed byte and then raises anything below `1` to `1`:

- `0` and negative values down to `-128` hold each frame for one game frame.
- Values from `128` to `256` wrap to zero or a negative number, so they also hold each frame for one game frame. `DeathFrameRate=200`, for example, plays at full speed, not slowly.
- Larger values wrap around again: `300` acts as `44`.
