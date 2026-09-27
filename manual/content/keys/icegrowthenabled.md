---
key: IceGrowthEnabled
summary: Allows ice sheets to creep outward and cracked ice to refreeze.
see_also: [TiberiumGrowthEnabled, VeinGrowthEnabled, IceSolidifyFrameTime]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="map file"
[Basic]
IceGrowthEnabled=no
```

With the switch on, ice changes during the mission in two ways:

- Ice sheets creep outward. At the interval [`IceGrowthRate`](/keys/icegrowthrate/) sets, each growth step turns the thin ice at a sheet's edge into full ice. Only cells that the map data marks as allowing ice growth take part.
- Cracked ice refreezes. A cracked cell heals once [`IceSolidifyFrameTime`](/keys/icesolidifyframetime/) has passed, and cracked cells beside it heal with it.

Both need a theater whose [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) is `yes`; by default only the snow theater sets it. In any other theater the switch changes nothing.

With the switch off, cracks stay cracked until it is turned back on; ice can still crack and break. The [Ice growth](/mapping/actions/taction-ice-growth/) trigger action turns the switch on or off during the mission.
