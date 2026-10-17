---
key: Cloakable
summary: Whether an object of this type hides itself and recovers its cloak on its own.
see_also: ["system:cloaking"]
when_omitted:
  kind: value
  value: "no"
---

A cloakable object hides itself whenever nothing on the [list of refusals](/systems/cloaking/#starting-a-cloak) applies, and it starts hiding again after every event that forces it out.

Each vehicle, infantryman, aircraft and structure copies the flag from its type when it is created, and every later test reads the object's copy. The ability can therefore be gained during a match. A [cloak crate](/keys/crateradius/) sets the copy on every object on the ground near the crate, whatever house owns it.

An object without the flag can still be hidden in two ways. A [cloaking field](/systems/cloaking/#cloaking-fields) covering its cell hides it only while the cover lasts. The `CLOAK` [veteran ability](/systems/veterancy/#abilities) works like the flag: the object hides itself and starts hiding again on its own.
