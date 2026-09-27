---
key: TiberiumDeathToVisceroid
summary: Whether deaths to Tiberium and gas particles leave a visceroid behind.
see_also: [SmallVisceroid, Visceroids, "system:tiberium"]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="map file"
[Basic]
TiberiumDeathToVisceroid=no
```

With the switch on, two kinds of death leave a visceroid on the cell where they happen:

- infantry killed by the [damage Tiberium deals](/systems/tiberium/#damage) as they move into its cell;
- any object killed by the damage a gas particle ([`BehavesLike=Gas`](/keys/behaveslike/#scope-particletype)) deals to its cell.

The visceroid is the UnitType named by [`SmallVisceroid`](/keys/smallvisceroid/#scope-global-rules), and it belongs to the `Neutral` house. No visceroid appears when a vehicle occupies the cell.

This switch alone decides whether these deaths leave visceroids. The `[SpecialFlags]` entry [`Visceroids`](/keys/visceroids/) has no effect on them. Visceroids placed on the map or created by [`TiberiumWildlife`](/keys/tiberiumwildlife/) do not depend on it.
