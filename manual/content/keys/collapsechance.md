---
key: CollapseChance
summary: Percent chance that a destroyable cliff comes down when something reaches its cell.
see_also: ["IsRailgun", "IsSonic"]
when_omitted:
  kind: value
  value: "100"
---

Each hit on a destroyable cliff cell brings the cliff down with this percent chance. `100` collapses it on every hit and `0` never does. Values above `100` behave as `100`. Only cells the theater marks as destroyable cliffs are rolled for.

These hits roll for a collapse:

- an explosion in the cell;
- an [`IsRailgun=yes`](/keys/israilgun/) beam stopped by rising ground, at the cell where it stops;
- an `IsRailgun=yes` beam fired at a cell, at that cell, when the beam reaches it;
- an [`IsSonic=yes`](/keys/issonic/) wave, at every cell it currently covers, once per frame for as long as the wave lasts.

Because a sonic wave rolls again on every frame, even a low value is likely to bring down a cliff that stays under the wave for long. At `1`, a cliff under a wave for 100 frames comes down about 63 times in 100.
