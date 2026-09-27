---
key: PlayerControl
summary: Hands a campaign house to the local player, who commands its objects, and gives the house the player's difficulty slot.
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "no"
---

`PlayerControl=yes` hands a campaign house to the local player. The player can select and command its objects, and EVA announcements and radar events about the house reach the player. The computer runs no production or base-building AI for it.

```ini title="scenario map file"
[GDI] ; a house record in the scenario's own house list
PlayerControl=yes
Edge=North
```

The setting also gives the house the player's [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot) in place of the computer's. Set it on the house that `[Basic] Player=` names. Without it, that house plays the mission with the computer's handicap.

More than one house may set it. Each such house is controlled by the player and gets the player's difficulty slot. The sidebar still builds only for the `[Basic] Player=` house, so any other house with this setting has neither a sidebar nor computer production.

Outside a campaign this setting is ignored. Only the house the local machine is playing counts as the player's.
