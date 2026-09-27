---
key: PropulsionSoundEffect
summary: The sounds a levitating unit's thrust may play.
see_also: ["AccelerationProbability", "AccelerationDuration"]
when_omitted:
  kind: value
  value: ""
---

Every fourth thrust by a levitating unit plays one sound picked at random from this list. The thrust count is kept once for all levitating units, not per unit, so the sound plays once for every four thrusts on the whole map.

The sound plays centered at its full volume, however far the unit is from the view and even when the unit is under the shroud.

```ini title="rules.ini"
[LEVITATION]
PropulsionSoundEffect=MYFLOAT1,MYFLOAT2 ; sound IDs registered in SOUND.INI
```

A name that matches no registered sound is dropped from the list. Separate names with commas only: a space after a comma becomes part of the next name, and that name is then dropped. When no sounds remain, thrusts are silent and otherwise unchanged.

To clear the list and silence thrusts, set `PropulsionSoundEffect=<none>`. An assignment with an empty value keeps the list already in effect.

[`Drag`](/keys/drag/) covers which objects read this section and the `[General]` section a file must contain for any of it to be read at all.
