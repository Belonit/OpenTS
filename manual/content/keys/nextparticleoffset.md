---
key: NextParticleOffset
summary: How far a successor particle is placed from the one it replaces.
see_also: ["NextParticle", "Radius"]
when_omitted:
  kind: value
  value: 0,0,0
---

```ini title="rules.ini"
[MYGASSEED] ; a ParticleType registered in [Particles]
Image=gaslrgmk
BehavesLike=Gas
MaxEC=448
EndStateAI=11
NextParticle=MYGASCLOUD ; a ParticleType registered in [Particles]
NextParticleOffset=0,0,150 ; the cloud forms 150 leptons above where the seed expired
```

The successor named by [`NextParticle`](/keys/nextparticle/) appears this far from the point where the particle expired, as X, Y and Z offsets in leptons. Only gas, weak gas and web systems use it. A smoke system places its two successors with [`Radius`](/keys/radius/) instead, and fire, spark and railgun systems create no successors.

The offset belongs to the expiring type, so each link of a chain places the next one. If every type in a chain sets `NextParticleOffset=0,0,150`, each successor appears 150 leptons above the point where the one before it expired. A successor placed below the ground is raised to ground level.

:::note[A value with fewer than three components reads as the default]
`NextParticleOffset=0,0` is short of the three components an offset needs, so the key reads as its default and the debug log records the line; [INI syntax](/formats/ini-syntax/#malformed-values) has the rule.
:::
