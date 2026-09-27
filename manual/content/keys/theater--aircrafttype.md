---
key: Theater
scope: aircrafttype
label: Theater-specific artwork
see_also: ["NewTheater", "Image", "Voxel"]
when_omitted:
  kind: value
  value: "no"
---

The type's shape file takes the extension set by the scenario theater's [`Suffix`](/keys/suffix/#scope-theater) in place of `.SHP`. By default that is `.TEM` in temperate and `.SNO` in snow. The rest of the name is the Image ID, with the exceptions below for a TerrainType, SmudgeType, or BuildingType. There is no fallback to `.SHP`, so a type with no file for the current theater has no shape in that theater.

```ini title="art.ini"
[MYROCK] ; a TerrainType that sets no Image=
Theater=yes ; draws MYROCK.TEM or MYROCK.SNO, never MYROCK.SHP
```

This applies to a BuildingType, OverlayType, SmudgeType, TerrainType, BulletType, and ParticleType. A ParticleSystemType or VoxelAnimType draws no shape, so the flag changes nothing on them.

The file is looked up again for every scenario and every loaded saved game, so its extension always matches the current theater.

A type that also sets [`NewTheater=yes`](/keys/newtheater/) uses this flag and ignores that one.

Leave [`Image=`](/keys/image/) unset on a TerrainType or SmudgeType marked here, or set it to the type's own ObjectType ID. When the scenario's theater differs from the previous scenario's, these two types look up the theater file under their ObjectType ID. When the theater repeats, and after a saved game loads, they use the Image ID, so a different Image ID gives different artwork depending on how the scenario was reached.

A BuildingType loads its theater shape even when it is [`Voxel=yes`](/keys/voxel/). After a saved game loads, the name's second letter is also replaced as [`NewTheater=yes`](/keys/newtheater/) describes. A structure whose Image ID is `GAHUT` therefore draws `GAHUT.TEM` in a temperate scenario, and `GTHUT.TEM` once that game is saved and loaded.

When a scenario starts, a BuildingType marked here also loads its [`Buildup`](/keys/buildup/) file with the theater's extension, unless it sets [`DemandLoadBuildup=yes`](/keys/demandloadbuildup/). The Buildup page covers how that changes the construction animation. After a saved game loads, the structure uses the ordinary construction file and timing described there.

On an AircraftType, InfantryType, or UnitType the flag has no effect when a scenario starts: the type loads its plain `<Image ID>.SHP`. After a saved game loads, though, these types take the theater file when one exists, so an infantry type or a shape-drawn vehicle can change its look on loading. Leave the flag off these types.
