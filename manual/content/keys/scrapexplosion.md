---
key: ScrapExplosion
summary: The animations a destroyed object leaves behind while scrap wreckage is switched on.
see_also: [Explosion, ScrapMetal, Explodes, DebrisTypes, "system:destruction-and-debris"]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
Explosion=TWLT070,FRAG1,FRAG3      ; AnimTypes registered in [Animations]
ScrapExplosion=FBALL1_SCRAP,FRAGG1_SCRAP
```

While [`ScrapMetal`](/keys/scrapmetal/) is on, a destroyed object plays animations from this list instead of from its [`Explosion`](/keys/explosion/) list. They are picked and placed exactly as `Explosion` describes, exceptions included. A type that leaves this list empty keeps its `Explosion` animations, so a ruleset can convert its types a few at a time.

Both lists are read whatever the switch is set to, and the choice between them is made when the object is destroyed. One set of rules therefore serves games played with scrap wreckage on and off.
