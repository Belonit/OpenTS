---
key: Elasticity
scope: animtype
label: Animation bounciness
see_also: ["Bouncer", "BounceAnim", "BounceSound", "DamageRadius"]
when_omitted:
  kind: value
  value: "0.8"
---

The share of its speed a thrown animation keeps when it hits a surface: `1.0` keeps all of it and `0.0` keeps none. The value changes only the speed. The direction it rebounds in comes from the slope of the cell it hit.

A [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype) animation is removed at its first contact, so the rebound speed never carries it anywhere. This setting decides whether that contact counts as a strike or as settling.

Whether the contact settles depends on the speed left after it and on the animation's height above the ground, or above a bridge deck it is over. Each lepton of height counts as 1.4 of upward speed and is added to the vertical speed. That vertical figure and the horizontal speed combine like the sides of a right triangle. A result below `2.5` means the animation has settled. The test runs on every frame of the flight, so a slow animation close to the ground can settle just before it touches down.

Only a strike plays [`BounceAnim`](/keys/bounceanim/#scope-animtype) and [`BounceSound`](/keys/bouncesound/#scope-animtype) and deals the [`DamageRadius`](/keys/damageradius/#scope-animtype) damage. The impact effects run whether the animation strikes or settles, unless it ends low over water as [`ExpireAnim`](/keys/expireanim/#scope-animtype) defines it. They are the `ExpireAnim` animation and its blast, the [`ExpireSound`](/keys/expiresound/#scope-animtype), the spawns, and any Tiberium. Tiberium is not spread at bridge-deck height or above.

:::caution[`Elasticity=0.0` skips the strike effects on a landing]
An animation that keeps no speed settles whenever the contact leaves it at ground level. That covers landing on the ground, landing on a bridge deck, and hitting a building or wall close to the ground. Every bouncing animation in the shipped `art.ini` sets `Elasticity=0.0`, so none of them plays its bounce animation or sound or deals bounce damage when it lands in one of those places. A contact that leaves the animation away from ground level, above or below it, still counts as a strike, because the height alone passes the threshold. That happens when it rises into the underside of a bridge. It can also happen when it hits a cliff face, which can leave it back at its previous position in the air or below the surface of the higher cell.
:::
