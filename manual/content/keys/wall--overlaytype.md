---
key: Wall
scope: overlaytype
label: Wall overlay
see_also: ["system:walls-and-gates"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[GAWALL]
Wall=yes
Strength=150
```

`Wall=yes` makes an overlay a wall segment. The flag turns on:

- the connection artwork that joins neighboring segments into a run;
- the [damage stages](/systems/walls-and-gates/#taking-damage) that [`Strength`](/keys/strength/#scope-overlaytype) and [`DamageLevels`](/keys/damagelevels/) drive;
- blocking, whatever the overlay's [`Land`](/keys/land/) value, unless the overlay is also [`Crushable=yes`](/keys/crushable/#scope-aircrafttype), which lets crusher vehicles drive over it;
- the sell cursor and the sale of the segment;
- damage from a [`Wall=yes`](/keys/wall/#scope-warheadtype) warhead, or from a [`Wood=yes`](/keys/wood/) warhead when the overlay's armor is wood.

[Walls and gates](/systems/walls-and-gates/) covers each of these. The stock wall overlays leave `Land` at `Clear`, so this flag alone makes them block.

Without the flag, an overlay takes no wall damage and has none of the behavior above. It blocks movement only through its land type, as its `Land` value and the movement costs decide.

This flag is separate from [`Wall=yes`](/keys/wall/#scope-buildingtype) on the BuildingType that lays the overlay. A wall structure converts into the overlay its [`ToOverlay`](/keys/tooverlay/) names whether or not that overlay sets this flag. If the overlay does not set it, the result is an ordinary overlay with none of the wall behavior.
