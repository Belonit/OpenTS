---
key: AltImage
summary: The shape set a visceroid draws its attack animation from.
see_also: ["SmallVisceroid", "LargeVisceroid", "Image"]
when_omitted:
  kind: value
  value: ""
  note: No attack shape set is loaded, so a visceroid draws nothing while it attacks. Other UnitTypes are unaffected.
---

The value is a filename without its extension, up to 23 characters. The engine appends `.SHP` and loads that file from the game archives when it reads the section. No `art.ini` section is involved: unlike [`Image`](/keys/image/#scope-aircrafttype), the name is only ever a file.

Only a [`SmallVisceroid=yes`](/keys/smallvisceroid/#scope-unittype) or [`LargeVisceroid=yes`](/keys/largevisceroid/#scope-unittype) UnitType draws from it. Other UnitTypes load the file and never show it. A visceroid switches to this shape set each time it fires and plays five frames from it. It draws its idle wandering from the ordinary [`Image`](/keys/image/#scope-aircrafttype). While the `PENGO` [main-menu code](/systems/developer-mode/#the-main-menu-code-recognizer) is on, visceroids use replacement art and never draw from either.

```ini title="rules.ini"
[MYVISCEROID] ; a UnitType registered in [VehicleTypes]
LargeVisceroid=yes
Image=MYVISC     ; idle frames
AltImage=MYVISCA ; attack frames, MYVISCA.SHP
```

The file holds eight five-frame runs, one for each direction the visceroid can attack in. The run is chosen by the direction from the visceroid to its target, in this order:

| Frames | Target direction |
| --- | --- |
| 0–4 | West |
| 5–9 | North-west |
| 10–14 | North |
| 15–19 | North-east |
| 20–24 | East |
| 25–29 | South-east |
| 30–34 | South |
| 35–39 | South-west |

If no loaded archive holds the named file, the visceroid draws nothing while it attacks. Its position, weapon and damage are unaffected.
