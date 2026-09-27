---
key: TrackTunnels
summary: The tile set that supplies the four railway tunnel mouths, one per facing.
see_also: [Tunnels, DirtTunnels, DirtTrackTunnels]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The four pieces create tunnel entrances exactly as the road tunnel pieces do. [`Tunnels`](/keys/tunnels/) covers the land-type requirement and which facing each piece gives. This role is tested second of the four tunnel roles, so a tile that also falls inside the `Tunnels` set takes its facing from its position in that set.
