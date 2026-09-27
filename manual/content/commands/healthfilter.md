---
command_id: HealthFilter
---

Narrows the selection to one condition band at a time. Only selected objects the player controls count, and each falls into one band:

- red, with health at or below [`ConditionRed`](/keys/conditionred/);
- yellow, with health at or below [`ConditionYellow`](/keys/conditionyellow/);
- green, with health above that.

Bands are worked out again on every press, so an object repaired or damaged since the previous press counts in its current band.

The command remembers the selection it first narrowed as its group. A press continues that group when the selection is exactly the group, all of one of its bands, or all of two of its bands. What the press does depends on which of these the selection is:

- The whole group: keeps only its most damaged band.
- One band: keeps only the next band the group holds, in the order red, yellow, green, wrapping from green back to red. If the group holds no other band, the selection stays the same.
- Two bands of a group that holds all three: keeps only the third band.

With one red, one yellow and one green object selected, the first press keeps only the red object, the second only the yellow, the third only the green, and the fourth the red again.

Any other selection starts a new group. If it holds more than one band, the press remembers it as the group and keeps only its most damaged band. If it holds one band, the press does nothing and the previous group stays remembered.

The group leaves out any remembered object that is destroyed, no longer the player's, or off the map, such as infantry inside a transport. The cycle continues over the objects that remain. The group is forgotten when a scenario or a saved game is loaded.

[`HealthFilterAddLower`](/commands/healthfilteraddlower/) adds the next band to the selection instead of replacing it. Neither command does anything while the player is placing a structure.
