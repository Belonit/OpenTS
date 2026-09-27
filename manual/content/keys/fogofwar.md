---
key: FogOfWar
summary: Raises the fog of war over a campaign mission.
see_also: [FogRate, "system:map-visibility"]
when_omitted:
  kind: value
  value: "no"
  note: A campaign mission that omits the key runs without fog, even if the mission before it had fog on.
---

```ini title="map file"
[SpecialFlags]
FogOfWar=yes
```

`FogOfWar=yes` turns the fog of war on for a single-player mission. When the mission finishes loading, fog covers every cell not already under it. [Shroud, fog and the radar map](/systems/map-visibility/#the-fog-of-war) owns what the fog then does, and how [`FogRate`](/keys/fograte/) brings it back over ground nothing is watching.

Other game types do not read the entry. There the game's fog of war option decides, whatever the map says.
