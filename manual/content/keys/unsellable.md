---
key: Unsellable
summary: Prevents the player from selling the BuildingType's structures.
see_also: ["system:walls-and-gates"]
when_omitted:
  kind: value
  value: "no"
---

`Unsellable=yes` stops the player from selling any structure of this type. The sell cursor is never offered over it.

The flag does not stop sales the game starts itself. A computer house sells unsellable structures like any other, including when it sells off its whole base, and so does the [Sell building](/mapping/actions/taction-sell-attached/) trigger action.

The flag also covers wall segments. A segment can be sold, or cleared for a new segment, gate or tower, only if the first BuildingType whose [`ToOverlay`](/keys/tooverlay/) lays its overlay is sellable. When several BuildingTypes lay the same overlay, only the one declared first counts. [Walls and gates](/systems/walls-and-gates/#crushing-clearing-and-selling) covers selling and clearing walls.
