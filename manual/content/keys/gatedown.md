---
key: GateDown
summary: The sound played at a gate as its door starts opening.
see_also: ["system:walls-and-gates", "Gate"]
when_omitted:
  kind: value
  value: none
---

The sound plays once, at the gate, when its door starts to open from rest. It does not play when a closing door reverses to open again, or when the gate is told to open while it is already opening or open.

Despite the names, this is the opening sound and [`GateUp`](/keys/gateup/) is the closing one.
