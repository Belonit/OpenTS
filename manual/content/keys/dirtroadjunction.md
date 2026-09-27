---
key: DirtRoadJunction
summary: The tile set that supplies the eleven dirt road junctions.
see_also: [DirtRoadCurve, DirtRoadStraight, DirtRoadSlopes]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

Every dirt road network the [random map generator](/systems/map-generation/) lays starts on one of the eleven junctions counted from this role. The generator tries each of the eleven once at the network's starting cell, beginning with a randomly chosen one so that networks do not all open the same way. If none of them fits, the generator lays no road there.

Only the starting junction comes from this role. Junctions laid later in a network come from the run counted from [`DirtRoadCurve`](/keys/dirtroadcurve/), which holds the same eleven pieces at offsets 24 to 34.

The generator reads the starting junction's connection points by its distance from the first `DirtRoadCurve` tile. Keep this role's first tile exactly 24 tiles after that one, which is where it sits when the junction set directly follows a 24-tile curve set. Otherwise the road grows from the connection points of whatever piece sits at that distance. A junction outside both the 101-tile run and the [`DirtRoadSlopes`](/keys/dirtroadslopes/) set is read as the run's first piece, a curve.
