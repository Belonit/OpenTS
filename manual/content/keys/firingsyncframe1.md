---
key: FiringSyncFrame1
summary: The countdown value at which the first round of a burst leaves a shape-drawn vehicle.
see_also: ["FiringSyncFrame2", "FiringFrames", "StartFiringFrame", "Burst"]
when_omitted:
  kind: value
  value: "-1"
---

The setting releases the round partway through the vehicle's firing animation, so the shot lines up with the artwork. At the default `-1` the round leaves first and the animation plays after it.

The value is matched against a countdown. When the vehicle starts to fire, the countdown begins at `2 × FiringFrames − 1` and falls by one each game frame. The frame drawn is the countdown halved, counting the run's first frame as 0, so the run plays from its last frame down to its first. `FiringSyncFrame1=8` releases the round while frame 4 is drawn, and frames 3 to 0 play after the shot. Each frame is held for two game frames, so `9` shows the same frame and releases one game frame earlier.

```ini title="art.ini"
[DEFENDER] ; the Image ID of the stock Core Defender
FiringFrames=12    ; the countdown runs 23 down to 0
FiringSyncFrame1=8 ; first round at frame 4 of the run
FiringSyncFrame2=3 ; second round at frame 1
```

The weapon's rate of fire decides when the animation can start. Once it has started, the round waits for the countdown to reach the value and then leaves at once, without waiting on the rate of fire again.

The setting covers only the primary weapon, and only the first round of each [`Burst`](/keys/burst/). A weapon with `Burst=1` has only first rounds, so every shot is tied. [`FiringSyncFrame2`](/keys/firingsyncframe2/) covers the second round. The secondary weapon and the third and later rounds of a burst are never tied to the animation.

:::caution[A value the countdown never reaches stops the weapon]
Keep the value between `0` and `2 × FiringFrames − 1`, or leave it at `-1`. Any other value is never matched, so the vehicle's primary weapon never fires. A vehicle with no [`FiringFrames`](/keys/firingframes/) has no countdown and fires normally whatever is set here.
:::
