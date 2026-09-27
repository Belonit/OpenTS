---
key: GuardArea
summary: The IQ level at which a computer house leaves idle objects in Area Guard instead of Guard.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "4"
---

A computer house whose [`IQ`](/keys/iq/) is at least this level sends its idle infantry and vehicles to Area Guard instead of Guard. Area Guard scans out to the area radius from the spot where the object was left and pursues what it finds. Guard scans only out to the guard radius. [Scan radius](/systems/target-selection/#scan-radius) gives both distances.

A member of a team always takes Guard. Outside a team, the level applies differently to infantry and vehicles:

- **Infantry.** Only a computer house's infantry is tested. At or above the level, an armed soldier, an engineer or a vehicle thief takes Area Guard, and any other unarmed soldier takes Guard. A human house's infantry takes Area Guard only through the `GUARD_AREA` [veterancy ability](/systems/veterancy/#abilities), whatever the house's `IQ`.
- **Vehicles.** An armed vehicle takes Area Guard when its house reaches the level or when it holds the `GUARD_AREA` ability. An unarmed vehicle is never sent to Area Guard.

The vehicle test does not check who owns the vehicle. A human house whose map sets its `IQ` to this level or higher sends its idle armed vehicles to Area Guard as well.
