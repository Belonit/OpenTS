---
key: DirtTunnels
summary: The tile set that supplies the four dirt road tunnel mouths, one per facing.
see_also: [Tunnels, TrackTunnels, DirtTrackTunnels]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The four pieces build road tunnels exactly as the [`Tunnels`](/keys/tunnels/) pieces do; that page explains the tunnel and which facing each piece stands for. This role is checked third of the four tunnel roles, after [`Tunnels`](/keys/tunnels/) and [`TrackTunnels`](/keys/tracktunnels/), so a tile that also falls inside either of those sets is claimed by that set instead.
