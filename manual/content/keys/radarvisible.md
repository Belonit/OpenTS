---
key: RadarVisible
summary: Whether the object is plotted on the radar map under every condition.
see_also: [Invisible, "system:cloaking"]
when_omitted:
  kind: value
  value: "no"
---

`RadarVisible=yes` plots the object on the radar whatever the ordinary [radar test](/systems/cloaking/#on-the-radar) would decide. Shroud, fog of war, cloaking, tunneling, the radar-invisible ability, and whether the player has discovered the object no longer hide it. An enemy object is plotted from the moment it appears on the map, before the player has seen it, and stays plotted as it moves.

[`Invisible=yes`](/keys/invisible/) overrides it and keeps the object off the radar for every house. A BuildingType with [`InvisibleInGame=yes`](/keys/invisibleingame/) has `RadarVisible` forced back to `no`.
