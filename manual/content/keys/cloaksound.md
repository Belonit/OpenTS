---
key: CloakSound
summary: The sound played at an object's position as it starts to hide or to reappear.
see_also: ["system:cloaking"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
CloakSound=CLOAK5 ; the shipped sound, defined in SOUND.INI
```

`CloakSound` plays at an object's position each time the object starts to hide or to reappear. It plays for objects of every house. That includes each vehicle and infantryman a growing [cloaking field](/systems/cloaking/#cloaking-fields) passes over, and each structure that fades out under one.

One kind of reappearance is silent. A critically damaged vehicle, infantryman or aircraft, with health at or below [`ConditionRed`](/keys/conditionred/), can abandon its cloak partway through hiding: it has a ten percent chance each frame while its fade is in the darkened band. When it abandons the cloak this way, it fades back into view without the sound.
