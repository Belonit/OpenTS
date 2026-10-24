---
format_id: stats-dmp
title: Match statistics file
summary: Records the result of a game against other machines in `stats.dmp` for a ladder client to upload.
kind: binary
source_files:
- code/stats.cpp
- code/packet.cpp
- code/field.cpp
- code/queue.cpp
- code/mainloop.cpp
- code/utracker.cpp
- code/spawner.cpp
extensions:
- .DMP
role: persistence
---

A game against other machines started with [`WriteStatistics=yes`](/formats/spawn-ini/#the-match-results-file) in `SPAWN.INI` writes `stats.dmp` when the match is decided. The CnCNet quick-match client uploads the file to the ladder after the game exits. Without that key, and in a skirmish or campaign mission, no file is written.

## When and where

The game writes the file once per match, at the first of these:

- the local player wins or is defeated;
- a player quits, is dropped or is removed, and one team is left;
- the game goes out of sync, or loses its connection to the other machines;
- the local player leaves before the match is decided.

The file goes beside the game's executable, or into the folder [`-USERDIR=`](/using/command-line/user-directory/) names. It replaces any `stats.dmp` already there. An [observer's](/systems/observers/) machine writes no file.

The counts and the match time carry over through a saved game, so a match resumed from a save, or loaded during play, reports the whole match.

## Layout

The file is the Westwood Online results packet. All numbers are big-endian.

| Offset | Size | Contents |
| --- | --- | --- |
| 0 | 2 | Total size of the file in bytes, header included |
| 2 | 2 | Packet ID, always `0` |
| 4 | | Fields, one after another, to the end of the file |

Each field is an 8-byte header followed by its data and then zero bytes up to the next multiple of four:

| Offset | Size | Contents |
| --- | --- | --- |
| 0 | 4 | Tag, four ASCII characters |
| 4 | 2 | Type |
| 6 | 2 | Data length in bytes, without the padding |
| 8 | length | Data |

| Type | Data |
| --- | --- |
| `1` | One signed byte |
| `2` | One unsigned byte, used for yes or no |
| `5` | A signed 32-bit number |
| `6` | An unsigned 32-bit number |
| `7` | Text, ending with a zero byte that the length counts |
| `20` | A list of unsigned 32-bit counts |

The total size is a 16-bit number, so a match whose fields would pass 65,535 bytes writes no file.

## Match fields

| Tag | Type | Contents |
| --- | --- | --- |
| `IDNO` | 6 | `GameID` from `SPAWN.INI` |
| `SCEN` | 7 | `UIMapName` from `SPAWN.INI`, or the scenario's own name when that key is empty |
| `HASH` | 7 | `MapHash` from `SPAWN.INI`; left out when that key is empty |
| `DURA` | 6 | How long the match ran, in units of 0.96 seconds |
| `AFPS` | 6 | Game frames per `DURA` unit |
| `FINI` | 2 | Whether the game counted the match as finished when it wrote the file |
| `OOSY` | 2 | Whether the game went out of sync or lost its connection |
| `PLRS` | 6 | The number of players in the file |
| `SPID` | 6 | The local player's index in the file |
| `CRED` | 6 | Starting credits |
| `UNIT` | 6 | Starting unit count |
| `TECH` | 6 | Tech level |
| `AIPL` | 6 | Number of computer players |
| `BASE` | 2 | `Bases` |
| `CRAT` | 2 | `Crates` |
| `TIBR` | 2 | `BridgeDestroy`, despite the tag |
| `SHAD` | 2 | Whether the shroud grows back |
| `FLAG` | 2 | Whether the match is capture the flag |
| `SPED` | 1 | Game speed |
| `VERS` | 7 | The game version, after a `V` |
| `DATE` | 20 | The executable's modification time, each 32-bit half big-endian with the low half first |
| `PROC` | 1 | A processor class |
| `MEMO` | 5 | Installed memory in bytes |
| `GSKU`, `TRNY`, `TIME`, `PNGS`, `PNGR` | 6 or 5 | Always `0` |

## Player fields

The file lists each person in the match, defeated or not. Observers, computer players and a player whose base the computer took over are left out. The players are sorted by name, ignoring case, and numbered from `0`. Each player field ends with the player's number as a digit, so `NAM0` is the first player's name.

| Tag | Type | Contents |
| --- | --- | --- |
| `NAM` | 7 | The player's `Name` from `SPAWN.INI`, even under `QuickMatch` |
| `CMP` | 6 | How the match ended for the player; see below |
| `LCN` | 2 | Whether the player lost their connection without resigning |
| `SID` | 6 | The player's country |
| `COL` | 6 | The player's color scheme |
| `TID` | 6 | The player's number again |
| `BSP` | 5 | The start position the player began at, or `-1` |
| `CRD` | 5 | Credits at the end |
| `IPA` | 6 | The network address the game holds for the player's machine; `0` through a tunnel |
| `CID` | 6 | Always `0` |
| `HRV` | 6 | Always `0` |

`CMP` is a set of bits:

| Value | When |
| --- | --- |
| `8` | The game had not counted the match as finished; every player gets this value |
| `2` | The player lost their connection |
| `528` | The player quit or resigned (`512` and `16`) |
| `512` | The player was defeated |
| `256` | None of the above: the player won |

The first row that applies is used.

The count fields are lists of counts, one for each type in the order the game created its types, and stop after the last count that is not zero. An empty list means none.

| Tag | Counts |
| --- | --- |
| `INB`, `UNB`, `PLB`, `BLB` | Infantry, vehicles, aircraft and buildings the player gained, including their starting forces and anything captured |
| `INL`, `UNL`, `PLL`, `BLL` | Infantry, vehicles, aircraft and buildings the player had at the end; civilian infantry is not counted |
| `INK`, `UNK`, `PLK`, `BLK` | Infantry, vehicles, aircraft and buildings the player destroyed |
| `BLC` | Buildings the player captured |
| `CRA` | Crates the player picked up, by crate kind |
