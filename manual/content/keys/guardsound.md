---
key: GuardSound
summary: Sound acknowledging the guard command.
see_also: [StopSound, ScatterSound, DeploySound]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
GuardSound=GUARDCMD ; a sound ID registered in SOUND.INI
```

The [Guard](/commands/guardobject/) command plays this sound once each time it runs with anything selected, without a map position. One sound covers the whole selection.

The sound confirms the key press, not an order. It plays even when no selected object obeys, for example when the selection holds only structures or unarmed infantry. An empty selection plays nothing.
