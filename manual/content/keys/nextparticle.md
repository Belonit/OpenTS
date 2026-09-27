---
key: NextParticle
summary: The particle type created in place of this one when it expires.
see_also: ["NextParticleOffset", "Radius", "MaxEC", "BehavesLike"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[MYGASCLOUD] ; a ParticleType registered in [Particles]
Image=CLOUD1
BehavesLike=Gas
MaxEC=1000
EndStateAI=28
NextParticle=MYGASTHIN ; a thinner cloud takes its place as it expires

[MYGASTHIN] ; a ParticleType registered in [Particles]
Image=CLOUD1D
BehavesLike=Gas
MaxEC=50
EndStateAI=12
DeleteOnStateLimit=yes
; no NextParticle, so the chain ends here
```

The particle system holding the particle decides whether a successor appears, and how many:

- A gas, weak gas or web system replaces each expiring particle with one successor, placed at [`NextParticleOffset`](/keys/nextparticleoffset/) from the point where the original expired.
- A smoke system replaces it with two, thrown to either side by this type's [`Radius`](/keys/radius/). It ignores the offset.
- Fire, spark and railgun systems create no successors, so the setting has no effect on the types they hold.

A successor keeps the speed its predecessor had reached. Only a `Smoke` or `Fire` successor moves by that speed; `Gas`, `WeakGas` and `Web` particles do not move by speed at all. In a gas, weak gas or web system the successor also keeps the sideways drift the predecessor had built up. In a smoke system the successor usually starts one step more translucent, as [`Translucency`](/keys/translucency/#scope-particletype) describes. Everything else, including lifetime, damage, behavior and artwork, comes from the successor's own section.

`NextParticle=<none>` clears the setting. Any other name the game has not seen, `none` included, registers a new particle type under that name. That type reads a section of the same name if the rules have one, even when `[Particles]` does not list it. With no such section, its particles do nothing and disappear after their first frame.

:::danger[Do not name a damaging Fire type as a successor]
A `Fire` particle spares the object that fired its particle system, and a successor carries no link to that system. A `Fire` successor with [`Damage`](/keys/damage/#scope-particletype) therefore stops the game the first time it applies damage while a live object shares its cell. The same type is safe as the particle a system holds directly.
:::

:::danger[In a smoke system every link doubles the particle count]
Each expiring particle is replaced by two, so a chain of three types turns one particle into four, and a fourth link into eight. A chain that leads back to a type already in it never ends: the count doubles every generation until the game runs out of memory. Gas, weak gas and web systems replace one with one, so a loop there holds the count steady but leaves a cloud that never finishes dying.
:::
