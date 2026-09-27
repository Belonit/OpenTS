---
key: VeinGrowthEnabled
summary: Allows veinhole monsters to spread their fields during a scenario.
see_also: ["system:veins", "MaxVeinholeGrowth", "VeinholeGrowthRate"]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="map file"
[Basic]
VeinGrowthEnabled=no
```

With the switch off, no veinhole monster takes a [growth step](/systems/veins/#growth). Its field gains no cells, and cells that harvesting left thin do not grow back.

The rest of the vein system carries on. Fields already on the map still attack what stands in them and can still be harvested. A destroyed monster's field still withers.

The [Vein growth](/mapping/actions/taction-vein-growth/) trigger action writes the same switch while the scenario is running.
