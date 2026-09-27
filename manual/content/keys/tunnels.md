---
key: Tunnels
summary: The tile set that supplies the four road tunnel mouths, one per facing.
see_also: [TrackTunnels, DirtTunnels, DirtTrackTunnels, MovementZone]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

A cell holding one of these four pieces becomes a tunnel entrance, provided its tile artwork reports the [`Tunnel` land type](/reference/enums/land-type/). The engine checks each such cell that has no tunnel yet whenever it works out the cell's terrain.

The piece's position in the set sets the tunnel's entry facing:

| Piece | Entry facing |
| --- | --- |
| First | East |
| Second | South |
| Third | West |
| Fourth | North |

A tile can fall inside more than one of the four tunnel roles. The engine tests them in this order and uses the first that contains the tile:

1. `Tunnels`
2. [`TrackTunnels`](/keys/tracktunnels/)
3. [`DirtTunnels`](/keys/dirttunnels/)
4. [`DirtTrackTunnels`](/keys/dirttracktunnels/)

With the role unresolved, the theater's first three tiles match as the second, third and fourth pieces, but only if their artwork reports `Tunnel` land.

Route-finding links a tunnel cell to its tunnel's exit when the cell's two neighbors along one axis are also tunnel cells, so a route can pass through the tunnel.
