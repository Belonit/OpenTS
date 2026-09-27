---
key: Power
scope: buildingtype
label: Power output and drain
when_omitted:
  kind: value
  value: "0"
---

A positive value is the power the type supplies to its house. A negative value is a drain of that size, and the type then supplies nothing. One type cannot both supply and drain; no separate key sets drain.

```ini title="rules.ini"
[MYPOWR]  ; example power plant BuildingType
Power=100

[MYRADAR] ; example radar BuildingType that consumes 40
Power=-40
```

A plug adds its value to the structure it is installed in, so a turbine's output and a plug's drain both reach the house through their host. [The power balance](/systems/power/#how-the-balance-is-computed) covers how output and drain are totaled, and [what low power costs](/systems/power/#what-low-power-costs) covers what a shortfall does to the base.

A selected structure whose type has a positive value shows its owner's current total output and drain. The readout appears for the local player's own and allied structures, for a structure the local player has infiltrated with a spy, and for every such structure when the local player is an observer.
