---
key: MaxDeathCounter
summary: The number of game frames a destroyed vehicle with death frames lingers as a wreck before it explodes.
see_also: ["DeathFrames", "DeathFrameRate", "StartDeathFrame"]
when_omitted:
  kind: computed
  note: The derived StartDeathFrame plus DeathFrames, or -1 for a vehicle with no death frames.
---

A vehicle with [`DeathFrames`](/keys/deathframes/) above `0` stays on the map as a wreck when it is destroyed. The wreck explodes and is deleted once this many game frames have passed since its destruction. The value is a duration, not a frame number. It has no effect on a vehicle whose `DeathFrames` is `0`.

The death animation runs for `DeathFrames × DeathFrameRate` game frames and then holds its last frame. A longer value leaves the wreck on that last frame for the rest of the time, and a shorter one cuts the animation off.

Left unset, the value is longer than the death animation at the default [`DeathFrameRate`](/keys/deathframerate/), so the wreck holds its last frame for a while before it explodes.
