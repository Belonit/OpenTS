---
key: LightSize
summary: How strong a light a particle system casts.
see_also: [BehavesLike, OneFrameLight, ParticleCap, SparkSpawnFrames]
when_omitted:
  kind: value
  value: "0"
---

Sets how large and bright a system's glow is. `0` or below casts no light.

`64` draws the glow at full size and brightness, and lower values shrink and dim it in proportion. `32` gives a glow about half as large and bright, and the stock systems' `21` and `25` give about a third and two fifths.

The glow is drawn from 64 numbered ramps, each wider and brighter than the one before. On each frame of the light, the game picks a ramp and scales its number by this value divided by `64`.

```ini title="rules.ini"
[MyWeldingSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Spark
HoldsWhat=MyWeldingSpark ; a ParticleType registered in [Particles]
ParticleCap=25
SparkSpawnFrames=20
LightSize=25
OneFrameLight=true
```

[`OneFrameLight`](/keys/oneframelight/) chooses which of two lights the system casts at this strength:

- With `OneFrameLight=yes`, a system of any behavior draws its glow on every frame it holds a particle, reduced as it empties. That page describes this light.
- With `OneFrameLight=no`, only a `Spark` [system](/keys/behaveslike/#scope-particlesystemtype) casts a light, and only at the highest detail setting. It throws one glow if its first frame throws a burst. The glow lasts ten frames: it brightens over the first three and fades over the remaining seven.

:::danger[Keep `LightSize` at 75 or below]
For the flash a `Spark` system throws with `OneFrameLight=no`, values up to `65` use only the 64 glow ramps. From `66` to `75`, the brightest frames pick one of ten flat, evenly lit discs numbered after the ramps, so the glow changes shape at its peak. From `76` up, the brightest frames pick a number past the last disc. The game then reads whatever lies beyond the discs, with unpredictable results that can include a crash. The `OneFrameLight=yes` glow reaches the discs and the overrun only at higher values, so `75` is safe for both lights.
:::
