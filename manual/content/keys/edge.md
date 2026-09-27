---
key: Edge
summary: The map edge that a scenario house's reinforcement teams enter from.
see_also: [PlayerControl, Credits]
when_omitted:
  kind: value
  value: North
---

`Edge` sets the map edge where the house's [reinforcement teams](/mapping/actions/taction-reinforcements/) drive, walk or fly onto the map. The value is one of the [reinforcement sources](/reference/enums/reinforcement-source/).

Only a campaign mission reads its house records, so this is a campaign setting.

```ini title="scenario map file"
[Nod] ; a house record in the scenario's own house list
Edge=South
```

The TeamType's [`Waypoint`](/keys/waypoint/) decides whether this edge is used:

- If the TeamType names no waypoint, the team enters at a clear cell along this edge. A value the engine does not recognize, or `Air`, uses the north edge.
- If it names a waypoint, the team enters from the map edge nearest that waypoint. This setting then only sets the direction the arriving objects face.

Teams that arrive by drop pod, by burrowing, by walking out of a structure or transport, or through the [Reinforcement (team) at waypoint](/mapping/actions/taction-reinforcements-special/) action do not cross the map edge, so this setting does not affect them.

The Retreat mission does not use this setting either. Infantry and vehicles on that mission head for the map edge nearest their team's waypoint, or nearest their own position when there is no team waypoint.
