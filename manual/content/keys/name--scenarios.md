---
key: Name
scope: scenarios
label: Scenario title
see_also: [RequiredAddOn]
when_omitted:
  kind: value
  value: "<none>"
  note: The title is the literal text "<none>". The previous mission's title does not carry over.
---

```ini title="map file"
[Basic]
Name=GDI 10A: Destroy the Prototype Facility (A)
```

The title labels saves of the mission in a campaign or skirmish game. The save dialog on the in-game options screen offers it as the save's description, and the descriptions of quicksaves and automatic saves include it. A title longer than 43 characters is cut off at 43.

In a campaign, `MISSION.INI` can replace the title. After reading the map, the game opens `MISSION.INI`, or `MISSION1.INI` for a map with `RequiredAddOn=1`. A `Name=` in the section named after the scenario replaces the map's title. The section name must be the full scenario name the mission was started with, path included.

The stock campaigns never reach this override. Their scenarios are named by path, such as `Maps/Missions/GDI1A.MAP`, while the stock mission file names its sections by bare filename, such as `[GDI1A.MAP]`. The title from the map file is used.
