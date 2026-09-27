---
key: CrewEscape
summary: The chance that a destroyed vehicle's crew steps out as an infantry survivor.
see_also: ["system:capture", Crew, Crewed, Passengers, "system:transports"]
when_omitted:
  kind: value
  value: ".5"
---

The value is a probability from `0` to `1`: `.5` gives an even chance, and `0` never produces a crew. A destroyed vehicle rolls once and produces at most one soldier, whose type comes from [`Crew`](/keys/crew/) or [`Technician`](/keys/technician/). The soldier appears at the wreck with strength between 5 and half its type's maximum. It hunts for a computer house and stands guard for a human one.

A vehicle takes the roll only when **all of** these hold:

- it was not destroyed in one of the ways listed below that leave no crew;
- its type has [`Crewed=yes`](/keys/crewed/);
- its type declares no [`Passengers`](/keys/passengers/) capacity.

A transport therefore never produces a crew, even when it is crewed and empty. Structures do not use this setting; their survivor count comes from [`SurvivorRate`](/keys/survivorrate/) and [`SurvivorDivisor`](/keys/survivordivisor/).

Several kinds of destruction leave no crew, whatever this setting says. They include an energizing laser fence, a firestorm wall, an aircraft crashing onto the vehicle, and a bridge collapse, for a vehicle on the deck, beneath it, or driving onto it.

A vehicle taken by a hijacker skips the roll. [The hijacker steps back out](/systems/capture/#stealing-a-vehicle) in the crew's place, whatever this setting, `Crewed=` or the cause of destruction.

:::caution[A death animation removes the crew]
A vehicle whose artwork declares [`DeathFrames`](/keys/deathframes/) survives the killing hit at one point of strength, plays its death animation, and is then exploded and removed. That path skips the crew roll, so such a vehicle never produces a crew or a hijacker, and never drops a crate it carries.
:::
