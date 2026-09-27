---
key: DirtRoadSlopes
summary: The tile set that supplies the eight pieces taking a dirt road up a ramp.
see_also: [DirtRoadCurve, DirtRoadJunction, PavedRoadSlopes]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
no_effect: true
---

The [random map generator](/systems/map-generation/) lists the eight ramp pieces in its dirt road table, after the 101 flat pieces counted from [`DirtRoadCurve`](/keys/dirtroadcurve/), but never lays one. The pieces it chooses from all come from the flat run, so a generated dirt road never climbs a ramp. [`PavedRoadSlopes`](/keys/pavedroadslopes/) is the paved counterpart and has no effect either.
