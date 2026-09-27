---
key: LaserColor
summary: The color of the beam a railgun system draws.
see_also: [BehavesLike, Laser, LaserInnerColor, LaserOuterColor]
when_omitted:
  kind: value
  value: "0,0,0"
---

The value is three comma-separated channel values, red, green and blue, each from `0` to `255`. The beam is a single line in this color, so this color is its whole appearance. Only a `Railgun` [system](/keys/behaveslike/#scope-particlesystemtype) with [`Laser=yes`](/keys/laser/) reads it.

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
Laser=yes
LaserColor=255,128,0 ; orange
```

Above the lowest detail setting, the beam blends the pixels it crosses toward this color, but only in the channels this color sets above `0`. In a channel set to `0`, those pixels keep their value. `255,128,0` therefore shifts the red and green of what the beam crosses and keeps its blue, and a color of `0,0,0` draws no visible beam.

At the lowest detail setting, the beam is painted flat in this color as given, so `0,0,0` draws a black line there.

:::note[A malformed color keeps the previous value]
`LaserColor=255` gives one channel where three are needed, so the line is malformed and the beam keeps the color it had; [INI syntax](/formats/ini-syntax/#malformed-values) has the rule. A channel above `255` wraps around instead of being clamped: `256` reads as `0`.
:::
