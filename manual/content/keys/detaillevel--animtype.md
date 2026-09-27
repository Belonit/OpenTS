---
key: DetailLevel
scope: animtype
label: Animation detail threshold
see_also: ["TranslucencyDetailLevel", "Translucency"]
when_omitted:
  kind: value
  value: "0"
---

The animation is drawn only when the player's [detail setting](/keys/detaillevel/#scope-client-settings) is at least this value. The detail setting runs from `0`, the lowest, to `2`, the highest. A value of `1` hides the animation at the lowest setting, `2` shows it only at the highest, and any value above `2` hides it at every setting. At `0` or below, the animation is always drawn. Give purely decorative animations a higher value so that they are the first to disappear on a slow machine.

The setting controls drawing only. A hidden animation is still created, still advances through its frames and loops, and still deals its damage, leaves craters and scorch marks, and spreads Tiberium.

The picture of a structure's animation remembered under the fog of war uses the same test, so an animation this setting hides is missing there as well.

[`TranslucencyDetailLevel`](/keys/translucencydetaillevel/) separately decides at which settings the animation is drawn translucent. This setting decides only whether it is drawn at all.

```ini title="art.ini"
[MYPILE_A] ; an idle animation for a barracks
Image=MYPILE_A
LoopStart=0
LoopEnd=8
LoopCount=-1
Rate=300
Surface=yes
DetailLevel=1 ; not drawn at the lowest detail setting
```
