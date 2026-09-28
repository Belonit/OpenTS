---
key: IonStormVolume
scope: themes
label: Music level under the storm sound
see_also: [FadeOut, Volume]
when_omitted:
  kind: value
  value: "0.33"
---

`IonStormVolume=` in THEME.INI's `[General]` section sets how loud the music plays while an ion storm plays its storm sound, as a share of the music's usual level. It uses the same scale as a track's [`Volume=`](/keys/volume/#scope-themes), and a value above 1 is read as a percentage, so `0.33` and `33` mean the same thing.

```ini title="theme01.ini"
[General]
IonStormVolume=0.5
```

The music fades to this level over [`FadeOut=`](/keys/fadeout/) seconds when the storm breaks and back when it ends. A track that starts during the storm starts at this level. The key has no effect on a storm that plays the storm music track instead of a storm sound; [Ion storms](/systems/ion-storms/#storm-audio) explains which a storm uses. A value that is not a number is ignored.
