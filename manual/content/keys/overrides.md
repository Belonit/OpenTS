---
key: Overrides
summary: Overlay that no other overlay may replace once it is on a cell.
see_also: [Land, Wall, Tiberium]
when_omitted:
  kind: value
  value: "no"
---

An overlay with `Overrides=yes` cannot be replaced by an ordinary overlay placed on its cell during play. The flag is read on the overlay already in the cell, not on the one arriving. When the cell holds an overlay that sets it, the new overlay is refused and the cell keeps what it had.

The test covers ordinary overlays only. Walls, overlays with `Land=Railroad`, veins and veinholes are placed by their own rules and do not check this flag. Overlays a map places as it loads are not checked either.

```ini title="rules.ini"
[MYPIPE]         ; example ground fixture that a crate must not replace
Overrides=yes
```

:::caution[The name reads backward]
Setting the flag does not let a type override others. It protects the type from being overridden.
:::

A refused overlay still plays its [`CellAnim`](/keys/cellanim/).
