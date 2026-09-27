---
title: Object and type system
summary: Where runtime state, shared type data, engine IDs, factories, and INI reads belong.
category: architecture
source_files:
  - code/abstract.h
  - code/abstract.cpp
  - code/abstype.h
  - code/abstype.cpp
  - code/object.h
  - code/object.cpp
  - code/objtype.h
  - code/objtype.cpp
  - code/mission.h
  - code/radio.h
  - code/techno.h
  - code/foot.h
  - code/aircraft.h
  - code/techtype.h
  - code/techtype.cpp
---

`AbstractClass` is the common base for persistent engine entities. Map objects and INI-backed type definitions are separate branches below it. A runtime instance stores state for one object in the current match; a type definition stores data shared by every instance with the same INI identifier.

This page covers simulation objects and their definitions. UI controls, file classes, and locomotors use other hierarchies.

## Terms

| Term | Meaning in this manual |
| --- | --- |
| Runtime instance | One object or state record created for the current match, such as a `UnitClass` or `HouseClass`. |
| Type definition | Shared configuration loaded once for an INI identifier, such as a `UnitTypeClass`. |
| ObjectType ID | The identifier a definition's `Name()` returns, stored in `IniName`. A map-object definition uses it as its INI section name. Other definitions use it as a section name, as weapons and warheads do, or as an entry key in a registry section, as tags and triggers do. |
| RTTI | The engine's `RTTIType` value. It is separate from C++ RTTI. |
| Heap ID | The index `Fetch_Heap_ID()` returns for a class stored in a family-specific heap. |

`IsActive`, `IsInLimbo`, and `Strength` are independent runtime fields. Calling something a runtime instance says nothing about their values.

## Primary runtime hierarchy

The tree shows each class's primary base path. Bases in parentheses are additional C++ bases outside that path.

```text title="Primary runtime inheritance"
AbstractClass
+- ObjectClass
   +- MissionClass
   |  +- RadioClass
   |     +- TechnoClass (+ FlasherClass, StageClass)
   |        +- BuildingClass
   |        +- FootClass
   |           +- AircraftClass (+ IFlyControl)
   |           +- InfantryClass
   |           +- UnitClass
   +- AnimClass (+ StageClass)
   +- BulletClass
   +- BuildingLightClass
   +- IsometricTileClass
   +- OverlayClass
   +- ParticleClass
   +- ParticleSystemClass
   +- SmudgeClass
   +- TerrainClass (+ StageClass)
   +- VeinholeMonsterClass
   +- VoxelAnimClass (+ BounceClass)
   +- WaveClass
```

`ObjectClass` supplies map position, strength, limbo and active state, cell links, tags, render-layer membership, and the `Class_Of()` interface. `MissionClass` adds mission state. `RadioClass` adds radio contact, in which one object sends another a message and receives the answer at once. `TechnoClass` adds ownership, combat, targeting, cargo, and production state. `FootClass` is the base for mobile technos: aircraft, infantry, and vehicles.

The additional bases add narrow behavior. For example, `StageClass` supplies staged animation, and `IFlyControl` is the aircraft flight-control interface. Check them before assuming a class lacks a contract: every techno is also a `FlasherClass` and a `StageClass`.

Other persistent state derives from `AbstractClass` without being a map object or a type definition. Important families include `HouseClass`, `TeamClass`, `TagClass`, `TriggerClass`, `TActionClass`, `TEventClass`, `ScriptClass`, `FactoryClass`, `CellClass`, and `SuperClass`.

## Type-definition hierarchy

`AbstractTypeClass` also derives from `AbstractClass`, so type definitions share the engine identity and persistence interfaces of runtime state. They do not derive from `ObjectClass`.

```text title="INI-backed type definitions"
AbstractClass
+- AbstractTypeClass
   +- ObjectTypeClass
   |  +- TechnoTypeClass
   |  |  +- AircraftTypeClass
   |  |  +- BuildingTypeClass
   |  |  +- InfantryTypeClass
   |  |  +- UnitTypeClass
   |  +- AnimTypeClass
   |  +- BulletTypeClass
   |  +- IsometricTileTypeClass
   |  +- OverlayTypeClass
   |  +- ParticleSystemTypeClass
   |  +- ParticleTypeClass
   |  +- SmudgeTypeClass
   |  +- TerrainTypeClass
   |  +- VoxelAnimTypeClass
   +- AITriggerTypeClass
   +- CampaignClass
   +- HouseTypeClass
   +- ScriptTypeClass
   +- SideClass
   +- SuperWeaponTypeClass
   +- TagTypeClass
   +- TaskForceClass
   +- TeamTypeClass
   +- TiberiumClass
   +- TriggerTypeClass
   +- WarheadTypeClass
   +- WeaponTypeClass
```

`AbstractTypeClass` owns the INI identifier (`IniName`), the display name (`GivenName`, read from `Name=`), and the common `Read_INI`/`Write_INI` contract. `ObjectTypeClass` adds properties shared by map-object definitions, including artwork identifiers, strength, armor, footprint behavior, and object factories. `TechnoTypeClass` adds data shared by owned combat actors, including weapons, movement, production, targeting, and veterancy.

