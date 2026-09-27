---
key: CloseEnough
summary: Distance in cells within which a blocked ground object treats its destination as reached.
see_also: [Stray]
when_omitted:
  kind: value
  value: "2.5"
  note: "640 leptons."
---

A ground object whose move is blocked stops and drops the move order when it is already this close to its destination. Infantry, walkers, hovercraft and driven vehicles all apply it.

When the destination lies in an area the object cannot reach at all, the object drops the move order at once, however near or far it is.

When the destination is reachable but no path to it can be found, an object nearer than this drops the order at once, provided it meets a condition that depends on its kind:

- a driven vehicle or a hovercraft must be on a Move or Area Guard mission, and not on a priority mission;
- infantry or a walker must not be tethered to another object, as it is while a transport unloads it.

An object that is farther away, or fails its condition, retries the search several times. When the retries run out, a driven vehicle or hovercraft drops the order. Infantry and walkers stop but usually keep it.

When a friendly object is temporarily standing in the next cell ahead, an object normally asks it to move aside. It stops and drops the order instead when **all of** these hold:

- it is nearer than this to its destination;
- the destination is less than two height levels above or below it;
- it is not standing in a tunnel.

An object in radio contact with another object, as it is while boarding a transport or docking, never stops this way. The exception is a driven vehicle or hovercraft that finds the blocker in the cell it is about to enter, which stops even in radio contact.

When an object starts a path search to a cell a friendly object temporarily blocks, it can redirect itself to a passable cell nearby. It does this only while it is farther from the destination than this distance. A member of a team compares against [`Stray`](/keys/stray/) instead.

During a team's move, a member on a Move mission that has stopped within this distance of its own destination drops that destination and goes idle, unless it has a target. The team then stops waiting for that member to arrive.
