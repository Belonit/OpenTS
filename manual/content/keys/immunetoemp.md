---
key: ImmuneToEMP
summary: Stops an EM pulse from stunning, powering off, downing or destroying objects of this type.
see_also: ["system:emp-pulse", "IsCoreDefender", "EMEffect", "Cyborg"]
when_omitted:
  kind: context-dependent
  note: A BuildingType or UnitType uses its `IsCoreDefender=` value. Every other type uses `no`.
---

```ini title="rules.ini"
[MYTANK]         ; a UnitType registered in [VehicleTypes]
ImmuneToEMP=yes
```

With `ImmuneToEMP=yes`, an [EM pulse](/systems/emp-pulse/) from any source, including an [`EMEffect=yes`](/keys/emeffect/) warhead, has no effect on objects of this type:

- a vehicle, cyborg, burrowing object or aircraft on the ground is not stunned;
- an aircraft taking off or landing does not crash;
- a structure is not powered off or stunned;
- a limpet mine is not destroyed.

An immune object still springs its [Paralyzed](/mapping/events/tevent-paralyzed/) trigger event when [a pulse reaches it](/systems/emp-pulse/#what-a-pulse-reaches).

The key changes nothing for objects that a pulse never affects, such as infantry other than [cyborgs](/keys/cyborg/) and aircraft one height level or more above the ground.

To make an [`IsCoreDefender=yes`](/keys/iscoredefender/) type vulnerable, set `ImmuneToEMP=no`.
