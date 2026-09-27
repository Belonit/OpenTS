---
format_id: teamtypes
title: Team types
summary: Registers team definitions that link an owner, TaskForce, Script, waypoint, and behavior flags.
kind: registry
route: /mapping/team-types/
files:
  - AI.INI
  - AIFS.INI
  - map file
registrations:
  - { section: TeamTypes, id_from: value, entry_section: "<TeamType ID>" }
key_scopes:
  - applies_to: TeamType
source_files:
  - code/teamtype.cpp
  - code/init.cpp
  - code/scenario.cpp
---

`[TeamTypes]` values name the TeamType sections to load, and the number to the left of each line is only that line's name. The keys in each section set the team's owner, TaskForce, Script, origin waypoint, recruitment rules, and behavior flags.

Keep a team type ID to 24 characters or fewer. A longer ID is cut to its first 24 characters, and the game looks for the team type's section under that shortened name, so the team type keeps the default for every key.

OpenTS loads `AI.INI`, then `AIFS.INI` when Firestorm is enabled, then the map's team types. When a later file defines a team type ID that an earlier file already defined, each key in its section replaces the earlier value, and each key it leaves out keeps the earlier value.

```ini title="AI.INI, AIFS.INI, or map file"
[TeamTypes]
0=MyAttackTeam ; example TeamType

[MyAttackTeam]
House=GDI
TaskForce=MyAttackForce ; defined under [TaskForces]
Script=MyAttackScript   ; defined under [ScriptTypes]
Waypoint=A
```
