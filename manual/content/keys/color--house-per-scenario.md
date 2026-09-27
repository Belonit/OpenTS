---
key: Color
scope: house-per-scenario
label: Scenario house color
see_also: [PlayerControl, Credits, Edge]
when_omitted:
  kind: inherited
  note: The color scheme the house's country sets, from its Color= in the rules.
---

The value names a color scheme declared in [`[Colors]`](/keys/color/), in any letter case. A name that `[Colors]` does not declare leaves the house on its country's color.

```ini title="scenario map file"
[Nod] ; a house record in the scenario's house list
Color=DarkRed
```

The scheme colors everything the house owns: its infantry, vehicles, aircraft and structures, and their dots on the radar. Messages shown in the house's color, such as its low-power warning, use it too.

The setting overrides the country's [`Color=`](/keys/color/#scope-housetype) for this scenario only. The country's setting is unchanged.

Only a campaign mission reads its house records, so the setting has no effect in skirmish or multiplayer. There, each house takes the color its player picked in the lobby.
