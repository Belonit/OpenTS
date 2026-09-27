---
format_id: scenario-objects
title: Scenario object records
summary: Defines the vehicles, infantry, aircraft, structures, and trigger ownership loaded with a scenario.
kind: file
source_files:
- code/unit.cpp
- code/infantry.cpp
- code/aircraft.cpp
- code/building.cpp
- code/trigtype.cpp
- code/tagtype.cpp
- code/house.cpp
- code/scenario.cpp
filenames:
- "<scenario>.INI"
- "*.MAP"
- "*.MPR"
related:
- type: format
  id: ini-syntax
- type: system
  id: starting-forces
- type: key
  id: House
- type: key
  id: Allies
- type: key
  id: NodeCount
- type: key
  id: UseMPAIBaseNodes
---

Scenario INI files store placed objects as comma-separated rows in `[Units]`, `[Infantry]`, `[Aircraft]`, and `[Structures]`. Every row begins with the owner, the ObjectType ID, and the strength, where `256` is undamaged. The location comes next: X and Y fields when [`NewINIFormat`](/keys/newiniformat/) is 4 or higher, or a single cell number, Y × 128 + X, in older layouts. The fields after the location differ by section, and a `[Structures]` row has no mission field.

The loader reads rows in section order and ignores their keys. Still give each row a distinct key: a repeated key replaces the earlier row and moves it to the end of the section, as [INI syntax](/formats/ini-syntax/#repeats-and-later-files) describes.

In a campaign, every vehicle, infantry, and aircraft starts the mission its row names. Outside a campaign, only objects owned by a human player start their mission, and the rest start idle.

## Runtime owners

An object row creates an object only when its owner names a house playing in the current game. The owner can be written two ways:

- A country, by its ID or its [`Name=`](/keys/name/) string. It names the first house in the game that plays that country. A country that the rules define but nobody plays in this game names no house.
- A [spawn house](#spawn-houses), which names the house that starts at that position.

A row is skipped when its owner names no house or its ObjectType ID names no type of that section's kind. Nothing is created and the rest of the row is not read. An object that is created but cannot be placed at its location is deleted.

`[Triggers]` definitions follow the same owner rule. They also accept the owner `<none>`, which names the house playing the first country the rules register. A definition whose owner names no house is deleted.

A trigger can link to a definition that appears later in `[Triggers]`. A link to a definition that is missing or was deleted stays empty. A `[Tags]` row that names such a definition has no trigger and never fires.

## Spawn houses

A spawn house names whoever starts at one of the eight numbered start positions, waypoints `0` through `7`. It is written `Spawn1` through `Spawn8` or `<Player @ A>` through `<Player @ H>`, so `Spawn1` and `<Player @ A>` both name waypoint `0`. Case does not matter, but the spelling must be exact: `Spawn 1` and `Spawn9` are read as country names. Spawn house names are checked before country names, so a country called `Spawn1` cannot be named that way.

In a skirmish or multiplayer game, start positions are assigned as the scenario loads, before any team, trigger, or object row is read. A spawn house in any of those rows therefore names the house that starts at that position. [Starting forces](/systems/starting-forces/#the-start-position) explains how positions are assigned. An observer, or a house whose country sets [`MultiplayPassive`](/keys/multiplaypassive/), never holds a position, and no house holds one in a campaign.

A spawn house that nobody holds, such as `Spawn3` in a two-player game, names no house. Object rows it owns are skipped, and `[Triggers]` definitions it owns are deleted. A TeamType whose [`House=`](/keys/house/) names it creates no team through a trigger action. The [AI trigger pass](/systems/ai-team-production/#from-suggestion-to-team) can still raise that team, and the team then belongs to the house running the pass.

A scenario can add a section named after a spawn house, `[Spawn1]` through `[Spawn8]`, to configure the house that holds that position. The section is ignored when nobody holds the position. It can set [`Allies=`](/keys/allies/). When the map sets [`UseMPAIBaseNodes=yes`](/keys/usempaibasenodes/), it can also set the base nodes: [`NodeCount`](/keys/nodecount/) and its numbered entries.

Trigger events, trigger actions, and team script missions that take a house by number read `50` through `57`, and `4475` through `4482`, as `Spawn1` through `Spawn8`. Any other number selects the country with that index, so `58` through `60` have no special meaning.

A house number can name no house, because nobody holds the position or nobody plays the country. What happens then depends on the entry. Some events are never satisfied and others are always satisfied. Most actions and missions do nothing, but [Winner is...](/mapping/actions/taction-win/) makes the player lose and [Loser is...](/mapping/actions/taction-lose/) makes the player win. Each entry's page states its case.

## Vehicle follower IDs

The follower field comes after the on-bridge flag in a `[Units]` row. It holds the zero-based position, within `[Units]`, of the row whose vehicle follows this one, or `-1` for none. Positions count every row in section order, including rows that were skipped or could not be placed, so a rejected row does not shift the positions after it. The follower can be an earlier or a later row.

No link is made when the position is negative, past the end of the section, or names a row whose vehicle was not created or could not be placed.
