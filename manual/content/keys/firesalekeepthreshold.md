---
key: FireSaleKeepThreshold
summary: How strong a house must be for a Short Game fire sale to leave one structure standing.
see_also: [FireSaleStructureWeight, BaseUnit, "system:base-attacked"]
when_omitted:
  kind: value
  value: "8"
---

```ini title="rules.ini"
[AI]
FireSaleKeepThreshold=12
FireSaleStructureWeight=2
```

In a Short Game skirmish or multiplayer match, a fire sale leaves one structure standing while the selling house is strong enough to fight on. A Short Game defeats a house once it has no structures and no [`BaseUnit`](/keys/baseunit/) vehicle, so the kept structure lets the house attack with the army it still has. A structure with an [`UndeploysInto`](/keys/undeploysinto/) type counts as a vehicle for that test unless it is a construction yard, so it cannot be the structure kept.

Each fire sale counts the house's forces:

- each vehicle and each infantry unit on the map counts `1`, and aircraft do not count;
- a structure that counts as a vehicle counts `1`;
- every other structure on the map with strength left adds [`FireSaleStructureWeight`](/keys/firesalestructureweight/) until it is being sold. Any crew leaves it as the sale starts and counts as infantry from then on.

When the count is at least `FireSaleKeepThreshold`, the sale keeps the first of the house's structures, in the order they were created, that it would otherwise take down. A structure that counts as a vehicle, one already being sold, one with a planted C4 charge and one with no [`Buildup`](/keys/buildup/) artwork are never the one kept. Below the threshold, the sale sells everything.

A structure with no `Buildup` artwork cannot be sold, except a [`FirestormWall=yes`](/keys/firestormwall/) structure, which is removed. When the house owns such a structure without a planted C4 charge, the house survives the sale anyway, and the sale keeps nothing extra whatever the count.

Fire sales repeat on later AI passes, so the house keeps the same structure until its count drops below the threshold. The next sale then sells that structure too.

The rule applies to every fire sale in the match: the one a computer house orders when it can no longer produce anything, and the endgame state set by the [Fire Sale](/mapping/actions/taction-fire-sale/) trigger action or the fire sale team line. Campaigns and games without Short Game sell every structure. Set `FireSaleKeepThreshold=0`, or any value below it, to sell every structure in a Short Game as well.
