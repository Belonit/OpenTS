---
key: AIHateDelays
summary: The frames a computer house waits before picking its first enemy, one entry per difficulty.
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: ""
  note: The list stays empty and the difficulty slot is used to index it anyway, reading storage that was never allocated.
---

Each entry is a delay in game frames. Outside a campaign, a computer house waits that long from the start of the game before it can pick an enemy on its own. Damage can still give it an enemy sooner, because every hit from a house it is not allied with [raises its anger](/systems/base-attacked/#what-raises-it) toward that house.

Each entry belongs to one [difficulty slot](/systems/difficulty/#the-per-difficulty-lists), so give the list three entries. For a computer house the first entry is used at the Hard setting and the last at Easy. A shorter list is read past its end for the missing slots.

The countdown is set once, as a skirmish or multiplayer game is set up, for every computer house whose country does not set `MultiplayPassive=yes`. A campaign never sets it, and a campaign house never picks an enemy this way.

When the countdown has run out, the house has no enemy and one of its structures is on the map, it [picks a first enemy](/systems/base-attacked/#picking-a-first-enemy). That is normally the nearest house that is not its ally, not passive and not defeated. Until a house has an enemy, [only defensive AI triggers can pass](/systems/ai-team-production/#defensive-teams-and-the-enemy).
