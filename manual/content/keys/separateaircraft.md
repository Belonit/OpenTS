---
key: SeparateAircraft
summary: Whether pad aircraft are bought separately from the pads they dock at.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "no"
---

At `yes`, pad aircraft are bought separately from the pads they dock at, with these effects:

- A [`HoverPad=yes`](/keys/hoverpad/) structure no longer receives a free copy of the first [`PadAircraft`](/keys/padaircraft/) entry when it first opens.
- The first structure in the `Dock` list of the first `PadAircraft` entry no longer has the average `PadAircraft` price deducted from its `Cost` to form its [reduced price](/keys/cost/#what-a-structure-gives-away). Its repairs therefore cost more, and damage to it raises more anger toward the attacker. The linked section lists every use of the reduced price.

The price paid for the pad and the refund for selling it are based on the written `Cost` at either setting. Aircraft are still built at pads and still dock at them. The shipped rules set `yes`.
