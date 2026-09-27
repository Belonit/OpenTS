---
key: Damage
scope: animtype
label: Animation damage
when_omitted:
  kind: value
  value: "0.0"
---

An ordinary animation deals this damage around itself while it plays. The amount builds up each time the animation advances a frame. Whenever the total reaches one or more whole points, those points are dealt together as one explosion at the animation's position, and the fraction carries over. The explosion uses the [`FlameDamage2`](/keys/flamedamage2/) warhead, or [`C4Warhead`](/keys/c4warhead/) for the animation named `INVISO`. A fractional value such as `0.03` deals one point about every 33 animation frames, and `3` deals one explosion of 3 points every animation frame.

An animation attached to a terrain object, such as a burning tree, builds up damage five times as fast.

An animation placed by the [Play Anim At](/mapping/actions/taction-play-anim/) or [Drop Zone Flare](/mapping/actions/taction-dz/) trigger action deals none of this damage.

A thrown animation ([`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype)) deals no damage while it plays. It uses this value when it lands, through its own [`Warhead`](/keys/warhead/#scope-animtype):

- A contact that counts as a strike damages objects within [`DamageRadius`](/keys/damageradius/#scope-animtype) in the struck cell.
- The blast that comes with [`ExpireAnim`](/keys/expireanim/#scope-animtype) damages objects in the landing cell and the eight around it. An animation with no `ExpireAnim`, or one that lands on water, deals no blast.

An animation with no `Warhead` deals neither.
