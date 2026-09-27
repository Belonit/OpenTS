---
key: OmniHealer
summary: Lets a healing weapon mend infantry and vehicles alike.
see_also: ["Mechanic", "Damage", "AmbientDamage", "Passengers", "Verses", "system:repair", "system:target-selection", "system:warheads"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MEDIC] ; an InfantryType registered in [InfantryTypes]
OmniHealer=yes
```

`OmniHealer=yes` lets a healer mend both infantry and vehicles. A healer is an object whose weapon [`Damage`](/keys/damage/#scope-weapontype) plus [`AmbientDamage`](/keys/ambientdamage/) averages below zero across its weapon slots. On any other object the key does nothing.

[`Mechanic=yes`](/keys/mechanic/) switches an infantry healer from infantry to vehicles. This key keeps infantry and adds the vehicles, landed aircraft and deployed buildings that `Mechanic` covers. Setting both has the same effect as setting `OmniHealer` alone.

The healer shows the heal cursor over a damaged allied infantry and the repair cursor over a damaged allied vehicle. Its [automatic target search](/systems/target-selection/) looks for both.

Infantry and vehicle healers use the key. For a healing vehicle it is the only way to heal infantry.
