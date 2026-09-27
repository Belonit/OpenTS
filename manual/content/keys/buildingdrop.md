---
key: BuildingDrop
summary: The sound played where a vehicle deploys into a structure.
see_also: [BuildingSlam, DeploySound, UndeploysInto]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
BuildingDrop=PLACE2 ; a sound ID registered in SOUND.INI
```

The sound plays once, at the vehicle's position, when a vehicle deploys into a structure, such as an MCV becoming a construction yard. It plays only when the new structure belongs to a house the local player controls:

- In a campaign, that is the player's house and any house with [`PlayerControl=yes`](/keys/playercontrol/).
- In a skirmish or multiplayer game, it is only the local player's house.

Placing a structure built from the sidebar plays [`BuildingSlam`](/keys/buildingslam/) instead.
