---
key: FlameDamage2
summary: The warhead every damaging animation delivers its damage through.
see_also: ["FlameDamage", "Damage", "C4Warhead"]
when_omitted:
  kind: value
  value: none
---

Every animation whose [`Damage`](/keys/damage/#scope-animtype) is above zero deals that damage through this warhead. The one exception is the animation whose ID is exactly `INVISO`, which uses [`C4Warhead`](/keys/c4warhead/) instead.

Each time the animation advances a frame, it adds its `Damage` to a running total. Whenever the total reaches one point or more, the whole points go off as a blast at the animation's center, and the fraction carries over to the next frame. A new animation's total starts at one point, so the first frame it advances always sets off a blast. When the animation chains into its next type, the total starts again from zero.

An animation attached to a terrain object adds five times its `Damage` each frame. A fire burning on a tree therefore deals its damage five times as fast as the same fire on open ground.

These animations take no part in this:

- a [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype) animation, which is removed when it lands. Any damage it deals on landing goes through its [`Warhead=`](/keys/warhead/#scope-animtype);
- an animation placed by the [Play Anim At](/mapping/actions/taction-play-anim/) trigger action, which deals no damage.

With the key unset, every damaging animation except `INVISO` deals no damage, though its artwork still plays.
