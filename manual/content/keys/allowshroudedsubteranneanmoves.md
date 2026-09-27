---
key: AllowShroudedSubteranneanMoves
summary: Whether a subterranean unit accepts a click on an object standing under the shroud, and follows a rally point into the shroud.
see_also: ["system:map-visibility", MoveToShroud]
when_omitted:
  kind: value
  value: "no"
---

A subterranean unit is one whose type takes the [`Subterannean` movement zone](/reference/enums/movement-zone/). At `no`, a move click that would send one onto an object under the shroud does nothing: the click is used up, the unit gets no order, and it stays where it is. At `yes`, the same click gives an ordinary move order.

Aircraft ignore a move click onto a shrouded object in the same way, and no setting changes that for them. The key covers only a click on an object. A click on shrouded ground follows [`MoveToShroud`](/keys/movetoshroud/) instead.

At `no`, a player's subterranean unit leaving a factory also ignores a rally point that is still shrouded for the player. At `yes`, it follows the rally point if its type also allows `MoveToShroud`, as [rally points](/systems/production/#rally-points) describes.
