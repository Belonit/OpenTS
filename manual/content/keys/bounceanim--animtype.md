---
key: BounceAnim
scope: animtype
label: Animation bounce effect
see_also: ["BounceSound", "Elasticity", "DamageRadius", "ExpireAnim"]
when_omitted:
  kind: value
  value: none
---

The named animation plays where a thrown animation strikes something. A thrown animation is one with [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype). It can strike the ground, a bridge deck, or a building or wall in its path.

Not every contact is a strike. A contact that leaves the thrown animation with too little motion counts as settling and plays no bounce animation. [`Elasticity`](/keys/elasticity/#scope-animtype) decides which a contact is. Every bouncing animation in the shipped `art.ini` sets an `Elasticity` that makes an ordinary landing settle.

A thrown animation is removed on its first contact, whether it strikes or settles. The bounce animation therefore plays at most once, on the same frame as [`ExpireAnim`](/keys/expireanim/#scope-animtype). It appears where the thrown animation was one frame before the contact, so it can sit a short distance from the contact point where `ExpireAnim` appears.

The bounce animation also plays on water. There, splash animations replace the expiry animation and its blast, but the bounce animation is unaffected.

A name that matches no animation type still creates one under that name. It draws the shape file and reads the `art.ini` section of that name if they exist, so a misspelled name plays an animation with no artwork.
