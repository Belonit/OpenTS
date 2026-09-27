---
key: Loadable
summary: Lets the player order infantry and vehicles into a transport that belongs to a team of this type.
see_also: [Passengers, IsVehicleTransport, "system:ai-team-execution", "system:transports"]
when_omitted:
  kind: value
  value: "no"
---

`Loadable=yes` lets the player order infantry and vehicles into a transport that is on a team of this type. The setting belongs to the transport's team, not to the team of the object being ordered aboard.

When the player points an infantryman or vehicle at an allied transport that can carry passengers, the cursor shows that entry is refused under **any of:**

- the transport is on a team whose TeamType does not set `Loadable=yes`;
- the transport is moving.

A transport on no team is refused only while it is moving. Otherwise the ordinary boarding checks decide.

The setting governs only what the player can order. A team loading its members through the [Load onto Transport](/mapping/missions/tmission-load/) mission orders them aboard directly and does not read it.
