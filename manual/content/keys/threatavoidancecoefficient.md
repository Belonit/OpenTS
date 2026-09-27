---
key: ThreatAvoidanceCoefficient
summary: How heavily the type weighs the region threat figures when the pathfinder prices a route.
see_also: ["system:base-attacked", AvoidThreats, ThreatPosed]
when_omitted:
  kind: value
  value: "0"
---

Higher values make an object of this type route further around danger, and a value of `0` or below makes the pathfinder ignore threat. When a route is planned for the object, the pathfinder multiplies [the threat figure](/systems/base-attacked/#the-threat-map) of each region on the way by this value:

- The [block stage of route search](/systems/route-search/#planning-in-blocks) adds the product, rounded down to a whole number, to the price of each step at the 8-by-8 and 4-by-4 sizes. A product below 1 adds nothing.
- The shortcuts that straighten a planned route refuse cells where the product is high. [What reads the map](/systems/base-attacked/#what-reads-the-map) gives the thresholds.

The value is read only when a route is planned; a route the object is already following is not priced again. The threat figures themselves come from [`ThreatPosed`](/keys/threatposed/).

Only infantry and vehicles whose locomotor plans routes on the ground use the value: the drive, hover, levitate, mech and walk locomotors. Each object copies the value from its type when it is placed on the map. While it belongs to a team with [`AvoidThreats=yes`](/keys/avoidthreats/), it uses `1` in place of its own value. Structures and ordinary aircraft do not plan routes, so the key has no effect on them.
