---
enum_id: MissionType
slug: mission
title: Mission
summary: Runtime mission state machines assignable through mission-valued scripting payloads.
representation: integer
bindings:
  key_value_types: []
  scripting_parameter_types: [mission]
source_files: [code/mission.hh, code/_mission.cpp]
values:
  - { constant: MISSION_SLEEP, value: 0, input: "0", meaning: "Do nothing. An aircraft in the air switches to Guard at once." }
  - { constant: MISSION_ATTACK, value: 1, input: "1", meaning: "Attack the object's current target. An object with no target switches to its idle mission." }
  - { constant: MISSION_MOVE, value: 2, input: "2", meaning: "Move toward the assigned destination." }
  - { constant: MISSION_QMOVE, value: 3, input: "3", meaning: "Rewritten to Move before the mission is queued." }
  - { constant: MISSION_RETREAT, value: 4, input: "4", meaning: "Head for a map edge, preferring the edge the object's team came from." }
  - { constant: MISSION_GUARD, value: 5, input: "5", meaning: "Hold position and guard." }
  - { constant: MISSION_STICKY, value: 6, input: "6", meaning: "Guard in place, dropping a target that moves out of range instead of chasing it. A vehicle on this mission never scatters. An infantryman, vehicle or aircraft standing still on this mission ignores a mission that a script or trigger gives it later." }
  - { constant: MISSION_ENTER, value: 7, input: "7", meaning: "Enter another object cooperatively." }
  - { constant: MISSION_CAPTURE, value: 8, input: "8", meaning: "Enter a target to capture it." }
  - { constant: MISSION_HARVEST, value: 9, input: "9", meaning: "Find and collect nearby Tiberium." }
  - { constant: MISSION_GUARD_AREA, value: 10, input: "10", meaning: "Actively guard an area." }
  - { constant: MISSION_RETURN, value: 11, input: "11", meaning: "Do nothing. No kind of object acts on this mission." }
  - { constant: MISSION_STOP, value: 12, input: "12", meaning: "Do nothing. No kind of object acts on this mission." }
  - { constant: MISSION_AMBUSH, value: 13, input: "13", meaning: "Do nothing. A computer-owned object switches to Hunt when a player first discovers it." }
  - { constant: MISSION_HUNT, value: 14, input: "14", meaning: "Search for and destroy enemies." }
  - { constant: MISSION_UNLOAD, value: 15, input: "15", meaning: "Find a location and unload cargo." }
  - { constant: MISSION_SABOTAGE, value: 16, input: "16", meaning: "Enter a target to destroy it." }
  - { constant: MISSION_CONSTRUCTION, value: 17, input: "17", meaning: "Play a structure's buildup." }
  - { constant: MISSION_DECONSTRUCTION, value: 18, input: "18", meaning: "Play a structure's builddown when it is sold or undeploys." }
  - { constant: MISSION_REPAIR, value: 19, input: "19", meaning: "Repair or reload a docked vehicle, heal or promote held infantry, or send a vehicle to the repair bay." }
  - { constant: MISSION_RESCUE, value: 20, input: "20", meaning: "Clear the threats around a nominated spot, then move to the cell the house picks and guard the area there." }
  - { constant: MISSION_MISSILE, value: 21, input: "21", meaning: "Run a structure's launch sequence: a missile silo's, or an EM pulse cannon's aim and fire." }
  - { constant: MISSION_HARMLESS, value: 22, input: "22", meaning: "Do nothing, as with Sleep." }
  - { constant: MISSION_OPEN, value: 23, input: "23", meaning: "Open a gate and close it again once the way is clear." }
  - { constant: MISSION_PATROL, value: 24, input: "24", meaning: "Move toward the destination, fighting threats met along the way, then carry on." }
---

These are the missions an object on the map can be in. Team scripts use a separate list of team missions, described under Mapping.

Each mission has a name. A placed object's row in a [scenario file](/formats/scenario-objects/) names the mission it starts in, and each mission's settings sit in a `rules.ini` section of the same name, as [Missions in brief](/systems/target-selection/#missions-in-brief) describes. The name is the constant without its `MISSION_` prefix, capitalized as in `Guard` or `QMove`. Two constants have other names: `MISSION_GUARD_AREA` is `Area Guard` and `MISSION_DECONSTRUCTION` is `Selling`.

Two script entries give objects a mission by its number: the [Do this...](/mapping/missions/tmission-do/) team mission and the [All Assign Mission...](/mapping/actions/taction-all-assign-mission/) trigger action. Their pages say which objects take the mission. Both assign `QMove` as `Move`.

Each kind of object acts only on some missions:

- Every kind, structures included: `Attack`, `Guard`, `Sticky` and `Area Guard`.
- Infantry, vehicles and aircraft: `Move`, `QMove`, `Enter`, `Capture`, `Sabotage`, `Hunt`, `Rescue` and `Patrol`.
- Infantry and vehicles: `Retreat`.
- Vehicles, aircraft and structures: `Unload`.
- Vehicles and structures: `Repair`.
- Vehicles only: `Harvest`.
- Structures only: `Construction`, `Selling`, `Missile` and `Open`.
- No kind: `Sleep`, `Return`, `Stop`, `Ambush` and `Harmless`.

A mission that an object does not act on still becomes its mission. The object then does nothing until another mission replaces it. A script that gives a team `Missile` or `Open` therefore leaves its members standing where they are, and an aircraft given `Retreat` stays where it is.

An infantryman, vehicle or aircraft put on `Selling` keeps it for the rest of the game. It ignores every later mission and does nothing.

The missions no kind acts on differ in what ends them:

- The wake-up trigger actions, such as [Wakeup self](/mapping/actions/taction-wakeup-self/), move an object on `Sleep` or `Harmless` to `Guard`.
- An aircraft in the air on `Sleep` switches to `Guard` at once.
- An infantryman, vehicle or aircraft on `Sleep` switches to `Guard` when a structure it is in radio contact with orders it away, for example when that structure is sold.
- A computer-owned object on `Ambush` switches to `Hunt` when a player first discovers it.

`Repair` does something different on each kind of object:

- A repair bay repairs and reloads the vehicle in radio contact with it.
- A hospital heals the infantryman it holds, and an armory promotes one instead.
- A construction yard plays its production animation and does nothing else.
- A vehicle looks for a building of the type [`RepairBay`](/keys/repairbay/) names and switches to `Enter` once one accepts it. Until then it keeps searching. If its house owns no building of that type, the vehicle switches to its idle mission.

`Rescue` sends an infantryman, vehicle or aircraft to clear threats near a spot, then on to a cell its house picks. Once there, or at once if the house picks no cell, it switches to `Area Guard`. A computer house puts most of the defenders it calls up [when its base is attacked](/systems/base-attacked/) on `Rescue`, with the object under attack as the spot.
