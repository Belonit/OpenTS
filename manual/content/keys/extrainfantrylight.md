---
key: ExtraInfantryLight
summary: Extra brightness every infantryman is drawn with, as a fraction of normal brightness.
see_also: [ExtraUnitLight, ExtraAircraftLight]
when_omitted:
  kind: value
  value: "0"
  note: "A later file that declares `[AudioVisual]` without this key keeps only the whole part of the current value, so a value below `1` becomes `0`."
---

`ExtraInfantryLight` draws every infantryman brighter by a flat amount. The value is a fraction of normal brightness, so `.2` adds a fifth of normal brightness. The amount is added on top of the light the infantryman takes from its cell, including on a bridge and in a shadowed cell.

```ini title="rules.ini"
[AudioVisual]
ExtraInfantryLight=.2
```

Only the infantryman's body takes the amount. The shadow drawn under an infantryman above the ground does not. While an infantryman falls in a drop pod, the pod is drawn at normal brightness.

:::caution[Repeat this key wherever `[AudioVisual]` appears again]
A later file that declares `[AudioVisual]` without this key resets it, even if that file sets only other keys in the section. Later files include `langrule.ini`, the Firestorm rules file, the multiplayer rules files and the scenario map.
:::
