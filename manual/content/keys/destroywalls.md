---
key: DestroyWalls
summary: Whether a computer house in this difficulty slot scores walls as targets while it scans.
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "yes"
  note: The difficulty block is re-read from fixed defaults whenever its section is present, so a later file that contains the section without this key restores yes rather than keeping the earlier value.
---

`[Easy]`, `[Normal]` and `[Difficult]` each set their own flag. An object uses the flag of [the difficulty slot its house holds](/systems/difficulty/#from-the-setting-to-a-slot).

With `no`, a computer house's objects stop considering walls when they [scan for a target](/systems/target-selection/#picking-the-winner). Objects of a human player's house never scan for walls, so the flag changes nothing for them.

The flag affects only that scan. An object whose target is already a wall still attacks it.

A house copies the seven difficulty figures when it gets its slot, but this flag always follows the current difficulty section. A section read later, such as one in a campaign's companion INI, therefore changes wall targeting for every computer house in that slot. [What one difficulty section sets](/systems/difficulty/#what-one-difficulty-section-sets) gives the read order.
