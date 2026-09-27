---
key: IsJuggernaut
summary: Marks a deployed structure as a Juggernaut, which stows its gun before it packs up.
see_also: [DeploysInto, UndeploysInto, StartPitch, StartFacing]
when_omitted:
  kind: value
  value: "no"
---

The flag makes the structure one of the eight [deployed-vehicle kinds](/keys/deploysinto/), which deploy and [pack up](/keys/undeploysinto/) on the vehicle's own cell.

When [an EM pulse](/systems/emp-pulse/#what-a-pulse-reaches) stuns the structure, sparks appear on it.

Two effects are specific to this flag, and both stow the gun:

- Before a Juggernaut is sold or packed up, it turns its barrel back to [`StartPitch`](/keys/startpitch/) and its body to [`StartFacing`](/keys/startfacing/). Nothing else in the sequence begins until both arrive.
- The vehicle created when it packs up starts with its barrel at `StartPitch`.

A computer-owned Juggernaut given a target beyond the range of its primary weapon drops the target and deconstructs, unless it is immobilized. With an `UndeploysInto` type it packs up; without one it is sold. A primary weapon whose projectile is anti-aircraft skips this range test. [`TickTank=yes`](/keys/ticktank/) and [`Artillary=yes`](/keys/artillary/) structures behave the same way.
