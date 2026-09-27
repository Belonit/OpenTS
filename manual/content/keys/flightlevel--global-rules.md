---
key: FlightLevel
scope: global-rules
label: Rules-wide cruising altitude
see_also: ["AircraftFogReveal"]
when_omitted:
  kind: value
  value: "500"
---

The cruising height, in leptons above the ground, of every type that does not set a [cruising altitude of its own](/keys/flightlevel/#scope-aircrafttype). The stock rules set `600`, which every stock aircraft except the dropship flies at. The dropship and the two hunter-seeker drones set their own heights.

The value also sets the height test for [`AircraftFogReveal`](/keys/aircraftfogreveal/). An aircraft flying below half this height can have that reveal blocked by high ground, as [who looks, and when](/systems/map-visibility/#who-looks-and-when) describes. The aircraft type's own `FlightLevel` does not move this threshold.
