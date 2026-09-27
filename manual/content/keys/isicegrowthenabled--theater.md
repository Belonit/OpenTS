---
key: IsIceGrowthEnabled
scope: theater
label: Theater ice
see_also: [IsArctic, IceGrowthEnabled, IceGrowthRate]
when_omitted:
  kind: context-dependent
  note: "`yes` for SNOW, which keeps its original settings; `no` for TEMPERATE and for every other theater."
---

`IsIceGrowthEnabled` turns ice behavior on for a theater. With it off:

- ice never grows, refreezes, or has its edges smoothed;
- ice never cracks or breaks under a vehicle, and explosions never crack it;
- [`IceGrowthEnabled`](/keys/icegrowthenabled/) on a map has no effect.

```ini title="rules.ini"
[DESERT]
IsIceGrowthEnabled=no
```

The setting also changes the tiles when the theater loads. With it on, the edge tiles of [`Ice1Set`](/keys/ice1set/), [`Ice2Set`](/keys/ice2set/) and [`Ice3Set`](/keys/ice3set/) count as water, so the open edge of an ice sheet is water to anything moving across it. With it off, those tiles keep the land types their artwork declares.
