---
key: LaserInnerColor
summary: The color of the thin core line of a laser beam.
see_also: ["IsLaser", "LaserOuterColor", "LaserOuterSpread", "LaserDuration"]
when_omitted:
  kind: value
  value: "0,0,0"
---

`LaserInnerColor` sets the color of the thin core line down the middle of an [`IsLaser=yes`](/keys/islaser/) beam, as red, green and blue values from `0` to `255`.

```ini title="rules.ini"
[MyObeliskRay] ; example WeaponType
IsLaser=yes
LaserInnerColor=255,0,0
```

At the medium and high [detail levels](/keys/detaillevel/#scope-client-settings), the core is an antialiased line blended onto whatever lies beneath it, one channel at a time. Only channels above `0` are blended; a `0` channel leaves that channel of the picture beneath unchanged. The default `0,0,0` therefore draws no visible core.

At the low detail level, the core is drawn as a plain line in this color, darkened where the picture beneath is shaded, so `0,0,0` draws a black line.

The core is the only part of a laser whose color you choose freely at the medium and high detail levels. The glow lines beside it use only the red of [`LaserOuterColor`](/keys/laseroutercolor/), and the screen glow along the beam only brightens red.

The value is read from the weapon in the object's first weapon slot, whichever slot fired. A laser weapon in the second slot therefore uses the first weapon's core color.

:::note[A partial triplet reads as the default]
`LaserInnerColor=255` names one channel where three are needed, so the core keeps its default color and the debug log records the line; [INI syntax](/formats/ini-syntax/#malformed-values) has the rule.
:::
