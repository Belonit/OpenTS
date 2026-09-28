---
key: Volume
scope: themes
label: Track loudness
see_also: [Sound, ScoreVolume]
when_omitted:
  kind: value
  value: "1.0"
---

`Volume=` sets how loud the music track plays, as a share of the level the [`ScoreVolume`](/keys/scorevolume/) option gives every track. It uses the same scale as the music volume slider: `Volume=0.5` with the slider at full sounds as loud as a track without the key with the slider at half. A value above 1 is read as a percentage, so `0.5` and `50` mean the same thing. The value is held between silence and full loudness, so no track plays louder than its file.

```ini title="theme01.ini"
[MYTHEME]
Name=Example theme
Volume=0.7
```

A value that is not a number is ignored, and the track plays at full loudness.
