---
key: LaserOuterSpread
summary: How far each channel of a laser beam's glow color may shift at random on each frame.
see_also: ["IsLaser", "LaserOuterColor", "LaserInnerColor"]
when_omitted:
  kind: value
  value: "0,0,0"
---

Each of the three numbers is the most that the matching channel of [`LaserOuterColor`](/keys/laseroutercolor/) may shift up or down. On every frame the beam is drawn, a new random shift is picked for each channel, and the result is kept within 0 to 255. The glow therefore shimmers for as long as the beam lasts. Both glow lines take the same shifted color, and the beam's core is not affected.

```ini title="rules.ini"
[MyObeliskRay] ; example WeaponType
IsLaser=yes
LaserOuterColor=128,0,0
LaserOuterSpread=40,0,0 ; the glow's red varies between 88 and 168
```

At normal detail the glow changes only the red of the pixels beneath it, so only the first number has a visible effect. The green and blue numbers show only at the lowest detail setting, which draws the glow as solid lines in its full color. A glow turned off by `LaserOuterColor=0,0,0` stays off whatever the spread.

The numbers always come from the weapon in the object's [first weapon slot](/systems/firing-geometry/#what-each-part-of-a-shot-reads), even when a laser in the second slot fires.

:::note[A partial triplet reads as the default]
`LaserOuterSpread=40` names one channel where three are needed, so the spread keeps its default and the debug log records the line; [INI syntax](/formats/ini-syntax/#malformed-values) has the rule.
:::
