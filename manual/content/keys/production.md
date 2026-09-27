---
key: Production
summary: The IQ at which a computer house builds without waiting for a trigger.
see_also: [IQ, MaxIQLevels, BuildConst]
when_omitted:
  kind: value
  value: "5"
---

A computer house whose [`IQ`](/keys/iq/) is at or above this value builds without waiting for a trigger. Every game frame, the house is marked as started, as base-building and as alerted. A human player's house is never marked this way.

The three marks have these effects:

- **Started.** The house's factories, the construction yard included, begin building what the house has chosen. An unstarted computer house still decides which structure, vehicle, infantry and aircraft it wants next, but none of its factories starts on them.
- **Base-building.** The house's [MCVs deploy and hunt on their own](/keys/buildconst/).
- **Alerted.** No effect.

The same check also marks a computer house as started and alerted whenever it is already marked as base-building. Base-building therefore brings the other two marks with it, whatever the house's IQ. These routes set marks without the threshold:

- The [Auto Base Building...](/mapping/actions/taction-base-building/) trigger action sets base-building.
- A computer house's MCV deploying into a construction yard outside a campaign game sets base-building.
- The [Production Begins...](/mapping/actions/taction-begin-production/) trigger action and the [Begin production](/mapping/missions/tmission-begin-production/) team mission set only the started mark.
- The [Autocreate Begins...](/mapping/actions/taction-autocreate/) trigger action sets only the alerted mark.
- A house the computer takes over from a player who leaves the game is marked started and base-building, but only if it owns a construction yard.
- A house the computer takes over because its player did not return to a loaded multiplayer save is marked started.

Outside a campaign game, the computer opponents the game adds get [`MaxIQLevels`](/keys/maxiqlevels/) as their IQ, and so does a house the computer takes over from a player. Those houses meet this threshold unless it is set above `MaxIQLevels`. In a campaign, this value decides which houses build from the start and which wait for a trigger.
