---
key: RadarEventDurations
summary: The frames a radar event stays in play, one entry per event kind.
see_also: ["system:map-visibility", RadarEventVisibilityDurations, RadarEventSuppressionDistances]
when_omitted:
  kind: value
  value: ""
  note: The game crashes the first time a radar event settles.
---

Entries are positional: one per [radar event](/reference/enums/radar-event/) kind, in the order that page lists them. Each entry is the number of game frames, 900 to the game minute, that an event of that kind stays in play after its box settles. The time the box spends closing in is not counted.

```ini title="rules.ini"
[General]
; example values: combat, non-combat, drop zone, base attacked, harvester attacked, enemy sensed
RadarEventDurations=400,400,400,400,600,600
```

When the count runs out, the event is removed, and an entry of `0` or less removes it as soon as it settles. Until it is removed, a combat, harvester-attacked or enemy-sensed event keeps [suppressing](/keys/radareventsuppressiondistances/) later events of its kind nearby.

:::danger[Give all six kinds an entry]
Any of the six kinds can read this list. The engine raises three of them, and the other three come only from the [Create Radar Event](/mapping/actions/taction-radar-event/) trigger action. A kind whose entry lies past the end of a shorter list reads an undefined value the first time an event of that kind settles.
:::
