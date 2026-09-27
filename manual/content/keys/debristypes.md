---
key: DebrisTypes
summary: The voxel wreckage a destroyed object throws, spent in list order against its debris budget.
see_also: [MaxDebris, DebrisMaximums, MetallicDebris, ExplosiveVoxelDebris]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
MaxDebris=6
DebrisTypes=MYSCRAP,MYTIRE ; VoxelAnimTypes registered in [VoxelAnims]
DebrisMaximums=4,2
```

The list is used only when [`MaxDebris`](/keys/maxdebris/) is above zero. It replaces the generic debris: a type with a budget and no list throws [`MetallicDebris`](/keys/metallicdebris/) animations instead, and a type with a list throws none of them.

Entries are thrown in list order, each up to its [`DebrisMaximums`](/keys/debrismaximums/) figure. A later entry is cut short or skipped only when the earlier entries have used up the budget. `MaxDebris` describes the random draw and the budget.

`DebrisTypes=none` empties the list, so the type falls back to `MetallicDebris`. A key written with nothing after the `=` keeps the list an earlier rules file set.
