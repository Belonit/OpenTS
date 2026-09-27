---
key: TranslucencyDetailLevel
summary: The lowest detail setting at which the animation is drawn faded rather than solid.
see_also: ["Translucency", "Translucent", "DetailLevel"]
when_omitted:
  kind: value
  value: "0"
---

The animation is drawn faded only while the player's detail setting is at or above this value. At lower settings it is drawn solid, which costs less to draw.

The player's detail setting runs from `0` at its lowest to `2` at its highest. `0` fades the animation at every setting, `1` draws it solid at the lowest setting, `2` fades it only at the highest, and any value above `2` draws it solid at every setting.

The value controls every fade the animation can have:

- the fade by stage of a [`Translucent=yes`](/keys/translucent/#scope-animtype) animation;
- the fixed fade of [`Translucency=`](/keys/translucency/#scope-animtype);
- the fade it follows from a cloaking structure that runs it.

```ini title="art.ini"
[MYRING1] ; a blast ring, drawn solid on the lowest detail setting
Image=MYRING1
Translucent=yes
TranslucencyDetailLevel=1
Rate=300
Flat=true
```

:::caution[A cloaked structure's animations can stay visible]
Below this setting, the animations a structure runs are drawn solid even after the structure has cloaked completely. They stay on screen over a structure the player can no longer see. To avoid this, give [`DetailLevel`](/keys/detaillevel/#scope-animtype) the same value, so the animation is not drawn at all at those settings.
:::

This value decides only how the animation is drawn. Whether it is drawn at all is set by [`DetailLevel`](/keys/detaillevel/#scope-animtype).
