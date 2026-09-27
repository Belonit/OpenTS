---
key: BuildingSlam
summary: The sound played when the local player places a finished structure on the map.
see_also: [BuildingDrop, CrumbleSound, "system:production"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
BuildingSlam=PLACE2 ; a sound ID registered in SOUND.INI
```

The sound plays once when the local player places a finished structure from the sidebar, a wall or firestorm wall section included. Structures placed by other players or by computer houses make no sound on this machine.

The sound has no map position, so it plays at the same volume wherever the view is.
