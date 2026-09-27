---
format_id: scenario-triggers
title: Scenario trigger records
summary: Defines the field layout of a scenario file's trigger, event, action and tag records.
kind: file
source_files:
- code/trigtype.cpp
- code/tagtype.cpp
- code/tevent.cpp
- code/taction.cpp
- code/scenario.cpp
- code/display.cpp
- code/persist.hh
filenames:
- "<scenario>.INI"
- "*.MAP"
- "*.MPR"
related:
- type: format
  id: ini-syntax
- type: format
  id: scenario-objects
- type: system
  id: trigger-springing
---

A map file declares its triggers in five sections. `[Triggers]` holds one row per trigger, and `[Events]` and `[Actions]` hold that trigger's events and actions under the same trigger ID. `[Tags]` declares the tags that fire triggers, and `[CellTags]` places a tag on a map cell. [Trigger springing](/systems/trigger-springing/) covers what the game does with these records and gives [a worked example of all five sections](/systems/trigger-springing/#tags-triggers-and-events-in-brief).

Every row except a cell tag row is a comma-separated list whose fields are known only by their position. Do not leave a field empty. Consecutive commas count as one separator, so every value after the gap moves one field earlier.

The game reads the trigger rows and then the tag rows as the scenario starts. Every trigger ID in `[Triggers]` is registered before any row is read, so a trigger row may name a trigger defined later in the section by its ID. A display name matches only a trigger whose row has already been read.

## The trigger row

The entry name is the trigger's ID, which other records use to refer to the trigger. Unlike in the object sections, the entry name matters here. The value holds eight fields in this order:

| Position | Content |
| --- | --- |
| 1 | The owner: a house name, or `<none>` for the house playing the first country the rules register. [Runtime owners](/formats/scenario-objects/#runtime-owners) covers both forms. |
| 2 | The next trigger in this trigger's chain, by ID or display name, or `<none>` for none. [Tags, triggers and events in brief](/systems/trigger-springing/#tags-triggers-and-events-in-brief) explains how a tag uses the chain. |
| 3 | The trigger's display name. Field 2 of another trigger row and the trigger field of a tag row accept this name in place of the ID. |
| 4 | `0` starts the trigger enabled; any other number starts it disabled. The three fields after it use the opposite sense. |
| 5 | `1` enables the trigger at easy difficulty. |
| 6 | `1` enables the trigger at medium difficulty. |
| 7 | `1` enables the trigger at hard difficulty. |
| 8 | `1` lets the trigger's tag pass to another object, as described below the table. |

A tag passes on when any trigger in its chain sets field 8. It passes in these cases:

- A destroyed vehicle passes the tag to the infantry that escapes from it.
- Infantry that captures a structure or takes over a vehicle passes its tag to what it took.

A vehicle that infantry took over does not offer its destruction events to a tag that passes on. The tag goes to the infantry that escapes from the wreck, if one escapes.

Only the field for the difficulty being played is used, and [difficulty](/systems/trigger-springing/#difficulty) covers what it decides.

Fields 5 to 8 may be left off the end of the row. A missing difficulty field enables the trigger at that difficulty, and a missing field 8 counts as `0`. A row that also leaves off field 4 starts the trigger disabled.

A row with an empty value, or whose owner matches no house in the game, is dropped. With `<none>`, that happens when no house plays the first country. A tag that names a dropped trigger fires nothing.

## The event row

The entry name is the trigger's ID. The value starts with the number of events, followed by three fields for each event:

| Position | Content |
| --- | --- |
| 1 | The number of events in the row. |
| 2, 5, 8, ... | The event's number, which its [event page](/mapping/events/) lists as Numeric ID. |
| 3, 6, 9, ... | What the next field holds: `0` a number, `1` a [team type](/mapping/team-types/). |
| 4, 7, 10, ... | The number, or the team type's ID or display name. |

```ini title="map file"
[Events]
01000004=1,14,0,0          ; one event: 14, Mission Timer Expired
01000005=2,12,0,500,17,0,0 ; two events: 12 with the number 500, then 17
```

Every event needs all three of its fields. [Mission Timer Expired](/mapping/events/tevent-mission-timer-expired/) takes no parameter (its page lists the Need token `NEED_NONE`), so the first row writes `0,0` after the event number. A trigger with no events may leave out its row or write `0`.

Write as many events as the count says. Events beyond the count are ignored, and a row with fewer fields than its count requires crashes the game when the scenario loads.

The game examines a trigger's events in the reverse of their order in the row, so in the second row above it examines event 17 before event 12. [Remembering a satisfied event](/systems/trigger-springing/#remembering-a-satisfied-event) covers what the order decides.

## The action row

The entry name is the trigger's ID. The value starts with the number of actions, followed by eight fields for each action:

| Position | Content |
| --- | --- |
| 1 | The number of actions in the row. |
| 2, 10, 18, ... | The action's number, which its [action page](/mapping/actions/) lists as Numeric ID. |
| 3, 11, 19, ... | What the next field holds: `0` a number, `1` a team, `2` a trigger, `3` a tag, or `4` a team with a time in the action's last field. |
| 4, 12, 20, ... | Under `0`, the number. Under `1` to `4`, the ID of the team, trigger or tag, or `-1` for none. |
| 5 to 8, 13 to 16, ... | Four rectangle fields: X, Y, width and height. Most actions write all four as `0`. The exceptions keep part of their parameter here, and their pages name the field, as [Give Credits](/mapping/actions/taction-give-credits/) does. |
| 9, 17, 25, ... | The waypoint the action works at, or the time under `4`. |

A team, trigger or tag named in an action must be named by its ID; display names are not matched. An ID that matches nothing creates an empty team, trigger or tag under that name. A value of one or two characters other than `-1` is read as a position in the game's list of teams, triggers or tags, counting from `0`. Give anything an action names an ID of at least three characters.

Write as many actions as the count says. As with events, a row with fewer fields than its count requires crashes the game when the scenario loads. A trigger with no actions may leave out its row or write `0`.

The last action in a row may leave out its final field, which then means waypoint `A`, or time `0` under `4`. In any earlier action, leaving out the final field shifts every later field.

## The tag row

The entry name is the tag's ID. The value holds three fields:

| Position | Content |
| --- | --- |
| 1 | The tag's lifetime: `0` volatile, `1` semi-persistent, `2` persistent. [Tag lifetimes](/systems/trigger-springing/#tag-lifetimes) covers what each one does. |
| 2 | The tag's display name. |
| 3 | The trigger the tag fires, by ID or display name. |

A tag whose trigger field is missing, `<none>`, or names no trigger fires nothing.

## The cell tag row

`[CellTags]` has one row per tagged cell. The entry name is the cell, written as one number, and the value is the tag:

| Part | Content |
| --- | --- |
| Entry name | The cell number: the column plus 1000 times the row on a map whose [NewINIFormat](/keys/newiniformat/) is 4 or higher, or the column plus 128 times the row on an older map. |
| Value | The tag's ID from `[Tags]`, in any letter case. Display names are not matched. A value that matches no tag places a new tag with no trigger, which fires nothing. `<none>` places no tag. |

A cell takes the first row that places a tag on it. Later rows for the same cell are ignored.
