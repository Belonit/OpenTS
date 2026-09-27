---
key: DamageRadius
scope: animtype
label: Animation strike reach
see_also: ["Damage", "Warhead", "Elasticity", "BounceAnim"]
when_omitted:
  kind: value
  value: "0"
---

The reach of a thrown animation's strike, in leptons (256 to a cell). When a contact counts as a strike, each object in the struck cell within this reach takes [`Damage`](/keys/damage/#scope-animtype) through the animation's [`Warhead`](/keys/warhead/#scope-animtype). The shipped debris uses `DamageRadius=50` to `100`, about a fifth to two fifths of a cell, and the meteors use `DamageRadius=300`.

The reach is measured as the sum of the two horizontal distances along the map axes, so it covers a diamond, not a circle. Height is ignored. A value of `0` reaches only an object centered exactly on the point of impact.

Only objects in the struck cell are checked. A reach wider than a cell still cannot damage anything in a neighboring cell.

Only a strike deals this damage. [`Elasticity`](/keys/elasticity/#scope-animtype) decides whether a contact is a strike, and an ordinary landing by a shipped bouncing animation never is.

The blast that comes with [`ExpireAnim`](/keys/expireanim/#scope-animtype) on landing is separate and ignores this setting. It damages objects in the landing cell and the eight around it, and the warhead's [`Spread`](/keys/spread/#scope-warheadtype) sets how the damage falls off across them.
