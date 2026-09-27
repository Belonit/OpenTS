---
key: StartColor1
summary: One end of the color range a spark or railgun particle is created at.
see_also: ["StartColor2", "ColorList", "ColorSpeed"]
when_omitted:
  kind: value
  value: 0,0,0
---

```ini title="rules.ini"
[MYWELDSPARK] ; a ParticleType registered in [Particles]
BehavesLike=Spark
MaxEC=500
XVelocity=16
YVelocity=16
ZVelocityRange=15
ColorList=(0,128,255),(255,255,255),(80,80,80),(0,0,0)
StartColor1=80,255,255 ; each spark is created somewhere between these two
StartColor2=255,255,100
ColorSpeed=.13
```

Each new particle starts at a random color on the blend between this color and [`StartColor2`](/keys/startcolor2/), so a burst is created as a spread of shades instead of one flat color. The value is a plain `red,green,blue` triplet with no brackets, unlike the entries of [`ColorList`](/keys/colorlist/). Each component is held in one byte, so `256` reads as `0`.

The starting color takes the place of the first `ColorList` entry for that particle. The particle blends from it to the list's second entry, then continues along the list as usual. If both `StartColor1` and `StartColor2` are black (`0,0,0`), the particle starts at the list's first entry instead, as most stock spark and railgun types do.

Only [`Spark` and `Railgun`](/keys/behaveslike/#scope-particletype) particles are drawn in these colors, and only a type with a `ColorList` picks a starting color at all. Particles of other behaviors draw their artwork and ignore both keys.

:::note[A partial triplet reads as the default]
`StartColor1=80` names one channel where three are needed, so the particles start at their default color and the debug log records the line. [INI syntax](/formats/ini-syntax/#malformed-values) has the rule.
:::
