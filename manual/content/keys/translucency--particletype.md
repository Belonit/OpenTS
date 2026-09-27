---
key: Translucency
scope: particletype
label: Particle fade
see_also: ["Translucent25State", "Translucent50State", "BehavesLike"]
when_omitted:
  kind: value
  value: "0"
---

`Translucency` sets how faded a particle of this type is when it is created. The game draws only three fade levels, and the value must land on one of them:

| Value | Particle is drawn |
| --- | --- |
| `25` | a quarter faded |
| `50` | half faded |
| `75` through `127` | three quarters faded |
| any other value, including `0` | solid |

Each particle keeps its level in one signed byte, so the value wraps around every 256. `128` through `255` wrap below zero and draw solid, while `281` acts as `25` and `306` as `50`.

Fading is drawn only at the High detail setting. At Medium detail every particle is drawn solid. At Low detail, `Smoke` and `Spark` particles are not drawn at all and the rest are drawn solid.

`Spark` and `Railgun` particles are drawn as single pixels with no artwork, and they ignore this setting.

The level can change after the particle is created:

- A [`Fire`](/keys/behaveslike/#scope-particletype) particle switches to `25` when its animation state reaches [`Translucent25State`](/keys/translucent25state/), and to `50` when it reaches [`Translucent50State`](/keys/translucent50state/).
- A smoke system adds `25` to each particle it emits once its spawn interval has grown past [`SpawnTranslucencyCutoff`](/keys/spawntranslucencycutoff/).
- When a smoke system replaces an expiring particle with its [`NextParticle`](/keys/nextparticle/) pair, each successor starts at its parent's current level and ignores its own type's `Translucency`. Five times in six, `25` is added to that level.

Those steps can push a level past `127`. It then wraps, and the particle is drawn solid again. A particle that starts at `25` wraps after five generations of successors that each add a step.

```ini title="rules.ini"
[MYSMOKEPUFF] ; a ParticleType registered in [Particles]
Image=SGRYSMK1
BehavesLike=Smoke
Translucency=25 ; a quarter faded when created
MaxEC=80
EndStateAI=20
```
