---
key: LightRedTint
summary: The red the glow of a structure adds to the cells it reaches.
see_also: [LightGreenTint, LightBlueTint, LightIntensity, LightVisibility]
when_omitted:
  kind: value
  value: "1000"
---

```ini title="rules.ini"
[REDLAMP] ; the stock red light post
LightVisibility=4000
LightIntensity=0.01
LightRedTint=1.5
LightGreenTint=0.01
LightBlueTint=0.01
```

The value is how much red the structure's light adds to the ground around it. At the structure's center, `LightRedTint=1` adds as much red as a map at [`Red=1`](/keys/red/) already has. The addition falls off in a straight line to nothing at [`LightVisibility`](/keys/lightvisibility/), like [`LightIntensity`](/keys/lightintensity/). A negative value takes red out instead, as the stock negative red light does.

The balance between the three tints gives a light its color, and the strongest tint also brightens the ground. For each cell, the game adds up the map's tint and every light reaching the cell, then divides the red, green and blue totals by the strongest of the three. The ground's brightness is multiplied by that strongest total, up to twice full daylight. Raising all three tints together therefore brightens the ground without coloring it. One tint well above the other two colors it.

Set all three tints on any structure with a light. [`LightIntensity`](/keys/lightintensity/) explains what the built-in `1000` does to the ground.

A later rules file can wipe out a fractional value. If any later rules file, such as the expansion's rules or a map's own rules, contains the structure's section but not this key, the stored value loses its fraction. A `1.5` red drops to `1`, and a `0.05` red drops to `0`, which removes it from the light.
