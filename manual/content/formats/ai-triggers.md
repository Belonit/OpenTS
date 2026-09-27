---
format_id: ai_triggers
title: AI triggers
summary: Defines the weighted records from which a house draws its next one or two teams.
kind: record
route: /mapping/ai-triggers/
files:
  - AI.INI
  - AIFS.INI
  - map file
section: AITriggerTypes
syntax: "<AITrigger ID>=<up to 18 comma-separated fields>"
enable_section: AITriggerTypesEnable
fields:
  - position: 1
    label: Name
    value: Display name
    required: true
  - position: 2
    label: Primary team
    value: TeamType ID or <none>
    required: true
  - position: 3
    label: Owner
    value: House ID, <all>, or <none>
    required: true
    note: Tested only in a campaign game. A house ID the game does not recognize counts as <none>.
  - position: 4
    label: Ignored
    value: Present but discarded
    required: true
  - position: 5
    label: Condition type
    value: Integer from -1 through 4
    required: true
  - position: 6
    label: Condition object
    value: ObjectType ID
    required: true
  - position: 7
    label: Comparator
    value: Hexadecimal comparison block
    required: true
  - { position: 8, label: Starting weight, value: Number truncated to an integer, required: false }
  - { position: 9, label: Minimum weight, value: Number truncated to an integer, required: false }
  - { position: 10, label: Maximum weight, value: Number truncated to an integer, required: false }
  - { position: 11, label: Skirmish, value: 0 or 1, required: false }
  - { position: 12, label: Ignored, value: Present but discarded, required: false }
  - { position: 13, label: Side, value: "The side's position in the rules' [Sides] list, counted from one; 0 leaves the trigger unrestricted", required: false }
  - { position: 14, label: Base defense, value: 0 or 1, required: false, note: "Stored and written back, never read; whether a trigger counts as defensive comes from its teams' IsBaseDefense." }
  - { position: 15, label: Secondary team, value: TeamType ID or <none>, required: false }
  - { position: 16, label: Easy, value: 0 or 1, required: false }
  - { position: 17, label: Medium, value: 0 or 1, required: false }
  - { position: 18, label: Hard, value: 0 or 1, required: false }
key_scopes:
  - applies_to: AITriggerType
source_files:
  - code/aitrig.cpp
  - code/init.cpp
  - code/scenario.cpp
---

Each assignment in `[AITriggerTypes]` defines one AI trigger: its ID to the left of `=`, and its fields, separated by commas, to the right. [AI triggers and team production](/systems/ai-team-production/) explains how a house chooses among triggers and what each field decides.

## Where triggers are read

The game reads AI triggers from `AI.INI`, then from `AIFS.INI` when Firestorm is enabled, then from the map.

Whether a trigger is enabled depends on where it was defined:

- A trigger from `AI.INI` or `AIFS.INI` is enabled.
- A trigger from the map is disabled unless the map's `[AITriggerTypesEnable]` section enables it.

`[AITriggerTypesEnable]` pairs an AI trigger ID with a yes-or-no value. In a campaign game, `yes` enables the trigger and `no` disables it, and this works for a trigger from `AI.INI` or `AIFS.INI` as well. Outside a campaign, every ID listed in the section is enabled, whatever its value.

A map entry with the same ID as a trigger from `AI.INI` or `AIFS.INI` redefines that trigger. Each field the map entry supplies replaces the earlier value. The trigger stays enabled unless `[AITriggerTypesEnable]` disables it, and it counts as a map trigger, so [`IgnoreGlobalAITriggers=yes`](/keys/ignoreglobalaitriggers/) does not skip it.

## Writing the fields

Put a value in every field up to the last one you write. Consecutive commas count as one separator, so an empty field moves every later field one position earlier. Write `<none>` in a team or owner field you want to leave empty, and the intended value in every other field. A `0` in a weight field sets that weight to `0`, and a `0` in a difficulty field turns the trigger off at that difficulty.

Fields 1 through 7 are required. If the value ends before field 7, the trigger is still registered with the fields read so far. A new trigger cut short after its owner and before its condition type has no condition, so a campaign game can still draw it. A redefined trigger cut short there keeps its earlier condition.

Fields 8 through 18 can be left off the end. A new trigger missing them has weights of `1`, is not available in skirmish, has no side restriction and no secondary team, and is enabled at every difficulty. A redefined trigger keeps the values it already had.

## Condition types

The condition type selects what the trigger measures and which of the next two fields it reads. A field the condition does not read can hold anything.

| Value | What it measures | Fields it reads |
| --- | --- | --- |
| `-1` | Nothing; the condition always holds | Neither |
| `0` | How many objects of the condition object's type the enemy owns | Condition object and comparison block |
| `1` | How many objects of the condition object's type the owning house owns | Condition object and comparison block |
| `2` | Whether the enemy's power output minus its drain is below `100` | Neither |
| `3` | Whether the enemy's power output minus its drain is below `0` | Neither |
| `4` | The enemy's money, counting stored Tiberium | Comparison block |

A condition type outside this table never holds. [AI triggers and team production](/systems/ai-team-production/#defensive-teams-and-the-enemy) covers which house is the enemy and what happens when a house has none.

## The comparison block

The comparison block holds the number to compare against and the comparison to apply. It is written in hexadecimal, two digits to a byte:

- bytes 1 to 4 hold the number;
- bytes 5 to 8 hold the comparison, as a value from the table below.

Each is a four-byte integer written low byte first. Digits after the sixteenth are not used.

| Comparison value | Holds when the measured amount is |
| --- | --- |
| `0` | Less than the number |
| `1` | Less than or equal to the number |
| `2` | Equal to the number |
| `3` | Greater than or equal to the number |
| `4` | Greater than the number |
| `5` | Not equal to the number |

Any other comparison value never holds. For example, "at least 5" is the number `5` with comparison `3`, so the block starts `0500000003000000`.

## The condition object

The condition object is an ObjectType ID. The game looks it up among infantry, vehicle, aircraft and structure types, in that order, and uses the first match. An ID that matches no type does not reject the trigger: the count is `0`, and the comparison is made against that.
