---
key: BounceSound
scope: animtype
label: Animation bounce sound
see_also: ["BounceAnim", "ExpireSound", "Elasticity", "Report"]
when_omitted:
  kind: value
  value: none
---

The sound plays where a thrown animation strikes something, under the same conditions as [`BounceAnim`](/keys/bounceanim/#scope-animtype). It plays on the contact that ends the flight when [`Elasticity`](/keys/elasticity/#scope-animtype) counts that contact as a strike, and not when the animation settles. It plays on water as well as on land.

A name that matches no sound is ignored, so a misspelled name leaves the animation with no bounce sound.
