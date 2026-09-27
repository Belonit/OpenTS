---
key: CrateTrigger
summary: Whether collecting the overlay springs the crate pickup trigger events.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "no"
---

Collecting an overlay with `CrateTrigger=yes` fires two trigger events:

- [Pickup Crate](/mapping/events/tevent-pickup-crate/) springs on the collector's tag, if the collector has one, before the crate's result is chosen.
- [Pickup Crate (any)](/mapping/events/tevent-pickup-crate-any/) fires for the scenario's general triggers on the next game frame.

If the Pickup Crate trigger destroys the collector, collection stops there. The crate stays on the map, no result is delivered, and Pickup Crate (any) does not fire.

The overlay must also set [`Crate=yes`](/keys/crate/). An overlay that is not a crate is never collected, so `CrateTrigger=yes` alone fires nothing.
