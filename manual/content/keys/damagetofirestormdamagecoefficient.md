---
key: DamageToFirestormDamageCoefficient
summary: How much firestorm charge a raised wall loses per point of damage aimed at one of its sections.
see_also: [FirestormWall, ChargeToDrainRatio, "system:laser-fences"]
when_omitted:
  kind: value
  value: "0.1"
---

While a house's firestorm wall is up, its [`FirestormWall=yes`](/keys/firestormwall/) sections [take no damage](/systems/laser-fences/#damage-while-the-wall-is-up). For a house a human is playing, each hit on a section shortens how long the wall stays up instead, and a larger coefficient brings the wall down sooner. [A computer house's wall](/systems/laser-fences/#computer-houses) does not drain, so firing on it never brings it down.

The hit's full damage, before armor and before any reduction for distance from the impact, is multiplied by this value. A splash that lands far from a section therefore costs the wall as much as a direct hit. The result is taken off the countdown of the house's firestorm superweapon in frames, rounded up to a whole frame, so every damaging hit costs at least one frame. The countdown never goes below zero. With `0.1`, a hit of 25 damage costs three frames.

A value written in an INI file can be stored slightly above what is written, as `.1` and `.05` are. A product that looks whole then costs one frame more. With `DamageToFirestormDamageCoefficient=.1`, a hit of 10 damage costs two frames; with the key omitted, it costs one.

```ini title="rules.ini"
[General]
DamageToFirestormDamageCoefficient=0.05   ; a hit of 30 damage costs two frames
```
