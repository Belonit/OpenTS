---
key: HighRadarBrightness
scope: theater
label: Theater radar ceiling
see_also: [LowRadarBrightness]
when_omitted:
  kind: context-dependent
  note: "`1.1` for SNOW, which keeps its original settings; `1.6` for TEMPERATE and for every other theater."
---

`HighRadarBrightness` sets how much brighter raised ground shows on the radar. It multiplies the tile colors that [`LowRadarBrightness`](/keys/lowradarbrightness/) has already scaled, in proportion to the cell's height. A cell at height level 0 gets none of it, and a cell at height level 12 gets all of it.

At level 12, a cell's colors are therefore scaled by `LowRadarBrightness` times `HighRadarBrightness`. TEMPERATE's `1.0` and `1.6` give `1.6` there, and SNOW's `0.8` and `1.1` give `0.88`. A cell above level 12 keeps changing at the same rate per level.

```ini title="rules.ini"
[DESERT]
HighRadarBrightness=1.6
```

A value of `1.0` shows every height alike. A value below `1.0` draws high ground darker than low ground.

Each color channel stops at full brightness, so a light tile color can stop brightening before level 12.
