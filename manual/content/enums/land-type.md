---
enum_id: LandType
slug: land-type
title: Land type
summary: Terrain classes used by movement, pathfinding, and terrain restrictions.
representation: token
bindings:
  key_value_types: [landtype]
  scripting_parameter_types: []
source_files: [code/land.hh, code/const.cpp, code/cell.cpp, code/isotype.cpp]
values:
  - { constant: LAND_CLEAR, value: 0, input: "Clear", meaning: "Clear ground." }
  - { constant: LAND_ROAD, value: 1, input: "Road", meaning: "Road surface." }
  - { constant: LAND_WATER, value: 2, input: "Water", meaning: "Open water." }
  - { constant: LAND_ROCK, value: 3, input: "Rock", meaning: "Rock, including cells that `CliffBackImpassability` converts." }
  - { constant: LAND_WALL, value: 4, input: "Wall", meaning: "Wall terrain." }
  - { constant: LAND_TIBERIUM, value: 5, input: "Tiberium", meaning: "Tiberium field." }
  - { constant: LAND_BEACH, value: 6, input: "Beach", meaning: "Beach terrain." }
  - { constant: LAND_ROUGH, value: 7, input: "Rough", meaning: "Rough ground." }
  - { constant: LAND_ICE, value: 8, input: "Ice", meaning: "Solid ice." }
  - { constant: LAND_RAILROAD, value: 9, input: "Railroad", meaning: "Rail track terrain." }
  - { constant: LAND_TUNNEL, value: 10, input: "Tunnel", meaning: "Tunnel terrain." }
  - { constant: LAND_WEEDS, value: 11, input: "Weeds", meaning: "Vein weed terrain." }
---

A cell's land type comes from the tile beneath it, unless an overlay on the cell sets one. [`Land`](/keys/land/) covers which of the two the cell reports. Tiles produce nine of the twelve land types; `Wall`, `Tiberium` and `Weeds` come only from overlays.

[`CliffBackImpassability=2`](/keys/cliffbackimpassability/) can then change a cell that lies a cliff step or more below a nearby cell to `Rock`. A cell whose overlay has `Land=Wall`, `Land=Railroad` or [`NoUseTileLandType=yes`](/keys/nousetilelandtype/) becomes `Rock` whatever its land type is. Any other cell becomes `Rock` only if its land type is `Clear`, `Water`, `Beach` or `Ice`, so a `Road`, `Rough` or `Railroad` tile keeps its land type, and so does a `Tiberium` cell.

Each land type has a `rules.ini` section of the same name, such as `[Clear]` or `[Railroad]`. The section holds the movement cost for each [speed type](/reference/enums/speed-type/) and the [`Buildable`](/keys/buildable/) flag, as [the terrain table](/systems/movement-and-terrain/#the-terrain-table) describes. The twelve land types are fixed by the engine. A mod can change the values in a section but cannot add a land type.
