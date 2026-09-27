---
key: ScatterSound
summary: Sound acknowledging the scatter command.
see_also: [StopSound, GuardSound, DeploySound]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
ScatterSound=SCATCMD ; a sound ID registered in SOUND.INI
```

The [Scatter](/commands/scatterobject/) command plays this sound once per use, however many objects are selected. It plays as an interface sound, not from a place on the map.

The sound confirms the key press, not the order. It plays whenever anything is selected, even when nothing in the selection can scatter, such as a structure. Only an empty selection is silent.
