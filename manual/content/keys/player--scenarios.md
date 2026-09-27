---
key: Player
scope: scenarios
label: Commanded house
see_also: [SpeechSide, NextScenario]
when_omitted:
  kind: computed
  note: The first country registered, the same as an empty value.
---

```ini title="map file"
[Basic]
Player=GDI
```

`Player` names the house the player controls in a campaign mission. The name can be the country's ID or its full name, ignoring case. The player commands that house's units and structures, spends its credits, and builds from its build options. The map selection screen after the mission reads its campaign progression from the same house.

In a multiplayer or skirmish game, the lobby or the launch file assigns houses and this key is ignored.

:::danger[Name a house the mission contains]
The mission's houses are the first countries registered, one for each entry in the map's `[Houses]` section. They are counted in the order the rules declare countries, not the order `[Houses]` lists them. If `Player` names any other country, or a name that matches no country, the game crashes while loading the mission.
:::
