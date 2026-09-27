---
key: ShroudGrow
summary: Whether the shroud creeps back over terrain that nothing is watching.
see_also: ["system:map-visibility", ShroudRate]
when_omitted:
  kind: value
  value: "no"
---

At `yes`, the shroud creeps back over revealed terrain that nothing is watching. Every [`ShroudRate`](/keys/shroudrate/) game minutes, a [shroud pass](/systems/map-visibility/#shroud-regrowth) covers one more cell at the edge of each revealed area. At `no`, revealed terrain stays revealed unless a trigger, a team's Reshroud map mission or a darkness crate shrouds it again.

This key only switches the timed passes on. The [Creep shadow back in](/mapping/actions/taction-creep-shadow/) trigger action runs a pass at any value.
