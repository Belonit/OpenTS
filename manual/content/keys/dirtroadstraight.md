---
key: DirtRoadStraight
summary: Parsed tile set of straight dirt road pieces that nothing reads.
no_effect: true
see_also: [DirtRoadCurve, DirtRoadJunction, DirtRoadSlopes]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The engine resolves the set number but never uses the result. The [random map generator](/systems/map-generation/) still lays straight dirt road pieces, but it finds them at offsets 35 to 100 of the run counted from [`DirtRoadCurve`](/keys/dirtroadcurve/), not through this role.
