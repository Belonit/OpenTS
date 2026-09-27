---
key: ExtraAircraftLight
summary: Extra brightness every aircraft is drawn with, as a fraction of normal brightness.
see_also: [ExtraUnitLight, ExtraInfantryLight]
when_omitted:
  kind: value
  value: "0"
  note: "A later file that declares `[AudioVisual]` without this key keeps only the whole part of the current value, so a value below `1` becomes `0`."
---

`ExtraAircraftLight` draws every aircraft brighter by a flat amount. The value is a fraction of normal brightness, so `.2` adds a fifth of normal brightness. An aircraft is also drawn brighter the higher it flies; this amount is the same at every altitude, including on the ground.

```ini title="rules.ini"
[AudioVisual]
ExtraAircraftLight=.2
```

Only the aircraft's body takes the amount. Its shadow and anything drawn over the body do not.

:::caution[Repeat this key wherever `[AudioVisual]` appears again]
A later file that declares `[AudioVisual]` without this key resets it, even if that file sets only other keys in the section. Later files include `langrule.ini`, the Firestorm rules file, the multiplayer rules files and the scenario map.
:::
