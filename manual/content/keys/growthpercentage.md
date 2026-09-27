---
key: GrowthPercentage
summary: Share of a Tiberium type's queued cells that one growth pass may ripen.
see_also: ["system:tiberium", "Growth"]
when_omitted:
  kind: value
  value: "0.1"
  note: A tenth of the type's queued cells.
---

Each [growth pass](/systems/tiberium/#growth) takes a random number of cells from the type's queue, from 1 up to a limit, and grows each one that still holds this type by one stage. The queue holds the type's cells that are still below full growth. The limit is the queue length multiplied by this value, raised to 5 if lower and cut to 50 if higher.

The queue covers every cell of the type on the map, so all of the type's fields share one limit. A map with little of this type grows at most 5 cells per pass, and no pass grows more than 50 cells, however much of the type the map holds.

A value of `0.00001` or less stops the type growing. Below `0.00001`, Tiberium dropped onto a cell that already holds this type also adds no stage, so the contents a destroyed storage building scatters onto such a cell are lost.
