---
key: Repairable
summary: Allows a structure to be repaired with the wrench, worked on by an engineer, and treated as a building by a commando.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "yes"
  note: "InfantryTypes start at `no`, though no path reads an infantry's value."
---

Only a structure's value has an effect. It controls four things:

- **Wrench:** the repair cursor accepts a structure only while it is `Repairable=yes` and below full [`Strength`](/keys/strength/#scope-aircrafttype), or while a limpet mine is attached to it. A structure that can undeploy into a vehicle, other than a construction yard, is never accepted.
- **Automatic repair and sale:** the [repair-or-sell decision](/systems/repair/#when-the-computer-repairs) considers only structures the wrench would accept. A `Repairable=no` structure takes part only while a limpet mine is attached to it.
- **Engineer:** over a visible `Repairable=no` structure, the player's engineer cannot restore an allied structure, capture or damage an enemy one, or repair a bridge from a bridge repair hut. A mobile war factory is exempt. Capturing or damaging an enemy structure also needs [`Capturable=yes`](/keys/capturable/). Over a structure remembered under fog of war, the rules differ. A bridge repair hut offers the bridge repair cursor whatever its `Repairable` value, and any other `Repairable=yes` structure offers the capture cursor, even an allied or non-capturable one.
- **Commando:** a commando or other explosives carrier plants explosives on a `Repairable=yes` structure and shoots at a `Repairable=no` one.

The value on a vehicle or aircraft does nothing. A service depot repairs them whatever it says, and the wrench refuses every object that is not a structure.
