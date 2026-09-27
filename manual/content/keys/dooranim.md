---
key: DoorAnim
summary: The shape file drawn over a structure as its factory door works.
see_also: ["DoorStages", "DamagedDoor", "UnderDoorAnim", "DeployingAnim", "DeployTime", "WeaponsFactory", "system:production"]
when_omitted:
  kind: value
  value: ""
  note: No door shape is loaded and none is drawn.
---

The door animation is drawn on a [`WeaponsFactory=yes`](/keys/weaponsfactory/) structure only while a finished vehicle leaves it. Its frames show the factory door opening and closing, and they are drawn over the structure and over the vehicle in the doorway. [`DoorStages`](/keys/doorstages/) sets which frame each point of the door's travel shows.

```ini title="art.ini"
[MYWEAP] ; example war factory, drawn from its own Image ID
DoorAnim=GAWEAP_D  ; loaded as GTWEAP_D.SHP in temperate
DoorStages=9
UnderDoorAnim=GAWEAP_1
```

Write the filename without its extension; the engine loads `<value>.SHP`. Before loading, the second letter of the name is rewritten for the scenario's theater, as it is for [`NewTheater=yes`](/keys/newtheater/) artwork, whether or not the structure sets `NewTheater`. The letter changes only when it already matches the [`ImageLetter`](/keys/imageletter/) of some theater, so `GAWEAP_D` loads as `GTWEAP_D.SHP` in temperate and as `GAWEAP_D.SHP` in snow.

The door frames are drawn at the lighting level of the structure's cell, so [`ExtraLight`](/keys/extralight/) does not change them.
