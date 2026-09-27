---
key: Strength
scope: animtype
label: Maximum strength
no_effect: true
see_also: [Crushable, Damage]
when_omitted:
  kind: value
  value: "0"
---

An animation has no strength in play, because nothing can damage, heal, or crush one:

- An explosion damages the objects occupying the cells it reaches, plus any aircraft, jumpjet infantry, and [`Jellyfish=yes`](/keys/jellyfish/) vehicles near a blast in the air. An animation never occupies a cell and is none of those.
- A vehicle crushes only objects occupying the cells it enters.
- A heal crate restores only objects owned by the house that opened it, and an animation has no owner.

No other gameplay path reads the value.

The damage an animation deals to objects beneath it is set by [`Damage`](/keys/damage/#scope-animtype), which is unrelated to this key.
