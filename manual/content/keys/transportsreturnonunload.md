---
key: TransportsReturnOnUnload
summary: Releases each transport from the team when an Unload mission finishes and puts it on the Move mission.
see_also: [Passengers, "system:ai-team-execution"]
when_omitted:
  kind: value
  value: "no"
---

With this set, once an [Unload](/mapping/missions/tmission-unload/) mission has emptied every transport, each transport leaves the team and is put on the Move mission. A transport is a member whose type sets [`Passengers`](/keys/passengers/) above zero. When the team's TaskForce includes an aircraft that carries passengers, only aircraft count as transports, and a ground transport is treated like any other member.

The Unload mission's argument, the number on its script line, still decides what happens to the members that are not transports. It has no effect on the transports, which are released whatever it names.

Despite the key's name, a released transport normally has no destination and does not travel back. With no destination, the Move mission sends it straight to its idle behavior.

The destination comes from a return point the team keeps for each transport:

1. Each time the team moves toward a target, every transport that has no return point yet records the cell it stands in.
2. When the team advances to the next line of its script, it erases every member's return point. This includes the advance onto the Unload line, and the Unload mission records nothing.
3. On release, the transport is sent to its return point, and the point is cleared.

The points recorded on the approach are therefore already gone at release. A transport goes somewhere only if some other order stored a destination for it between the advance onto the Unload line and the release.
