---
key: ExitCoord
summary: The offset from its exit cell's center at which a barracks places a produced object.
see_also: [GDIBarracks, NODBarracks, WeaponsFactory, "system:production"]
when_omitted:
  kind: value
  value: 0,0,0
---

`ExitCoord` moves the point where a barracks puts down an object it releases. Only a [`GDIBarracks=yes`](/keys/gdibarracks/) or [`NODBarracks=yes`](/keys/nodbarracks/) structure uses it, and only when the object leaves by the barracks' preferred exit cell.

```ini title="rules.ini"
[GAPILE] ; the stock GDI barracks
GDIBarracks=yes
ExitCoord=-64,64,0
```

The three numbers are X, Y and height, in leptons; 256 leptons make one cell. The stock value above moves the soldier a quarter of a cell toward lower X and a quarter of a cell toward higher Y.

The height is absolute, not measured from the ground. An object whose height would put it below the ground is raised onto it. A soldier is moved to one of the cell's standard infantry positions, chosen by which part of the cell the point lies in, only when its height equals the ground level at that point. With the stock height of `0`, that happens only on ground at level 0. On higher ground the soldier is lifted onto the ground and stays at the offset X and Y.

## Where the offset is measured from

A `GDIBarracks=yes` structure prefers to release its object toward the cell one along and two down from the top-left cell of its footprint. A `NODBarracks=yes` structure prefers the cell two along and two down. The object does not appear on that cell. It appears on the cell inside the footprint next to it: the preferred cell moved one step back on each axis where it lies outside the footprint. On a footprint two cells deep, which both stock barracks have, that is a cell on the bottom row of the barracks itself. The offset is measured from the center of that cell.

When the preferred cell is blocked, the object leaves by another cell around the footprint. It then appears at the center of the matching cell inside the footprint, with no offset. [Leaving the factory](/systems/production/#leaving-the-factory) covers how the exit cell is picked.

:::caution[A weapons factory ignores this key]
A [`WeaponsFactory=yes`](/keys/weaponsfactory/) structure puts every object it releases, soldiers included, at the same fixed point on the structure, even when it is also a barracks. Writing `ExitCoord` on such a type changes nothing.
:::
