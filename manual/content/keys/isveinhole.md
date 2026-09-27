---
key: IsVeinhole
summary: Lets a click pick a veinhole monster built from the TerrainType, and makes the monster a legal target.
see_also: ["system:veins", "VeinholeTypeClass"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[VEINTREE] ; the TerrainType named by [General] VeinholeTypeClass
Name=Veinhole Tree
Strength=1000
IsVeinhole=true
```

Set the flag on the TerrainType that [`VeinholeTypeClass`](/keys/veinholetypeclass/) names. A click over a [veinhole monster](/systems/veins/#veinhole-monsters) then picks the monster. Without the flag, the click passes over it.

The flag also makes the type a legal target, even when its section sets [`LegalTarget=no`](/keys/legaltarget/).

Terrain objects of an `IsVeinhole=yes` type get no per-frame update. An ordinary terrain object of such a type placed on a map never animates, seeds Tiberium or spreads fire.

The flag does not choose which type monsters are built from. `VeinholeTypeClass` does that, whether or not the type it names sets this flag.
