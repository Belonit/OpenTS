---
key: FShift
scope: sounds
label: Pitch variation
see_also: [VShift]
when_omitted:
  kind: value
  value: "0"
---

`FShift=` shifts the pitch of each play by a random percentage. The engine draws the shift when the play starts, and every sample of that play, including every cycle of a loop, uses it. A higher pitch also plays the sample faster, and a lower one slower.

A single value spans both directions, and its sign is ignored, so `FShift=5` is the same as `FShift=-5 5`. Two values give a range, in either order. The pitch stays between half and double the recorded pitch, so values are held between -50 and 100.

Write whole percentages. If either value has a decimal point, both are read as a thousand times larger, so `FShift=0.5` can halve or double the pitch.

```ini title="sound01.ini"
[GUN5]
FShift=-8 8
```
