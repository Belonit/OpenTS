---
format_id: capture-ini
title: Map capture description
summary: Names the map a -CAPTURE run draws to a PNG picture, and the settings the picture is drawn with.
kind: file
source_files:
- code/mapcapture.cpp
- code/headless.cpp
filenames:
- '*.INI'
related:
- type: format
  id: ini-syntax
- type: format
  id: spawn-ini
- type: command
  id: launch:capture
- type: command
  id: launch:capture-map
---

A map capture description is an INI file that [`-CAPTURE=<file>`](/using/command-line/capture) reads. The capture it describes loads one map, draws one picture of it with no interface, and writes the picture as a PNG file. The game shows no window, console or dialog during the run and exits once the capture is done. [`-CAPTUREMAP=`](/using/command-line/capture-map) with [`-CAPTUREOUT=`](/using/command-line/capture-output) makes the same capture with the default settings and no file.

The keys below belong in the `[Capture]` section.

```ini title="sunstroke.ini"
[Capture]
Map=Maps\Fan-made\sunstroke.map
Output=previews\sunstroke.png
Shroud=None
Frames=30
```

## Keys

| Key | Values | Default | Meaning |
| --- | --- | --- | --- |
| `Map` | a path | — | The map to draw. It is found the way the game finds a scenario: in the game's data folders, or at a full path. |
| `Output` | a path | — | The PNG file to write, replacing any file already there. A relative path is taken from the description file's folder. The folder must exist. |
| `Shroud` | `None`, `Player` | `None` | `None` reveals the whole map and draws no fog. `Player` draws the shroud the `[Settings]` seat sees once the frames have run; see [Seats](#seats). |
| `Seats` | `Observer`, `Listed` | `Observer` | Who is seated on a multiplayer map; see [Seats](#seats). |
| `Area` | `Local`, `Full` | `Local` | `Local` draws the map's [`LocalSize`](/keys/localsize/) area after the game trims it. `Full` draws the area `LocalSize` covers when a map leaves it out: the whole playfield, trimmed the same way. |
| `Frames` | `0` or more | `0` | The game frames to run after the load and before drawing. Objects can move, ore can grow and triggers can fire during them, so `0` draws the scenario exactly as it loads. |

`Map` and `Output` are required. Values are not case-sensitive. A missing `Map` or `Output`, a value other than the ones listed, or a negative `Frames` stops the run before the map is loaded.

## What a capture draws

The picture is 48 pixels wide for each column of the area and 24 pixels high for each row, plus 108. A `LocalSize` area of 111 by 75 cells gives a picture of 5328 by 1908 pixels.

A capture draws the map with its own lighting and with no sidebar, cursor, messages or other interface. Firestorm is enabled when it is installed, except that listed seats follow their own `Firestorm` setting. The random number seed is fixed, so the same description draws the same picture each time.

A map plays as a campaign mission when `[Basic]` `MultiplayerOnly` is not set and `[Basic]` `Player` names a house in its `[Houses]` section other than Neutral or Special. A campaign mission keeps every house it lists and every object they own, whatever `Seats` says.

## Seats

`Seats` decides who plays a multiplayer map.

- `Observer` seats a single observer. Only Neutral and Special objects stay on the map. No starting units, base or crates are placed, and objects owned by a country or a spawn house are left out. `Shroud=Player` cannot be used with it on a multiplayer map.
- `Listed` seats the houses the description file lists, in the [client launch file](/formats/spawn-ini/#who-is-playing) format: `[Settings]` and `[Other1]` to `[Other7]` for people, and computer players through `AIPlayers`, `HouseCountries` and `HouseColors`. These `[Settings]` options also apply: `Bases`, `Credits`, `Crates`, `UnitCount`, `AIPlayers`, `AIDifficulty`, `FogOfWar`, `TechLevel`, `Firestorm` and `Seed`. The starting units and bases they ask for are placed as when a match starts. A seating the launch file would [refuse](/formats/spawn-ini/#when-something-is-wrong) fails the capture.

The picture is drawn for the `[Settings]` seat. With `Shroud=Player`, that seat must not be a spectator, and the picture shows the ground its starting units and base have revealed. On a campaign mission, `Shroud=Player` shows what the mission's player house has revealed.

## Results

The game exits with code 0 once the picture is written and with code 1 otherwise. The capture fails when the description is invalid, the map is missing or does not load, the seats cannot be played, `Shroud=Player` has no playing seat, or the picture cannot be drawn or written. The reason goes to the debug log and to the console the game was started from. A crash ends the run with code 1 and leaves a crash report.
