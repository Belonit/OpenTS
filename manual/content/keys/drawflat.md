---
key: DrawFlat
summary: Whether the overlay sorts as a marking on the ground or as something standing upright.
see_also: [IsARock, Wall, Tiberium, High]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="rules.ini"
[MYFENCE]        ; example upright ground fixture that is not a wall
DrawFlat=no
```

`DrawFlat` decides how the overlay's artwork sorts against objects passing through or beside its cell. It does not move the artwork on screen.

With the default `DrawFlat=yes`, the overlay sorts as a marking lying on the ground. With `DrawFlat=no`, it sorts as something standing upright in the cell, and its whole shape also sorts as though it stood one terrain height level higher. [`IsARock=yes`](/keys/isarock/) removes that one-level lift and keeps the upright sorting.

:::note[Some overlays ignore this key]
Bridge decks, Tiberium overlays, [`Wall=yes`](/keys/wall/#scope-overlaytype) overlays and the vein overlay (`VEINS` in the stock rules) sort in a fixed way. Walls always sort as upright, and the other three as ground markings. The veinhole overlays are drawn by the veinhole monster. The key applies only to other overlays.
:::
