---
key: Warhead
scope: animtype
label: Animation warhead
see_also: ["Damage", "DamageRadius", "ExpireAnim"]
when_omitted:
  kind: value
  value: none
---

The warhead delivers the [`Damage`](/keys/damage/#scope-animtype) of a thrown animation, one with [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype), when it lands. Landing deals damage in two ways:

- Each object in the landing cell within [`DamageRadius`](/keys/damageradius/#scope-animtype) of the landing point takes the damage.
- If the animation names an [`ExpireAnim`](/keys/expireanim/#scope-animtype), a blast of the same damage goes off at the landing point. There is no blast when the animation lands in water, unless it lands on a bridge.

The warhead's armor multipliers and its [`Spread`](/keys/spread/#scope-warheadtype) decide what the damage is worth against each target. Its [`Bright`](/keys/bright/#scope-warheadtype) flag makes the blast throw a flash of light.

With no warhead, landing deals no damage and throws no light. The animation still flies, starts its expire animation and plays its sounds, and it still craters or spreads tiberium where its other settings ask for it.

The key has no effect on an animation that is not thrown. Such an animation with `Damage` above `0` damages the area around its position through the [`FlameDamage2`](/keys/flamedamage2/) warhead, or through [`C4Warhead`](/keys/c4warhead/) for the animation named `INVISO`, whatever this key says.
