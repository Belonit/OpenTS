---
key: BlowupSound
summary: Sound a structure makes as damage takes it past a condition threshold.
see_also: [CrumbleSound, ConditionRed, Strength]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
BlowupSound=EXPLOSML ; a sound ID registered in SOUND.INI
```

The sound plays when a single hit takes a structure past either of two thresholds, as long as the hit does not destroy it:

- from at least half its maximum strength, rounded down, to below half;
- from above [`ConditionRed`](/keys/conditionred/) of its maximum strength to below it.

A hit that crosses both thresholds plays the sound once. Further damage that crosses no threshold plays nothing.

The sound plays at the structure's position, so it is quieter the farther the structure is from the view.

Only structures play it. Vehicles, infantry and aircraft crossing the same thresholds make no sound.
