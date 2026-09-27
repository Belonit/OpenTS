---
key: RetargetAccuracy
summary: The chance that a bomblet from a splitting projectile keeps the carrier's target.
see_also: [Splits, AirburstWeapon, Cluster]
when_omitted:
  kind: value
  value: "0"
---

Only a [`Splits=yes`](/keys/splits/) projectile reads the figure. Write it as a fraction from `0` to `1` or as a percentage: `75%` and `0.75` are the same assignment.

Each bomblet is decided separately:

1. If the carrier still has its target, the bomblet keeps that target at this chance.
2. Otherwise the bomblet draws a target at random from a list of candidates, and that entry is removed from the list.

`0` sends every bomblet to the random draw, and `1` sends every bomblet at the carrier's target. A carrier that lost its target before the burst, for example because the target was destroyed, sends every bomblet to the draw.

The candidate list holds every object within five cells of the carrier's target. When the carrier was aimed at a cell, or has lost its target, the list is built around the carrier's position instead. If fewer than [`Cluster`](/keys/cluster/) objects are there, the list is padded with random cells up to three cells away in each direction from the same point, so every bomblet has something to aim at.

:::caution[Bomblets can target the firer's own side]
The candidate list includes the firer, its other vehicles, infantry, aircraft and structures, and those of its allies, when they are within five cells of the point the list is built around. A bomblet that draws the firer draws again on an even chance, and the second draw can pick the firer too. A low figure against a target close to friendly units scatters bomblets onto them.
:::
