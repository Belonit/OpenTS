---
enum_id: MZoneType
slug: movement-zone
title: Movement zone
summary: Pathfinding classes, each deciding which terrain and obstacles a type of that class may cross.
representation: token
bindings:
  key_value_types: [mzonetype]
  scripting_parameter_types: []
source_files: [code/mzone.hh, code/ccini.cpp, code/map.cpp, code/cell.cpp]
values:
  - { constant: MZONE_NORMAL, value: 0, input: "Normal", meaning: "Open land only." }
  - { constant: MZONE_CRUSHER, value: 1, input: "Crusher", meaning: "Open land and cells with a crushable overlay." }
  - { constant: MZONE_DESTROYER, value: 2, input: "Destroyer", meaning: "Crusher cells, plus wall cells and cells a terrain object fills completely." }
  - { constant: MZONE_AMPHIBIOUS_DESTROYER, value: 3, input: "AmphibiousDestroyer", meaning: "Destroyer cells, plus water and beach." }
  - { constant: MZONE_AMPHIBIOUS_CRUSHER, value: 4, input: "AmphibiousCrusher", meaning: "Crusher cells, plus water and beach." }
  - { constant: MZONE_AMPHIBIOUS, value: 5, input: "Amphibious", meaning: "Open land, water and beach." }
  - { constant: MZONE_SUBTERANNEAN, value: 6, input: "Subterannean", meaning: "Every cell in the playable area except water, beach and cells a terrain object partly fills.", note: "The accepted token preserves the engine's historical spelling." }
  - { constant: MZONE_INFANTRY, value: 7, input: "Infantry", meaning: "Open land and cells a terrain object partly fills." }
  - { constant: MZONE_INFANTRY_DESTROYER, value: 8, input: "InfantryDestroyer", meaning: "Infantry cells, plus cells with a crushable overlay, wall cells and cells a terrain object fills completely." }
  - { constant: MZONE_FLYER, value: 9, input: "Fly", meaning: "Every cell in the playable area." }
---

A movement zone class decides which cells count as crossable when the engine divides the map into [movement zones](/glossary/#movement-zone) and plans routes. [`MovementZone`](/keys/movementzone/) sets a type's class. The ten classes are fixed by the engine.

Each class accepts some of the cell ratings that [the zone map](/systems/movement-and-terrain/#the-zone-map) describes and refuses the rest. The table above names the cells each class accepts. Open land is the rating for a cell that no other rating covers. [`TemperateOccupationBits`](/keys/temperateoccupationbits/) covers how much of a cell a terrain object fills.

Apart from `Subterannean`, which also makes the type burrow (see [`MovementZone`](/keys/movementzone/)), a class decides only where routes may go. `Destroyer` plans routes through walls and through trees and rocks that fill their cells, but the class breaks through none of them. Whether a vehicle shoots a wall in its way depends on its primary weapon's warhead, as [Walls in combat and movement](/systems/walls-and-gates/#walls-in-combat-and-movement) describes. Whether a vehicle crushes a crushable wall or object it drives onto is set by [`Crusher=yes`](/keys/crusher/), which a type of any class can use.
