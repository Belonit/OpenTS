---
key: SmallVisceroid
scope: global-rules
label: Spawned visceroid type
see_also: ["TiberiumDeathToVisceroid", "LargeVisceroid", "system:tiberium"]
when_omitted:
  kind: value
  value: none
---

The named UnitType is the creature that Tiberium deaths leave behind. It belongs to the Neutral house, whoever owned the victim. It appears after either of two deaths, unless the scenario sets [`TiberiumDeathToVisceroid=no`](/keys/tiberiumdeathtovisceroid/):

- an infantryman killed by the Tiberium in its cell ([Damage](/systems/tiberium/#damage) covers that hit);
- any object killed by the damage a gas particle ([`BehavesLike=Gas`](/keys/behaveslike/#scope-particletype)) deals to its cell.

The creature appears in the cell where the death happened. No creature appears in a cell that a vehicle occupies or is moving into.

:::caution[Name a type or turn the deaths off]
If no type is named here, the first qualifying death crashes the game in any scenario that does not set `TiberiumDeathToVisceroid=no`.
:::

```ini title="rules.ini"
[General]
SmallVisceroid=VISC_SML  ; the UnitType the shipped rules name
```

Naming a type here does not make it behave like a visceroid. Merging, wandering and the creature artwork come from [`SmallVisceroid=yes`](/keys/smallvisceroid/#scope-unittype) in that type's own section. Without it, the spawned type is an ordinary vehicle.

The name does not have to match a declared UnitType. A name that matches no type creates a UnitType of that name, which reads its statistics from a section of the same name and stays blank if the rules have none. Only `none` and `<none>` select no type.
