---
key: MovementZone
summary: Selects which terrain the type can cross when the game decides whether it can reach a cell.
see_also: ["system:base-attacked"]
when_omitted:
  kind: value
  value: "Normal"
---

For each [movement zone](/reference/enums/movement-zone/) class, the engine divides the map into connected zones. Whether an object can get from one cell to another is answered on the zone map of the class its type names. The pathfinder uses the same class to decide which terrain a route may cross.

`Subterannean` also marks the type as a burrowing mover. A move order to a visible cell outside its connected zone then stands as given, where another ground type's order is moved to a nearby cell it can reach. An order to a shrouded cell, to a cell outside the playable area, or to a cell it cannot enter is still moved to a nearby cell. [`MoveToShroud`](/keys/movetoshroud/) decides whether it accepts an order into the shroud at all, and [`AllowShroudedSubteranneanMoves`](/keys/allowshroudedsubteranneanmoves/) decides whether such a type may be sent to an object under the shroud.

Two automatic decisions compare zones directly without plotting a route:

- The [base defense call-up](/systems/base-attacked/#which-objects-qualify) drops a candidate whose destination is not in the same zone as the damaged object.
- [Target selection](/systems/target-selection/#why-a-candidate-is-rejected) rejects a candidate in a different zone. It skips this test in a range scan and when the scanning object is a structure or an aircraft.

Both use the class named by the type that moves or scans, never the other object's class.

:::caution[Use a listed class name]
Class names are matched in any letter case. Any other value is not replaced by `Normal`. The type is left with no valid class, and its route and reachability checks then give unpredictable results, which can include a crash.
:::
