---
key: MaximumQueuedObjects
summary: The most entries a production queue may hold.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "5"
---

A production slot holds one object in progress and up to this many orders waiting behind it. At the default `5`, a player can have six objects of one category, such as infantry, on order at once. An order past the limit is refused, and the player who gave it hears [`ScoldSound`](/keys/scoldsound/).

Structures never queue, so the limit does not apply to them. [The queue](/systems/production/#the-queue) describes what a second structure order does instead.
