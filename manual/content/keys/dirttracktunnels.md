---
key: DirtTrackTunnels
summary: The tile set that supplies the four dirt railway tunnel mouths, one per facing.
see_also: [Tunnels, TrackTunnels, DirtTunnels]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The four pieces build railway tunnels exactly as the [`Tunnels`](/keys/tunnels/) pieces build road tunnels; that page explains the tunnel and which facing each piece stands for. This role is checked last of the four tunnel roles, so a tile that also falls inside any of the other three tunnel sets is claimed by that set instead.
