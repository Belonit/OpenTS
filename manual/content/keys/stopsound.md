---
key: StopSound
summary: Sound acknowledging the stop command.
see_also: [GuardSound, ScatterSound, DeploySound]
when_omitted:
  kind: value
  value: none
---

The [Stop Object](/commands/stopobject/) command plays `StopSound` once each time it is used with anything selected, however many objects the selection holds. The sound is not tied to a place on the map, so it plays at full volume wherever the view is.

```ini title="rules.ini"
[AudioVisual]
StopSound=STOPCMD ; a sound ID registered in SOUND.INI
```

The command sends a stop order only to objects the player can move or fire with, but the sound plays for any selection that is not empty. It therefore plays even when no selected object received the order.
