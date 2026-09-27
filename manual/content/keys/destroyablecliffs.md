---
key: DestroyableCliffs
summary: Tile set holding the two cliff faces that weapon fire can bring down.
see_also: [CollapseChance, SlopeSetPieces, CliffSet]
when_omitted:
  kind: value
  value: "-2"
  note: The role stays unresolved and the theater has no collapsible cliff, since the two tile indices it would name are both negative and no cell can hold them.
---

Exactly two tiles in the theater can collapse: the first tile of the set this key names and the tile after it. Every other cliff face is permanent. [Theater control files](/formats/theater-control/) explains how a `[General]` role is resolved to a tile index.

A cell holding one of the two tiles rolls [`CollapseChance`](/keys/collapsechance/) each time any of these reaches it:

- an explosion centered in the cell;
- a sonic wave sweeping the cell;
- a railgun beam fired at the cell, or one that stops against it because the ground there rises above the beam.

When the roll succeeds, the cliff tile is removed from every cell it covered and two pieces from [`SlopeSetPieces`](/keys/slopesetpieces/) are laid in its place. Movement zones are rebuilt, so units can path up the new slope. Any unit attacking one of those cells drops the target and returns to its previous mission, and any team targeting one of them drops the target. Rubble from the `XGRYMED1`, `XGRYMED2` and `XGRYSML1` animations is scattered over the collapsed area; the three names are fixed in the engine.

The two tiles also affect targeting before they collapse:

- A player can order a unit to attack one of these cells without the force-fire key, as long as the cell holds no overlay, the unit's primary weapon has a warhead without [`Fire`](/keys/fire/), and the unit can move or already has the cell in range.
- While a unit closes in on one of these cells, it switches its target to whichever cell of the same cliff tile is nearest to it.
- A unit with one [`Webby`](/keys/webby/) weapon and one other weapon uses the other weapon against these cells.

:::note[The fallback is `-2`, not `-1`]
Every other tile role in `[General]` falls back to `-1`. This one falls back to `-2`, so the second tile it names is `-1` and not the theater's first tile. Writing `DestroyableCliffs=-1` does not change anything: a value that matches no tile set leaves the role at `-2`, the same as omitting the key.
:::
