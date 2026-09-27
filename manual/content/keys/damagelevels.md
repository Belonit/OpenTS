---
key: DamageLevels
summary: The number of damage stages a wall overlay passes through before it is removed.
see_also: ["system:walls-and-gates", "Strength"]
when_omitted:
  kind: value
  value: "1"
---

```ini title="art.ini"
[GAWALL]
DamageLevels=3
```

Each [landed hit](/systems/walls-and-gates/#whether-a-hit-lands) advances a wall segment by one damage stage. A segment is removed when its stage reaches `DamageLevels`. A segment with no [connections](/systems/walls-and-gates/#connection-frames) to neighboring walls is removed one stage earlier.

At the default of `1`, the first landed hit removes any segment. A connected segment survives a hit only when the value is `2` or more, and an unconnected one only when it is `3` or more.

When a segment reaches the stage one below `DamageLevels`, it [damages its undamaged neighbors](/systems/walls-and-gates/#stepping-through-the-stages) of the same overlay type. This happens only when `DamageLevels` is above `2`.

Infantry walk through a wall cell whose stage equals `DamageLevels` exactly, as though it were a hole. Damage never leaves a segment at that stage, because it removes the segment there, so only a map's overlay data can create such a cell.

Higher counts need artwork for every stage. For the overlays at certain `[OverlayTypes]` positions, the game also deletes an unconnected segment at a stage the stock artwork does not cover, as soon as its connection frames are rebuilt. [Damage stages with no artwork](/systems/walls-and-gates/#damage-stages-with-no-artwork) lists the positions and stages.
