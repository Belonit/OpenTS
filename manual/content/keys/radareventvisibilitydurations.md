---
key: RadarEventVisibilityDurations
summary: The frames a settled radar event stays drawn, one entry per event kind.
see_also: ["system:map-visibility", RadarEventDurations]
when_omitted:
  kind: value
  value: ""
  note: The game crashes the first time a radar event settles.
---

Entries are positional: one per [radar event](/reference/enums/radar-event/) kind, in the order that page lists them. Each entry is the number of game frames, 900 to the game minute, that the settled marker of an event of that kind stays drawn. The count starts when the box settles. The box closing in is drawn whatever this list says.

When the count runs out, the marker stops being drawn and stops pulsing. The event itself stays in play until its [`RadarEventDurations`](/keys/radareventdurations/) count runs out too. Until then, a combat, harvester-attacked or enemy-sensed event still [suppresses](/keys/radareventsuppressiondistances/) later events of its kind nearby.

The marker is drawn for whichever of the two counts is shorter, because removing the event also removes its marker. An entry of `0` or less hides the marker as soon as the box settles.

:::danger[Give all six kinds an entry]
Any of the six kinds can read this list. The engine raises three of them, and the other three come only from the [Create Radar Event](/mapping/actions/taction-radar-event/) trigger action. A kind whose entry lies past the end of a shorter list reads an undefined value, so its marker may vanish at once, partway through, or only when the event is removed.
:::
