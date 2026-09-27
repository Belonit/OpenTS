---
format_id: scripts
title: Scripts
summary: Registers ordered team-mission lists containing up to fifty mission and argument pairs.
kind: record
route: /mapping/scripts/
files:
  - AI.INI
  - AIFS.INI
  - map file
section: ScriptTypes
syntax: "<slot>=<mission>,<argument>"
registration: { section: ScriptTypes, id_from: value, entry_section: "<Script ID>" }
fields:
  - { position: 1, label: Mission, value: Team mission index, required: true }
  - { position: 2, label: Argument, value: Integer interpreted by the selected mission, required: true }
key_scopes:
  - applies_to: ScriptType
related:
  - { type: mission, id: TMISSION_ATTACK }
source_files:
  - code/script.cpp
  - code/tmission.cpp
  - code/init.cpp
  - code/scenario.cpp
---

Each value in `[ScriptTypes]` is a script ID, and the section with that name holds the script. The number to the left of a `[ScriptTypes]` line only names the line. Give each line a distinct number: a repeated number replaces the earlier line in the same file, as [INI syntax](/formats/ini-syntax/#repeats-and-later-files) describes, so the earlier script is not loaded.

In a script section, `Name=` gives the display name and the numbered lines `0` through `49` hold the missions in order. The game reads those lines in number order and packs them together, so gaps in the numbering are skipped. Lines numbered `50` or higher are ignored. Each [mission page](/mapping/missions/) says what its argument means.

```ini title="AI.INI, AIFS.INI, or map file"
[ScriptTypes]
0=MyAttackScript

[MyAttackScript]
Name=Attack any enemy
0=0,1 ; Attack, with argument 1 (any suitable enemy)
```

The game reads scripts from `AI.INI`, then from `AIFS.INI` when Firestorm is enabled, then from the map file. [OPENTS.INI](/formats/opents-ini/#the-files-it-reads) can rename the two AI files. When a later file lists a script ID that an earlier one already loaded, the later file's section replaces that script's missions. If the later file lists the ID but has no section for it, the earlier script is kept unchanged.
