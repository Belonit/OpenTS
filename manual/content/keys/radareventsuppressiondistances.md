---
key: RadarEventSuppressionDistances
summary: The cells within which a radar event causes a later event of its kind to be dropped, one entry per event kind.
see_also: ["system:map-visibility", RadarEventDurations]
when_omitted:
  kind: value
  value: ""
  note: The game crashes the first time a suppressible event is raised while another of its kind is in play.
---

Entries are positional: one per [radar event](/reference/enums/radar-event/) kind, in the order that page lists them. Only combat, harvester-attacked and enemy-sensed events use their entry. The other three kinds are always created, and their entries are never read.

A new event of one of those three kinds is dropped when an event of the same kind, still in play, lies closer than that kind's entry, in cells measured in a straight line. An event stays in play, and goes on suppressing, until its [`RadarEventDurations`](/keys/radareventdurations/) count runs out, even after it has stopped being drawn.

The distance also limits how often three EVA lines play, because each plays only when its event is created:

- The harvester-under-attack line plays with a harvester-attacked event. The engine raises one when a [`Harvester=yes`](/keys/harvester/#scope-unittype) vehicle of the local player takes damage that has any effect and survives it. A killing blow raises no event and plays no line.
- The cloaked-detected and subterranean-detected lines play with an enemy-sensed event. The engine raises one while the local player's sensors detect a cloaked or underground object of a house that does not share the player's view.

:::danger[Give the list six entries]
Enemy sensed is the last of the six kinds, so a list of five entries or fewer reads an undefined value for it. That happens as soon as an enemy-sensed event is raised while another is in play.
:::
