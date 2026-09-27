---
key: Civilian
summary: Counts the soldier as a civilian evacuee when it boards an aircraft transport.
see_also: [Nominal, Fraidycat, Disguised]
when_omitted:
  kind: value
  value: "no"
---

A soldier of a `Civilian=yes` type counts as a civilian evacuee unless it is a technician. A **technician** is an infantry of a [`Nominal=yes`](/keys/nominal/) type that a structure produced as a survivor when it was sold, or when it was destroyed and has build-up artwork.

When an evacuee boards an aircraft transport, the transport switches to the Retreat mission. Retreat gives an aircraft no orders, so the transport does not head for the map edge. It drops the mission it had and carries on with any movement already under way.

An aircraft on the Retreat mission that is outside the playable area is removed together with everything aboard. Each evacuee removed this way marks its own house, not the transport's, as having evacuated a civilian. The mark is never cleared. Only the [Civilians Evacuated](/mapping/events/tevent-evac-civilian/) trigger event reads it, and that event [can never be satisfied](/systems/trigger-springing/#three-events-that-cannot-be-reached).

This setting does nothing else. Running from danger is [`Fraidycat=yes`](/keys/fraidycat/), and showing another type's identity is [`Disguised=yes`](/keys/disguised/).
