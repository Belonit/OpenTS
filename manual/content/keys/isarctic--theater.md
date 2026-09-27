---
key: IsArctic
scope: theater
label: Arctic theater
see_also: [IsIceGrowthEnabled, TemperateOccupationBits, SnowOccupationBits]
when_omitted:
  kind: context-dependent
  note: "`yes` for SNOW, which keeps its original settings; `no` for TEMPERATE and for every other theater."
---

`IsArctic` picks which occupation bits terrain objects use in this theater. With `yes` they use [`SnowOccupationBits`](/keys/snowoccupationbits/), and with `no` they use [`TemperateOccupationBits`](/keys/temperateoccupationbits/). The bits decide which sub-positions of a cell a tree or rock blocks. A terrain type has only these two sets, so a new theater uses one of them.

```ini title="rules.ini"
[DESERT]
IsArctic=no     ; uses TemperateOccupationBits
```

An arctic theater also draws the numbers on waypoints in black instead of light gray.

The [random map generator](/systems/map-generation/) places no veinholes in an arctic theater and gives it three quarters of the usual ambient light. The generator lays out only TEMPERATE and SNOW, so this part of the setting affects only those two theaters. When the rules declare no theater under the name the generator asks for, it uses the first declared theater, and that theater's `IsArctic` decides instead.
