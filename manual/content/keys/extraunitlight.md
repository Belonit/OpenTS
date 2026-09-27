---
key: ExtraUnitLight
summary: Extra brightness every vehicle is drawn with, as a fraction of normal brightness.
see_also: [ExtraInfantryLight, ExtraAircraftLight]
when_omitted:
  kind: value
  value: "0"
  note: "A later file that declares `[AudioVisual]` without this key keeps only the whole part of the current value, so a value below `1` becomes `0`."
---

`ExtraUnitLight` draws every vehicle brighter by a flat amount. The value is a fraction of normal brightness, so `.2` adds a fifth of normal brightness. The amount is added on top of the light the vehicle takes from its cell, including on a bridge and in a shadowed cell.

```ini title="rules.ini"
[AudioVisual]
ExtraUnitLight=.2
```

The amount lights the vehicle's body and the harvesting animation drawn beside a working harvester. It changes nothing except how vehicles are drawn.

:::caution[Repeat this key wherever `[AudioVisual]` appears again]
A later file that declares `[AudioVisual]` without this key resets it, even if that file sets only other keys in the section. Later files include `langrule.ini`, the Firestorm rules file, the multiplayer rules files and the scenario map.
:::
