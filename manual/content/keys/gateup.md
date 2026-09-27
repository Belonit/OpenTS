---
key: GateUp
summary: The sound played at a gate as its door starts closing.
see_also: ["system:walls-and-gates", "Gate"]
when_omitted:
  kind: value
  value: none
---

The sound plays once, at the gate, when its door starts to close. That happens after [`GateCloseDelay`](/keys/gateclosedelay/) has run out with nothing standing in the gate.

Despite the names, this is the closing sound and [`GateDown`](/keys/gatedown/) is the opening one.
