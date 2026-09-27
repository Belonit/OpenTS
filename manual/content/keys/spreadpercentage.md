---
key: SpreadPercentage
summary: Share of a Tiberium type's queued cells that one spread pass may seed from.
see_also: ["system:tiberium", "Spread"]
when_omitted:
  kind: value
  value: "0.1"
  note: A tenth of the type's queued cells.
---

Each [spread pass](/systems/tiberium/#spread) seeds up to a random number of new cells from the type's queued cells, from 1 up to a limit. The limit is the queue length multiplied by this value, raised to 5 if lower and cut to 25 if higher.

The queue covers every cell of the type on the map, so all of the type's fields share one limit, and no pass seeds more than 25 cells in total.

Each new cell counts toward the limit. A queued cell with more than one free neighbor can seed several of them in the same pass. A queued cell with no free neighbor, or one that can no longer spread, leaves the queue without counting, so a pass can work through far more of the queue than the limit when most of a field is hemmed in.

A value of `0.00001` or less stops the type spreading from its cells.
