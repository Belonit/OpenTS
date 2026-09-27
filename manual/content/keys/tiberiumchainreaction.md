---
key: TiberiumChainReaction
summary: Sets off the Tiberium in the cell the animation starts on.
see_also: ["system:tiberium", "TiberiumExplosionDamage", "Debris"]
when_omitted:
  kind: value
  value: "no"
---

When the animation starts on a cell that holds Tiberium, it removes all the Tiberium from that cell and sets off an explosion there. [Damage](/systems/tiberium/#damage) covers the explosion's damage and the debris it can leave.

The cell is checked when the animation starts, not while it plays. An animation created with a delay starts when the delay ends, not when it is created. An animation that [`RandomLoopDelay`](/keys/randomloopdelay/) pauses between passes starts again when each pause ends, so the cell is checked again then. Tiberium that reaches the cell between these checks is not set off. An animation that switches to this type through [`Next`](/keys/next/) is checked when it switches.

Only the one cell is set off. Unlike Tiberium set off by a weapon, the explosion does not set off neighboring Tiberium in turn.

An animation placed by [Play Anim At](/mapping/actions/taction-play-anim/) still sets off the Tiberium under it, because the action marks it harmless only after it has started. A type it later switches to through `Next` plays no [`Report`](/keys/report/#scope-animtype) sound and sets off no Tiberium.
