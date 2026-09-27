---
key: IsARock
summary: Draws objects on a slope beside the overlay in front of it, and cancels the one-level depth lift of an upright overlay.
see_also: [DrawFlat, High]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MYBOULDER]      ; example rock overlay beside cliff ramps
DrawFlat=no
IsARock=yes
```

`IsARock` has two separate effects: one on the overlay's own depth, and one on objects standing on a slope beside it.

On its own artwork, it cancels the one-level lift that [`DrawFlat=no`](/keys/drawflat/) applies, so the overlay sorts at its real ground height while still sorting as upright. With `DrawFlat=yes` there is no lift, and the key does not change how the overlay is drawn.

It also brings infantry and vehicles standing on a slope in front of a rock beside them. An object on a slope checks the cells to its south, east and south-east. If one of them holds an `IsARock=yes` overlay, the object is drawn in front of it instead of disappearing into it.

:::caution[An ordinary overlay can hide a rock]
The object checks the south cell first, then the east cell, then the south-east cell, and stops at the first cell that holds any overlay. An ordinary overlay to the south therefore hides a rock to the east or south-east, and the object is drawn as though the rock were not there.
:::
