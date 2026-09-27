---
format_id: taskforces
title: Task forces
summary: Registers reusable team compositions containing up to six infantry, vehicle, or aircraft entries.
kind: record
route: /mapping/task-forces/
files:
  - AI.INI
  - AIFS.INI
  - map file
section: TaskForces
syntax: "<slot>=<count>,<ObjectType ID>"
registration: { section: TaskForces, id_from: value, entry_section: "<TaskForce ID>" }
fields:
  - { position: 1, label: Count, value: Integer unit count, required: true }
  - { position: 2, label: Type, value: "InfantryType, UnitType, or AircraftType ID", required: true }
key_scopes:
  - applies_to: TaskForce
source_files:
  - code/taskforc.cpp
  - code/emember.cpp
  - code/init.cpp
  - code/scenario.cpp
---

`[TaskForces]` values name the TaskForce sections to load. The number to the left of a `[TaskForces]` line is only that line's name. Inside a TaskForce section the number is the member's slot, and each section accepts slots `0` through `5`.

Keep a task force ID to 23 characters or fewer. The game reads only the first 23 characters of a `[TaskForces]` value and loads the section with that shortened name, so a longer ID gets no members. A team type whose `TaskForce=` names the full ID gets a separate task force, which is also empty.

OpenTS loads `AI.INI`, then `AIFS.INI` when Firestorm is enabled, then the map's task forces. When a later file defines a task force ID that an earlier file already defined, its section replaces that task force's whole member list for the scenario. `Name=` and `Group=` keep their earlier values unless the later section sets them. A later file that lists the ID under `[TaskForces]` but has no section of that name leaves the task force unchanged.

```ini title="AI.INI, AIFS.INI, or map file"
[TaskForces]
0=MyAttackForce

[MyAttackForce]
Name=Attack force
0=4,E1
1=1,MMCH
```

Each member's type is looked up among infantry, then vehicles, then aircraft. Structures are not accepted. A member whose type matches none of these is dropped. The remaining members close up in slot order, so neither a dropped member nor a skipped slot number leaves a gap.
