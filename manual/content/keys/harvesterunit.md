---
key: HarvesterUnit
summary: UnitTypes the engine treats as a house's harvesters when it counts or replaces them.
see_also: ["system:tiberium", "Harvester"]
when_omitted:
  kind: value
  value: "none"
---

```ini title="rules.ini"
[General]
HarvesterUnit=HARV
```

The value is a comma-separated list of UnitType IDs. The list does not make a type harvest: [`Harvester=yes`](/keys/harvester/#scope-unittype) does that, and a harvesting type left off the list still harvests. The list decides which vehicles the engine counts, protects and replaces as harvesters.

Every listed type counts as a harvester in these places:

- A computer house whose IQ reaches the [`Harvester`](/keys/harvester/#scope-global-rules) level queues a replacement harvester when it owns too few listed harvesters for its refineries. That page lists the other conditions.
- A computer house judges whether it can still earn money partly from whether it owns a listed harvester.
- While a computer house has a listed type on order, some production modes hold back its infantry and aircraft, as described under [`AIAlternateProductionCreditCutoff`](/keys/aialternateproductioncreditcutoff/).
- In skirmish and multiplayer games, the number of listed harvesters a house owns weights a computer house's [search for a Tiberium patch](/systems/tiberium/#finding-a-patch).
- A unit crate gives a free harvester to a house that owns a refinery and no listed harvester.

When the engine must price, queue or hand out one harvester, it takes the first entry that the country the house [acts as](/keys/actslike/) may own. When that country may own none of them, it takes the first entry.

The [harvester truce](/keys/harvesterimmune/) protects exactly the listed types, and also leaves them out of the multiplayer defeat test. Its page lists what the truce protects them from.

A listed vehicle recovering from an EMP stun goes back to harvesting unless it was unloading. This happens with or without the truce.

With an empty list, a computer house always judges that it can still earn, so it never sells its base to buy a harvester it cannot name.
