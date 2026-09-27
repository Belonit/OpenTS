---
key: CloakStop
summary: Whether the object must come to a halt before it may start hiding.
see_also: [Cloakable, "system:cloaking"]
when_omitted:
  kind: value
  value: "no"
---

A vehicle, infantryman or aircraft of this type does not start a cloak while it is moving. Once it stops, it may start one under the usual conditions in [Starting a cloak](/systems/cloaking/#starting-a-cloak). Moving does not remove a cloak the object already has, so an object that hid while standing still stays hidden while it travels.

An object whose rank grants the `CLOAK` [veteran ability](/systems/veterancy/#abilities) ignores this key and may start a cloak while moving.

A structure does not use the value.

:::caution[A cloaking field hides a moving object]
A [cloaking field](/systems/cloaking/#cloaking-fields) of the object's own house hides it while it moves, because the field does not check this key. A [`Cloakable=yes`](/keys/cloakable/) object hidden that way stays hidden after it leaves the field.
:::
