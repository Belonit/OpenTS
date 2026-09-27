---
format_id: map-seed
title: Map seed files
summary: Stores random-map generator inputs in a `[RandomMap]` section.
kind: file
filenames:
  - "*.SED"
key_scopes:
  - file: map seed file
    section:
      kind: literal
      name: RandomMap
source_files:
  - code/mapgen.cpp
  - code/scenario.cpp
---

A map seed file holds the settings of the [random map generator](/systems/map-generation/) and no map data. The game uses these files in two ways:

- The random-map dialog saves its settings as a `.SED` file in the [saved-games folder](/formats/save-games/), and lists and loads the `.SED` files it finds there.
- Scenario loading treats any file whose name ends in `.SED` as a seed file and generates the map from it, using the file's own `Seed`. When the host accepts a random map in the skirmish setup or a multiplayer lobby, the game saves the settings as `RandMap.Sed` and the match plays that file.

`RandMap.Sed` is found through the ordinary game file search, and the dialog does not list it. Any other `.SED` name is read from the saved-games folder.

A scenario file can carry the same section. With [`RandomMap=yes`](/keys/randommap/) in its `[Basic]` section, its map is generated from its `[RandomMap]` section. That key's page says which seed the map uses and which of the file's other settings still apply.

```ini title="MyMap.SED"
[RandomMap]
Description=Four-player temperate map
Width=1
Height=1
NumPlayers=4
Seed=12345
```

## Map size

[`Width`](/keys/width/#scope-random-map-generation) and [`Height`](/keys/height/#scope-random-map-generation) are size indices from `0` through `3`, not cell counts. [`NumPlayers`](/keys/numplayers/#scope-random-map-generation) selects a row of the table below, which gives the smallest and the largest size for that many players:

- Index `0` gives the smallest size and index `3` the largest.
- Indices `1` and `2` give the size one third and two thirds of the way from the smallest to the largest, rounded down.

Width and height use the same table, so equal indices give a square map. `Width=3` is 100 cells for two players and 175 for eight.

| `NumPlayers` | Cells at index `0` | Cells at index `3` |
| --- | --- | --- |
| 2 | 50 | 100 |
| 3 | 65 | 115 |
| 4 | 75 | 128 |
| 5 | 85 | 140 |
| 6 | 100 | 160 |
| 7 | 120 | 170 |
| 8 | 135 | 175 |

These sizes are the playable area, which the generated map declares in `[Map] LocalSize=`. The playfield, declared in `[Map] Size=`, is four cells wider and twelve cells taller. The example above builds a 92 by 92 playable area on a 96 by 104 playfield.

## Missing and out-of-range settings

Before a map is built, a setting the section leaves out takes its default, and a value outside a setting's range is moved to the nearest end of that range. `NumPlayers=9`, for example, builds an eight-player map. This applies whether the file is loaded into the random-map dialog or played as a scenario. Each setting's key page gives its default and range.

The Firestorm expansion also changes some settings at that point. Without Firestorm enabled, the mutated biome becomes temperate, and `TiberiumWildlife`, `VeinholeMonsters`, `UseIonStorms`, `UseTransitions` and `UseBlueTiberium` are turned off. With Firestorm enabled, `UseBlueTiberium` is always turned on.
