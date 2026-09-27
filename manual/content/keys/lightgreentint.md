---
key: LightGreenTint
summary: The green the glow of a structure adds to the cells it reaches.
see_also: [LightRedTint, LightBlueTint, LightIntensity, LightVisibility]
when_omitted:
  kind: value
  value: "1000"
---

```ini title="rules.ini"
[GRENLAMP] ; the stock green light post
LightVisibility=4000
LightIntensity=0.01
LightRedTint=0.01
LightGreenTint=1.5
LightBlueTint=0.01
```

The value is how much green the structure's light adds to the ground around it. At the structure's center, `LightGreenTint=1` adds as much green as a map at [`Green=1`](/keys/green/) already has. The addition falls off in a straight line to nothing at [`LightVisibility`](/keys/lightvisibility/), like [`LightIntensity`](/keys/lightintensity/). A negative value takes green out instead.

The balance between the three tints gives a light its color; [`LightRedTint`](/keys/lightredtint/) explains how they combine. Set all three tints on any structure with a light. [`LightIntensity`](/keys/lightintensity/) explains what the built-in `1000` does to the ground.

A later rules file can wipe out a fractional value. If any later rules file, such as the expansion's rules or a map's own rules, contains the structure's section but not this key, the stored value loses its fraction. A `1.5` green drops to `1`, and a `0.01` green drops to `0`, which removes it from the light.
