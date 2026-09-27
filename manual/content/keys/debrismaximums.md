---
key: DebrisMaximums
summary: The largest number of pieces each debris type may contribute, one figure per entry.
see_also: [DebrisTypes, MaxDebris, MetallicDebris]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
MaxDebris=6
DebrisTypes=MYSCRAP,MYTIRE ; VoxelAnimTypes registered in [VoxelAnims]
DebrisMaximums=4,2 ; at most four MYSCRAP, then at most two MYTIRE
```

Each figure caps the debris type in the same position of [`DebrisTypes`](/keys/debristypes/): the first figure caps the first type, the second caps the second, and so on. The figure is a maximum, and the count thrown is drawn at random; [`MaxDebris`](/keys/maxdebris/) describes the draw. A figure of `0` never throws a piece of its type and leaves the whole remaining budget to the next entry.

The list does nothing on a type that names no `DebrisTypes`.

:::danger[Give every debris type a figure of 0 or more]
The engine does not check that this list is as long as `DebrisTypes`. A type with `MaxDebris` above 0 that names debris types but no maximums crashes when it is destroyed. With fewer figures than debris types, each extra type reads its figure from past the end of the list. The piece count is then unpredictable, and the read can crash the game.

A figure of `-1` divides by zero and crashes the game when the object is destroyed.
:::
