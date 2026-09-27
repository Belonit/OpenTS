---
key: Volume
summary: The share of full loudness the sound effect is played at.
see_also: [Priority, MinVolume, VShift, SoundVolume, VoiceVolume]
when_omitted:
  kind: value
  value: "1.0"
---

`Volume=` sets how loud the sound plays, as a fraction of its sample's recorded loudness. A value above 1 is read as a percentage, so `0.5` and `50` mean the same thing, and `1` and `100` are both full loudness. `Volume=1.5` is therefore 1.5 percent. The value is held between silence and full loudness, so no sound plays louder than its sample.

Each play multiplies the value by two more factors, and the product is again held at full loudness:

- the distance fade of a sound played at a place in the world, or the loudness the game asks for when the sound has no place;
- the play's random [`VShift=`](/keys/vshift/) draw.

The [`SoundVolume`](/keys/soundvolume/) option then scales every sound effect, and while it is at zero no sound effect starts. The one exception is the beep the voice volume slider plays outside a game, which follows [`VoiceVolume`](/keys/voicevolume/) instead.

```ini title="sound01.ini"
[SCOLD8]
Priority=75
Volume=0.5
```

A `Volume=` in the `[Defaults]` section of [SOUND.INI](/formats/sound-ini/) applies to every sound section that omits the key.

:::caution[A value above 1 no longer raises the loudness]
In earlier releases, a value above 1 made a sound louder than its sample, so `Volume=2` played a quiet sample at up to twice its loudness. The same line now means two percent. Remove such values or write `Volume=100`.
:::
