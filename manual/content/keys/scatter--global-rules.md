---
key: Scatter
scope: global-rules
label: IQ threshold
see_also: [IQ, PlayerScatter]
when_omitted:
  kind: value
  value: "3"
---

When a threat heads for a cell, an occupant whose house has an [`IQ`](/keys/iq/) at or above this value is told to scatter out of the way. The test applies to a house a person controls as well. A map that raises a player house's `IQ` this far makes that player's vehicles dodge incoming fire without an order. A vehicle that is driving somewhere does not dodge.

The test applies to warnings raised by three threats:

- an aircraft firing at a target in the cell;
- an infantryman firing at a target in the cell, when its primary weapon is slower than [`Incoming`](/keys/incoming/);
- a crushing vehicle driving onto a cell that holds infantry.

This is one of several conditions that let a warned occupant scatter. [`PlayerScatter`](/keys/playerscatter/) lists the others.

:::caution[A walking soldier keeps to its path]
A soldier that is already walking scatters only if its type sets [`Fraidycat=yes`](/keys/fraidycat/), because walking turns the warning into an unforced one. Such a soldier still refuses when its mission sets [`Scatter=no`](/keys/scatter/#scope-mission-behavior). If a person controls its house, it also needs one of the conditions [`PlayerScatter`](/keys/playerscatter/) lists for infantry. A standing soldier scatters unless it is in the middle of an action that cannot be interrupted.
:::
