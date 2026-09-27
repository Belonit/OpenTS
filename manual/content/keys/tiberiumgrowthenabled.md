---
key: TiberiumGrowthEnabled
summary: Allows Tiberium to ripen and spread during a scenario.
see_also: ["system:tiberium", "TiberiumSpreads", "TiberiumGrows"]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="map file"
[Basic]
TiberiumGrowthEnabled=no
```

With the switch off, no Tiberium type [grows or spreads](/systems/tiberium/#growth). No cell gains a stage by growing, and existing patches seed no new cells.

Blossom trees and other sources that place Tiberium still plant it on cells that hold none. With the switch off they cannot add stages to an existing patch.

The [Tiberium growth](/mapping/actions/taction-tib-growth/) trigger action writes the same switch while the scenario is running.
