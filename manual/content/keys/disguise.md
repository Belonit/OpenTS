---
key: Disguise
summary: The InfantryType whose name and artwork a disguised soldier shows to everyone else.
see_also: ["system:capture", Disguised]
when_omitted:
  kind: value
  value: none
---

A [`Disguised=yes`](/keys/disguised/) soldier takes two things from this InfantryType, and each has its own ownership test:

- **Name.** Holding the cursor over the soldier shows this type's [`Name=`](/keys/name/) to a player who is allied with the soldier's house, or observing, but does not control it. An enemy player sees the generic "Enemy Soldier" label instead, unless the soldier's own type sets [`Nominal=yes`](/keys/nominal/).
- **Artwork.** The soldier is drawn with this type's shape file for every player except its owner.

Outside a campaign, the two tests give the same answer. In a campaign, a second house that the scenario marks [`PlayerControl=yes`](/keys/playercontrol/) counts as controlled for the name but not for the artwork. Its disguised soldiers therefore wear the disguise artwork under their own name.

Only the shape file changes. The soldier still animates with its own type's sequence, so it picks frames from the disguise artwork by its own frame numbers. Give both types matching sequences, or the disguise shows the wrong frames.

With no type named, a disguised soldier keeps its own name and artwork for every player.
