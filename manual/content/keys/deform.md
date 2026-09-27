---
key: Deform
summary: The chance, in percentage points per point of damage, that a blast lowers the ground under it.
see_also: [DeformThreshhold]
when_omitted:
  kind: value
  value: "0"
---

A blast's chance to crater, in percent, is its damage multiplied by this value. The result is truncated to a whole percent, so a product below 1 never craters. A value written with a trailing percent sign is divided by 100: `Deform=15%` adds 0.15 percentage points of chance per point of damage.

```ini title="rules.ini"
[MyShellWH] ; example WarheadType
Deform=15%
DeformThreshhold=120
```

With this warhead, a 200-damage blast craters 30 percent of the time. A blast of 120 damage or less never craters, because the chance is rolled only above [`DeformThreshhold`](/keys/deformthreshhold/). Truncation can land one percent below the exact product: at 300 damage the chance is 44 percent, not 45.

The damage tested is the blast's full damage, not what any object in it takes.

A crater lowers the cell by one height level. One corner drops at the moment of the blast, and the rest follow five game frames later. If a second crater starts anywhere on the map within those five frames, the first crater keeps only its first corner. The ground stays unchanged in any of these cases:

- any of the eight cells around the blast lies outside the playfield;
- a structure, terrain object, landed aircraft, overlay or bridge is on or near the cell, or the cell's tile cannot be reshaped;
- the blast is at or above the deck of a bridge.

A [wide-area blast](/systems/warheads/#the-wide-area-blast) makes one extra roll at its center from its full damage, and this roll ignores bridge decks. Each cell's ordinary blast then rolls again with that cell's own figure, under the rules above, so the center cell gets a second roll at full damage.

The collateral blast of a dying [`Explodes=yes`](/keys/explodes/#scope-aircrafttype) object, or of one with the `EXPLODES` [ability](/systems/veterancy/#abilities), uses the `Deform` of its first weapon's warhead. A loaded harvester's blast uses that of [`C4Warhead`](/keys/c4warhead/).
