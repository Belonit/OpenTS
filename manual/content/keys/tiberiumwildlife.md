---
key: TiberiumWildlife
summary: Scales how many tiberium creatures each tiberium field spread across a generated map releases, as a figure from 0 to 100.
see_also: [Tiberium, TiberiumLayout, "system:tiberium"]
when_omitted:
  kind: value
  value: "0"
  note: No field gets any creatures.
---

Each tiberium field spread across a generated map draws a creature budget scaled by this figure, then spends it as it grows. Each creature appears at a cell drawn at random from the part of the field not yet grown, and is owned by the `Neutral` house. [Map seed files](/formats/map-seed/) covers the section it is written in.

```ini title="map seed file"
[RandomMap]
TiberiumWildlife=30
```

Creatures appear only with the Firestorm addon enabled; without it, the setting is turned off before any map is built, as [Map seed files](/formats/map-seed/#missing-and-out-of-range-settings) describes. Only the fields spread across the map get creatures. The fields at the players' start points never do.

Each creature is one of four IDs, drawn with equal chance: `VISC_SML`, `VISC_LRG`, `JFISH` and `DOGGIE`. Stock rules define them as the baby visceroid, the adult visceroid, the tiberium floater and the tiberian fiend.

Keep `VISC_SML`, `VISC_LRG` and `JFISH` defined as vehicles and `DOGGIE` as infantry. If one is missing, or defined as the other kind, a field that draws it can crash the game.

A creature that cannot be put down at its cell is discarded and still counts against the budget.

:::caution[Most figures give a field no creatures or an unlimited number]
A field's budget is one of five equally likely outcomes, `-2`, `-1`, `0`, `1` or `2`, multiplied by the figure divided by 100 and rounded down. The two negative outcomes were meant to give no creatures, but the engine computes them as very large positive numbers. Up to `50` they give a budget that never runs out; above `50` they overflow and give none.

| `TiberiumWildlife` | Unlimited budget | Budget of one | Budget of two | No budget |
| --- | --- | --- | --- | --- |
| `1` to `49` | 2 fields in 5 | Never | Never | 3 fields in 5 |
| `50` | 2 fields in 5 | 1 field in 5 | Never | 2 fields in 5 |
| `51` to `99` | Never | 1 field in 5 | Never | 4 fields in 5 |
| `100` | Never | 1 field in 5 | 1 field in 5 | 3 fields in 5 |

A field places at most its budget, and a field that stops growing early can place fewer.

A field with an unlimited budget keeps releasing creatures for as long as it grows. Each next creature's cell is drawn from the part of the field still to grow, so such a field gets several creatures, not one per cell.
:::

The map generator dialog offers the setting as a check box. Checking it writes `30` and clearing it writes `0`. At `30`, two fields in five get an unlimited budget and the rest get none. The randomize button can write any figure from `0` to `100`, and any figure above `0` shows as a checked box. The dialog previews, builds and saves that figure until the box is clicked.