Derive a new definition family from `ObjectTypeClass` only if it describes a map object. Weapons, warheads, teams, triggers, and campaigns have INI sections but derive directly from `AbstractTypeClass`.

## Identity, heaps, and lookup

`AbstractClass` exposes four identifiers, and they are not interchangeable:

| Interface | Purpose |
| --- | --- |
| `What_Am_I()` / `Fetch_RTTI()` | Returns the concrete class's `RTTIType`. `Fetch_RTTI()` is pure virtual and intermediate classes such as `ObjectClass` and `TechnoClass` do not override it, so only a concrete class has an RTTI value. There is no `RTTI_NONE` default. |
| `Fetch_ID()` | Returns the object's unique number. A class whose constructor assigns one takes it from the scenario's running counter, or zero if no scenario exists yet. Other classes, such as `TeamClass`, `TriggerClass` and `TeamTypeClass`, keep -1. The number is saved with the object, and target tracking and the sync CRC use it. |
| `Fetch_Heap_ID()` | Returns the object's index in its family-specific heap when the concrete class overrides it. The base implementation returns zero. |
| `Class_ID()` | Returns the concrete class's 16-byte `ClassID`. Save records hold it, so it names a class, never one of its objects. The `Locomotor` key uses the same 16-byte form to name a locomotor class. |

An RTTI value selects a class family, a heap ID selects one entry in that family's heap, and an ObjectType ID is the textual INI name.

Most map objects built from an INI definition return it from `Class_Of()`, and technos also return it from `Techno_Type_Class()`. `Class_Of()` is virtual, and some classes answer differently: `BuildingLightClass` and `WaveClass` return null, and `VeinholeMonsterClass` returns the one veinhole definition the rules name.

Two interfaces look up a definition, and two create an object from one:

| Direction | Interface |
| --- | --- |
| Runtime instance to shared definition | `Class_Of()`, or `Techno_Type_Class()` for a techno |
| Textual ID to object definition | `ObjectTypeClass::From_Name()` and family-specific lookup |
| Definition to unplaced instance | `Create_One_Of(HouseClass*)` |
| Definition to placed instance | `Create_And_Place(Cell, HouseClass*)` |

The two creation interfaces are virtual, and some families refuse. Animation, bullet, particle, particle-system, and voxel-animation definitions return false from `Create_And_Place()` and null from `Create_One_Of()`. `AircraftTypeClass::Create_And_Place()` also returns false, although its `Create_One_Of()` creates an aircraft. Check the return value.

`ObjectTypeClass::ObjectTypes` is the cross-family registry of object definitions. Each concrete family also has its own heap and typed lookup functions. Code that already knows the family should use the typed lookup instead of scanning the cross-family registry.

## INI read order

A definition reads a base class's keys only if its reader calls the base reader; inheritance alone does not. Each base reader in the chain runs first, and it reads nothing unless the definition's section is present, so a missing section leaves the whole chain unread. A `UnitTypeClass` read runs `AbstractTypeClass::Read_INI`, then `ObjectTypeClass::Read_INI`, then `TechnoTypeClass::Read_INI`, and then reads the unit-specific keys.

Some families never reach `AbstractTypeClass::Read_INI`, so they do not read `Name=`:

- `AITriggerTypeClass`, `SideClass`, `TagTypeClass`, `TriggerTypeClass`, `WarheadTypeClass`, and `WeaponTypeClass` read their data without calling it.
- `IsometricTileTypeClass` definitions are built from the theater's control file, and no `Read_INI` runs for them.

Trace the concrete reader before treating a base-class key as inherited.

The reader that reads a key decides which definitions accept it:

- A key in `AbstractTypeClass::Read_INI` applies to every definition whose reader reaches it.
- A key in `ObjectTypeClass::Read_INI` applies only to map-object definitions.
- A key in `TechnoTypeClass::Read_INI` applies only to aircraft, structures, infantry, and vehicles.
- A key in a concrete reader applies only to that family, unless another reader reads the same spelling on its own.

A derived reader may reinterpret or overwrite a field after its base reader has run. The reader that reads a key tells you where it enters the hierarchy, not that it behaves the same in every family below.

## Where new state belongs

Put a new field in the narrowest class that all of its users share. A field placed higher is saved with every class below it and, if it has a key, is read for every family whose reader reaches it. A field placed lower has to be repeated, along with its reader code, in each sibling class.

| Requirement | Placement | Example |
| --- | --- | --- |
| Changes independently for every object during a match | The narrowest runtime class that owns the behavior | Remaining ammo, `Ammo` on `TechnoClass` |
| Shared by every object with one INI identifier | The corresponding concrete `TypeClass` | `CrateGoodie=` on `UnitTypeClass` |
| Shared by several map-object definition families | `ObjectTypeClass` or another common type base | `Image=` on `ObjectTypeClass` |
| Shared only by owned combat definitions | `TechnoTypeClass` | Maximum ammo, `Ammo=` read into `MaxAmmo` on `TechnoTypeClass` |
| Applies to the match rather than an object definition | The owning global or scenario subsystem | A game-wide rule in `RulesClass` |
| References another persistent runtime object | Runtime state plus detach, load swizzling, and CRC review | A non-owning target or contact pointer |
