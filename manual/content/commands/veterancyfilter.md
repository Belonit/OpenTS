---
command_id: VeterancyFilter
---

Narrows the selection to one [veterancy](/systems/veterancy/) rank at a time: elite, veteran or rookie. Only selected objects the player controls count. Ranks are worked out again on every press, so an object promoted since the previous press counts at its new rank.

The command remembers the selection it first narrowed as its group. A press continues that group when the selection is exactly the group, all of one of its ranks, or all of two of its ranks. What the press does depends on which of these the selection is:

- The whole group: keeps only its highest rank.
- One rank: keeps only the next lower rank the group holds, wrapping from rookie back to elite. If the group holds no other rank, the selection stays the same.
- Two ranks of a group that holds all three: keeps only the third rank.

With one elite, one veteran and one rookie selected, the first press keeps only the elite, the second only the veteran, the third only the rookie, and the fourth the elite again.

A selection that does not continue the group and holds more than one rank becomes the new group, and the press keeps only its highest rank. A single-rank selection that does not continue the group does nothing, and the previous group stays remembered.

A remembered object counts as part of the group only while it exists, belongs to the player and is on the map. Infantry inside a transport does not count, and counts again once it unloads. The cycle continues over the objects that count.

The group is forgotten when a scenario or a saved game is loaded.

[`VeterancyFilterAddLower`](/commands/veterancyfilteraddlower/) adds the next rank to the selection instead of replacing it. Neither command does anything while the player is placing a structure.
