---
key: MoveToShroud
summary: Whether the type accepts an order onto ground that is still under the shroud.
see_also: ["system:map-visibility", Sight, AllowShroudedSubteranneanMoves]
when_omitted:
  kind: value
  value: "yes"
  note: An AircraftType defaults to no instead.
---

At `no`, the player cannot order the object onto a shrouded cell: the no-move cursor shows, and a click leaves the object where it is.

At `yes`, a click on a shrouded cell becomes a plain move. An attack click on shrouded ground sends the object there without firing. A patrol waypoint order stays a patrol order.

In a campaign, the same rule applies to a click on an object that stands under the shroud. Outside a campaign, this setting does not change such a click. An aircraft ignores a move click on a shrouded object even at `yes`, and so does a subterranean unit unless [`AllowShroudedSubteranneanMoves=yes`](/keys/allowshroudedsubteranneanmoves/) is set.

At `no`, a player's object leaving a factory also ignores a rally point that is still shrouded for the player, as [rally points](/systems/production/#rally-points) describes.
