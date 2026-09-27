---
key: Crewed
summary: Allows a structure or vehicle of the type to release surviving infantry when it is destroyed, or when a structure is sold.
see_also: ["system:capture", CrewEscape, Passengers, "system:transports"]
when_omitted:
  kind: value
  value: "no"
---

A structure releases survivors when it is destroyed or sold only if its type is `Crewed=yes`. Without it, the structure releases none, whatever [`SurvivorRate`](/keys/survivorrate/) and [`SurvivorDivisor`](/keys/survivordivisor/) work out to. [Survivors](/systems/capture/#survivors) covers the count and the odds for each cell.

A destroyed vehicle can release one crew member only if its type is `Crewed=yes` and declares no [`Passengers`](/keys/passengers/) capacity. [`CrewEscape`](/keys/crewescape/) sets the chance and lists the deaths that leave no crew.

A vehicle stolen by an infantryman, through either theft feature, does not use the key. When it is destroyed, [the thief steps back out](/systems/capture/#stealing-a-vehicle) with no crew-escape roll.

An InfantryType or AircraftType accepts the key, but it has no effect on either.
