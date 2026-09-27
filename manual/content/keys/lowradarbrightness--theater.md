---
key: LowRadarBrightness
scope: theater
label: Theater radar floor
see_also: [HighRadarBrightness]
when_omitted:
  kind: context-dependent
  note: "`0.8` for SNOW, which keeps its original settings; `1.0` for TEMPERATE and for every other theater."
---

`LowRadarBrightness` scales a cell's radar colors at every height. A cell shows two colors on the radar, both taken from its tile artwork, and this value multiplies both of them. Below `1.0` the theater's ground shows darker on the radar than in its artwork, and above `1.0` it shows lighter.

```ini title="rules.ini"
[DESERT]
LowRadarBrightness=1.0
```

Raised ground is scaled by this value first and then by [`HighRadarBrightness`](/keys/highradarbrightness/), which sets how much brighter high ground shows than low ground.

Neither value applies to a cell whose radar color comes from what lies on it. A tree or other terrain object, a bridge, Tiberium, or any other overlay shows its own color unscaled.
