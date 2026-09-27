---
key: DeploySound
scope: global-rules
label: Deploy order sound
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
DeploySound=27-I002 ; a sound ID registered in SOUND.INI
```

The [Deploy Object](/commands/deployobject/) command plays this sound once after it issues the deploy order. It plays at full volume, not from a place on the map. One sound covers the whole selection however many objects were given the order. When no selected object can take the order, no order is issued and no sound plays.

This sound belongs to the order, not to the deployment. A structure's [build-up sound](/keys/deploysound/#scope-buildingtype) is a separate setting.
