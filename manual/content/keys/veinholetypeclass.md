---
key: VeinholeTypeClass
summary: TerrainType every veinhole monster in the scenario reports as its own.
see_also: ["system:veins", "IsVeinhole", "VeinholeMonsters"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[General]
VeinholeTypeClass=VEINTREE

[VEINTREE]
Name=Veinhole Tree
Image=None
Armor=None
Strength=1000
IsVeinhole=true
```

Every [veinhole monster](/systems/veins/#veinhole-monsters) on the map uses the TerrainType named here. A monster has no type of its own, so this one setting covers all of them. The section does not need to be listed in `[TerrainTypes]`.

The section's settings apply to every monster:

- [`Strength`](/keys/strength/) is the monster's starting and maximum strength.
- [`Armor`](/keys/armor/) and [`Immune`](/keys/immune/) decide what damage does to it.
- [`IsVeinhole=yes`](/keys/isveinhole/) lets players click the monster and makes it a legal target.

The monster is drawn from the theater's `VEINHOLE` shape file, not from the section's `Image`.

:::danger[Name an existing TerrainType]
If `VeinholeTypeClass` is not set, the game crashes when it creates a monster: while it loads a map that holds a veinhole, or while it generates a random map that plants one.

If it names a section the rules do not contain, the type has no strength, and [`TreeStrength`](/keys/treestrength/) does not fill in for it. Every monster then starts below zero strength. An object at zero strength or below takes no damage, so nothing can kill these monsters.
:::
