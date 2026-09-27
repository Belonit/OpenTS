---
key: RadarOff
summary: Sound played as the radar pane begins closing.
see_also: ["system:map-visibility", RadarOn]
when_omitted:
  kind: value
  value: none
---

The sound plays, without a position, when the radar pane starts to close. These are the usual occasions:

- The local player loses the radar. [Power output and drain](/systems/power/#radar) covers what takes it away.
- In a multiplayer game without radar, [Radar Toggle](/commands/toggleradar/) closes the name and kill list.
- An in-game transmission ends while the player has no radar.
