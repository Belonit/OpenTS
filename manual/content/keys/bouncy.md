---
key: Bouncy
summary: Lets a ballistic projectile rebound off the surface it lands on instead of detonating there.
see_also: [Elasticity, Arcing]
when_omitted:
  kind: value
  value: "no"
---

Without this setting, a projectile detonates where it first lands. Only a projectile whose [`ROT`](/keys/rot/#scope-bullettype) is zero ever lands. One with a `ROT` above zero detonates when it arrives at its target, so the setting has no effect on it.

Each rebound keeps the fraction of the projectile's speed that [`Elasticity`](/keys/elasticity/#scope-bullettype) sets and reflects off the slope of the ground it landed on, so a projectile landing on a ramp is thrown off downhill. Bridges count as ground. A projectile that falls onto a bridge deck bounces off the deck, and one that rises into a deck from below bounces off its underside.

A bouncy projectile still detonates on landing when an object that is not friendly stands in its cell. Friendly means belonging to the firer's house or to an ally of it. The cell tested is the one the projectile was in at the start of that frame, which is normally the cell it lands in. The firer's cell never counts.

Between landings, the projectile also goes off when it comes within half a cell of an object that is not friendly and stands in the cell the projectile is now in. Only one object in that cell is checked.

Two limits end the bouncing:

- The third landing detonates the projectile wherever it came down, so it rebounds at most twice.
- A projectile moving slower than 10 leptons a frame and lying within 10 leptons of the ground detonates where it lies.

[Ballistic flight](/systems/projectile-flight/#ballistic-flight) gives the full landing rules.

```ini title="rules.ini"
[MYGRENADE] ; a BulletType, registered by a weapon naming it as its Projectile
Image=DISCUS
Arcing=yes
Bouncy=yes
Elasticity=0.5 ; half its speed is kept on each rebound
```
