---
key: Sticky
summary: Parsed flag that the engine never uses.
no_effect: true
see_also: ["Damage"]
when_omitted:
  kind: value
  value: "no"
---

The name suggests that the animation attaches itself to the object standing where it appears, so that an explosion would ride along with the vehicle it hit.

An animation is attached to an object only when the code that creates it attaches it, whatever its type says. For example, a parachute is attached to the object it lowers, a fire is attached to the object that caught fire, and the sparks of an EMP are attached to the object they disabled.
