---
key: Range
scope: sounds
label: Hearing distance
see_also: [Type, MinVolume, Volume]
when_omitted:
  kind: value
  value: "28"
---

How far outside the view a sound played at a place in the world can still be heard, in cells of 48 pixels. A sound played without a place, such as a button click, ignores it.

Inside the view, the sound plays at full loudness. Beyond the edge of the view, its loudness falls in a straight line to silence at `Range=` cells. The distance used is the larger of the horizontal distance and twice the vertical distance. A sound that has faded below five percent is not started, and a playing one that fades below it stops, so the sound falls silent a little short of `Range=`.

With `LOCAL` in the sound's [`Type=`](/keys/type/#scope-sounds), the distance is measured from the center of the view instead of its edge. With `GLOBAL`, the fade stops at [`MinVolume=`](/keys/minvolume/).

A value of `0` or less acts as `1`, and a value above 1000 is read as 1000.

```ini title="sound01.ini"
[GUN5]
Range=20
```

The default of 28 cells is 1344 pixels, within about one percent of the 1360 pixels over which the original game faded sounds. To the sides of the view, shipped sounds therefore fade out where they did. Above and below the view they fade out in half the distance, because the original game did not count vertical distance twice.
