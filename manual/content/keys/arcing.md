---
key: Arcing
summary: Aims the weapon by solving a ballistic arc to the target instead of pointing straight at it.
see_also: [Floater, Inaccurate, Bouncy, Lobber, Gravity]
when_omitted:
  kind: value
  value: "no"
---

`Arcing=yes` changes how the shot is aimed and how the weapon's reach is judged. It does not choose how the projectile flies. A projectile with no [`ROT`](/keys/rot/#scope-bullettype) falls under gravity either way, but without `Arcing=yes` its launch pitch is not aimed to land it on the target.

Use `Arcing=yes` only on a projectile with no `ROT`. A projectile whose `ROT` is above zero leaves the firer at 1 lepton a frame, and no arc at that speed reaches a target any distance away, so the weapon does not fire. The firer still counts the target as in range, because the range test uses the weapon's [`Speed`](/keys/speed/#scope-weapontype), and it keeps trying.

**Aiming.** The firer launches the shot along a ballistic arc that lands on the target's predicted position. The arc is worked out from the launch speed and [`[AudioVisual] Gravity`](/keys/gravity/), halved for a [`Floater=yes`](/keys/floater/) projectile. [What the shot leaves with](/systems/projectile-flight/#what-the-shot-leaves-with) explains the launch speed. The high, lobbed arc is used when the weapon is [`Lobber=yes`](/keys/lobber/), or when the target stands higher above the firer than it is away horizontally. Otherwise the flat arc is used.

When no arc at the launch speed reaches the target, the weapon does not fire. No projectile is created, no ammunition is spent and no reload delay starts, so the firer can try again at once.

**Reach.** An arcing weapon counts a target as in range when an arc at the weapon's launch speed can reach it. The distance is not compared with the weapon's [`Range`](/keys/range/#scope-weapontype). A projectile with no `ROT` is launched at a speed worked out from `Range`, which reaches about 1.2 times `Range` over level ground. A target lower than the firer can therefore be hit from farther away, and a higher one only from closer.

Two limits still apply to an arcing weapon:

- A target closer than the weapon's [`MinimumRange`](/keys/minimumrange/) is out of range.
- A target in a bridge cell that stands three or more terrain levels above the firer is never in range.

**Aircraft.** An aircraft also needs a valid arc before it fires. It then launches a projectile with no `ROT` level along its heading, so the shot does not follow the arc.

**Clearance.** An arc passes over walls and structures only where it flies high enough. A projectile with no `ROT` that crosses a cell less than 150 leptons above the ground lands on any wall or structure in that cell, except a structure of the firer's house or its allies. A [`Bouncy=yes`](/keys/bouncy/) projectile rebounds from that landing; any other projectile detonates there. [Ballistic flight](/systems/projectile-flight/#ballistic-flight) lists the other exceptions.

A [`High=yes`](/keys/high/#scope-overlaytype) overlay sets off any projectile that crosses its cell less than 100 leptons above the ground, unless the projectile is itself [`High=yes`](/keys/high/#scope-bullettype).

**Scatter.** Pairing the setting with [`Inaccurate=yes`](/keys/inaccurate/) makes the shot scatter: the aim point is moved by up to [`BallisticScatter`](/keys/ballisticscatter/) before the arc is worked out. Neither setting scatters a shot on its own.
