---
key: VShift
scope: sounds
label: Loudness variation
see_also: [FShift, Volume]
when_omitted:
  kind: value
  value: "0"
---

`VShift=` makes each play of the sound quieter by a random whole percentage. The engine draws the percentage when the play starts and keeps it until the play ends, so a placed sound does not change loudness at random as the view scrolls.

A single value lowers the loudness by up to that percentage. `VShift=10` plays at between 90 and 100 percent of the loudness [`Volume=`](/keys/volume/#scope-sounds) sets. The sign of a single value is ignored, so `VShift=-10` means the same thing.

Two values give a signed range, in either order. `VShift=-20 -5` lowers the loudness by between 5 and 20 percent.

`VShift=` never makes a sound louder than `Volume=` alone. A positive draw plays as loud as `Volume=` alone, so `VShift=0 10` never changes the loudness.

Values are held between -100 and 100, and a draw of -100 silences that play.

Write whole percentages. If either value has a decimal point, both values are read as a thousand times larger. `VShift=0.5` can then lower the loudness to silence, and `VShift=-20 -0.5` silences every play.

```ini title="sound01.ini"
[GUN5]
VShift=15
```
