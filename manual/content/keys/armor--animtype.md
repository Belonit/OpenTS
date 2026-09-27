---
key: Armor
scope: animtype
label: Animation armor class
no_effect: true
see_also: [Damage, Immune]
when_omitted:
  kind: value
  value: none
---

An armor class matters only to an object that takes damage or that a unit weighs as a target. An animation is neither. [`Strength`](/keys/strength/#scope-animtype) lists the damage paths and why none of them reaches an animation.

An animation can deal damage instead. [`Damage`](/keys/damage/#scope-animtype) sets what it applies to whatever is under it, and that damage is scaled by the armor class of each object it hits.
